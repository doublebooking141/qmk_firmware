// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "led7seg.h"
#include "led_bottons.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *   ┌───┬───┬───┬───┬───┐     
     *   │ 1 │ 2 │ 3 │ 4 │ G │
     * ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐
     * │ 5 │ 6 │ 7 │ 8 │ B │ C │
     * └───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_1,  KC_2,    KC_4,    KC_5,    KC_G,
        KC_5,  KC_6,    KC_7,    KC_8,    KC_B,   KC_C
    )
};
// 初期化
void matrix_init_user(void) {
    matrix_init_led7seg();
    led_botton_init();
}

void housekeeping_task_user(void) {
    led7seg_task_user();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    prodess_record_led( record);
    return true;
}

void suspend_power_down_user(void) {
    // code will run multiple times while keyboard is suspendedl
    susepend_power_down_led7seg();
    susepend_power_down_led_botton();

}

void suspend_wakeup_init_user(void) {
    // code will run on keyboard wakeup
    susepnd_wakeup_init_led7seg();
    susepnd_wakeup_init_led_botton();
}