// Copyright 2023 *+. Audrey .+*
// SPDX-License-Identifier: GPL-3.0-or-later
#include "../../lib/audreyality.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /////////////////////////////////////////////////////////////////////////////////// Default Layers ///////////////////////////////////////////////////////////////
    [_DFL_MACOS] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, H_O_M_E,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  DF_WIND,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,	  H_O_M_E,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             MO_CTLL, OS_FUNL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_DFL_WINDOWS] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, H_O_M_E,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  DF_MCOS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   RM_NEXT,
        KC_LGUI, KC_LALT, KC_LCTL,                            KC_SPC,                             MO_CTLL, OS_FUNL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /////////////////////////////////////////////////////////////////////// Exclusive Task Layers /////////////////////////////////////////////////////////////////////
    [_XTL_MASK] = LAYOUT_65_ansi_blocker(
        H_O_M_E, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, H_O_M_E,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            CTLRSVP, FNLRSVP, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_XTL_FUNCTION] = LAYOUT_65_ansi_blocker(
        XTLRSVP, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_F12,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F13,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_F14,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP, KC_F15,
        _______, _______, _______,                            _______,                            CTLRSVP, FNLRSVP, KC_HOME, KC_PGDN, KC_END
    ),
    [_XTL_LED_MATRIX] = LAYOUT_65_ansi_blocker(
        XTLRSVP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_SPDU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_SPDD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, RM_VALU,
        _______, _______, _______, _______, _______, _______, _______, _______, RM_PREV, RM_NEXT, _______, _______,          RM_VALU, RM_VALD,
        _______, _______, _______,                            _______,                            CTLRSVP, FNLRSVP, RM_HUED, RM_VALD, RM_HUEU
    ),
    ///////////////////////////////////////////////////////////////////////// Modify Default Layers ///////////////////////////////////////////////////////////////////
    [_DTL_HELLDIVERS] = LAYOUT_65_ansi_blocker(
        XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F13,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          XXXXXXX, KC_F14,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_F15,
        KC_LCTL, XXXXXXX, KC_LALT,                            _______,                            CTLRSVP, XXXXXXX, _______, _______, _______
    ),
    /////////////////////////////////////////////////////////////////////// Control Layer (ALWAYS LAST) ///////////////////////////////////////////////////////////////
    [_XTL_CONTROL] = LAYOUT_65_ansi_blocker(
        QK_BOOT, DF_MCOS, DF_WIND, TG_NUMP, TG_LEDM, TG_PROG, TG_HELL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,  XXXXXXX, XXXXXXX, KC_WAKE,
        PRTYSRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,
        M_A_S_K, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          S_A_V_E, KC_VOLU,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, PRTYSRC, XXXXXXX,          XXXXXXX, KC_VOLD,
        XXXXXXX, XXXXXXX, XXXXXXX,                            H_O_M_E,                            CTLRSVP, D_F_L_T, KC_MPRV, KC_MPLY, KC_MNXT
    )
    /////////////////////////////////////////////////////////////////////// END //////////////////////////////////////////////////////////////////////////////////////
};
