#include "common.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACOS_SPOTLIGHT:
            return send_keycode(record, 0x221);
        case MACOS_DICTATION:
            return send_keycode(record, 0xCF);
        case MACOS_FOCUS:
            return send_keycode(record, 0x9B);

        case SWAP_DFL_HOME:
            layer_control(dfl=true, home=true);
            return false;
        case GOTO_DTL_HOME:
            goto_layer(mdl=_DTL_HOME);
            return false;
        case GOTO_DTL_HELLDIVERS:
            goto_layer(mdl=_DTL_HELLDIVERS);
            return false;
        // direct lighting controls; don't activate pretty mode
        case GOTO_DTL_PROGRAMMING:
            // bright fuscia color; TODO: move to layer control
            set_pretty(animation=RGB_MATRIX_SOLID_COLOR, color={215, 240, 80});
            pretty_control(save=true);
            layer_control()
            return false;
        case GOTO_XTL_MASK:
            goto_layer(xtl=_XTL_MASK);
            return false;

        case EEPROM_WRITE_SETTINGS:
            return save_user();

        case USE_PRETTY_LIGHT_SOURCE:
            pretty_control(PRETTY);
            return false;
        case USE_PRETTY_BACKLIGHT:
            // TODO: pull color from define
            // desaturated yellow color
            set_pretty(animation=RGB_MATRIX_SOLID_COLOR, color={215, 240, 80}, speed=10);

            pretty_control(save=true);
            return false;
    }
    return true;
}

void keyboard_post_init_user(void) {
    // load ambient eeprom state
    pretty_restore();
    // TODO: when working with led matrix driver,
    //   initialize the matrix w/ all LEDS on.

    // always load into the default layer w/ optional
    //  MDL extension applied
    to_default_layer();
    mdl_restore();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t highest = get_highest_layer(state);
    bool xtl_enabled = false;

    switch (highest) {
        case _DFL_MACOS:
        case _DFL_WINDOWS:
            mdl_off(save=true);
            pretty_control(PRETTY);
            break;

        case _XTL_FUNCTION:
            xtl_enabled = true;
            pretty_control(LAYER);
            // note: speed controls ALPHAS color offset
            set_layer_ani(animation=RGB_MATRIX_ALPHAS_MODS, color={184, 237, 140} speed=30);
            break;
        case _XTL_LED_MATRIX:
            xtl_enabled = true;
            set_layer_ani(animation=RGB_MATRIX_CYCLE_PINWHEEL, color={0, 172, 50});
            pretty_control(LAYER);
            break;

        case _DTL_PROGRAMMING:
            // bright fuscia color
            set_pretty(animation=RGB_MATRIX_SOLID_COLOR, color={215, 240, 80});
            pretty_control(LAYER);

        case _DTL_HELLDIVERS:
            // helldivers yellow with fast-fade from orangey-yellow when the keys are pressed
            // note: speed controls reactive offset
            set_layer_ani(animation=RGB_MATRIX_SOLID_REACTIVE, color={43, 255, 191}, speed=10);
            pretty_control(LAYER);
            break;

        case _XTL_CONTROL:
            set_layer(animation=RGB_MATRIX_RAINBOW_MOVING_CHEVRON, speed=60);
            pretty_control(LAYER);
            break;

        default:
            break;
    }

    if(xtl_enabled) {
        layer_on(_XTL_MASK);
    } else {
        layer_off(_XTL_MASK);
    }

    return state;
}
//// save default layer, helldivers layer, and animation in eeprom
