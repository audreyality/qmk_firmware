#include "common.h"

// check which default layer is active
uint8_t qmk_dfl(void) {
    uint8_t dfl = AUD_DEFAULT_LAYER;
    if(layer_state_is(_DFL_MACOS)) {
        dfl = _DFL_MACOS;
    } else if(layer_state_is(_DFL_WINDOWS)) {
        dfl = _DFL_WINDOWS;
    }
    return dfl;
}

// gather for default task layers
uint8_t qmk_dtl(void) {
    uint8_t dtl = 0;
    if(layer_state_is(_DTL_HELLDIVERS)) {
        dtl = _DTL_HELLDIVERS;
    } else if(layer_state_is(_DTL_PROGRAMMING)) {
        dtl = _DTL_PROGRAMMING;
    }

    return dtl;
}

uint8_t qmk_xtl(void) {
    uint8_t xtl = 0;
    if(layer_state_is(_XTL_FUNCTION)) {
        xtl = _XTL_FUNCTION;
    } else if(layer_state_is(_XTL_LED_MATRIX)) {
        xtl = _XTL_LED_MATRIX;
    } else if(layer_state_is(_XTL_MASK)) {
        // this test must be last because _XTL_MASK is enabled
        // for most XTL layers
        xtl = _XTL_MASK;
    }

    // ** always evaluate separately **
    if (layer_state_is(_XTL_CONTROL)){
        xtl = _XTL_CONTROL;
    }

    return xtl;
}

void to_layer(uint8_t layer) {
    switch (layer) {
        case _DFL_MACOS:
        case _DFL_WINDOWS:
            layer_move(layer);
            break;

        case _DTL_HELLDIVERS:
        case _DTL_PROGRAMMING:
            layer_move(qmk_dfl());
            layer_on(layer);
            break;

        case _XTL_CONTROL:
        case _XTL_FUNCTION:
        case _XTL_LED_MATRIX:
            layer_on(layer);
            // falls through

        case _XTL_MASK:
            layer_on(_XTL_MASK);
            return;

        default:
            layer_off(_XTL_MASK);
            break;
    }

    return;
}

void to_default_layer(void) {
    to_layer(qmk_dfl());
}

void to_home_layer(void) {
#   ifndef AUD_DTL_HOME_LAYER
#       define AUD_DTL_HOME_LAYER _DFL_MACOS
#   endif

    to_layer(AUD_DTL_HOME_LAYER);
}
