// Copyright 2023 *+. Audrey .+*
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once
#include "keymap.h"

// layer control data structures
typedef struct {
    uint8_t dfl;
    uint8_t mdl;
    uint8_t xtl;
} persistent_layer_t;

typedef struct {
    bool home;
    bool skip;
    bool save;
    bool load;
} layer_control_t;

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
