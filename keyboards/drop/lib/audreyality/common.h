// Copyright 2023 *+. Audrey .+*
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once
#include QMK_KEYBOARD_H

enum layer_names {
    // DFL - default layers
    _DFL_MACOS,
    _DFL_WINDOWS,

    // XTL - exclusive task layer; these layers are typically toggled
    //       into `TG(AUD_XTL_NUMPAD)`
    //       * MASK layer disables all keycodes from the default
    //         layer except those used for layer navigation
    //       * XTL layers typically have hard-coded lightng schemes,
    //         and often mask their lighting to only active keys.
    //       * XTL layers always reset when the power cycles or the
    //         keyboard reboots.
    _XTL_MASK,
    _XTL_FUNCTION,
    _XTL_LED_MATRIX,

    // DTL - default task layer; these layers tweak the default layer,
    //       typically by extending or disabling selected keys.
    //       * They are typically toggled using explicit commands.
    //       * They are mostly transparent to a default layer.
    //       * Their enabled state persists across reboots in eeprom.
    _DTL_HELLDIVERS,
    _DTL_PROGRAMMING,

    // `_XTL_CONTROL` must be last to maintain universal reachability
    _XTL_CONTROL
    // NB: max quanity of layers is 16
};

enum custom_keycodes {
    N_O_O_P = SAFE_RANGE,

    MACOS_SPOTLIGHT,
    MACOS_DICTATION,
    MACOS_FOCUS,

    SWAP_DFL_HOME              // persistent layer
    GOTO_DFL_ACTIVE,           // persistent layer
    GOTO_DTL_HELLDIVERS,       // persistent layer
    GOTO_DTL_PROGRAMMING,      // persistent layer
    GOTO_DTL_HOME,             // persistent layer; board-configurable w/ #define
    GOTO_XTL_MASK,             // runtime layer

    EEPROM_WRITE_SETTINGS,     // save layers & pretty_source

    USE_PRETTY_LIGHT_SOURCE,   // override layer lighting; runtime setting
    USE_PRETTY_BACKLIGHT,      // no-animation; board-confgurable w/ #define;
                               // saves pretty_source
};

// custom_keycodes shorthand
#define KC_SPOT MACOS_SPOTLIGHT
#define KC_DICT MACOS_DICTATION
#define KC_DND  MACOS_FOCUS

#define S_A_V_E EEPROM_WRITE_SETTINGS

// layer control data structures & shorthand
typedef struct {
    uint8_t dfl,
    uint8_t mdl,
    uint8_t xtl,
} persistent_layer_t;

typedef struct {
    bool home;
    bool skip;
    bool save;
    bool load;
} layer_control_t;

#define D_F_L_T GOTO_DFL_ACTIVE
#define D_I_V_E GOTO_DTL_HELLDIVERS
#define H_O_M_E GOTO_DTL_HOME
#define M_A_S_K GOTO_XTL_MASK

#define DF_MCOS DF(_DFL_MACOS)
#define DF_WIND DF(_DFL_WINDOWS)
#define OS_FUNL OSL(_XTL_FUNCTION)
#define MO_CTLL MO(_XTL_CONTROL)
#define TG_NUMP XXXXXXX
#define TG_PROG XXXXXXX
#define TG_LEDM TG(_XTL_LED_MATRIX)
#define TG_HELL TG(_DTL_HELLDIVERS)

// these will be important for later
#define ANIRSVP KC_TRNS
#define XTLRSVP KC_TRNS
#define FNLRSVP KC_TRNS
#define CTLRSVP KC_TRNS
#define MDLRSVP KC_TRNS

// animation controls, data structures & shorthand
#define PRTYSRC USE_PRETTY_LIGHT_SOURCE
#define BK_LITE USE_PRETTY_BACKLIGHT

enum animation_source {
    LAYER = 0,
    PRETTY,
}

typedef struct {
    uint8_t animation,
    hsv_t color,
    uint8_t speed,

} animation_t;

typedef struct  {
    animation_source source,
    bool save,
} animation_control_t;
