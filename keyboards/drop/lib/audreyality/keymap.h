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
    _XTL_NUMPAD,

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
    RESERVED = SAFE_RANGE,

    MACOS_SPOTLIGHT,
    MACOS_DICTATION,
    MACOS_FOCUS,

    SWAP_DFL_HOME,             // persistent layer
    GOTO_DFL,                  // persistent layer
    GOTO_DTL_HELLDIVERS,       // persistent layer
    GOTO_DTL_PROGRAMMING,      // persistent layer
    GOTO_DTL_HOME,             // persistent layer; board-configurable w/ #define
    GOTO_XTL_MASK,
    GOTO_XTL_NUMPAD,
    GOTO_XTL_LED_MATRIX,

    // runtime lighting controls
    TOGGLE_LAYER_LIGHT_SOURCE,
    USE_LAYER_LIGHT_SOURCE,
    USE_PRETTY_LIGHT_SOURCE,
    USE_PRETTY_BACKLIGHT,
};

// macos keycode shorthand
#define KC_SPOT MACOS_SPOTLIGHT
#define KC_DICT MACOS_DICTATION
#define KC_DND  MACOS_FOCUS

// mac button map[ing]
#define AU_CMND KC_LGUI
#define AU_OPTN KC_LALT
#define AU_MCTL KC_LCTL

// `AUD_MACLIKE_WCTL` makes windows more mac-like by
// switching ctrl and alt on the default layer
#ifndef AUD_MACLIKE_WCTL
#   define AU_ALT  KC_LALT
#   define AU_WNDW KC_LGUI
#   define AU_WCTL KC_LCTL
#else
#   define AU_ALT  KC_LCTL
#   define AU_WNDW KC_LGUI
#   define AU_WCTL KC_LALT
#endif

// _user logic shorthand
#define D_F_L_T GOTO_DFL
#define SWAP_OS SWAP_DFL_HOME
#define H_O_M_E GOTO_DTL_HOME
#define D_I_V_E GOTO_DTL_HELLDIVERS
#define C_O_D_E GOTO_DTL_PROGRAMMING
#define M_A_S_K GOTO_XTL_MASK
#define _NUMPD_ GOTO_XTL_NUMPAD
#define _L_E_D_ GOTO_XTL_LED_MATRIX
// reserved to save audreyality state to eeprom
#define S_A_V_E XXXXXXX
// reserved to output audreyality state as text
#define _PRINT_ XXXXXXX

// layer control shorthand
#define DF_MCOS DF(_DFL_MACOS)
#define DF_WIND DF(_DFL_WINDOWS)
#define OS_FUNL OSL(_XTL_FUNCTION)
#define MO_CTLL MO(_XTL_CONTROL)
#define MO_LEDM TG(_XTL_LED_MATRIX)
#define TG_NUMP XXXXXXX
#define TG_PROG XXXXXXX
#define TG_LEDM TG(_XTL_LED_MATRIX)
#define TG_HELL TG(_DTL_HELLDIVERS)

// animation control shorthand
#define PRTYSRC USE_PRETTY_LIGHT_SOURCE
#define BK_LITE USE_PRETTY_BACKLIGHT

// these will be important for later
#define ANIRSVP KC_TRNS
#define XTLRSVP KC_TRNS
#define FNLRSVP KC_TRNS
#define CTLRSVP KC_TRNS
#define MDLRSVP KC_TRNS
