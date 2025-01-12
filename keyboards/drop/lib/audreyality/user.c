#include "common.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACOS_SPOTLIGHT:
            return send_keycode(record, 0x221);
        case MACOS_DICTATION:
            return send_keycode(record, 0xCF);
        case MACOS_FOCUS:
            return send_keycode(record, 0x9B);
    }
    return true;
}
