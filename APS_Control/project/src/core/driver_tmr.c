/**
 * @file driver_tmr.c
 * @brief Реализация драйвера таймера для проекта APS Control.
 *
 * Этот файл содержит реализацию функций и процедур, связанных с работой таймеров,
 * используемых в прошивке APS CPU. Обеспечивает инициализацию, конфигурирование
 * и управление аппаратными таймерами, необходимыми для различных операций
 * синхронизации и управления временем в системе.
 *
 * @author pader
 * @date 14.08.2025
 */


#include "driver_tmr.h"

#include <stdint.h>

#include "sine_table.h"
#include "at32f435_437.h"


/**
 * @brief Устанавливает значения из масштабированных синус-таблиц в каналы таймера.
 *
 * Использует значения из таблиц scaled_sine_table_0, scaled_sine_table_120, scaled_sine_table_240
 * и записывает их в соответствующие каналы таймера через tmr_channel_value_set.
 *
 * @param index Индекс в таблице (обычно 0..SINE_TABLE_SIZE-1)
 * @note В текущей реализации функция записывает только фазу 0° в два канала (пример).
 *       Для полноценной работы раскомментируйте строки для фаз 120° и 240° и используйте нужные каналы.
 */
void set_phase_pwm_from_table(uint16_t index)
{
	uint32_t val0 = scaled_sine_table_0[index % SINE_TABLE_SIZE];
	uint32_t val120 = scaled_sine_table_120[index % SINE_TABLE_SIZE];
	uint32_t val240 = scaled_sine_table_240[index % SINE_TABLE_SIZE];

	tmr_channel_value_set(TMR1, TMR_SELECT_CHANNEL_1, val0);
	tmr_channel_value_set(TMR1, TMR_SELECT_CHANNEL_2, val0);

	tmr_channel_value_set(TMR8, TMR_SELECT_CHANNEL_2, val120);
	tmr_channel_value_set(TMR8, TMR_SELECT_CHANNEL_3, val120);

	tmr_channel_value_set(TMR20, TMR_SELECT_CHANNEL_1, val240);
	tmr_channel_value_set(TMR20, TMR_SELECT_CHANNEL_2, val240);



}



