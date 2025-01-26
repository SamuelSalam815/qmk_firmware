#include QMK_KEYBOARD_H
#include "swapper.h"

enum keycodes{
    ALT_TAB = SAFE_RANGE,
    CTL_TAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(KC_Q, KC_W, KC_E, LT(2,KC_R), KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, LT(1,KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, LT(4,KC_ENT), LT(5,KC_SPC), OSM(MOD_LSFT), LT(3,KC_BSPC)),
	[1] = LAYOUT_split_3x5_2(KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_CIRC, KC_DLR, KC_LPRN, KC_RPRN, KC_PERC, KC_NO, KC_TRNS, KC_RCTL, KC_RALT, KC_RGUI, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_UNDS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT_split_3x5_2(KC_NO, KC_LT, KC_GT, KC_TRNS, KC_NO, KC_EXLM, KC_DQUO, KC_QUOT, KC_AT, KC_GRV, KC_NO, KC_LALT, KC_LCTL, KC_NO, KC_NO, KC_PLUS, KC_EQL, KC_MINS, KC_ASTR, KC_HASH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSLS, KC_PIPE, KC_AMPR, KC_TILD, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT_split_3x5_2(KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_NO, KC_RCTL, KC_RALT, KC_RGUI, KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[4] = LAYOUT_split_3x5_2(LGUI(KC_TAB), KC_NO, CTL_TAB, ALT_TAB, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_TAB, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, TO(6), KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_PSCR, KC_SCRL, KC_PAUS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[5] = LAYOUT_split_3x5_2(KC_NO, KC_F7, KC_F8, KC_F9, KC_F11, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F10, KC_NO, KC_NO, KC_RCTL, KC_RALT, KC_RGUI, KC_NO, KC_F4, KC_F5, KC_F6, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[6] = LAYOUT_split_3x5_2(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_H, KC_J, KC_K, KC_L, KC_NO, KC_LCTL, KC_NO, KC_NO, OSL(7), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, KC_SPC, TO(0), TO(0)),
	[7] = LAYOUT_split_3x5_2(KC_TAB, KC_7, KC_8, KC_9, TO(6), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_1, KC_2, KC_3, TO(6), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL, KC_4, KC_5, KC_6, TO(6), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, KC_0, TO(0), TO(0))
};

const uint16_t PROGMEM left_esc_combo[] = {LT(1,KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[] = {
    COMBO(left_esc_combo, KC_ESC),
    COMBO(del_combo, KC_DEL),
    COMBO(copy_combo, LCTL(KC_C)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
        case LGUI_T(KC_SCLN):
        case LT(5,KC_SPC):
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM arrow_keys[] = {KC_RIGHT, KC_LEFT, KC_DOWN, KC_UP};
const uint16_t PROGMEM arrow_keys_count = sizeof(arrow_keys) / sizeof(uint16_t);
struct swapper_keys alt_tab_swapper = {false, ALT_TAB, KC_LALT, KC_TAB, OSM(MOD_LSFT), arrow_keys, arrow_keys_count};
struct swapper_keys clt_tab_swapper = {false, CTL_TAB, KC_LCTL, KC_TAB, OSM(MOD_LSFT), arrow_keys, arrow_keys_count};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(keycode, record, &alt_tab_swapper);
    update_swapper(keycode, record, &clt_tab_swapper);
    return true;
}

