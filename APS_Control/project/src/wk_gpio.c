/* add user code begin Header */
/**
  **************************************************************************
  * @file     wk_gpio.c
  * @brief    work bench config program
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */
/* add user code end Header */

/* Includes ------------------------------------------------------------------*/
#include "wk_gpio.h"

/* add user code begin 0 */

/* add user code end 0 */

/**
  * @brief  init gpio_input/gpio_output/gpio_analog/eventout function.
  * @param  none
  * @retval none
  */
void wk_gpio_config(void)
{
  /* add user code begin gpio_config 0 */

  /* add user code end gpio_config 0 */

  gpio_init_type gpio_init_struct;
  gpio_default_para_init(&gpio_init_struct);

  /* add user code begin gpio_config 1 */

  /* add user code end gpio_config 1 */

  /* gpio input config */
  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = B_START_PIN | B_STOP_PIN | OVERHEAT_PIN | GRID_FAULT_PIN;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(GPIOE, &gpio_init_struct);

  gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
  gpio_init_struct.gpio_pins = F_A_PIN | F_A_N_PIN | F_B_PIN | F_B_N_PIN | F_C_PIN | 
                               F_C_N_PIN;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(GPIOD, &gpio_init_struct);

  /* gpio output config */
  gpio_bits_reset(OUT1_GPIO_PORT, OUT1_PIN);
  gpio_bits_reset(GPIOC, OUT2_PIN | OUT3_PIN | OUT4_PIN | LED_PIN | OUT_ENABLE_PIN | 
                  POWER_PIN | CHARGE_PIN | FAN_OUT_PIN);
  gpio_bits_reset(GPIOD, HL_START_PIN | HL_STOP_PIN | HL_ALARM_PIN);
  gpio_bits_reset(I2C1_WC_GPIO_PORT, I2C1_WC_PIN);

  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_OUTPUT;
  gpio_init_struct.gpio_pins = OUT1_PIN;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(OUT1_GPIO_PORT, &gpio_init_struct);

  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_OUTPUT;
  gpio_init_struct.gpio_pins = OUT2_PIN | OUT3_PIN | OUT4_PIN | LED_PIN | OUT_ENABLE_PIN | 
                               POWER_PIN | CHARGE_PIN | FAN_OUT_PIN;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(GPIOC, &gpio_init_struct);

  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_OUTPUT;
  gpio_init_struct.gpio_pins = HL_START_PIN | HL_STOP_PIN | HL_ALARM_PIN;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(GPIOD, &gpio_init_struct);

  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_OUTPUT;
  gpio_init_struct.gpio_pins = I2C1_WC_PIN;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(I2C1_WC_GPIO_PORT, &gpio_init_struct);

  /* add user code begin gpio_config 2 */

  /* add user code end gpio_config 2 */
}

/* add user code begin 1 */

/* add user code end 1 */
