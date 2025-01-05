#include QMK_KEYBOARD_H
#include "audreyality.h"
#include "rgb_matrix.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SPOT:
            return flap(record, 0x221);
        case KC_DICT:
            return flap(record, 0xCF);
        case KC_DND:
            return flap(record, 0x9B);
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t highest = get_highest_layer(state);

    switch (highest) {
        case AUD_DFL_MACOS:
        case AUD_DFL_WINDOWS:
            mask_layer(highest, false);
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(215, 240, 122); // fuscia
            break;
        case AUD_XTL_FUNCTION:
            mask_layer(highest, false);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
            rgb_matrix_sethsv_noeeprom(184, 237, 140);
            // speed controls offset; max 255
            rgb_matrix_set_speed_noeeprom(30);
            break;
        case AUD_XTL_LED_MATRIX:
            mask_layer(highest, false);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(184, 237, 140);
            break;
        case AUD_TTL_CONTROL:
            mask_layer(highest, true);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
            rgb_matrix_set_speed_noeeprom(60);
            break;
        case AUD_XTL_NUMPAD:
            mask_layer(highest, true);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(SOLID_COLOR(43, 255, 191));
            // speed controls offset; max 255
            rgb_matrix_set_speed_noeeprom(10);
            break;
        case AUD_MDL_HELLDIVERS:
            mask_layer(highest, false);
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


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (layer == AUD_NUMPAD_LAYER) {
            // Custom lighting for NUMPAD layer
            rgb_matrix_set_color(i, 255, 0, 0); // Set color to red
        } else if (layer == AUD_FN_LAYER) {
            // Custom lighting for FN layer
            rgb_matrix_set_color(i, 0, 255, 0); // Set color to green
        }
    }

    // Return true to allow default indicators to be processed
    return true;
}

bool rgb_matrix_indicators_kb(void) {
    uint8_t layer = get_highest_layer(layer_state);

    switch(layer) {
        case AUD_XTL_LED_MATRIX:
            paint_layer_led();
            return true;

    }
}

void paint_layer_led() {
    // paint E_X_I_T, QK_BOOT, RM_*
}

void paint_keycode(uint8_t led, uint16_t keycode) {
    uint8_t r, g, b;

    // lookup keycode from next-highest enabled layer
    // paint the layout for that keycode, if any.
    switch(keycode) {
        case E_X_I_T:
            // solid red
            rgb_matrix_set_color(led, 150, 0, 0);
            break;
        case RM_OFF:
            // off
        case RM_TOGG:
            // slow breathe, white
        case RM_ON:
            // white
        case RM_HUEU:
            // next hue up
        case RM_HUED:
            // next hue down
        case RM_SATU:
            // next sat up
        case RM_SATD:
            // next sat down
        case RM_VALU:
            // next valu up
        case RM_VALD:
            // next valu down
        case RM_SPDU:
            // rapid breathe, green
        case RM_SPDD:
            // slow breathe, yellow
        case RM_NEXT:
            // blue
        case RM_PREV:
            // blue
        case EE_CLR:
            // pulse yellow
        case QK_BOOT:
            // pulse red
    }

    rgb_matrix_set_color(i, r, g, b);
}

