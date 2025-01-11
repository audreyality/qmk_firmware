#include "common.h"

// runtime source always clears on reboot
animation_source runtime_source = LAYER;

// pretty_source saves & loads from eeprom
animation_t pretty_source;
animation_t layer_source;

void pretty_restore(void) {
    // restore pretty animation from eeprom - probably more than
    // just a byte...
    uint8_t pretty = eeconfig_read_byte(EECONFIG_CUSTOM_SETTING);
    // pretty_source = // map raw bytes to animation
}

#define pretty_control(...) _pretty_control((animation_t){__VA_ARGS__});
void _pretty_control(animation_control_t in) {
    if(in.source) {
        runtime_source = in.source;
    }

    if(runtime_source == LAYER) {
        rgb_matrix_mode_noeeprom(layer_source.animation);
        rgb_matrix_sethsv_noeeprom(layer_source.color.h, layer_source.color.s, layer_source.color.v);
        rgb_matrix_set_speed_noeeprom(layer_source.speed);
    } else {
        rgb_matrix_mode_noeeprom(pretty_source.animation);
        rgb_matrix_sethsv_noeeprom(pretty_source.color.h, pretty_source.color.s, pretty_source.color.v);
        rgb_matrix_set_speed_noeeprom(pretty_source.speed);
    }

    if(in.save) {
        // store animation settings in eeprom
    }
}

#define set_pretty(...) _set_pretty((animation_t*)&{__VA_ARGS__});
void _set_pretty(animation_t* in) {
    if(in->animation) {
        pretty_source.animation = in->animation;
    }

    if(in->color) {
        pretty_source.color = in->color;
    }

    if(in->speed) {
        pretty_source.speed = in->speed;
    }
}

#define set_layer_ani(...) _set_layer_ani((animation_t*)&{__VA_ARGS__});
void _set_layer_ani(animation_t* in) {

    if(in->animation) {
        layer_source.animation = in->animation;
    }

    if(in->color) {
        layer_source.color = in->color;
    }

    if(in->speed) {
        layer_source.speed = in->speed;
    }
}
