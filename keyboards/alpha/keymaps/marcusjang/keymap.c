#include QMK_KEYBOARD_H
#include "quantum.h"
#include "marcus.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │ H │ J │ K │ L │Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ Z │ X │ C │ V │Spc│ B │ N │ M │   │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
	[_BASE] = LAYOUT(
		KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,             KC_Y,    KC_U,             KC_I,           KC_O,          KC_P,    \
		SFT_T(KC_A), KC_S,        KC_D,        KC_F,        KC_G,             KC_H,    KC_J,             KC_K,           KC_L,          SFT_ENT, \
		             CTL_T(KC_Z), GUI_T(KC_X), ALT_T(KC_C), LT(_LOWER, KC_V), NAV_SPC, LT(_LOWER, KC_B), LT(_FN1, KC_N), LT(_FN2, KC_M)
	),
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │ H │ J │ K │ L │Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ Z │ X │ C │ V │Spc│ B │ N │ M │   │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
	[_LOWER] = LAYOUT(
		KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
		KC_MINS, KC_EQL,  KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, KC_COMM, KC_DOT,  KC_SLSH, \
		         KC_LCTL, KC_LGUI, KC_LALT, LOWER,   NAV_SPC, RAISE,   FN1,     FN2
	),
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │ H │ J │ K │ L │Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ Z │ X │ C │ V │Spc│ B │ N │ M │   │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
	[_RAISE] = LAYOUT(
		KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
		KC_UNDS, KC_PLUS, KC_DQUO, KC_LCBR, KC_RCBR, KC_PIPE, KC_COLN, KC_LABK, KC_RABK, KC_QUES, \
		         KC_LCTL, KC_LGUI, KC_LALT, LOWER,   NAV_SPC, RAISE,   FN1,     FN2
	),
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │ H │ J │ K │ L │Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ Z │ X │ C │ V │Spc│ B │ N │ M │   │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
	[_FN1] = LAYOUT(
		KC_TAB,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,  KC_BSPC, \
		KC_ESC,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX, XXXXXXX, KC_F10,  KC_F11,  KC_F12, KC_RSFT, \
		         KC_LCTL, KC_LGUI, KC_LALT, LOWER,   NAV_SPC, KC_HAEN, FN1,     FN2
	),
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │ H │ J │ K │ L │Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ Z │ X │ C │ V │Spc│ B │ N │ M │   │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
	[_FN2] = LAYOUT(
		KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, UNDO,    REDO,    KC_INS,  CLS_APP, CLS_TAB, KC_DEL,  \
		KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, KC_APP,  HANJA,   PRV_TAB, NXT_TAB, KC_PSCR, \
		         KC_LCTL, KC_LGUI, KC_LALT, KC_BTN3, KC_BTN4, KC_HAEN, FN1,     FN2
	),
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │ H │ J │ K │ L │Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ Z │ X │ C │ V │Spc│ B │ N │ M │   │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
	[_NAV] = LAYOUT(
		XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX,  \
		XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
		         KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
	),
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │ H │ J │ K │ L │Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ Z │ X │ C │ V │Spc│ B │ N │ M │   │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
	[_ADJUST] = LAYOUT(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAKE,    \
		         XXXXXXX, XXXXXXX, XXXXXXX, LOWER,   XXXXXXX, RAISE,   XXXXXXX, RESET
	)
};