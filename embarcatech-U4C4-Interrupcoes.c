#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pico/multicore.h>

#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "matrix.h"

#define LED_RED 200
#define LED_GREEN 0
#define LED_BLUE 0

#define RGB_RED 13
#define RGB_GREEN 11
#define RGB_BLUE 12

#define BUTTON_A 5
#define BUTTON_B 6

#define DEBOUNCE_TIME_US 200000  // 200ms
#define TIME 100

static volatile uint32_t last_press_A = 0;
static volatile uint32_t last_press_B = 0;
static volatile int counter = 0;  

void led_task(void) {
    while(1) {
        gpio_put(RGB_RED, 1);  
        sleep_ms(100);       
        gpio_put(RGB_RED, 0);  
        sleep_ms(100);        
    }
}

bool led_buffer[NUM_PIXELS] = {0};

void setup(void) {
    stdio_init_all();
    //pico_sdk_init();

    gpio_init(RGB_RED);
    gpio_set_dir(RGB_RED, GPIO_OUT);
    gpio_put(RGB_RED, 0);

    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);

    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);
}

static void gpio_irq_handler(uint gpio, uint32_t events) {
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    if (gpio == BUTTON_A && (events & GPIO_IRQ_EDGE_FALL)) {
        if (current_time - last_press_A > DEBOUNCE_TIME_US) {  
            last_press_A = current_time;
            counter = (counter + 1) % 10;  
        }
    } 
    else if (gpio == BUTTON_B && (events & GPIO_IRQ_EDGE_FALL)) {
        if (current_time - last_press_B > DEBOUNCE_TIME_US) { 
            last_press_B = current_time;
            counter = (counter - 1 + 10) % 10;  
        }
    }
}

int main(void) {
    setup();

    PIO pio = pio0;
    int sm = 0;

    multicore_launch_core1(led_task);

    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    while (1) {
        set_num_matrix(counter, led_buffer);  
        set_one_led(LED_RED, LED_GREEN, LED_BLUE, led_buffer);
        sleep_ms(TIME); 
    }
    
    return 0;
}
