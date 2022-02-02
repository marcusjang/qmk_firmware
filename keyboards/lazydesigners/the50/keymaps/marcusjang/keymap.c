#include QMK_KEYBOARD_H
#include "quantum.h"
#include "marcus.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐┌───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │Bsp││ 7 │ 8 │ 9 │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤├───┼───┼───┤
     * │SEsc│ A │ S │ D │ F │ G │ H │ J │ K │ L │Enter ││ 4 │ 5 │ 6 │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤├───┼───┼───┤
     * │LShfo│ Z │ X │ C │ V │ B │ N │ M │ , │ . │RShfc││ 1 │ 2 │ 3 │
     * ├────┬┴──┬┴───┼───┴───┴─┬─┴───┴──┬┴───┼───┼─────┤├───┼───┼───┤
     * │LCtl│Gui│LAlt│  Lower  │ SpcRis │NvHn│FnT│RCtrl││ 0 │ . │Ent│
     * └────┴───┴────┴─────────┴────────┴────┴───┴─────┘└───┴───┴───┘
     */
  [_BASE] = LAYOUT_wrapper(
    KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,   KC_7,    KC_8,    KC_9,   \
    SFT_ESC, _________________QWERTY_L2_________________, KC_H,    KC_J,    KC_K,    KC_L,    SFT_ENT,            KC_4,    KC_5,    KC_6,   \
    KC_LSPO, _________________QWERTY_L3_________________, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSPC,            KC_1,    KC_2,    KC_3,   \
    KC_LCTL, KC_LGUI, KC_LALT,             LOWER,           RIS_SPC,        NAV_HAN,       FN1_FN2,    HAN_MOM,   KC_0,    KC_DOT,  KC_ENT  \
  ),
    /* Lower layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐┌───┬───┬───┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│   ││QAp│QTp│Rfr│
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤├───┼───┼───┤
     * │    │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │  0   ││PTp│NTp│RTb│
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤├───┼───┼───┤
     * │     │ - │ = │ ' │ [ │ ] │ \ │ ; │ , │ . │  /  ││PAp│NaP│Psc│
     * ├────┬┴──┬┴───┼───┴───┴─┬─┴───┴──┬┴───┼───┼─────┤├───┼───┼───┤
     * │    │   │    │         │        │RAlt│Gui│     ││App│Hnj│H/E│
     * └────┴───┴────┴─────────┴────────┴────┴───┴─────┘└───┴───┴───┘
     */
  [_LOWER] = LAYOUT_wrapper(
    KC_GRV,  _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________, _______,   KC_KP_7, KC_KP_8, KC_KP_9, \
    _______, ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,            KC_KP_4, KC_KP_5, KC_KP_6, \
    _______, _________________SYMB_LEFT_________________, _________________SYMB_RIGHT________________,            KC_KP_1, KC_KP_2, KC_KP_3, \
    _______, _______, _______,             _______,         RAISE,           KC_RALT,      KC_RGUI,    KC_RCTL,   KC_KP_0, KC_PDOT, KC_PENT  \
  ),
    /* Raised layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐┌───┬───┬───┐
     * │ ~ │F11│F12│F13│F14│F15│   │   │Psc│Slk│Pau│Nlk││ / │ * │ - │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤├───┼───┼───┤
     * │    │ ! │ @ │ # │ $ │ % │ ^ │ & │ * │ ( │  )   ││   │   │ + │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤├───┼───┼───┤
     * │     │ _ │ + │ " │ { │ } │ | │ : │ < │ > │  ?  ││   │   │   │
     * ├────┬┴──┬┴───┼───┴───┴─┬─┴───┴──┬┴───┼───┼─────┤├───┼───┼───┤
     * │    │   │    │         │        │RAlt│Gui│     ││   │   │   │
     * └────┴───┴────┴─────────┴────────┴────┴───┴─────┘└───┴───┴───┘
     */
  [_RAISE] = LAYOUT_wrapper(
    KC_TILD, _______________HIGH_FUNC_LEFT______________, _______________HIGH_FUNC_RIGHT_____________, KC_NLCK,   KC_PSLS, KC_PAST, KC_PMNS, \
    _______, _______________NUM_SYM_LEFT________________, _______________NUM_SYM_RIGHT_______________,            XXXXXXX, XXXXXXX, KC_PPLS, \
    _______, _______________SHFT_SYMB_LEFT______________, _______________SHFT_SYMB_RIGHT_____________,            XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, _______, _______,             LOWER,           _______,         KC_RALT,      KC_RGUI,    KC_RCTL,   XXXXXXX, XXXXXXX, XXXXXXX  \
  ),
    /* Navigations layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐┌───┬───┬───┐
     * │   │QAp│QTp│   │Rfr│   │   │   │   │   │   │Del││ / │ * │ - │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤├───┼───┼───┤
     * │Caps│PTp│NTp│   │   │   │   │Mu←│Ply│Mu→│      ││   │   │ + │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤├───┼───┼───┤
     * │     │   │   │   │   │   │   │   │   │Clr│     ││   │   │   │
     * ├────┬┴──┬┴───┼───┴───┴─┬─┴───┴──┬┴───┼───┼─────┤├───┼───┼───┤
     * │    │   │    │         │        │RAlt│   │     ││   │   │   │
     * └────┴───┴────┴─────────┴────────┴────┴───┴─────┘└───┴───┴───┘
     */
  [_NAV] = LAYOUT_wrapper(
    _______, CLS_APP, CLS_TAB, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   KC_INS,  KC_HOME, KC_PGUP, \
    _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            KC_DEL,  KC_END,  KC_PGDN, \
    _______, PRV_TAB, NXT_TAB, PRV_APP, NXT_APP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, KC_UP,   XXXXXXX, \
    _______, _______, _______,             XXXXXXX,         XXXXXXX,         _______,      XXXXXXX,    _______,   KC_LEFT, KC_DOWN, KC_RGHT  \
  ),
    /* Function layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐┌───┬───┬───┐
     * │   │QAp│QTp│   │Rfr│   │   │   │   │   │   │Del││ / │ * │ - │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤├───┼───┼───┤
     * │Caps│PTp│NTp│   │   │   │   │Mu←│Ply│Mu→│      ││   │   │ + │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤├───┼───┼───┤
     * │     │   │   │   │   │   │   │   │   │Clr│     ││   │   │   │
     * ├────┬┴──┬┴───┼───┴───┴─┬─┴───┴──┬┴───┼───┼─────┤├───┼───┼───┤
     * │    │   │    │         │        │RAlt│   │     ││   │   │   │
     * └────┴───┴────┴─────────┴────────┴────┴───┴─────┘└───┴───┴───┘
     */
  [_FN1] = LAYOUT_wrapper(
    _______, CLS_APP, CLS_TAB, XXXXXXX, REFRESH, RSTR_TB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,    KC_WH_U, KC_BTN3, KC_BTN4, \
    KC_CAPS, PRV_TAB, NXT_TAB, PRV_APP, NXT_APP, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,            KC_BTN1, KC_MS_U, KC_BTN2, \
    _______, KC_APP,  HANJA,   KC_HAEN, KC_HAEN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CLEAR,   XXXXXXX,            KC_MS_L, KC_MS_D, KC_MS_R, \
    _______, _______, _______,             XXXXXXX,         XXXXXXX,         KC_RALT,      FN1_FN2,    _______,   KC_WH_D, XXXXXXX, KC_BTN5  \
  ),
    /* Second Function layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐┌───┬───┬───┐
     * │   │QAp│QTp│   │Rfr│   │   │   │   │   │   │Del││ / │ * │ - │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤├───┼───┼───┤
     * │Caps│PTp│NTp│   │   │   │   │Mu←│Ply│Mu→│      ││   │   │ + │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤├───┼───┼───┤
     * │     │   │   │   │   │   │   │   │   │Clr│     ││   │   │   │
     * ├────┬┴──┬┴───┼───┴───┴─┬─┴───┴──┬┴───┼───┼─────┤├───┼───┼───┤
     * │    │   │    │         │        │RAlt│   │     ││   │   │   │
     * └────┴───┴────┴─────────┴────────┴────┴───┴─────┘└───┴───┴───┘
     */
  [_FN2] = LAYOUT_wrapper(
    _______, KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,    CLS_APP, CLS_TAB, REFRESH, \
    KC_CAPS, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            PRV_TAB, NXT_TAB, RSTR_TB, \
    _______, KC_BTN5, KC_WH_L, KC_WH_R, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            PRV_APP, NXT_APP, KC_PSCR, \
    _______, _______, _______,             KC_BTN4,         XXXXXXX,         KC_RALT,      FN1_FN2,    _______,   KC_APP,  HANJA,   KC_HAEN  \
  ),
    /* Adjust layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐┌───┬───┬───┐
     * │   │QAp│QTp│   │Rfr│   │   │   │   │   │   │Del││ / │ * │ - │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤├───┼───┼───┤
     * │Caps│PTp│NTp│   │   │   │   │Mu←│Ply│Mu→│      ││   │   │ + │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤├───┼───┼───┤
     * │     │   │   │   │   │   │   │   │   │Clr│     ││   │   │   │
     * ├────┬┴──┬┴───┼───┴───┴─┬─┴───┴──┬┴───┼───┼─────┤├───┼───┼───┤
     * │    │   │    │         │        │RAlt│   │     ││   │   │   │
     * └────┴───┴────┴─────────┴────────┴────┴───┴─────┘└───┴───┴───┘
     */
  [_ADJUST] = LAYOUT_wrapper(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAKE,    XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TOG_NKR, RESET,   XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX,         XXXXXXX,         XXXXXXX,      XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX  \
  ),
};

void led_set_user(uint8_t usb_led) {
  // Turn LED On/Off for Caps Lock
  if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
    the50_led_on();
  } else {
    the50_led_off();
  }
}
