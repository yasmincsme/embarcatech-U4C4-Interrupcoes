#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

void set_num_matrix(uint8_t number, bool *led_buffer) {
    switch (number) {
    case 0: {
        bool pattern[NUM_PIXELS] = {
            0, 1, 1, 1, 0, 
            0, 1, 0, 1, 0, 
            0, 1, 0, 1, 0, 
            0, 1, 0, 1, 0, 
            0, 1, 1, 1, 0
        };
        memcpy(led_buffer, pattern, sizeof(pattern));
        break;
    }
    case 1: {
       bool pattern[NUM_PIXELS] = {
            0, 0, 1, 0, 0, 
            0, 0, 1, 0, 0, 
            0, 0, 1, 0, 0, 
            0, 1, 1, 0, 0, 
            0, 0, 1, 0, 0
        }; 
        memcpy(led_buffer, pattern, sizeof(pattern));
        break;
    }
    case 2: {
        bool pattern[NUM_PIXELS] = {
            0, 1, 1, 1, 0, 
            0, 1, 0, 0, 0, 
            0, 1, 1, 1, 0, 
            0, 0, 0, 1, 0, 
            0, 1, 1, 1, 0
        }; 
        memcpy(led_buffer, pattern, sizeof(pattern));
        break;
    }
    case 3: {
        bool pattern[NUM_PIXELS] = {
            0, 1, 1, 1, 0, 
            0, 0, 0, 1, 0, 
            0, 1, 1, 1, 0, 
            0, 0, 0, 1, 0, 
            0, 1, 1, 1, 0
        }; 
        memcpy(led_buffer, pattern, sizeof(pattern));
        break;
    }
    case 4: {
        bool pattern[NUM_PIXELS] = {
            0, 1, 0, 0, 0, 
            0, 0, 0, 1, 0, 
            0, 1, 1, 1, 0, 
            0, 1, 0, 1, 0, 
            0, 1, 0, 1, 0
        }; 
        memcpy(led_buffer, pattern, sizeof(pattern));
        break;
    }
    case 5: {
        bool pattern[NUM_PIXELS] = {
            0, 1, 1, 1, 0, 
            0, 0, 0, 1, 0, 
            0, 1, 1, 1, 0, 
            0, 1, 0, 0, 0, 
            0, 1, 1, 1, 0
        }; 
        memcpy(led_buffer, pattern, sizeof(pattern));
        break;
    }
    case 6: {
        bool pattern[NUM_PIXELS] = {
            0, 1, 1, 1, 0, 
            0, 1, 0, 1, 0, 
            0, 1, 1, 1, 0, 
            0, 1, 0, 0, 0, 
            0, 0, 0, 1, 0
        }; 
        memcpy(led_buffer, pattern, sizeof(pattern));
        break;
    }
    case 7: {
        bool pattern[NUM_PIXELS] = {
            0, 1, 0, 0, 0, 
            0, 0, 0, 1, 0, 
            0, 1, 0, 0, 0, 
            0, 0, 0, 1, 0, 
            0, 1, 1, 1, 0
        }; 
        memcpy(led_buffer, pattern, sizeof(pattern));
        break;
    }
    case 8: {
        bool pattern[NUM_PIXELS] = {
            0, 1, 1, 1, 0, 
            0, 1, 0, 1, 0, 
            0, 1, 1, 1, 0, 
            0, 1, 0, 1, 0, 
            0, 1, 1, 1, 0
        }; 
        memcpy(led_buffer, pattern, sizeof(pattern));
        break;
    }
    case 9: {
        bool pattern[NUM_PIXELS] = {
            0, 1, 0, 0, 0, 
            0, 0, 0, 1, 0, 
            0, 1, 1, 1, 0, 
            0, 1, 0, 1, 0, 
            0, 1, 1, 1, 0
        }; 
        memcpy(led_buffer, pattern, sizeof(pattern));
        break;
    }
    default:
        break;
    }
}

static inline void set_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return ((uint32_t) (r) << 8) | ((uint32_t) (g) << 16) | (uint32_t) (b);
}

void set_one_led(uint8_t r, uint8_t g, uint8_t b, bool *led_buffer) {
    uint32_t color = urgb_u32(r, g, b);

    for(uint8_t i = 0; i < NUM_PIXELS; ++i) {
        if(led_buffer[i]) {
            set_pixel(color);
        } else {
            set_pixel(0);
        }
    }
}