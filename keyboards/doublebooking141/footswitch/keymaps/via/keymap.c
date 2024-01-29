// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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