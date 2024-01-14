// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "add_keycodes.h"
#include "add_joystick.h"
#include "add_rgblayers.h"


// レイヤー名
enum layer_number {
    // 右手仕様、
    NORMAL = 0, SYMBOL,  ARROW, NUMPAD,
    // 予備用レイヤー
    EXTRA_1, EXTRA_2,
    // 自動マウスレイヤー切り替えや設定用のレイヤー
    UTIL, MOUSE , BALL_SETTINGS, LIGHT_SETTINGS    
};

// キーマップ
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [NORMAL] = LAYOUT(
        // 天面スイッチ
        KC_BSPC,    KC_MINUS,              KC_0,              KC_9,             LT(BALL_SETTINGS, KC_8),     LT( LIGHT_SETTINGS, KC_7), 
        KC_ENT,     LT(SYMBOL,KC_P),       KC_O,              KC_I,             KC_U,                         KC_Y,
        KC_RSFT,    LT(ARROW,KC_SLASH),    LT(MOUSE, KC_L),   KC_K,             KC_J,                         KC_H,
                    KC_RCTL,               LT(NUMPAD,KC_DOT), LT(UTIL,KC_COMM), KC_M,                         KC_N,
                                           KC_RALT,
         // 側面スイッチ
        LALT(KC_GRAVE),KC_SPACE,
         // 十字キーorジョイスティック                // ジョイスティックスイッチ
        KC_LEFT, KC_RIGHT, KC_DOWN, KC_UP,       KC_ENT,
        // 追加スイッチ                             // トグルスイッチ
        KC_MS_BTN1, KC_MS_BTN2,                   MO(NUMPAD)
    ),

    [SYMBOL] = LAYOUT(
        KC_DEL, KC_GRAVE,KC_BSLS,KC_EQUAL,KC_MINUS,XXXXXXX,
        _______,_______,KC_RBRC,KC_LBRC,XXXXXXX,XXXXXXX,
        _______,XXXXXXX,_______,KC_QUOT,KC_SCLN,XXXXXXX,
                _______,XXXXXXX,KC_SLSH,KC_DOT,KC_COMM,
                        _______,
        _______,_______,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        _______,_______,_______
    ),
    [ARROW] = LAYOUT(
        _______, XXXXXXX, KC_F12, KC_F10, KC_F8,    KC_F5,
        _______, XXXXXXX, KC_INS, KC_DEL, KC_PSCR,  XXXXXXX,
        _______, _______, _______, KC_UP, KC_NUM,   XXXXXXX,
                XXXXXXX, KC_RGHT, KC_DOWN, KC_LEFT, XXXXXXX,
                _______,
        _______, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______
    ),
    [NUMPAD] = LAYOUT(
        _______,KC_PAST,KC_PSLS,KC_P9,KC_P8,KC_P7,
        _______,KC_PPLS,KC_PMNS,KC_P6,KC_P5,KC_P4,
        _______,KC_NUM,_______,KC_P3,KC_P2,KC_P1,
                XXXXXXX,_______,KC_PDOT,KC_P0,KC_P0,
                        XXXXXXX,
        _______,_______,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        _______,_______,_______
    ),


    [UTIL] = LAYOUT(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, OLED_MOD,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                        XXXXXXX,
        XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX
    ),    

    [MOUSE] = LAYOUT(
        _______, AUTO_MOUSE, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,
        _______, XXXXXXX, XXXXXXX,KC_MS_BTN2 , KC_MS_BTN1, KC_WH_U,
        _______, XXXXXXX, _______, KC_MS_BTN3, KC_MS_BTN1, KC_WH_D,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX,
        KC_MS_BTN4, KC_MS_BTN5,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,
        LWIN(KC_L), KC_KB_MUTE, XXXXXXX

    ),
    [BALL_SETTINGS] = LAYOUT(
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, _______,  L_CHMOD,
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, CPI_I,    XXXXXXX,
        AUTO_MOUSE, XXXXXXX, XXXXXXX, L_ANG_D,   L_INV, L_ANG_I,
                    XXXXXXX, XXXXXXX, XXXXXXX, CPI_D,    XXXXXXX,
                          INV_SCRL,
        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX,                            XXXXXXX
    ),
    [LIGHT_SETTINGS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_MOD, _______,
        XXXXXXX, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, XXXXXXX,
                          XXXXXXX,
        RGB_MOD, RGB_MOD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX,                            XXXXXXX
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

