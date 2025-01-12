#include "common.h"

void keyboard_post_init_user(void) {
    // TODO: when working with led matrix driver,
    //   initialize the matrix w/ all LEDS on.

    to_home_layer();
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
            if(qmk_dfl() == _DFL_MACOS) {
                set_single_persistent_default_layer(_DFL_WINDOWS);
            } else  {
                set_single_persistent_default_layer(_DFL_MACOS);
            }
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
            to_layer(_XTL_LED_MATRIX);
            return false;
        case GOTO_XTL_NUMPAD:
            to_layer(_XTL_NUMPAD);
            return false;

    }
    return true;
}
