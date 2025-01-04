
/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/sys_io.h>

static int pinmux_planck_init(void) {

#if CONFIG_BOARD_PLANCK_LEFT
  const struct device *p0 = DEVICE_DT_GET(DT_NODELABEL(gpio0));
  const struct device *p1 = DEVICE_DT_GET(DT_NODELABEL(gpio0));
  int pin1 = 9;
  int pin2 = 10;

#if CONFIG_BOARD_CHARGER_CURRENT_40MA
  gpio_pin_configure(p0, pin1, GPIO_INPUT | GPIO_PULL_DOWN);
  gpio_pin_configure(p1, pin2, GPIO_INPUT);
#elif CONFIG_BOARD_CHARGER_CURRENT_100MA
  gpio_pin_configure(p0, pin1, GPIO_OUTPUT);
  gpio_pin_set(p0, pin1, 0);
  gpio_pin_configure(p1, pin2, GPIO_INPUT);
#elif CONFIG_BOARD_CHARGER_CURRENT_150MA
  gpio_pin_configure(p0, pin1, GPIO_OUTPUT);
  gpio_pin_set(p0, pin1, 0);
  gpio_pin_configure(p1, pin2, GPIO_INPUT | GPIO_PULL_DOWN);
#elif CONFIG_BOARD_CHARGER_CURRENT_250MA
  gpio_pin_configure(p0, pin1, GPIO_INPUT);
  gpio_pin_configure(p1, pin2, GPIO_OUTPUT);
  gpio_pin_set(p1, pin2, 0);
#elif CONFIG_BOARD_CHARGER_CURRENT_350MA
  gpio_pin_configure(p0, pin1, GPIO_OUTPUT);
  gpio_pin_set(p0, pin1, 0);
  gpio_pin_configure(p1, pin2, GPIO_OUTPUT);
  gpio_pin_set(p1, pin2, 0);
#elif CONFIG_BOARD_CHARGER_CURRENT_NONE
  gpio_pin_configure(p0, pin1, GPIO_INPUT);
  gpio_pin_configure(p1, pin2, GPIO_INPUT);

#endif

#elif CONFIG_BOARD_PLANCK_RIGHT
  const struct device *p0 = DEVICE_DT_GET(DT_NODELABEL(gpio0));
  const struct device *p1 = DEVICE_DT_GET(DT_NODELABEL(gpio0));
  int pin1 = 9;
  int pin2 = 10;

#if CONFIG_BOARD_CHARGER_CURRENT_40MA
  gpio_pin_configure(p0, pin1, GPIO_INPUT | GPIO_PULL_DOWN);
  gpio_pin_configure(p1, pin2, GPIO_INPUT);
#elif CONFIG_BOARD_CHARGER_CURRENT_100MA
  gpio_pin_configure(p0, pin1, GPIO_OUTPUT);
  gpio_pin_set(p0, pin1, 0);
  gpio_pin_configure(p1, pin2, GPIO_INPUT);
#elif CONFIG_BOARD_CHARGER_CURRENT_150MA
  gpio_pin_configure(p0, pin1, GPIO_OUTPUT);
  gpio_pin_set(p0, pin1, 0);
  gpio_pin_configure(p1, pin2, GPIO_INPUT | GPIO_PULL_DOWN);
#elif CONFIG_BOARD_CHARGER_CURRENT_250MA
  gpio_pin_configure(p0, pin1, GPIO_INPUT);
  gpio_pin_configure(p1, pin2, GPIO_OUTPUT);
  gpio_pin_set(p1, pin2, 0);
#elif CONFIG_BOARD_CHARGER_CURRENT_350MA
  gpio_pin_configure(p0, pin1, GPIO_OUTPUT);
  gpio_pin_set(p0, pin1, 0);
  gpio_pin_configure(p1, pin2, GPIO_OUTPUT);
  gpio_pin_set(p1, pin2, 0);
#elif CONFIG_BOARD_CHARGER_CURRENT_NONE
  gpio_pin_configure(p0, pin1, GPIO_INPUT);
  gpio_pin_configure(p1, pin2, GPIO_INPUT);

#endif
#endif
  return 0;
}

SYS_INIT(pinmux_planck_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
