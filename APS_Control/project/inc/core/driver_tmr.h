#ifndef DRIVER_TMR_H
#define DRIVER_TMR_H

#include <stdint.h>
#include "at32f435_437.h"

#include "sine_table.h"

/**
 * @file driver_tmr.h
 * @brief Функция для установки значений PWM по фазовым синус-таблицам (жёстко для TMR1, канал 1 и 2).
 *
 * Функция set_phase_pwm_from_table устанавливает значения из масштабированной синус-таблицы
 * scaled_sine_table_0 в каналы 1 и 2 таймера TMR1.
 *
 * @param index Индекс в таблице (0..SINE_TABLE_SIZE-1)
 */
void set_phase_pwm_from_table(uint16_t index);

#endif // DRIVER_TMR_H