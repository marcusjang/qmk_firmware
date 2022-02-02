#include QMK_KEYBOARD_H
#include "quantum.h"

enum userspace_layers {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FN1,
    _FN2,
    _NAV
};

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define RIS_HAN LT(_RAISE, KC_HAEN)
#define FN1     MO(_FN1)
#define FN2     MO(_FN2)
#define FN2_HAN LT(_FN2, KC_HAEN)
#define SFT_ESC MT(MOD_LSFT, KC_ESC)
#define SFT_ENT MT(MOD_RSFT, KC_ENTER)
#define NAV_SPC LT(_NAV, KC_SPC)

#define CTL_LFT C(KC_LEFT)
#define CTL_RGT C(KC_RGHT)
#define CTL_UP  C(KC_UP)
#define CTL_DWN C(KC_DOWN)

#define COPY    C(KC_C)
#define CUT     C(KC_X)
#define PASTE   C(KC_V)
#define UNDO    C(KC_Z)
#define REDO    S(C(KC_Z))

#define NXT_APP LCA(KC_TAB)
#define PRV_APP S(LCA(KC_TAB))
#define CLS_APP A(KC_F4)

#define NXT_TAB C(KC_TAB)
#define PRV_TAB S(C(KC_TAB))
#define CLS_TAB C(KC_F4)

#define REFRESH S(C(KC_R))
#define RSTR_TB S(C(KC_T))

enum userspace_custom_keycodes {
  HANJA = SAFE_RANGE,
  MAKE,
  CLEAR,
  HAN_MOM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
     * │Tab│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ Bsp │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬────┤
     * │SEsc│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │SEnt│ 
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┤
     * │LShfO│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RSf│
     * ├───┬─┴─┬─┴─┬─┴─┬─┴──┬┴───┴──┬┴───┼───┼───┼───┼───┤
     * │LCt│Gui│LAl│Fn1│Lowr│SpcNav │RiHn│Fn2│RAl│RCt│sd │
     * └───┴───┴───┴───┴────┴───────┴────┴───┴───┴───┴───┘
     */
  [_BASE] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    SFT_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, SFT_ENT, \
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH, KC_RSPC, \
    KC_LCTL, KC_LGUI, KC_LALT, FN1,     LOWER,      NAV_SPC,       RAISE,   FN2_HAN, KC_RALT, KC_RCTL, HAN_MOM  \
  ),
    /* Lower layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│   │   │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │    │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │      │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
     * │     │ - │ = │ ' │ [ │ ] │ \ │ ; │ , │ . │ / │     │
     * ├───┬─┴─┬─┴─┬─┴─┬─┴───┴──┬┴───┴───┼───┴┬──┴┬──┴─┬───┤
     * │   │   │   │   │        │        │    │   │    │   │
     * └───┴───┴───┴───┴────────┴────────┴────┴───┴────┴───┘
     */
  [_LOWER] = LAYOUT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, KC_MINS, KC_EQL,  KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, KC_COMM, KC_DOT,  KC_SLSH, _______, \
    _______, _______, _______, _______, _______,    _______,       RAISE,   _______, _______, _______, _______  \
  ),
    /* Raised layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ~ │F11│F12│F13│F14│F15│F16│F17│F18│F19│F20│   │   │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │    │ ! │ @ │ # │ $ │ % │ ^ │ & │ * │ ( │ ) │      │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
     * │     │ _ │ + │ " │ { │ } │ | │ : │ < │ > │ ? │     │
     * ├───┬─┴─┬─┴─┬─┴─┬─┴───┴──┬┴───┴───┼───┴┬──┴┬──┴─┬───┤
     * │   │   │   │   │        │        │    │   │    │   │
     * └───┴───┴───┴───┴────────┴────────┴────┴───┴────┴───┘
     */
  [_RAISE] = LAYOUT(
    KC_TILD, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, _______, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, KC_UNDS, KC_PLUS, KC_DQUO, KC_LCBR, KC_RCBR, KC_PIPE, KC_COLN, KC_LABK, KC_RABK, KC_QUES, _______, \
    _______, _______, _______, _______, LOWER,      _______,       _______, _______, _______, _______, _______  \
  ),
    /* Navigations layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │   │   │ ↑ │   │   │Hom│PgU│PgD│End│   │   │   │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │    │   │ ← │ ↓ │ → │   │ ← │ ↓ │ ↑ │ → │   │      │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
     * │     │   │   │   │   │   │Ct←│Ct↓│Ct↑│Ct→│   │     │
     * ├───┬─┴─┬─┴─┬─┴─┬─┴───┴──┬┴───┴───┼───┴┬──┴┬──┴─┬───┤
     * │   │   │   │   │        │        │    │   │    │   │
     * └───┴───┴───┴───┴────────┴────────┴────┴───┴────┴───┘
     */
  [_NAV] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX, _______, \
    _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CTL_LFT, CTL_DWN, CTL_UP,  CTL_RGT, XXXXXXX, _______, \
    _______, _______, _______, _______, _______,    _______,       _______, _______, _______, _______, _______  \
  ),
    /* Function layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │QAp│QTp│   │Rfr│   │   │   │   │   │Psc│   │Del│
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │    │PTp│NTp│   │   │   │   │   │Mu←│Ply│Mu→│      │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
     * │     │App│Hnj│Han│Cap│   │Sc↓│Sc↑│Mut│Vl↓│Vl↑│     │
     * ├───┬─┴─┬─┴─┬─┴─┬─┴───┴──┬┴───┴───┼───┴┬──┴┬──┴─┬───┤
     * │   │   │   │   │        │        │    │   │    │   │
     * └───┴───┴───┴───┴────────┴────────┴────┴───┴────┴───┘
     */
  [_FN1] = LAYOUT(
    _______, CLS_APP, CLS_TAB, XXXXXXX, REFRESH, RSTR_TB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_DEL,  \
    _______, PRV_TAB, NXT_TAB, PRV_APP, NXT_APP, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, _______, \
    _______, KC_APP,  HANJA,   KC_HAEN, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CLEAR,   _______, \
    _______, _______, _______, _______, _______,    _______,       _______, _______, _______, _______, _______  \
  ),
    /* Second Function layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │MWU│Ms2│MsU│Ms1│   │   │   │   │   │   │   │Del│
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │    │MWD│MsL│MsD│MsR│   │   │   │   │Rdo│Udo│      │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
     * │     │Ms5│MWL│MWR│Ms3│   │   │   │Cut│Cop│Pst│     │
     * ├───┬─┴─┬─┴─┬─┴─┬─┴───┴──┬┴───┴───┼───┴┬──┴┬──┴─┬───┤
     * │   │   │   │   │  Ms4   │        │    │   │    │   │
     * └───┴───┴───┴───┴────────┴────────┴────┴───┴────┴───┘
     */
  [_FN2] = LAYOUT(
    _______, KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CLS_APP, CLS_TAB, KC_DEL,  \
    _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, PRV_TAB, NXT_TAB, _______, \
    _______, KC_BTN5, KC_WH_L, KC_WH_R, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX, CUT,     COPY,    PASTE,   _______, \
    _______, _______, _______, _______, _______,    KC_BTN4,       _______, _______, _______, _______, _______  \
  ),
    /* Adjust layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │RTg│RMd│   │   │   │   │   │   │   │   │   │   │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │    │RHI│RSI│RVI│   │   │   │   │   │   │Mak│      │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
     * │     │RHD│RSD│RVD│Sc↓│Sc↑│Mut│Vl↓│Vl↑│   │Rst│     │
     * ├───┬─┴─┬─┴─┬─┴─┬─┴───┴──┬┴───┴───┼───┴┬──┴┬──┴─┬───┤
     * │   │   │   │   │        │        │    │   │    │   │
     * └───┴───┴───┴───┴────────┴────────┴────┴───┴────┴───┘
     */
  [_ADJUST] = LAYOUT(
    XXXXXXX, RGB_TOG, RGB_MOD, RGB_RMOD,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CLEAR,   REDO,    MAKE,    XXXXXXX, \
    XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, RESET,   XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  )
};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

        case HAN_MOM:
            register_code(KC_HAEN);
            unregister_code(KC_HAEN);
            return false;
            break;
    }

    return true;
};