
#include "quantum.h"

// ２次元配列を定義する。
// 7セグメントLEDの点灯パターンを定義する。


// 制御用ピンの配列を定義する。
// 7セグメントLEDのピンを定義する。
const uint8_t seg_pins[] = SEG_LED_PINS;
bool is_alive_seg = true;

const uint8_t PROGMEM led7seg[][8] = {
    // 0
    {1, 1, 1, 1, 1, 1, 0, 0},
    // 1
    {0, 1, 1, 0, 0, 0, 0, 0},
    // 2
    {1, 1, 0, 1, 1, 0, 1, 0},
    // 3
    {1, 1, 1, 1, 0, 0, 1, 0},
    // 4
    {0, 1, 1, 0, 0, 1, 1, 0},
    // 5
    {1, 0, 1, 1, 0, 1, 1, 0},
    // 6
    {1, 0, 1, 1, 1, 1, 1, 0},
    // 7
    {1, 1, 1, 0, 0, 0, 0, 0},
    // 8
    {1, 1, 1, 1, 1, 1, 1, 0},
    // 9
    {1, 1, 1, 1, 0, 1, 1, 0},
    // A
    {1, 1, 1, 0, 1, 1, 1, 0},
    // B
    {0, 0, 1, 1, 1, 1, 1, 0},
    // C
    {1, 0, 0, 1, 1, 1, 0, 0},
    // D
    {0, 1, 1, 1, 1, 0, 1, 0},
    // E
    {1, 0, 0, 1, 1, 1, 1, 0},
    // F
    {1, 0, 0, 0, 1, 1, 1, 0}
};

void matrix_init_led7seg(void) {
    // seg_pinsとして与えられたピンを出力に設定する
    //それらのピンをHighに設定する。
    if(is_alive_seg == true){
        
        for (uint8_t i = 0; i < sizeof(seg_pins); i++) {
            setPinOutput(seg_pins[i]);
            writePinHigh(seg_pins[i]);
        }
    }
}

void led7seg_task_user(void) {
    // 7セグメントLEDの点灯パターンを取得する。
    uint8_t layer = get_highest_layer(layer_state);

    // 7セグメントLEDの点灯パターンを出力する。
    for (uint8_t i = 0; i < sizeof(seg_pins); i++) {
        writePin(seg_pins[i], !led7seg[layer][i]);
    }
}

void susepend_power_down_led7seg(void){
    is_alive_seg = false;
}
void susepnd_wakeup_init_led7seg(void){
    is_alive_seg = true;
}