#ifndef SINE_TABLE_H
#define SINE_TABLE_H

/**
 * @file sine_table.h
 * @brief Модуль для работы с синус-таблицами с фазовыми сдвигами и их масштабирования.
 *
 * Содержит:
 *  - Определение размера таблицы и фазовых сдвигов
 *  - Объявления массивов синуса для фаз 0°, 120°, 240° (float)
 *  - Объявления масштабированных таблиц (uint16_t)
 *  - Прототипы функций генерации, инициализации и масштабирования таблиц
 *
 * Использование:
 *  - Вызовите init_sine_tables() для заполнения исходных таблиц
 *  - Вызовите update_scaled_sine_tables(scale_coeff) для обновления масштабированных таблиц
 *  - Для генерации произвольной таблицы используйте generate_sine_table_with_phase()
 */

#include <stdint.h>

#define SINE_TABLE_SIZE    40
#define SINE_PHASE_SHIFT_0    0
#define SINE_PHASE_SHIFT_120  120
#define SINE_PHASE_SHIFT_240  240

// Масштабированные таблицы (uint16_t) для фаз 0°, 120°, 240°
extern volatile  uint16_t scaled_sine_table_0[SINE_TABLE_SIZE];
extern volatile  uint16_t scaled_sine_table_120[SINE_TABLE_SIZE];
extern volatile  uint16_t scaled_sine_table_240[SINE_TABLE_SIZE];
extern volatile  uint16_t scaled_sine_table_none[SINE_TABLE_SIZE];

// Исходные таблицы синуса для фаз 0°, 120°, 240°
extern volatile  float sine_table_0[SINE_TABLE_SIZE];
extern volatile  float sine_table_120[SINE_TABLE_SIZE];
extern volatile  float sine_table_240[SINE_TABLE_SIZE];
extern volatile  float sine_table_none[SINE_TABLE_SIZE];

/**
 * @brief Инициализирует три синус-таблицы для фаз 0°, 120°, 240°
 */
void init_sine_tables(void);

/**
 * @brief Генерирует синус-таблицу с заданным фазовым сдвигом (в градусах)
 * @param table Массив для заполнения
 * @param size Размер массива
 * @param phase_deg Фазовый сдвиг в градусах
 */
void generate_sine_table_with_phase(float *table, int size, float phase_deg);

/**
 * @brief Масштабирует значения синус-таблицы с плавающей точкой в целочисленный массив с коэффициентом
 * @param sine_table Входной массив float
 * @param size Размер массива
 * @param result_table Выходной массив uint16_t
 * @param scale_coeff Коэффициент масштабирования
 */
void scale_sine_table(const float *sine_table, int size, uint16_t *result_table, float scale_coeff);

/**
 * @brief Обновляет все три масштабированные синус-таблицы с одинаковым коэффициентом
 * @param scale_coeff Коэффициент масштабирования
 */
void update_scaled_sine_tables(float scale_coeff);

#endif // SINE_TABLE_H
