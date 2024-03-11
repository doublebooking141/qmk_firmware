// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "add_joystick.h"
#include "quantum.h"
#include "analog.h"

// ファイル外参照変数
ballconfig_t ballconfig;
bool scrolling;
uint16_t cpi_array[] = CPI_OPTIONS;
uint16_t angle_array[] = ANGLE_OPTIONS;

// ファイル内のみ変数
int16_t gp26_newt;
int16_t gp27_newt;
bool joystick_attached;

keypos_t key_up;
keypos_t key_left;
keypos_t key_right;
keypos_t key_down;
bool pressed_up = false;
bool pressed_down = false;
bool pressed_left = false;
bool pressed_right = false;

void matrix_init_addedjoystick(void) {
    gp26_newt = analogReadPin(GP26);
    gp27_newt = analogReadPin(GP27);
    if(gp26_newt < NO_STICK_VAL ||  gp27_newt < NO_STICK_VAL ){
        joystick_attached = false;
    }else{
        joystick_attached = true;
    }
    key_up.row = 7;
    key_up.col = 0;
    key_left.row = 7;
    key_left.col = 1;
    key_right.row = 7;
    key_right.col = 2;
    key_down.row = 7;
    key_down.col = 3;
}

void matrix_scan_addedjoystick(void) {
    if(joystick_attached){

        int8_t layer = layer_switch_get_layer(key_down);
        int16_t keycode_up = keymap_key_to_keycode(layer, key_down);
        int16_t keycode_left = keymap_key_to_keycode(layer, key_right);
        int16_t keycode_right = keymap_key_to_keycode(layer, key_left);
        int16_t keycode_down = keymap_key_to_keycode(layer, key_up);

        if(!pressed_left && analogReadPin(GP26) - 512 > STICK_OFFSET){
            pressed_left = true;
            register_code(keycode_left);
        }else if(pressed_left && analogReadPin(GP26) - 512  < STICK_OFFSET){
            pressed_left = false;
            unregister_code(keycode_left);
        }else if(!pressed_right && analogReadPin(GP26) - 512  < -STICK_OFFSET){
            pressed_right = true;
            register_code(keycode_right);
        }else if (pressed_right && analogReadPin(GP26) - 512  > -STICK_OFFSET){
            pressed_right = false;
            unregister_code(keycode_right);
        }

        if(!pressed_up && analogReadPin(GP27) - 512  > STICK_OFFSET){
            pressed_up = true;
            register_code(keycode_up);
        }else if(pressed_up && analogReadPin(GP27) - 512  < STICK_OFFSET){
            pressed_up = false;
            unregister_code(keycode_up);
        }else if(!pressed_down && analogReadPin(GP27) - 512  < -STICK_OFFSET){
            pressed_down = true;
            register_code(keycode_down);
        }else if(pressed_down && analogReadPin(GP27) - 512  > -STICK_OFFSET){
            pressed_down = false;
            unregister_code(keycode_down);
        }
    }
}