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

#endif // SYSTEM_UTILS_H
