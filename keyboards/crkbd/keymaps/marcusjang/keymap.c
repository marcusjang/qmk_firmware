#include QMK_KEYBOARD_H
#include "quantum.h"
//#include <stdio.h>

enum userspace_layers {
    _BASE = 0,
    _GAME,
    _DJMAX,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FN1,
    _FN2,
    _NAV,
    _MUSIC
};

enum userspace_custom_keycodes {
    CAP_HAN = SAFE_RANGE,
    HANJA,
    HAN_MOM,
    MAKE,
    CLEAR,
    MUS_OFF,
    JEONGUK
};

#include "userspace_keys.h"
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │ │ Y │ U │ I │ O │ P │Bsp│
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │CEs│ A │ S │ D │ F │ G │ │ H │ J │ K │ L │ ; │SEn│
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │LSP│ Z │ X │ C │ V │ B │ │ N │ M │ , │ . │ / │RSP│
     * └───┴───┴───┼───┼───┼───┤ ├───┼───┼───┼───┴───┴───┘
     *             │Fn1│Lwr│SBs│ │NvS│Ris│Fn2│            
     *             └───┴───┴───┘ └───┴───┴───┘
     */
    [_BASE] = LAYOUT_wrapper( \
        KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC, \
        CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_ENT, \
        KC_LSPO, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSPC, \
                                   FN1,     LOWER,   SFT_BSP, NAV_SPC, RAISE,   FN2_HAN                             \
    ),
    /* DJMAX layer
     */
    [_DJMAX] = LAYOUT_wrapper( \
        KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC, \
        CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_ENT, \
        KC_LSPO, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSPC, \
                                   FN1,     LOWER,   KC_LALT, KC_RALT, RAISE,   L_DJMAX                             \
    ),
    /* Lower layer
     * ┌───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┬───┬───┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │ │F6 │F7 │F8 │F9 │F10│   │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │   │ 1 │ 2 │ 3 │ 4 │ 5 │ │ 6 │ 7 │ 8 │ 9 │ 0 │   │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │   │ - │ = │ ' │ [ │ ] │ │ \ │ ; │ , │ . │ / │   │
     * └───┴───┴───┼───╆━━━╅───┤ ├───┼───┼───┼───┴───┴───┘
     *             │   ┃Lwr┃   │ │   │   │   │            
     *             └───┺━━━┹───┘ └───┴───┴───┘
     */
    [_LOWER] = LAYOUT_wrapper( \
        KC_GRV,  _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________, _______, \
        _______, ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, _______, \
        _______, _________________SYMB_LEFT_________________, _________________SYMB_RIGHT________________, _______, \
                                   _______, _______, _______, _______, RAISE,   _______                             \
    ),
    /* Raised layer
     * ┌───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┬───┬───┐
     * │ ~ │F11│F12│F13│F14│F15│ │F16│F17│F18│F19│F20│   │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │   │ ! │ @ │ # │ $ │ % │ │ ^ │ & │ * │ ( │ ) │   │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │   │ _ │ + │ " │ { │ } │ │ | │ : │ < │ > │ ? │   │
     * └───┴───┴───┼───┼───┼───┤ ├───╆━━━╅───┼───┴───┴───┘
     *             │   │   │   │ │   ┃Ris┃   │            
     *             └───┴───┴───┘ └───┺━━━┹───┘
     */
    [_RAISE] = LAYOUT_wrapper( \
        KC_TILD, _______________HIGH_FUNC_LEFT______________, _______________HIGH_FUNC_RIGHT_____________, _______, \
        _______, _______________NUM_SYM_LEFT________________, _______________NUM_SYM_RIGHT_______________, _______, \
        _______, _______________SHFT_SYMB_LEFT______________, _______________SHFT_SYMB_RIGHT_____________, _______, \
                                   _______, LOWER,   _______, _______, _______, _______                             \
    ),
    /* Navigations layer
     * ┌───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┬───┬───┐
     * │   │   │   │ ↑ │   │   │ │Hom│PgU│PgD│End│   │   │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │   │   │ ← │ ↓ │ → │   │ │ ← │ ↓ │ ↑ │ → │   │   │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │Ctl│GUI│Alt│   │   │   │ │Ct←│Ct↓│Ct↑│Ct→│   │   │
     * └───┴───┴───┼───┼───┼───┤ ┢━━━╅───┼───┼───┴───┴───┘
     *             │   │   │   │ ┃NvS┃   │   │            
     *             └───┴───┴───┘ ┗━━━┹───┴───┘
     */
    [_NAV] = LAYOUT_wrapper( \
        _______, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX, _______, \
        _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______, \
        KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, CTL_LFT, CTL_DWN, CTL_UP,  CTL_RGT, XXXXXXX, _______, \
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX                             \
    ),
    /* Functions layer
     * ┌───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┬───┬───┐
     * │   │QAp│QTb│   │Rfr│   │ │   │   │   │   │Psc│Del│
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │   │PTb│NTb│   │   │   │ │   │   │Mu←│Ply│Mu→│   │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │   │App│Hnj│Han│Cap│   │ │   │   │   │   │   │   │
     * └───┴───┴───╆━━━╅───┼───┤ ├───┼───┼───┼───┴───┴───┘
     *             ┃Fn1┃   │   │ │   │   │   │            
     *             ┗━━━┹───┴───┘ └───┴───┴───┘
     */
    [_FN1] = LAYOUT_wrapper( \
        _______, CLS_APP, CLS_TAB, XXXXXXX, REFRESH, RSTR_TB, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PSCR, _______, \
        _______, PRV_TAB, NXT_TAB, PRV_APP, NXT_APP, REDO,    UNDO,    KC_KP_4, KC_KP_5, KC_KP_6, KC_NLCK, _______, \
        _______, KC_APP,  HANJA,   KC_HAEN, KC_CAPS, XXXXXXX, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, CLEAR,   _______, \
                                   XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL                             \
    ),
    /* Second Functions layer
     * ┌───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┬───┬───┐
     * │   │MWU│Ms2│MsU│Ms1│   │ │   │   │   │   │   │Del│
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │   │MWD│MsL│MsD│MsR│   │ │   │   │   │Rdo│Udo│   │ 
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │   │Ms5│MWL│MWR│MS3│   │ │   │   │Cut│Cop│Pst│   │
     * └───┴───┴───┼───┼───┼───┤ ├───┼───╆━━━╅───┴───┴───┘
     *             │   │   │Ms4│ │   │   ┃Fn2┃            
     *             └───┴───┴───┘ └───┴───┺━━━┛
     */
    [_FN2] = LAYOUT_wrapper( \
        _______, KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, XXXXXXX, XXXXXXX, CLS_APP, CLS_TAB, XXXXXXX, REFRESH, KC_DEL,  \
        _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, PRV_TAB, NXT_TAB, XXXXXXX, XXXXXXX, _______, \
        _______, KC_BTN5, KC_WH_L, KC_WH_R, KC_BTN3, KC_BTN4, XXXXXXX, XXXXXXX, CUT,     COPY,    PASTE,   _______, \
                                   KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX                             \
    ),
    /* Adjust layer
     */
    [_ADJUST] = LAYOUT_wrapper( \
        XXXXXXX, XXXXXXX, L_DJMAX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_SWAP, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, AG_NORM, MAKE,    XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, TOG_NKR, RESET,   XXXXXXX, \
                                   XXXXXXX, LOWER,   XXXXXXX, XXXXXXX, RAISE,   XXXXXXX                             \
    )
};

/*
#ifdef OLED_DRIVER_ENABLE
#include "oled.c"
#endif
*/

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef OLED_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
#endif

    switch (keycode) {
            
        case HANJA:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LANG2) SS_TAP(X_TAB));
            }
            return false;
            break;

        case MAKE:
            if (record->event.pressed) {
                SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP ":dfu");
            }
            return false;
            break;

        case CLEAR:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a") SS_TAP(X_DELETE));
            }
            return false;
            break;
    }

    return true;
};
