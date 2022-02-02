#include QMK_KEYBOARD_H
#include "quantum.h"
#include "marcus.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ - │Bsp│
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │Tab │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │Enter │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
     * │LShft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RSft │
     * ├───┬─┴─┬─┴─┬─┴─┬─┴───┴──┬┴───┴───┼───┴┬──┴┬──┴─┬───┤
     * │LCt│Gui│LAl│Fn1│ BspLwr │ SpcRis │NvHn│Fn2│RAlt│RCt│
     * └───┴───┴───┴───┴────────┴────────┴────┴───┴────┴───┘
     */
  [_BASE] = LAYOUT_wrapper(
    KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_MINS, KC_BSPC, \
    SFT_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,          SFT_ENT, \
    KC_LSPO, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,          KC_RSPC, \
    KC_LCTL, KC_LGUI, KC_LALT, FN1,          LOWER,         NAV_SPC,        RIS_HAN,  FN2_HAN,    KC_RCTL,      HAN_MOM  \
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
  [_LOWER] = LAYOUT_wrapper(
    KC_GRV,  _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________, _______, _______, \
    _______, ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,          _______, \
    _______, _________________SYMB_LEFT_________________, _________________SYMB_RIGHT________________,          _______, \
    _______, _______, _______, _______,      _______,       RAISE,          _______,  _______,    _______,      _______  \
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
  [_RAISE] = LAYOUT_wrapper(
    KC_TILD, _______________HIGH_FUNC_LEFT______________, _______________HIGH_FUNC_RIGHT_____________, _______, _______, \
    _______, _______________NUM_SYM_LEFT________________, _______________NUM_SYM_RIGHT_______________,          _______, \
    _______, _______________SHFT_SYMB_LEFT______________, _______________SHFT_SYMB_RIGHT_____________,          _______, \
    _______, _______, _______, _______,      LOWER,         _______,        _______,  _______,    _______,      _______  \
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
  [_NAV] = LAYOUT_wrapper(
    _______, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX, _______, _______, \
    _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,          _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CTL_LFT, CTL_DWN, CTL_UP,  CTL_RGT, XXXXXXX,          _______, \
    _______, _______, _______, _______,      _______,       _______,        _______,  _______,    _______,      _______  \
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
  [_FN1] = LAYOUT_wrapper(
    _______, CLS_APP, CLS_TAB, XXXXXXX, REFRESH, RSTR_TB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, _______, KC_DEL,  \
    _______, PRV_TAB, NXT_TAB, PRV_APP, NXT_APP, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,          _______, \
    _______, KC_APP,  HANJA,   KC_HAEN, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CLEAR,            _______, \
    _______, _______, _______, _______,      _______,       _______,        _______,  _______,    _______,      _______  \
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
  [_FN2] = LAYOUT_wrapper(
    _______, KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CLS_APP, CLS_TAB, _______, KC_DEL,  \
    _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, PRV_TAB, NXT_TAB,          _______, \
    _______, KC_BTN5, KC_WH_L, KC_WH_R, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX, CUT,     COPY,    PASTE,            _______, \
    _______, _______, _______, _______,      KC_BTN4,       _______,        _______,  _______,    _______,      _______  \
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
  [_ADJUST] = LAYOUT_wrapper(
    XXXXXXX, RGB_TOG, RGB_MOD, RGB_RMOD,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CLEAR,   REDO,    MAKE,             XXXXXXX, \
    XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, RESET,            XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,       XXXXXXX,        XXXXXXX,  XXXXXXX,    XXXXXXX,      XXXXXXX  \
  )
};
