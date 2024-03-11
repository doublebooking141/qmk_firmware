// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "add_rgblayers.h"
#include "quantum.h"

// レイヤーごとの発光場所、発光色の設定
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 18, 1, HSV_YELLOW}, { 35, 1, HSV_YELLOW}                              );
const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 36, 1, HSV_BLUE}                                                      );
const rgblight_segment_t PROGMEM my_scrolllock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 37, 1, HSV_RED}                                                       );

const rgblight_segment_t PROGMEM my_default_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 3, HSV_WHITE},{ 35, 3, HSV_WHITE}                                   );

const rgblight_segment_t PROGMEM my_normal_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 3, 32, HSV_WHITE}, { 38, 3, HSV_WHITE}                                 );

const rgblight_segment_t PROGMEM extra1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 5, 12, HSV_GREEN}                                                     );
const rgblight_segment_t PROGMEM extra2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 5, 5, HSV_BLUE},{ 11, 6, HSV_BLUE},{ 19, 6, HSV_BLUE},{ 26, 3, HSV_BLUE}
    );
const rgblight_segment_t PROGMEM extra3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 35, HSV_YELLOW}, { 39, 3, HSV_YELLOW}                             );
const rgblight_segment_t PROGMEM extra4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 35, HSV_BLUE}, { 39, 3, HSV_BLUE}                                 );

const rgblight_segment_t PROGMEM util_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {34, 2, HSV_PINK},{ 39, 2, HSV_WHITE}                                  );
const rgblight_segment_t PROGMEM mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 24, 3, HSV_BLUE}, { 33, 2, HSV_BLUE}, { 42, 1, HSV_BLUE}             );



const rgblight_segment_t PROGMEM ball_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 42, 1, HSV_GREEN} );

const rgblight_segment_t PROGMEM light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 42, 1, HSV_GREEN}                         );

// レイヤーごとの発光方法の指定
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_numlock_layer,
    my_scrolllock_layer,

    my_default_layer,

    my_normal_layer,
    extra1_layer,
    extra2_layer,
    extra3_layer,
    extra4_layer,

    util_layer,
    mouse_layer,
    ball_layer,
    light_layer
);

void keyboard_post_init_rgblayers(void) {
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    rgblight_set_layer_state(1, led_state.num_lock);
    rgblight_set_layer_state(2, led_state.scroll_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(3, layer_state_cmp(state, 0));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(4, layer_state_cmp(state, 0));
    rgblight_set_layer_state(5, layer_state_cmp(state, 1));
    rgblight_set_layer_state(6, layer_state_cmp(state, 2));
    rgblight_set_layer_state(7, layer_state_cmp(state, 3));
    rgblight_set_layer_state(8, layer_state_cmp(state, 6));
    rgblight_set_layer_state(9, layer_state_cmp(state, 7));
    rgblight_set_layer_state(10, layer_state_cmp(state, 8));
    rgblight_set_layer_state(11, layer_state_cmp(state, 9));
    return state;
}