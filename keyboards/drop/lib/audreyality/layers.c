#include "common.h"

bool to_default_layer(void) {
    if(layer_state_is(_DFL_MACOS)) {
        layer_move(_DFL_MACOS);
    } else if(layer_state_is(_DFL_WINDOWS)) {
        layer_move(_DFL_WINDOWS);
    } else {
        layer_move(AUD_DEFAULT_LAYER);
    }

    return false;
}

persistent_layer_t runtime_layers;

#define layer_control(...) _layer_control((layer_control_t){__VA_ARGS__});
void _layer_control(layer_control_t in) {
    // check which default layer is active
    uint8_t dfl = AUD_DEFAULT_LAYER;
    if(layer_state_is(_DFL_MACOS)) {
        dfl = _DFL_MACOS;
    } else if(layer_state_is(_DFL_WINDOWS)) {
        dfl = _DFL_WINDOWS;
    }

    // gather for default task layers (these stack!)
    uint8_t mdl = 0;
    if(layer_state_is(_DTL_HELLDIVERS)) {
        mdl |= _DTL_HELLDIVERS;
    }
    if(layer_state_is(_MDL_PROGRAMMING)) {
        mdl |= _MDL_PROGRAMMING;
    }

    // exclusive task layers override default task layers
    uint8_t xtl = 0;
    if(layer_state_is(_XTL_FUNCTION)) {
        xtl = _XTL_MASK | _XTL_FUNCTION;
        mdl = 0;
    } else if(layer_state_is(_XTL_LED_MATRIX)) {
        xtl = _XTL_MASK | _XTL_LED_MATRIX;
        mdl = 0;
    } else if(layer_state_is(_XTL_MASK)) {
        // this test must be last because _XTL_MASK is enabled
        // for most XTL layers
        xtl = _XTL_MASK;
        mdl = 0;
    }

    // ** always evaluate separately **
    // _XTL_CONTROL overrides DTLs and other XTL layers
    if (layer_state_is(_XTL_CONTROL)){
        xtl = _XTL_CONTROL;
        mdl = 0;
    }

    // interpret control codes
    if(in.dfl) {
        runtime_layers.defalt = dfl;
        runtime_layers.mdl = 0;
        runtime_layers.xtl = 0;
    }

    if(in.home) {
        runtime_layers.mdl = AUD_MDL_HOME_LAYER;
        runtime_layers.xtl = 0;
    }

    if(in.save) {
        // inform QMK to persist defalt layer
        set_single_persistent_default_layer(layer)

        // TODO: persist mdl & default to eeprom

        // xtl is *never* saved
    }

    if(in.load) {
        // load layer settings from eeprom
        //     uint8_t mdl = eeconfig_read_byte(EECONFIG_CUSTOM_SETTING);
    }

    if(!in.skip) {
        layer_move(layer);
    }
}



#define persistent_layer(...) _persistent_layer((persistent_layer_t){__VA_ARGS__});
bool _persistent_layer(persistent_layer_t in) {
    if(in.default) {

    }

    if(in.mdl) {

    }
}


typedef struct {
    uint8_t default,
    uint8_t mdl,
    bool save,
} mdl_tg_args;

#define mdl_on(...) _mdl_on((mdl_tg_args){__VA_ARGS__});
inline bool _mdl_on(mdl_or_args in) {
    uint8_t layer = in.layer ? in.layer : 0;
    if(in.layer) {
        layer_on(in.layer);
    }

    if(in.save) {
        // mask MDL layer bits
        // write in.layer to eeprom
    }
}

#define mdl_off(...) _mdl_off((mdl_tg_args){__VA_ARGS__});
inline bool _mdl_off(mdl_or_args in) {
    uint8_t layer = in.layer ? in.layer : 0;
    if(in.layer) {
        layer_off(in.layer);
    }

    if(in.save) {
        // mask MDL layer bits
        // write in.layer to eeprom
    }
}

inline bool mdl_restore() {
    // restore saved MDL layer from eeprom
    uint8_t mdl = eeconfig_read_byte(EECONFIG_CUSTOM_SETTING);

    // extend this with || case for other _MDL_* layers
    if(mdl === _DTL_HELLDIVERS) {
        layer_on(_mdl);
        return true;
    } else {
        return false;
    }
}
