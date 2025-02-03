<div align="center">
    <img src="https://moodle.embarcatech.cepedi.org.br/pluginfile.php/1/theme_moove/logo/1733422525/Group%20658.png" alt="Logo Embarcatech" height="100">
</div>

<br>

<div align="center">

# Unidade 4 - Capítulo 4: Interrupções

</div>


## Sumário

- [Enunciado](#enunciado)
- [Objetivos](#objetivos)
- [Descrição do Projeto](#descricao-do-projeto)
- [Requisitos do Projeto](#requisitos-do-projeto)
- [Funcionalidades Implementadas](#funcionalidades-implementadas)
- [Implementação Técnica](#implementacao-tecnica)
- [Entrega](#entrega)
- [Autor](#autor)

## Enunciado
Este projeto tem como objetivo consolidar a compreensão dos conceitos relacionados ao uso de interrupções no microcontrolador RP2040, explorando as funcionalidades da placa de desenvolvimento BitDogLab.

## Objetivos
- Compreender o funcionamento e a aplicação de interrupções em microcontroladores.
- Identificar e corrigir o fenômeno do bouncing em botões por meio de debouncing via software.
- Manipular e controlar LEDs comuns e LEDs endereçáveis WS2812.
- Fixar o estudo do uso de resistores de pull-up internos em botões de acionamento.
- Desenvolver um projeto funcional que combine hardware e software.

## Descrição do Projeto
O projeto consiste na implementação de um sistema utilizando os seguintes componentes conectados à placa BitDogLab:

- **Matriz 5x5 de LEDs (endereçáveis) WS2812**, conectada à GPIO 7.
- **LED RGB**, com os pinos conectados às GPIOs 11, 12 e 13.
- **Botão A**, conectado à GPIO 5.
- **Botão B**, conectado à GPIO 6.

## Requisitos do Projeto
Para garantir a correta implementação, os seguintes requisitos foram atendidos:

- **Uso de interrupções (IRQ):** Todas as funcionalidades relacionadas aos botões devem ser implementadas utilizando rotinas de interrupção.
- **Debouncing:** O tratamento do bouncing dos botões deve ser realizado via software.
- **Controle de LEDs:** O projeto deve demonstrar o uso adequado de LEDs comuns e LEDs WS2812.
- **Organização do código:** O código deve estar bem estruturado e comentado para facilitar a compreensão.

## Funcionalidades Implementadas
- O LED vermelho do LED RGB pisca continuamente 5 vezes por segundo, gerenciado em um núcleo separado do microcontrolador.
- O **botão A** incrementa o número exibido na matriz de LEDs cada vez que for pressionado, utilizando interrupções para detecção de borda de descida.
- O **botão B** decrementa o número exibido na matriz de LEDs cada vez que for pressionado, também utilizando interrupções.
- Os **LEDs WS2812** são usados para exibir números de **0 a 9**, com cada número sendo exibido na matriz em um formato fixo, semelhante a caracteres em estilo digital.

## Implementação Técnica
- **Interrupções (IRQ):** Todas as interações com os botões são tratadas por interrupções para garantir a responsividade.
- **Debouncing via software:** Implementado utilizando um tempo mínimo entre pressões sucessivas, prevenindo leituras erradas.
- **Controle de LEDs:** Uso de LEDs WS2812 por meio de uma comunicação serial com temporização precisa.
- **Código modularizado:** O código está dividido em funções separadas para clareza e manutenção, tendo um arquivo **matrix.c** que abstrai um pouco da complexidade do uso da matriz de leds do código principal.
- **Execução paralela:** O LED RGB é controlado no segundo núcleo do microcontrolador para evitar bloqueios na execução principal, funcionalidade esta que foi implementada com o auxílio da biblioteca **pico/multicore**.

## Instruções de Uso

1. **Clonar o Repositório**:

```bash
git clone https://github.com/yasmincsme/embarcatech-U4C4-Interrupcoes.git
```

   

2. **Compilar e Carregar o Código**:
   No VS Code, configure o ambiente e compile o projeto com os comandos:

```bash	
cmake -G Ninja ..
ninja
```

3. **Interação com o Sistema**:
   - Conecte a placa ao computador.
   - Clique em run usando a extensão do raspberry pi pico.


## Entrega

### 1. Roteiro de Testes


### 2. Vídeo de Demonstração

---
### Autora:
Yasmin Cordeiro de Souza Meira


