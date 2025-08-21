#ifndef MAIN_H
#define MAIN_H

#include "sine_table.h"
#include "driver_tmr.h"

// Размер таблицы синуса (если не определён в sine_table.h)
#ifndef SINE_TABLE_SIZE
#define SINE_TABLE_SIZE 1000
#endif

// Глобальная таблица для масштабированных значений синуса
extern uint16_t scaled_table[SINE_TABLE_SIZE];

// Прототипы пользовательских функций (если потребуется)

#endif // MAIN_H
