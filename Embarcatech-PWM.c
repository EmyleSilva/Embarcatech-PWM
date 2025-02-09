#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/pwm.h"

#define MOTOR_PIN 22
/**
 * O uso do macro "MOTOR_PIN" como pino 12 foi feito para realizar 
 * o experimento com LED na placa BitDogLab (Questão 6 da tarefa). 
 * O Registro do experimento se encontra no video disponibilizado no README. 
 */
//#define MOTOR_PIN 12


/**
 * A frequência de PWM deve ser de 50Hz
 * Aplicando os valores de Wrap e divisor abaixo na fórmula, temos:
 * freq = 125Mhz / (250.0 * 10.000) logo, freq = 50
 */
const uint16_t WRAP = 10000;
const float diviser = 250.0;
uint16_t duty_cycle = 0; //Nivel inicial do Dc em 0%
bool up_down = 1; //0 -> down | 1 -> up

/**
 * Função para configurar/inicializar o PWM
 */
void setup_pwm()
{
    gpio_set_function(MOTOR_PIN, GPIO_FUNC_PWM);

    uint slice = pwm_gpio_to_slice_num(MOTOR_PIN);

    pwm_set_clkdiv(slice, diviser);
    pwm_set_wrap(slice, WRAP);
    pwm_set_gpio_level(MOTOR_PIN, duty_cycle);

    pwm_set_enabled(slice, true);
}

/**
 * A fórmula calcula o valor do duty cycle com base 
 * no tempo em microssegundos.
 */
uint16_t calculate_new_dc(uint time_in_uq)
{
    /**
     * Usa a fórmula (Tdc * wrap) /  Tpwm
     * Onde: 
     * Tdc é o tempo em microssegundos
     *Tpwm é o periodo em microssegundos (20ms = 20000) 
     */
    return ((time_in_uq * WRAP) / 20000);
}

int main()
{
    stdio_init_all();
    setup_pwm();
    uint16_t min_dc = calculate_new_dc(500); //Para um duty_cycle de 0,025% (flange em 0º)
    uint16_t max_dc = calculate_new_dc(2400); //Para um duty_cycle de 0,12% (flange em 180º)

    /**
     * Requisitos iniciais (Questões 2, 3 e 4) 
     */
    pwm_set_gpio_level(MOTOR_PIN, max_dc); 
    sleep_ms(5000);

    pwm_set_gpio_level(MOTOR_PIN, calculate_new_dc(1470)); //Define um Dc de 0,0735% (flange em 90º)
    sleep_ms(5000);

    pwm_set_gpio_level(MOTOR_PIN, min_dc); 
    sleep_ms(5000);

    /**
     * Loop principal, realiza a rotina de movimentação periódica da flange do 
     * braço do servomotor entre ângulos de 0 e 180 graus. 
     */
    while (true) {
        if (up_down)
        {
            duty_cycle += 2; //Incremento de 5 µs
            if (duty_cycle >= max_dc) up_down = 0;
        }else {
            duty_cycle -= 2; //Decremento de 5 µs
            if (duty_cycle <= min_dc) up_down = 1;
        }        

        pwm_set_gpio_level(MOTOR_PIN, duty_cycle);
        sleep_ms(10); 
    }
}
