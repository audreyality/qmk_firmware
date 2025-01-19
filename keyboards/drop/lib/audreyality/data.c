#include "common.h"

typedef struct init_home {
    /** when `true` the keyboard remembers the mode
    * whether it was in home or default mode when
    * power is lost.
    */
    bool enabled : 1;
    /** when `true`, the keyboard restarts in the home
     * layer. Otherwise it restarts in the default layer.
     */
    bool go_home : 1;
} user_startup_t;

typedef union user_data {
    int32_t raw;
    struct {
        user_startup_t init;
    } data;
} user_data_t;

user_data_t usr;

void save(void) {
    eeconfig_update_user(usr.raw);
}

void load_settings(void) {
    usr.raw = eeconfig_read_user();
    bool initialized = usr.data.init.enabled || usr.data.init.go_home;

    if(!initialized) {
        usr.data.init = (user_startup_t) { .enabled = false, .go_home = true };
        save();
    }
}

bool try_toggle_init_home(void) {
    if(usr.data.init.enabled) {
        usr.data.init.go_home = !usr.data.init.go_home;
        save();

        return true;
    }

    return false;
}

void set_sticky(bool enabled) {
    usr.data.init.enabled = false;
    save();
}

void set_init_home(void) {
    usr.data.init = (user_startup_t) {.enabled = true, .go_home = true };
    save();
}

void set_init_default(void) {
    usr.data.init = (user_startup_t) {.enabled = true, .go_home = false };
    save();
}

bool get_init_default(void) {
    if(usr.data.init.enabled) {
        return !usr.data.init.go_home;
    }

    return false;
}

bool get_init_home(void) {
    if(usr.data.init.enabled) {
        return usr.data.init.go_home;
    }

    return true;
}
