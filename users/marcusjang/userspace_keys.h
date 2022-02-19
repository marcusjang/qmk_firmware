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

#define L_GAME1 TG(_GAME1)
#define L_GAME2 TG(_GAME2)

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

enum userspace_custom_keycodes {
	CAP_HAN = SAFE_RANGE,
	HANJA,
    HAN_MOM,
	MAKE,
    CLEAR,
    MUS_OFF,
    JEONGUK
};

enum userspace_tap_dance {
	TD_RSF_RCT,
    TD_NAV_RIS,
    TD_FN1_FN2
};
