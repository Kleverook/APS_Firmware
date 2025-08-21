#/**
# * @file system_utils.c
# * @brief Реализация системных функций для управления микроконтроллером APS Control.
# *
# * В этом файле реализуются функции, обеспечивающие базовые системные операции,
# * такие как включение необходимых прерываний и другие вспомогательные процедуры.
# *
# * Использование:
# *  - Вызовите enable_system_interrupts() для включения нужных прерываний.
# *  - Добавляйте новые функции для расширения системных возможностей по мере необходимости.
# *
# * @author (укажите автора)
# * @date (укажите дату создания)
# */
#include "system_utils.h"

/**
 * @brief Включает необходимые для работы системные прерывания.
 *
 * Эта функция включает прерывание переполнения для Таймера 1 с помощью
 * вызова tmr_interrupt_enable() с соответствующими параметрами. При необходимости
 * здесь можно добавить включение других прерываний для расширения функциональности системы.
 */
void enable_system_interrupts(void)
{
    // Включение прерывания переполнения таймера 1
    tmr_interrupt_enable(TMR1, TMR_OVF_INT, TRUE);
    // Здесь можно добавить другие прерывания по мере необходимости
}

/**
 * @brief Включает или выключает все выходы каналов таймеров TMR1, TMR8, TMR20.
 * @param state TRUE — включить, FALSE — выключить
 */
void set_all_timer_outputs_state(confirm_state state)
{
    tmr_channel_enable(TMR1, TMR_SELECT_CHANNEL_1,   state);
    tmr_channel_enable(TMR1, TMR_SELECT_CHANNEL_2,   state);
    tmr_channel_enable(TMR1, TMR_SELECT_CHANNEL_1C,  state);
    tmr_channel_enable(TMR1, TMR_SELECT_CHANNEL_2C,  state);
    tmr_channel_enable(TMR8, TMR_SELECT_CHANNEL_2,   state);
    tmr_channel_enable(TMR8, TMR_SELECT_CHANNEL_3,   state);
    tmr_channel_enable(TMR8, TMR_SELECT_CHANNEL_2C,  state);
    tmr_channel_enable(TMR8, TMR_SELECT_CHANNEL_3C,  state);
    tmr_channel_enable(TMR20, TMR_SELECT_CHANNEL_1,  state);
    tmr_channel_enable(TMR20, TMR_SELECT_CHANNEL_2,  state);
    tmr_channel_enable(TMR20, TMR_SELECT_CHANNEL_1C, state);
    tmr_channel_enable(TMR20, TMR_SELECT_CHANNEL_2C, state);
}

/**
 * @brief Включает или выключает счет таймеров TMR1, TMR8, TMR20.
 * @param state TRUE — разрешить счет, FALSE — запретить
 */
void set_all_timer_counters_state(confirm_state state)
{
    tmr_counter_enable(TMR1, state);
    tmr_counter_enable(TMR8, state);
    tmr_counter_enable(TMR20, state);
}