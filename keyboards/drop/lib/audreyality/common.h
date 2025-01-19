// Copyright 2023 *+. Audrey .+*
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once
#include "keymap.h"

#define AUD_HSV(H, S, V) (hsv_t){ .h = H, .s = S, .v = V }

// FIXME: solid sky blue
#define XTL_NUMPAD_HSV AUD_HSV(146, 166, 128)

// FIXME: fuscia with purple offset
#define DTL_PROGRAMMING_HSV AUD_HSV(238, 110, 128)
#define DTL_PROGRAMMING_HUE_OFFSET 25

// FIXME: orange with red offset
#define XTL_FUNCTION_HSV AUD_HSV(23, 255, 128)
#define XTL_FUNCTION_HUE_OFFSET 213

// FIXME: helldivers yellow with orangey-yellow offset
#define DTL_HELLDIVERS_HSV AUD_HSV(42, 255, 128)
#define DTL_HELLDIVERS_HUE_OFFSET 192

// FIXME: desaturated helldivers yellow with orange offset
#define PRETTY_BACKLIGHT_MODE RGB_MATRIX_ALPHAS_MODS
#define PRETTY_BACKLIGHT_HSV AUD_HSV(42, 153, 128)
#define PRETTY_BACKLIGHT_SPEED 213

// FIXME: mid-bright pastel
#define XTL_CONTROL_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define XTL_CONTROL_HSV AUD_HSV(0, 96, 128)
#define XTL_CONTROL_SPEED 60

// animation control data structures
typedef enum animation_source {
    LAYER = 0,
    PRETTY,
} animation_source;
