#include "quantum.h"

// 制御用ピンの配列を定義する。
const uint8_t led_pins[] = LED_PINS;
bool is_alive = true;





void susepend_power_down_led_botton(void){
    is_alive = false;
}
void susepnd_wakeup_init_led_botton(void){
    is_alive = true;
}



void led_task_user(int row, int col, bool state) {
    if (row<MATRIX_ROWS && col<MATRIX_COLS) {
        if (row==0) {
                switch (col){
                    case 1:
                        writePin(led_pins[1], !state);
                        break;
                    case 2:
                        writePin(led_pins[0], !state);
                        break;
                    case 3:
                        writePin(led_pins[2], !state);
                        break;
                    case 4:
                        writePin(led_pins[3], !state);
                        break;
                    case 5:
                        
                        writePin(led_pins[4], !state);
                        writePin(led_pins[5], !state);
                        break;
                    default:
                        break;
                }
        }else if (row == 1){
            switch (col){
                            case 0:
                                writePin(led_pins[8], !state);
                                break;
                            case 2:
                                break;
                            case 3:
                                writePin(led_pins[9], !state);
                                break;
                            case 4:
                                writePin(led_pins[10], !state);
                                break;
                            case 5:
                                writePin(led_pins[7], !state);
                                break;
                            case 6:
                                writePin(led_pins[6], !state);
                                break;
                            default:
                                break;
                        }
        }
    }
        
}

void led_botton_init(void) {
    // seg_pinsとして与えられたピンを出力に設定する
    //それらのピンをHighに設定する。
    if(is_alive == true){
        
        for (uint8_t i = 0; i < sizeof(led_pins); i++) {
            setPinOutput(led_pins[i]);
            writePinHigh(led_pins[i]);
        }
        for (int row = 0; row < MATRIX_ROWS; row++) {
            for (int col = 0; col < MATRIX_COLS; col++) {
                led_task_user(row,col,false); // 全てのLEDを消灯
            }
        }
    }

}
void prodess_record_led(keyrecord_t *record) {
    if (record->event.pressed) {
        led_task_user(record->event.key.row,record->event.key.col,true);
    } else {
        led_task_user(record->event.key.row,record->event.key.col, false);
    }
}