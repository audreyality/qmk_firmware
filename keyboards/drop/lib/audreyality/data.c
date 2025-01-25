#include "common.h"

typedef struct sticky {
    /** whether or not sticky state is recalled */
    bool enabled : 1;
    /** recalled sticky state */
    bool value : 1;
} sticky_t;

typedef union user_data {
    int32_t raw;
    struct {
        /** match (value) :
          *   disabled => startup on home layer. If a home layer isn't
          *               configured, start on the default layer.
          *   enabled  => value tracks startup layer:
          *       true -> startup on home layer.
          *      false -> startup on default layer.
          */
        sticky_t home;

        /** match (value)
          *   disabled => use layer lighting if configured,
          *               otherwise use pretty lighting.
          *   enabled  => value determines sticky lighting mode:
          *       true -> always use pretty lighting.
          *      false -> always use backlighting.
          */
        sticky_t pretty;
    } data;
} user_data_t;

user_data_t usr;

void save_settings(void) {
    eeconfig_update_user(usr.raw);
}

void load_settings(void) {
    usr.raw = eeconfig_read_user();
    bool initialized = usr.raw > 0;

    if(!initialized) {
        usr.data.home = (sticky_t) { .enabled = false, .value = true };
        usr.data.pretty = (sticky_t) { .enabled = false, .value = true };
        save_settings();
    }
}


sticky_t* sticky_bit(sticky_target_t target) {
    sticky_t* sticky = target == HOME_LAYER_BITS ? &usr.data.home : &usr.data.pretty;
    return sticky;
}

bool try_toggle_sticky_value(sticky_target_t target) {
    if(sticky_bit(target)->enabled) {
        sticky_t* sticky = sticky_bit(target);
        sticky->value = !sticky->value;
        save_settings();

        return true;
    }

    return false;
}

bool try_set_sticky_value(sticky_target_t target, bool value) {
    if(sticky_bit(target)->enabled) {
        sticky_t* sticky = sticky_bit(target);
        sticky->value = value;
        save_settings();

        return true;
    }

    return false;
}

void disable_sticky(sticky_target_t target) {
    sticky_bit(target)->enabled = false;
    save_settings();
}

void enable_sticky(sticky_target_t target) {
    sticky_bit(target)->enabled = true;
    save_settings();
}

void set_sticky_home(sticky_home_t value) {
    sticky_bit(HOME_LAYER_BITS)->enabled = true;
    sticky_bit(HOME_LAYER_BITS)->value = value == STICKY_HOME_LAYER;
    save_settings();
}

void set_sticky_pretty(sticky_pretty_t value) {
    sticky_bit(PRETTY_LIGHTING_BITS)->enabled = true;
    sticky_bit(PRETTY_LIGHTING_BITS)->value = value == STICKY_PRETTY_LIGHTING;
    save_settings();
}

bool use_sticky_home(sticky_home_t value) {
    sticky_t* sticky = sticky_bit(HOME_LAYER_BITS);
    sticky_home_t current = STICKY_DEFAULT_LAYER;
    if(!sticky->enabled || sticky->value) {
        current = STICKY_HOME_LAYER;
    }

    return value == current;
}

bool use_sticky_pretty(sticky_pretty_t value) {
    sticky_t* sticky = sticky_bit(PRETTY_LIGHTING_BITS);
    if(!sticky->enabled) {
        return false;
    }

    sticky_pretty_t current = sticky->value
        ? STICKY_PRETTY_LIGHTING
        : STICKY_NO_LIGHTING;

    return value == current;
}
