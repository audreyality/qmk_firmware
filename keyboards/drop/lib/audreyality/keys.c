#include "common.h"

inline bool send_keycode(keyrecord_t *record, uint16_t code) {
    if (record->event.pressed) {
        register_code16(code);
    } else {
        unregister_code16(code);
    }

    return false; // Skip all further processing of this key
}

bool save_user(void) {
    // TODO: save default layer, helldivers layer,
    // and pretties in eeprom

    layer_control(save=true);
    pretty_control(save=true);

    // TODO: save important state (e.g. animation,
    // helldivers vs keyboard mode)
    // for restoration at startup/etc

    return false;
}
