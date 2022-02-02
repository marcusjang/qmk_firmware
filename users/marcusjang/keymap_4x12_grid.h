#define LAYOUT_wrapper(...) LAYOUT_ortho_4x12(__VA_ARGS__)

#ifndef AUDIO_ENABLE
#undef AU_TOG
#undef MU_TOG
#undef MU_MOD
#define AU_TOG XXXXXXX
#define MU_TOG XXXXXXX
#define MU_MOD XXXXXXX
#endif

#ifdef NO_NKRO_SUPPORT
#undef TOG_NKR
#define TOG_NKR XXXXXXX
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │Bsp│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │SEs│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │SEn│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │LSP│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RSP│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │LCt│LGu│LAl│Fn1│Lwr│SBs│NvS│Ris│Fn2│RAl│RGu│RCt│
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT_wrapper( \
        KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC, \
        SFT_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_ENT, \
        KC_LSPO, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSPC, \
        KC_LCTL, KC_LGUI, KC_LALT, FN1,     LOWER,   NAV_SPC, NAV_SPC, RAISE,   FN2_HAN, KC_RALT, KC_RCTL, HAN_MOM  \
    ),
    /* Lower layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ - │ = │ ' │ [ │ ] │ \ │ ; │ , │ . │ / │   │
     * ├───┼───┼───┼───╆━━━╅───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   ┃Lwr┃   │   │   │   │   │   │   │
     * └───┴───┴───┴───┺━━━┹───┴───┴───┴───┴───┴───┴───┘
     */
    [_LOWER] = LAYOUT_wrapper( \
        KC_GRV,  _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________, _______, \
        _______, ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, _______, \
        _______, _________________SYMB_LEFT_________________, _________________SYMB_RIGHT________________, _______, \
        _______, ___________________BLANK___________________, _______, RAISE,   _______, _______, _______, _______  \
    ),
    /* Raised layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ~ │F11│F12│F13│F14│F15│   │   │Psc│Slk│Pau│   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ ! │ @ │ # │ $ │ % │ ^ │ & │ * │ ( │ ) │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ _ │ + │ " │ { │ } │ | │ : │ < │ > │ ? │   │
     * ├───┼───┼───┼───┼───┼───┼───╆━━━╅───┼───┼───┼───┤
     * │   │   │   │   │   │   │   ┃Ris┃   │   │   │   │
     * └───┴───┴───┴───┴───┴───┴───┺━━━┹───┴───┴───┴───┘
     */
    [_RAISE] = LAYOUT_wrapper( \
        KC_TILD, _______________HIGH_FUNC_LEFT______________, _______________HIGH_FUNC_RIGHT_____________, _______, \
        _______, _______________NUM_SYM_LEFT________________, _______________NUM_SYM_RIGHT_______________, _______, \
        _______, _______________SHFT_SYMB_LEFT______________, _______________SHFT_SYMB_RIGHT_____________, _______, \
        _______, ___________________BLANK___________________, ___________________BLANK___________________, _______  \
    ),
    /* Gaming layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │Bsp│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │SEs│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │SEn│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │LSP│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RSP│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │LCt│LGu│LAl│Fn1│Lwr│SBs│NvS│Ris│Fn2│RAl│RGu│RCt│
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [_GAME] = LAYOUT_wrapper( \
        KC_ESC,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC, \
        KC_LSFT, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_RSFT, \
        KC_TAB,  _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_ENT,  \
        KC_LCTL, KC_CAPS, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  NAV_SPC, RAISE,    KC_RALT, KC_RGUI, KC_APP, KC_RCTL  \
    ),
    /* DJMAX layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │Bsp│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │SEs│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │SEn│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │LSP│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RSP│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │LCt│LGu│LAl│Fn1│Lwr│SBs│NvS│Ris│Fn2│RAl│RGu│RCt│
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [_DJMAX] = LAYOUT_wrapper( \
        KC_LSFT, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_RSFT, \
        KC_ESC,  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_ENT,  \
        KC_TAB,  _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, L_DJMAX, \
        KC_SPC,  KC_PGDN, KC_1,    KC_2,   KC_Q,     KC_SPC,  KC_SPC,  KC_P,     KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT \
    ),
    /* Navigations layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │   │   │ ↑ │   │   │Hom│PgU│PgD│End│   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │   │ ← │ ↓ │ → │   │ ← │ ↓ │ ↑ │ → │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │Ct←│Ct↓│Ct↑│Ct→│   │   │
     * ├───┼───┼───┼───┼───┼───╆━━━╅───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   ┃NvS┃   │   │   │   │   │
     * └───┴───┴───┴───┴───┴───┺━━━┹───┴───┴───┴───┴───┘
     */
    [_NAV] = LAYOUT_wrapper( \
        _______, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX, _______, \
        _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CTL_LFT, CTL_DWN, CTL_UP,  CTL_RGT, XXXXXXX, _______, \
        _______, ___________________BLANK___________________, ___________________BLANK___________________, _______  \
    ),
    /* Function layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │QAp│QTb│   │Rfr│   │   │KP7│KP8│KP9│Psc│   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │PTb│NTb│PAp│NAp│Rdo│Udo│KP4│KP5│KP6│   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │App│Hnj│Han│Cap│   │   │KP1│KP2│KP3│Clr│   │
     * ├───┼───┼───╆━━━╅───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   ┃Fn1┃   │   │   │   │KP0│Nlc│   │   │
     * └───┴───┴───┺━━━┹───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [_FN1] = LAYOUT_wrapper( \
        _______, CLS_APP, CLS_TAB, XXXXXXX, REFRESH, RSTR_TB, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PSCR, _______, \
        _______, PRV_TAB, NXT_TAB, PRV_APP, NXT_APP, REDO,    UNDO,    KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX, _______, \
        _______, KC_APP,  HANJA,   KC_HAEN, KC_CAPS, XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, CLEAR,   _______, \
        _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_0, KC_NLCK, _______, _______  \
    ),
    /* Second Function layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │MWU│Ms2│MsU│Ms1│   │   │QAp│QTb│   │Rfs│Del│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │MWD│MsL│MsD│MsR│   │   │PTb│NTb│   │   │   │ 
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │Ms5│MWL│MWR│MS3│   │   │   │Cut│Cop│Pst│   │
     * ├───┼───┼───┼───┼───┼───┼───┼───╆━━━╅───┼───┼───┤
     * │   │   │   │   │   │Ms4│   │   ┃Fn2┃   │   │   │
     * └───┴───┴───┴───┴───┴───┴───┴───┺━━━┹───┴───┴───┘
     */
    [_FN2] = LAYOUT_wrapper( \
        _______, KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, XXXXXXX, XXXXXXX, CLS_APP, CLS_TAB, XXXXXXX, REFRESH, KC_DEL,  \
        _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, PRV_TAB, NXT_TAB, XXXXXXX, XXXXXXX, _______, \
        _______, KC_BTN5, KC_WH_L, KC_WH_R, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX, CUT,     COPY,    PASTE,   _______, \
        _______, _______, _______, XXXXXXX, XXXXXXX, KC_BTN4, ___________________NOOP____________________, _______  \
    ),
    /* Adjust layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │GME│DJM│Hu↑│Sa↑│Vr↑│Sp↑│Sp↓│LED│MAC│   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │RTg│RMd│Hu↓│Sa↓│Vr↓│Mu←│Ply│Mu→│WIN│Mak│   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │AuT│MuT│MuM│Sc↓│Sc↑│Mut│Vl↓│Vl↑│NKR│Rst│   │
     * ├───┼───┼───┼───╆━━━╅───┼───╆━━━╅───┼───┼───┼───┤
     * │   │   │   │   ┃Lwr┃   │   ┃Ris┃   │   │   │   │
     * └───┴───┴───┴───┺━━━┹───┴───┺━━━┹───┴───┴───┴───┘
     */
    [_ADJUST] = LAYOUT_wrapper( \
        XXXXXXX, L_GAME,  L_DJMAX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_SPD, LED_LVL, AG_SWAP, XXXXXXX, JEONGUK, \
        XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_MPRV, KC_MPLY, KC_MNXT, AG_NORM, MAKE,    XXXXXXX, \
        XXXXXXX, AU_TOG,  MU_TOG,  MU_MOD,  KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, TOG_NKR, RESET,   XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOWER,   XXXXXXX, XXXXXXX, RAISE,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
    ),
#ifdef AUDIO_ENABLE
    [_MUSIC] = LAYOUT_wrapper( \
        XXXXXXX, ___________________NOOP____________________, ___________________NOOP____________________, XXXXXXX,  \
        XXXXXXX, ___________________NOOP____________________, ___________________NOOP____________________, XXXXXXX, \
        XXXXXXX, ___________________NOOP____________________, ___________________NOOP____________________, XXXXXXX, \
        MUS_OFF, MU_MOD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___________________NOOP____________________, XXXXXXX  \
    )
#endif
    
};
