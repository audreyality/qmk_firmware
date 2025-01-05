// Copyright 2023 Massdrop, Inc.
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "audreyality.h"

// RSVPs bubble reserved logic from lower layers;
//  they should not be overridden

// TODO: implement these as lookups to RSVP layer
// #define RSVP_XT KC_TRNS
// #define RSVP_FN OS_FUNL
// #define RSVP_MD E_X_I_T

// the keymaps proper
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /////////////////////////////////////////////////////////////////////////////////// Default Layers ///////////////////////////////////////////////////////////////
    [AUD_DFL_MACOS] = LAYOUT_tkl_ansi(
        KC_ESC,           KC_BRID, KC_BRIU, KC_MCTL, KC_SPOT, KC_DICT, KC_DND,  KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE,    KC_NO,   KC_NO,   KC_NO,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_NO,   KC_NO,   KC_NO,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_NO,   KC_NO,   KC_NO,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, OS_CTLL, OS_FUNL,    KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [AUD_DFL_WINDOWS] = LAYOUT_tkl_ansi(
        KC_ESC,           KC_BRID, KC_BRIU, KC_MCTL, KC_SPOT, KC_DICT, KC_DND,  KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE,    KC_NO,   KC_NO,   KC_NO,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_NO,   KC_NO,   KC_NO,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_NO,   KC_NO,   KC_NO,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,
        KC_LGUI, KC_LALT, KC_LCTL,                            KC_SPC,                             KC_RCTL, KC_RALT, OS_CTLL, OS_FUNL,    KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /////////////////////////////////////////////////////////////////////// Exclusive Task Layers /////////////////////////////////////////////////////////////////////
    [AUD_XTL_BASE] = LAYOUT_tkl_ansi(
        E_X_I_T,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
        E_X_I_T, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,             XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, E_X_I_T, RSVP_FN,    XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [AUD_XTL_FUNCTION] = LAYOUT_tkl_ansi(
        RSVP_XT,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_F13,  KC_F14,  KC_F15,
        RSVP_XT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,     KC_F16,  KC_F17,  KC_F18,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_F19,  KC_F20,  KC_F21,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,             KC_PGUP,
        _______, _______, _______,                            _______,                            _______, _______, RSVP_XT, RSVP_XT,    KC_HOME, KC_PGDN, KC_END
    ),
    [AUD_XTL_NUMPAD] = LAYOUT_tkl_ansi(
        RSVP_XT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        RSVP_XT, _______, _______, _______, _______, _______, _______, KC_PSLS, KC_PAST, KC_PMNS, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, _______, _______,          KC_PENT,
        _______,          _______, _______, _______, _______, _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT,          _______,             KC_UP,
        _______, _______, _______,                            KC_TAB,                             _______, _______, RSVP_XT, RSVP_XT,    KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [AUD_XTL_LED_MATRIX] = LAYOUT_tkl_ansi(
        QK_BOOT,          E_X_I_T, E_X_I_T, E_X_I_T, E_X_I_T, E_X_I_T, E_X_I_T, E_X_I_T, E_X_I_T, E_X_I_T, E_X_I_T, E_X_I_T,  EE_CLR,    RM_OFF,  RM_TOGG, RM_ON,
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    RM_HUEU, RM_SATU, RM_VALU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    RM_HUED, RM_SATD, RM_VALD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,             RM_SPDU,
        _______, _______, _______,                            _______,                            _______, _______, RSVP_XT, RSVP_XT,    RM_PREV, RM_SPDD, RM_NEXT
    ),
    ///////////////////////////////////////////////////////////////////////// Modify Default Layers ///////////////////////////////////////////////////////////////////
    [AUD_MDL_PROGRAMMING] = LAYOUT_tkl_ansi(
        _______,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_F13,  KC_F14,  KC_F15,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_F16,  KC_F17,  KC_F18,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_F19,  KC_F20,  KC_F21,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        SC_LSPO,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          SC_RSPC,             _______,
        _______, _______, _______,                            _______,                            _______, _______, RSVP_MD, RSVP_FN,    _______, _______, _______
    ),
    [AUD_MDL_HELLDIVERS] = LAYOUT_tkl_ansi(
        XXXXXXX,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     XXXXXXX, XXXXXXX, KC_F13,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    XXXXXXX, XXXXXXX, KC_F14,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    XXXXXXX, XXXXXXX, KC_F15,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          XXXXXXX,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,             _______,
        KC_LCTL, XXXXXXX, KC_LALT,                            _______,                            KC_RALT, KC_RCTL, RSVP_MD, XXXXXXX,    _______, _______, _______
    ),
    /////////////////////////////////////////////////////////////////////// Control Layer (ALWAYS LAST) ///////////////////////////////////////////////////////////////
    [AUD_TTL_CONTROL] = LAYOUT_tkl_ansi(
        E_X_I_T,          DF_MCOS, DF_WIND, TG_PROG, TG_NUMP, TG_HELL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_LEDM,    XXXXXXX, XXXXXXX, KC_MUTE,
        QK_BOOT, DF_MCOS, DF_WIND, TG_PROG, TG_NUMP, TG_HELL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_LEDM, EE_CLR,     KC_WAKE, XXXXXXX, KC_VOLU,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_SLEP, XXXXXXX, KC_VOLD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,             XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, OS_CTLL, E_X_I_T,    KC_MPRV, KC_MPLY, KC_MNXT
    )
    /////////////////////////////////////////////////////////////////////// END //////////////////////////////////////////////////////////////////////////////////////
};
