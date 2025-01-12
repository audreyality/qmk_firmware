// Copyright 2023 *+. Audrey .+*
// SPDX-License-Identifier: GPL-3.0-or-later
#include "../../lib/audreyality/keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //////////////////////////////////////////////////////////////// Default Layers ////////////////////////////////////////////////////////////////
    [_DFL_MACOS] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, D_I_V_E,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, SWAP_OS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  TG_NUMP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,	  RM_NEXT,
        AU_MCTL, AU_OPTN, AU_CMND,                            KC_SPC,                             MO_CTLL, OS_FUNL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_DFL_WINDOWS] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, D_I_V_E,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, SWAP_OS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  TG_NUMP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   RM_NEXT,
        AU_WCTL, AU_WNDW, AU_ALT,                             KC_SPC,                             MO_CTLL, OS_FUNL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    ///////////////////////////////////////////////////////////// Default Task Layers //////////////////////////////////////////////////////////////
    [_DTL_HELLDIVERS] = LAYOUT_65_ansi_blocker(
        XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, D_F_L_T,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F13,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          XXXXXXX, KC_F14,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCTL,          _______, KC_F15,
        KC_LCTL, KC_X,    KC_LALT,                            _______,                            CTLRSVP, XXXXXXX, _______, _______, _______
    ),
    [_DTL_PROGRAMMING] = LAYOUT_65_ansi_blocker(
        KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, H_O_M_E,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_F2,
        SC_LSPO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SC_RSPC,          _______, KC_F5,
        _______, _______, _______,                            _______,                            CTLRSVP, FNLRSVP, _______, _______, _______
    ),
    /////////////////////////////////////////////////////////// Exclusive Task Layers //////////////////////////////////////////////////////////////
    [_XTL_MASK] = LAYOUT_65_ansi_blocker(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, H_O_M_E,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            H_O_M_E,                            CTLRSVP, FNLRSVP, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_XTL_LED_MATRIX] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_SATU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_SATD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RM_SPDU, RM_PREV,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_SPDU,          RM_VALU, RM_NEXT,
        _______, _______, _______,                            XTLRSVP,                            CTLRSVP, FNLRSVP, RM_HUED, RM_VALD, RM_HUEU
    ),
    [_XTL_NUMPAD] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, KC_PAST, KC_PSLS, _______, _______, _______, _______, _______, KC_BSPC, XTLRSVP,
        _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_TAB,  _______, _______, _______, _______, KC_DEL,
        _______, _______, _______, _______, _______, KC_PMNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______, _______,          KC_PENT, _______,
        _______, _______, _______, _______, _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, _______, KC_PENT,          KC_UP,   _______,
        _______, _______, _______,                            XTLRSVP,                            CTLRSVP, FNLRSVP, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    //////////////////////////////////////////////////////////////////// High-touch Layers (ALWAYS LAST) //////////////////////////////////////////////////////////////
    [_XTL_FUNCTION] = LAYOUT_65_ansi_blocker(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  XXXXXXX,
        _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_SPOT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DND,  KC_DICT,          KC_PGUP, _______,
        _______, _______, _______,                            XTLRSVP,                            CTLRSVP, FNLRSVP, KC_HOME, KC_PGDN, KC_END
    ),
    [_XTL_CONTROL] = LAYOUT_65_ansi_blocker(
        QK_BOOT, TG_NUMP, TG_LEDM, TG_PROG, TG_HELL, _______, _______, _______, _______, _______, _______, EE_CLR,  S_A_V_E, _______, SWAP_OS,
        PRTYSRC, DF_MCOS, DF_WIND, _______, _______, _______, _______, _______, _______, _______, _______, KC_WAKE, KC_SLEP, _______, KC_MUTE,
        M_A_S_K, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _L_E_D_, KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, PRTYSRC, C_O_D_E,          _______, KC_VOLD,
        _______, _______, _______,                            XTLRSVP,                            CTLRSVP, D_F_L_T, KC_MPRV, KC_MPLY, KC_MNXT
    )
    /////////////////////////////////////////////////////////////////////// END //////////////////////////////////////////////////////////////////////////////////////
};
