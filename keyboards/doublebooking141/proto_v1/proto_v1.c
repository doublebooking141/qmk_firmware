//#include proto_v1.h
#include QMK_KEYBOARD_H

const matrix_row_t matrix_mask[MATRIX_ROWS] = {
  0b11111110,
  0b11111101,
  0b11111011,
  0b11110111,
  0b11101111,
  0b11011111,
  0b10111111,
  0b01111111,
};