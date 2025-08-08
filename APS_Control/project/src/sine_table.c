//
// Created by pader on 08.08.2025.
//

#include <math.h>
#include "sine_table.h"

float sine_table[SINE_TABLE_SIZE];

void init_sine_table(void) {
    for (int i = 0; i < SINE_TABLE_SIZE; ++i) {
        float x = (float)i / (SINE_TABLE_SIZE - 1);
        sine_table[i] = 0.5f * (sinf(2.0f * M_PI * x) + 1.0f);
    }
}