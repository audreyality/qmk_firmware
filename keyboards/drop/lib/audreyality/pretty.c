#include "common.h"

typedef struct {
    uint8_t animation;
    hsv_t hsv;
    uint8_t speed;
} animation_t;

// runtime source always resets on reboot
animation_source runtime_src = LAYER;

// pretty_src saves & loads from eeprom
animation_t pretty_src;
animation_t layer_src;

void set_layer_mode(uint8_t animation) {
    layer_src.animation  = layer_src.animation;
    if(runtime_src == LAYER) {
        rgb_matrix_mode_noeeprom(layer_src.animation);
    }
}

void set_layer_hsv(hsv_t hsv) {
    layer_src.hsv = hsv;
    if(runtime_src == LAYER) {
        rgb_matrix_sethsv_noeeprom(
            layer_src.hsv.h,
            layer_src.hsv.s,
            layer_src.hsv.v
        );
    }
}

void set_layer_speed(uint8_t speed) {
    layer_src.speed = speed;
    if(runtime_src == LAYER) {
        rgb_matrix_set_speed_noeeprom(layer_src.speed);
    }
}

void set_pretty_mode(uint8_t animation) {
    pretty_src.animation  = animation;
    if(runtime_src == PRETTY) {
        rgb_matrix_mode_noeeprom(pretty_src.animation);
    }
}

void set_pretty_hsv(hsv_t hsv) {
    pretty_src.hsv = hsv;
    if(runtime_src == PRETTY) {
        rgb_matrix_sethsv_noeeprom(
            pretty_src.hsv.h,
            pretty_src.hsv.s,
            pretty_src.hsv.v
        );
    }
}

void set_pretty_speed(uint8_t speed) {
    pretty_src.speed = speed;
    if(runtime_src == PRETTY) {
        rgb_matrix_set_speed_noeeprom(pretty_src.speed);
    }
}

void set_source(animation_source source) {
    animation_t* src = source == LAYER
        ? &pretty_src
        : &layer_src;

    rgb_matrix_sethsv_noeeprom(src->hsv.h, src->hsv.s, src->hsv.v);
    rgb_matrix_set_speed_noeeprom(src->speed);
    rgb_matrix_mode_noeeprom(src->animation);
}

void save_pretty(void) {
    rgb_matrix_sethsv(pretty_src.hsv.h, pretty_src.hsv.s, pretty_src.hsv.v);
    rgb_matrix_set_speed(pretty_src.speed);
    rgb_matrix_mode(pretty_src.animation);

    // restore light source before save
    set_source(runtime_src);
}

void init_pretty_backlight(void) {
    // initialize backlight
#ifndef PRETTY_BACKLIGHT_MODE
#   define PRETTY_BACKLIGHT_MODE {215, 240, 80}
#endif
    set_pretty_mode(PRETTY_BACKLIGHT_MODE);

#ifndef PRETTY_BACKLIGHT_HSV
#   define PRETTY_BACKLIGHT_HSV {215, 240, 80}
#endif
    set_pretty_hsv(PRETTY_BACKLIGHT_HSV);

#ifndef PRETTY_BACKLIGHT_SPEED
#   define PRETTY_BACKLIGHT_SPEED {215, 240, 80}
#endif
    set_pretty_speed(PRETTY_BACKLIGHT_SPEED);

    // switch to backlight
    set_source(PRETTY);
}

void init_pretty_from_qmk(void) {
    pretty_src.animation = rgb_matrix_get_mode();
    pretty_src.hsv = rgb_matrix_get_hsv();
    pretty_src.speed = rgb_matrix_get_speed();
}

void init_pretty_from_eeprom(void) {
    rgb_matrix_reload_from_eeprom();
    init_pretty_from_qmk();

    // restore light source before load
    set_source(runtime_src);
}
