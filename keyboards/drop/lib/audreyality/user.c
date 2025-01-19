#include "common.h"

void keyboard_post_init_user(void) {
    load_settings();

    if(get_init_home()) {
        to_home_layer();
    } else {
        to_default_layer();
    }

    // TODO: when working with led matrix driver,
    //   initialize the matrix w/ all LEDS on.
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACOS_SPOTLIGHT:
            return send_keycode(record, 0x221);
        case MACOS_DICTATION:
            return send_keycode(record, 0xCF);
        case MACOS_FOCUS:
            return send_keycode(record, 0x9B);

        case SWAP_DFL_HOME:
            swap_default_layer();
            return false;

        case STICKY_HOME_ON:
            set_sticky(true);
            return false;

        case STICKY_HOME_OFF:
            set_sticky(false);
            return false;

        case STICKY_HOME_TOGGLE:
            try_toggle_init_home();
            return false;

        case STICKY_HOME_SET_DEFAULT:
            set_init_home();
            return false;

        case STICKY_HOME_SET_HOME:
            set_init_default();
            return false;

        case GOTO_DFL:
            to_default_layer();
            return false;

        case GOTO_DTL_HOME:
            to_home_layer();
            return false;

        case GOTO_DTL_HELLDIVERS:
            to_layer(_DTL_HELLDIVERS);
            return false;

        case GOTO_DTL_PROGRAMMING:
            to_layer(_DTL_PROGRAMMING);
            return false;

        case GOTO_XTL_MASK:
            to_layer(_XTL_MASK);
            return false;

        case GOTO_XTL_LED_MATRIX:
            set_source(PRETTY);
            to_layer(_XTL_LED_MATRIX);
            return false;

        case GOTO_XTL_NUMPAD:
            to_layer(_XTL_NUMPAD);
            return false;

        // light source controls override the default layer behavior
        case USE_LAYER_LIGHT_SOURCE:
            set_source(LAYER);
            return false;

        case USE_PRETTY_LIGHT_SOURCE:
            set_source(PRETTY);
            return false;

        // pretty animation controls
        case USE_PRETTY_BACKLIGHT:
            init_pretty_backlight();
            save_pretty();
            return false;
    }
    return true;
}

uint8_t last_highest_layer = 0;

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t highest = get_highest_layer(state);

    // sync qmk state and audreyality runtime state
    if(last_highest_layer == _XTL_LED_MATRIX) {
        init_pretty_from_qmk();
        save_pretty();

        // reset to play nicely with eeprom
        last_highest_layer = 0;
    }

    // #region LAYER_JUMP_TABLE

    // layers control light sources; implement layer-lighting control here
    // lets redirections (e.g. H_O_M_E),  qmk-builtins (e.g. TG(...)), and
    // the audreyality `to_layer` logic behave consistently.
    switch (highest) {
        case _XTL_FUNCTION:
            // paints "alpha" keys hsv and "mod" keys with hue offset
            set_layer_mode(RGB_MATRIX_ALPHAS_MODS);
            set_layer_hsv(XTL_FUNCTION_HSV);
            set_layer_speed(XTL_FUNCTION_HUE_OFFSET);
            goto animate_layer;

        case _XTL_NUMPAD:
            set_layer_mode(RGB_MATRIX_SOLID_COLOR);
            set_layer_hsv(XTL_NUMPAD_HSV);
            goto animate_layer;

        case _DTL_PROGRAMMING:
            // paints "alpha" keys hsv and "mod" keys with hue offset
            set_layer_mode(RGB_MATRIX_ALPHAS_MODS);
            set_layer_hsv(DTL_PROGRAMMING_HSV);
            set_layer_speed(DTL_PROGRAMMING_HUE_OFFSET);
            goto animate_layer;

        case _DTL_HELLDIVERS:
            // fast-fades from hue offset to layer hsv
            set_layer_mode(RGB_MATRIX_SOLID_REACTIVE);
            set_layer_hsv(DTL_HELLDIVERS_HSV);
            set_layer_speed(DTL_HELLDIVERS_HUE_OFFSET);
            goto animate_layer;

        case _XTL_CONTROL:
            // TODO: paint controls
            set_layer_mode(XTL_CONTROL_MODE);
            set_layer_hsv(XTL_CONTROL_HSV);
            set_layer_speed(XTL_CONTROL_SPEED);
            goto animate_layer;

        default:
            set_source(PRETTY);
            goto end;
    }

animate_layer:
    set_source(LAYER);

end:
    last_highest_layer = highest;

    // #endregion LAYER_JUMP_TABLE

    return state;
}
