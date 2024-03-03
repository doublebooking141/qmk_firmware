// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "add_keycodes.h"


// レイヤー名
enum layer_number {
    // 基本レイヤー
    BASE = 0,      
    // 補助レイヤー
    EXTRA_1, EXTRA_2, EXTRA_3, EXTRA_4, EXTRA_5, 
    // 自動マウスレイヤー切り替えや設定用のレイヤー
    UTIL, MOUSE , BALL_SETTINGS, LIGHT_SETTINGS    
};

// キーマップ
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        // 天面スイッチ
        KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BACKSLASH, KC_GRAVE,
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_CAPS_LOCK, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,
        KC_RIGHT_GUI, KC_LCTL, KC_LCTL, KC_LALT, KC_SPC, KC_SPC, KC_RIGHT_CTRL, KC_RIGHT_ALT,KC_RIGHT_CTRL, KC_LEFT, KC_DOWN, KC_RIGHT
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] =   { 
        ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN)
    }
};



// キースキャン
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    process_record_addedkeycodes(keycode, record);
    return true;
}


