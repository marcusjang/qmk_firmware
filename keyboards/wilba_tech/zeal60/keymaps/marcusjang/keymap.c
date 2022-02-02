#include QMK_KEYBOARD_H
#include "quantum.h"
#include "marcus.h"

#define LAYOUT_wrapper(...) LAYOUT_60_ansi(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Bspc  │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │CapHan│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter  │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │ LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │  RSfRct  │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │LCtl│LGui│LAlt│         Space          │RAlt│Lowr│Rais│RCtl│
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    [_BASE] = LAYOUT_wrapper(
        KC_ESC,  ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, KC_MINS, KC_EQL,  KC_BSPC, \
        KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_LBRC, KC_RBRC, KC_BSLS, \
        CAP_HAN, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,          SFT_ENT, \
        KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,                   RSF_RCT, \
        KC_LCTL, KC_LGUI, KC_LALT,                         KC_SPC,                                RIS_HAN, LOWER,   KC_RALT, KC_RCTL
    ),
    /* Lower layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│  Del  │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │     │   │   │ ↑ │   │   │Hom│PgU│PgD│End│   │   │   │ Psc │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Caps │   │ ← │ ↓ │ → │   │ ← │ ↓ │ ↑ │ → │   │   │        │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │        │   │   │   │   │   │Ct←│Ct↓│Ct↑│Ct→│   │          │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │    │    │    │                        │    │    │    │    │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    [_LOWER] = LAYOUT_wrapper(
        KC_GRV,  _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________, KC_F11,  KC_F12,  KC_DEL,  \
        _______, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, \
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,          _______, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CTL_LFT, CTL_DWN, CTL_UP,  CTL_RGT, XXXXXXX,                   _______, \
        _______, _______, _______,                        _______,                                RAISE,   _______, KC_APP,   HANJA
    ),
    /* Raised layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │     │MWU│Ms2│MsU│Ms1│   │   │   │   │   │   │   │   │     │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │      │MWD│MsL│MsD│MsR│   │   │   │   │   │   │   │        │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │        │Ms5│MWL│MWR│Ms3│   │   │   │   │   │   │          │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │    │    │    │         MLeft          │    │    │    │    │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    [_RAISE] = LAYOUT_wrapper(
        _______, _______, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  ES_INC,  BR_INC,  _______, MAKE,    RESET,   KC_DEL,  \
        KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  ES_DEC,  BR_DEC,  _______, CLS_APP, CLS_TAB, _______, \
        KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, PRV_TAB, NXT_TAB,          _______, \
        KC_BTN5, KC_WH_L, KC_WH_R, KC_BTN3, _______, _______, _______, _______, _______, _______, _______,                   _______, \
        _______, _______, _______,                        KC_BTN4,                                _______, LOWER, _______, _______
    )
};
