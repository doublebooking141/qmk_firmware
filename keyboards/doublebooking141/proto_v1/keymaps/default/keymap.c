// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "add_keycodes.h"
#include "add_joystick.h"
#include "add_rgblayers.h"


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
        KC_ESC,        XXXXXXX,    KC_F1,      KC_F2,   KC_F3,    KC_F4, 
        KC_1,          KC_2,       KC_3,       KC_4,    KC_5,     KC_6,
        KC_TAB,        KC_Q,       KC_W,       KC_E,    KC_R,     KC_T,
        KC_CAPS,       KC_A,       KC_S,       KC_D,    KC_F,     KC_G,
        KC_LEFT_SHIFT, KC_Z,       KC_X,       KC_C,    KC_V,     KC_B,
        KC_LEFT_CTRL , XXXXXXX,    KC_LEFT_ALT,KC_SPACE,KC_SPACE,KC_SPACE,
         // ドーターボード
        KC_MS_BTN3,
        XXXXXXX,
        XXXXXXX,
        // 親指回り
        KC_MS_BTN3, XXXXXXX, XXXXXXX,
        // 十字キーorジョイスティック               
        KC_UP, KC_LEFT, KC_RIGHT, KC_DOWN
    ),


    [UTIL] = LAYOUT(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, OLED_MOD,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX
    ),    
    [MOUSE] = LAYOUT(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX

    ),
    [BALL_SETTINGS] = LAYOUT(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, _______,  XXXXXXX,
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, CPI_I,    XXXXXXX,
        AUTO_MOUSE, XXXXXXX, XXXXXXX, L_ANG_D,   L_INV, L_ANG_I,
        XXXXXXX,    XXXXXXX, INV_SCRL, XXXXXXX, CPI_D,    XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX
    ),
    [LIGHT_SETTINGS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_MOD, _______,
        XXXXXXX, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        RGB_MOD, RGB_MOD,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [NORMAL] =   { 
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX), 
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX), 
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D)
    },
    [MOUSE] =   { 
        ENCODER_CCW_CW(KC_DEL, KC_BSPC), 
        ENCODER_CCW_CW(KC_UP, KC_DOWN), 
        ENCODER_CCW_CW(KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN),
        ENCODER_CCW_CW(KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN)
    },
    [LIGHT_SETTINGS] = { 
        ENCODER_CCW_CW(RGB_SPI, RGB_SPD), 
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD), 
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD), 
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD)
    }
};

// 初期化
void matrix_init_user(void) {
    matrix_init_addedjoystick();
}

void keyboard_post_init_user(void) {
    keyboard_post_init_rgblayers();
}

// キースキャン
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    process_record_addedkeycodes(keycode, record);
    return true;
}

// マトリックススキャン
void matrix_scan_user(void) {
    matrix_scan_addedjoystick();
}

