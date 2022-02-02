#include "marcusjang.h"

void set_keylog(uint16_t keycode, keyrecord_t *record);

#define ACTION_TAP_DANCE_DOUBLE_MODS(mod1, mod2) { \
    .fn = { td_double_mods_each, NULL, td_double_mods_reset }, \
    .user_data = &(qk_tap_dance_pair_t){ mod1, mod2 }, \
}

void td_double_mods_each(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_dance_pair_t *mods = (qk_tap_dance_pair_t *)user_data;
    // Single tap → mod1, double tap → mod2, triple tap etc. → mod1+mod2
    if (state->count == 1 || state->count == 3) {
        register_code(mods->kc1);
    } else if (state->count == 2) {
        unregister_code(mods->kc1);
        register_code(mods->kc2);
    }
    // Prevent tap dance from sending kc1 and kc2 as weak mods
    state->weak_mods &= ~(MOD_BIT(mods->kc1) | MOD_BIT(mods->kc2));
}

void td_double_mods_reset(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_dance_pair_t *mods = (qk_tap_dance_pair_t *)user_data;
    if (state->count == 1 || state->count > 2) {
        unregister_code(mods->kc1);
    }
    if (state->count >= 2) {
        unregister_code(mods->kc2);
    }
}

#define ACTION_TAP_DANCE_DOUBLE_LAYERS(layer1, layer2) { \
    .fn = { NULL, td_double_layers_finished, td_double_layers_reset }, \
    .user_data = &(qk_tap_dance_pair_t){ layer1, layer2 }, \
}

void td_double_layers_finished(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_dance_pair_t *layers = (qk_tap_dance_pair_t *)user_data;
    if (state->count == 1 || state->count == 3) {
        layer_on(layers->kc1);
    } else if (state->count == 2) {
        layer_invert(layers->kc2);
    }
}

void td_double_layers_reset(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_dance_pair_t *layers = (qk_tap_dance_pair_t *)user_data;
    if (state->count == 1 || state->count > 2) {
        layer_off(layers->kc1);
    }
    if (state->count >= 2) {
        layer_off(layers->kc2);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RSF_RCT] = ACTION_TAP_DANCE_DOUBLE_MODS(KC_RSFT, KC_RCTL),
    [TD_NAV_RIS] = ACTION_TAP_DANCE_DOUBLE_LAYERS(_RAISE, _NAV),
    [TD_FN1_FN2] = ACTION_TAP_DANCE_DOUBLE_LAYERS(_FN1, _FN2)
};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

float jeonguk_song[][2] = SONG(JEONGUK_SONG);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t caps_haen_timer;


#ifdef SSD1306OLED
  if (record->event.pressed) {
    set_keylog(keycode, record);
    // set_timelog();
  }
#endif

    switch (keycode) {
            
        case CAP_HAN:
            if (record->event.pressed) {
                caps_haen_timer = timer_read();
            } else {
                if (timer_elapsed(caps_haen_timer) < TAPPING_TERM) {
                    register_code(KC_HAEN);
                    unregister_code(KC_HAEN);
                } else {
                    register_code(KC_CAPS);
                    unregister_code(KC_CAPS);
                }
            }
            return false;
            break;

        case HANJA:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LANG2) SS_TAP(X_TAB));
            }
            return false;
            break;

        case MAKE:
            if (record->event.pressed) {
                SEND_STRING("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP);
            }
            return false;
            break;

        case CLEAR:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a") SS_TAP(X_DELETE));
            }
            return false;
            break;

        case MUS_OFF:
            #ifdef AUDIO_ENABLE
                if (record->event.pressed) {
                    layer_clear();
                    music_off();
                }
            #endif
            return false;
            break;

        case JEONGUK:
            #ifdef AUDIO_ENABLE
                if (record->event.pressed) {
                    PLAY_SONG(jeonguk_song);
                }
            #endif
            return false;
            break;

        case HAN_MOM:
            register_code(KC_HAEN);
            unregister_code(KC_HAEN);
            return false;
            break;
    }

    return true;
};

#ifdef AUDIO_ENABLE

/*
void matrix_init_user(void) {

    set_tempo(200);
}
*/

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case MUS_OFF:
      return false;
    default:
      return true;
  }
}

void music_on_user(void) {
    layer_move(_MUSIC);
}

#endif