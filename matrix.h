#ifndef MATRIX_H
#define MATRIX_H

#include "pico/stdlib.h"
#include "hardware/pio.h"

#define NUM_PIXELS 25
#define IS_RGBW false
#define WS2812_PIN 7

void set_num_matrix(uint8_t number, bool *led_buffer);
static inline void set_pixel(uint32_t pixel_grb);
static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b);
void set_one_led(uint8_t r, uint8_t g, uint8_t b, bool *led_buffer);

#endif // MATRIX_H