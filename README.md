# Controle de Servomotor PWM

Projeto criado para simular o controle do ângulo de um servomotor utilizando o módulo PWM presente no microcontrolador RP2040.

## Vídeo de Demonstração

O vídeo demonstrativo do projeto pode ser encontrado no link abaixo:  
[Link para o vídeo](https://youtu.be/EqtT0Uz25nc)

## Descrição do Projeto

O projeto utiliza os seguintes componentes presentes no simulador Wokwi:
- Microcontrolador Raspberry Pi Pico W.
- Servomotor - motor micro servo padrão.

Além disso, para o experimento na placa de desenvolvimento BitDogLab, é utilizado um **LED RGB** conectado à GPIO 12.

## Funcionalidades do Projeto

1. **Movimentação do braço do Servomotor**
   - Inicialmente, o braço do servomotor é posicionado a um ângulo de 180 graus. Após 5 segundos, o braço muda para uma posição de 90 graus. Após mais 5 segundos, é movimentado para um ângulo de 0 graus. Por fim, aguarda mais 5 segundos.
   - Uma rotina de movimentação periódica é iniciada, movendo-o em ângulos de 0 e 180 graus de maneira suave, com um atraso de 10ms entre cada movimentação.

2. **Experimento na placa BitDogLab**
   - O código pode ser executado na placa, mudando o pino do módulo PWM de 22 (conectado ao servomotor no Wokwi) para 12 (LED RGB na placa).

## Requisitos do Projeto

- Frequência PWM definida para 50Hz (Período de 20ms).
- Definição de Duty Cycle (Dc) para 2400μs.
- Definição de Dc para 1470μs.
- Definição de Dc para 500μs.
- Após as definições anteriores, deve ser feita uma rotina de movimentação periódica do braço do servomotor entre ângulos de 0 e 180 graus.
- Realização de um experimento com a placa BitDogLab, executando o código do exercício utilizando o **LED RGB - GPIO 12** para observar o comportamento do LED.

## Simulação no Wokwi

Para visualizar a simulação do projeto no Wokwi:
1. Instale e configure o simulador Wokwi seguindo as instruções encontradas no link a seguir:  
   [Introdução ao Wokwi para VS Code](https://docs.wokwi.com/pt-BR/vscode/getting-started).
2. Abra o arquivo `diagram.json` no VS Code.
3. Clique em "Start Simulation".

## Como Compilar e Executar

1. **Pré-requisitos**:
   - Ter o ambiente de desenvolvimento para o Raspberry Pi Pico configurado (compilador, SDK, etc.).
   - CMake instalado.

2. **Compilação**:
   - Clone o repositório ou baixe os arquivos do projeto.
   - Navegue até a pasta do projeto e crie uma pasta de build:
     ```bash
     mkdir build
     cd build
     ```
   - Execute o CMake para configurar o projeto:
     ```bash
     cmake ..
     ```
   - Compile o projeto:
     ```bash
     make
     ```

3. **Upload para a placa**:
   - Conecte o Raspberry Pi Pico ao computador.
   - Copie o arquivo `.uf2` gerado para a placa.