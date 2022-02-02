#define LOWER   MO(_LOWER)
#define LWR_SPC LT(_LOWER, KC_SPC)
#define LWR_BSP LT(_LOWER, KC_BSPC)
#define LWR_HAN LT(_LOWER, KC_HAEN)

#define RAISE   MO(_RAISE)
#define RIS_SPC LT(_RAISE, KC_SPC)
#define RIS_HAN LT(_RAISE, KC_HAEN)

#define FN1     MO(_FN1)
#define FN2     MO(_FN2)
#define FN2_HAN LT(_FN2, KC_HAEN)

#define SFT_ESC MT(MOD_LSFT, KC_ESC)
#define SFT_BSP MT(MOD_LSFT, KC_BSPC)
#define SFT_ENT MT(MOD_RSFT, KC_ENTER)

#define NAV_SPC LT(_NAV, KC_SPC)
#define NAV_HAN LT(_NAV, KC_HAEN)

#define L_GAME  TG(_GAME)
#define L_DJMAX TG(_DJMAX)

#define CTL_LFT C(KC_LEFT)
#define CTL_RGT C(KC_RGHT)
#define CTL_UP  C(KC_UP)
#define CTL_DWN C(KC_DOWN)
#define CTL_ESC MT(MOD_LCTL, KC_ESC)

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

#define ADJ_M   MO(_ADJUST)
#define ADJ_LOK TT(_ADJUST)
#define ADJ_TOG TG(_ADJUST)

#define RSF_RCT TD(TD_RSF_RCT)
#define NAV_RIS TD(TD_NAV_RIS)
#define FN1_FN2 TD(TD_FN1_FN2)

#define TOG_NKR MAGIC_TOGGLE_NKRO

#define ___________________BLANK___________________        _______, _______, _______, _______, _______
#define ___________________NOOP____________________        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ________________NUMBER_LEFT________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _______________NUM_SYM_LEFT________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _______________NUM_SYM_RIGHT_______________        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN

#define _________________FUNC_LEFT_________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define _______________HIGH_FUNC_LEFT______________        KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15
//#define _______________HIGH_FUNC_RIGHT_____________        KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20
#define _______________HIGH_FUNC_RIGHT_____________        XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS

#define _________________SYMB_LEFT_________________        KC_MINS, KC_EQL,  KC_QUOT, KC_LBRC, KC_RBRC
#define _________________SYMB_RIGHT________________        KC_BSLS, KC_SCLN, KC_COMM, KC_DOT,  KC_SLSH

#define _______________SHFT_SYMB_LEFT______________        KC_UNDS, KC_PLUS, KC_DQUO, KC_LCBR, KC_RCBR
#define _______________SHFT_SYMB_RIGHT_____________        KC_PIPE, KC_COLN, KC_LABK, KC_RABK, KC_QUES
