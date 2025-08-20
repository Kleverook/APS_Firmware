
/**
 * @file sine_table.c
 * @brief Реализация таблиц значений синуса для микроконтроллерных приложений.
 *
 * В этом файле определены три таблицы синуса (фазы 0°, 120°, 240°) и функции для их инициализации.
 * Значения рассчитываются по формуле: 0.5 * (sin(2πx + phase) + 1), где x изменяется от 0 до 1, а phase — сдвиг в радианах.
 *
 * Использование:
 *  - Вызовите функцию init_sine_tables() для заполнения всех трёх массивов перед использованием.
 *  - Для генерации таблицы с произвольным фазовым сдвигом используйте generate_sine_table_with_phase().
 *  - Массивы sine_table_0, sine_table_120, sine_table_240 можно использовать для быстрого доступа к значениям синуса с фазовыми сдвигами.
 *
 * @author Падерин Даниил
 * @date 08.08.2025
 */


#include <math.h>
#include "sine_table.h"

#include <stdint.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif


// Массивы для масштабированных фазных таблиц
volatile uint16_t scaled_sine_table_0[SINE_TABLE_SIZE];
volatile uint16_t scaled_sine_table_120[SINE_TABLE_SIZE];
volatile uint16_t scaled_sine_table_240[SINE_TABLE_SIZE];
volatile uint16_t scaled_sine_table_none[SINE_TABLE_SIZE];

volatile float sine_table_0[SINE_TABLE_SIZE];
volatile float sine_table_120[SINE_TABLE_SIZE];
volatile float sine_table_240[SINE_TABLE_SIZE];
volatile float sine_table_none[SINE_TABLE_SIZE];


/**
 * @brief Заполняет переданный массив значениями синуса с заданным фазовым сдвигом (в градусах).
 * @param table Массив для заполнения
 * @param size Размер массива
 * @param phase_deg Фазовый сдвиг в градусах
 */
void generate_sine_table_with_phase(float *table, int size, float phase_deg) {
    float phase_rad = phase_deg * (float)M_PI / 180.0f;
    for (int i = 0; i < size; ++i) {
        float x = (float)i / (size - 1);
        table[i] = 0.5f * (sinf(2.0f * M_PI * x + phase_rad) + 1.0f);
    }
}

/**
 * @brief Инициализирует три синус-таблицы с фазовыми сдвигами 0°, 120°, 240°.
 */
void init_sine_tables(void) {
    generate_sine_table_with_phase(sine_table_0, SINE_TABLE_SIZE, SINE_PHASE_SHIFT_0);
    generate_sine_table_with_phase(sine_table_120, SINE_TABLE_SIZE, SINE_PHASE_SHIFT_120);
    generate_sine_table_with_phase(sine_table_240, SINE_TABLE_SIZE, SINE_PHASE_SHIFT_240);
    generate_sine_table_with_phase(sine_table_none, SINE_TABLE_SIZE, SINE_PHASE_SHIFT_240);
}
/**
 * @brief Масштабирует значения синус-таблицы с плавающей точкой в целочисленный массив с коэффициентом
 * @param sine_table Входной массив float
 * @param size Размер массива
 * @param result_table Выходной массив uint16_t
 * @param scale_coeff Коэффициент масштабирования
 */
void scale_sine_table(const float *sine_table, int size, uint16_t *result_table, float scale_coeff) {
    for (int i = 0; i < size; i++) {
        float scaled = sine_table[i] * scale_coeff;
        if (scaled < 1.0f) scaled = 1.0f;
        if (scaled > 3999.0f) scaled = 3999.0f;
        result_table[i] = (uint16_t)scaled;
    }
}


/**
 * @brief Инициализирует и масштабирует три фазные таблицы синуса с одинаковым коэффициентом
 * @param scale_coeff Коэффициент масштабирования
 */
void update_scaled_sine_tables(float scale_coeff) {
    scale_sine_table(sine_table_0, SINE_TABLE_SIZE, scaled_sine_table_0, scale_coeff);
    scale_sine_table(sine_table_120, SINE_TABLE_SIZE, scaled_sine_table_120, scale_coeff);
    scale_sine_table(sine_table_240, SINE_TABLE_SIZE, scaled_sine_table_240, scale_coeff);
    scale_sine_table(sine_table_none, SINE_TABLE_SIZE, scaled_sine_table_none, scale_coeff);
}