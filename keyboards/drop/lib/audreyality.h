#pragma once

// AUD - unique prefix for defines
// DFL - default layers
// TTL - temporarily triggered layer; these layers usually
//       are activated momentarily like `MO(AUD_TTL_CONTROL)`
// MDL - modify default layer; these layers extend the default
//       layer with
// XTL - exclusive task layer; these layers are typically toggled
//       like `TG(AUD_XTL_NUMPAD)`
//       * MASK layer disables all keycodes from the default
//         layer except those used for layer navigation
//       * Other layers enable the MASK using `trilayer` support
#define AUD_DFL_MACOS 0
#define AUD_DFL_WINDOWS 1
#define AUD_XTL_BASE 2
#define AUD_XTL_FUNCTION 3
#define AUD_XTL_NUMPAD 4
#define AUD_XTL_LED_MATRIX 5
#define AUD_MDL_PROGRAMMING 6
#define AUD_MDL_HELLDIVERS 7

// place control layer above all other layers so
// that it cannot be overridden
#define AUD_TTL_CONTROL 8
// NB: max layer is 15

enum custom_keycodes {
    // macOS Spotlight key
    KC_SPOT = SAFE_RANGE,
    // macOS dictation key
    KC_DICT,
    // macOS focus key
    KC_DND,
    // toggle fixed layer animations
    KC_LANI,

    // trigger specialized lookups so that keys
    // can be targetted by specialized LED colors
    RSVP_XT,
    RSVP_FN,
    RSVP_MD
}

// layer control
#define DF_MCOS DF(AUD_DFL_MACOS)
#define DF_WIND DF(AUD_DFL_WINDOWS)
#define OS_FUNL OSM(AUD_XTL_FUNCTION)
#define OS_CTLL OSM(AUD_TTL_CONTROL)
#define TG_NUMP TG(AUD_XTL_NUMPAD)
#define TG_PROG TG(AUD_MDL_PROGRAMMING)
#define TG_LEDM TG(AUD_XTL_LED_MATRIX)
#define TG_HELL TG(AUD_MDL_HELLDIVERS)

// exits return to the base layer
#define E_X_I_T T0(AUD_DFL_MACOS)

inline bool flap(keyrecord_t *record, uint16_t code) {
    if (record->event.pressed) {
        register_code16(code);
    } else {
        unregister_code16(code);
    }

    return false; // Skip all further processing of this key
}

void mask_layer(uint8_t layer, bool mask_enabled) {
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
    is31fl3733_update_led_control_registers();
}
