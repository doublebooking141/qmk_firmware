// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "add_keycodes.h"
#include "add_joystick.h"
#include "add_rgblayers.h"
#include <print.h>


// レイヤー名
enum layer_number {
    // 右手仕様、
    NORMAL = 0, 
    // 予備用レイヤー
    EXTRA_1, EXTRA_2,EXTRA_3,EXTRA_4,EXTRA_5,
    // 自動マウスレイヤー切り替えや設定用のレイヤー
    UTIL, MOUSE , BALL_SETTINGS, LIGHT_SETTINGS    
};

// キーマップ
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [NORMAL] = LAYOUT(
        // キーモジュール
        KC_ESC,
        KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,
        KC_CAPS,       KC_A,       KC_S,       KC_D,    KC_F,     KC_G,
        KC_LEFT_SHIFT, KC_Z,       KC_X,       KC_C,    KC_V,     KC_B,
        KC_LEFT_CTRL , KC_LEFT_CTRL,    KC_LEFT_ALT, KC_SPACE, KC_SPACE,
        // エンコーダー
        KC_F1, KC_F2, KC_F3, KC_F4,
        //親指回り,
        KC_SPACE, KC_SPACE,
        // JSスイッチ
        KC_SPACE,
        // ジョイスティック               
        KC_UP, KC_LEFT, KC_RIGHT,KC_DOWN
    ),
    [EXTRA_1] = LAYOUT(
        // キーモジュール
        KC_ESC,
        KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,
        KC_CAPS,       KC_A,       KC_S,       KC_D,    KC_F,     KC_G,
        KC_LEFT_SHIFT, KC_Z,       KC_X,       KC_C,    KC_V,     KC_B,
        KC_LEFT_CTRL , KC_LEFT_CTRL,    KC_LEFT_ALT,KC_SPACE,KC_SPACE,
        // エンコーダー
        KC_F1, KC_F2, KC_F3, KC_F4,
        //親指回り,
        KC_SPACE, KC_SPACE,
        // JSスイッチ
        KC_SPACE,
        // ジョイスティック               
        KC_UP, KC_LEFT, KC_RIGHT,KC_DOWN
    ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [NORMAL] =   { 
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D), 
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D), 
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D)
    },
    [EXTRA_1] =   { 
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D), 
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D), 
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D)
    },
};

// 初期化
void matrix_init_user(void) {
    matrix_init_addedjoystick();
    debug_enable = true;
    debug_matrix = true;
    debug_mouse  = true;
}


void keyboard_post_init_user(void) {
    keyboard_post_init_rgblayers();
}

// キースキャン
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    process_record_addedkeycodes(keycode, record);
    #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
  return true;
    return true;
}

// マトリックススキャン
void matrix_scan_user(void) {
    matrix_scan_addedjoystick();
}

