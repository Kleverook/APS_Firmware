#ifndef SYSTEM_UTILS_H
#define SYSTEM_UTILS_H

#include "at32f435_437.h"

/**
 * @file system_utils.h
 * @brief Системные функции для управления микроконтроллером.
 */

/**
 * @brief Включает необходимые прерывания в системе.
 * Здесь можно добавить вызовы для включения любых нужных прерываний.
 */
void enable_system_interrupts(void);

/**
 * @brief Включает или выключает все выходы каналов таймеров TMR1, TMR8, TMR20.
 * @param state TRUE — включить, FALSE — выключить
 */
void set_all_timer_outputs_state(confirm_state state);

/**
 * @brief Включает или выключает счет таймеров TMR1, TMR8, TMR20.
 * @param state TRUE — разрешить счет, FALSE — запретить
 */
void set_all_timer_counters_state(confirm_state state);

#endif // SYSTEM_UTILS_H
