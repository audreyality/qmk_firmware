// Copyright 2023 *+. Audrey .+*
// SPDX-License-Identifier: GPL-3.0-or-later
#include "audreyality.h"

bool to_default_layer(void) {
    if(layer_state_is(_DFL_MACOS)) {
        layer_move(_DFL_MACOS);
    } else if(layer_state_is(_DFL_WINDOWS)) {
        layer_move(_DFL_WINDOWS);
    } else {
        layer_move(AUD_DEFAULT_LAYER);
    }

    return false;
}

inline bool flap(keyrecord_t *record, uint16_t code) {
    if (record->event.pressed) {
        register_code16(code);
    } else {
        unregister_code16(code);
    }

    return false; // Skip all further processing of this key
}

void mask_layer(uint8_t layer, bool mask_enabled) {
    // mask leds by toggling their on/off controls
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if(index == NO_LED) continue;

            // turning the LED off lets the animation logic continue to
            // update LED color for the active keys on the layer.
            bool enable = !mask_enabled || keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS;
            is31fl3733_set_led_control_register(index, enable, enable, enable);
        }
    }

    // transmit control codes
    is31fl3733_update_led_control_registers(0);
    is31fl3733_update_led_control_registers(1);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SPOT:
            return flap(record, 0x221);
        case KC_DICT:
            return flap(record, 0xCF);
        case KC_DND:
            return flap(record, 0x9B);
        case E_X_I_T:
            return to_default_layer();

    }
    return true;
}

void keyboard_post_init_user(void) {
    // setting the default layer on startup keeps the LEDs
    // in sync with the layer state
    to_default_layer();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t highest = get_highest_layer(state);

    switch (highest) {
        case _DFL_MACOS:
        case _DFL_WINDOWS:
            mask_layer(highest, false);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(215, 240, 80); // fuscia
            break;
        case _XTL_FUNCTION:
            mask_layer(highest, true);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(215, 240, 80); // fuscia
            // speed controls offset; max 255
            rgb_matrix_set_speed_noeeprom(60);
            break;
        case _XTL_LED_MATRIX:
            mask_layer(highest, false);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_PINWHEEL);
            rgb_matrix_sethsv_noeeprom(0, 172, 50);
            break;
        case _TTL_CONTROL:
            mask_layer(highest, false);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
            rgb_matrix_set_speed_noeeprom(60);
            break;
        case _MDL_HELLDIVERS:
            mask_layer(highest, true);
            // solid yellow with fast-fade from orangey-yellow
            // when the keys are pressed
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(43, 255, 191); // helldivers yellow
            // speed controls offset; max 255
            rgb_matrix_set_speed_noeeprom(10);
            break;
        default:
            break;
    }

    return state;
}

