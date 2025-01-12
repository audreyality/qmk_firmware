// Copyright 2023 *+. Audrey .+*
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once
#include "keymap.h"

// animation control data structures
typedef enum {
    LAYER = 0,
    PRETTY,
} animation_source;

typedef struct {
    uint8_t animation;
    hsv_t color;
    uint8_t speed;
} animation_t;

typedef struct  {
    animation_source source;
    bool save;
} animation_control_t;
