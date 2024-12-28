// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum keymap_layers {
     L_DVORAK = 0,
     L_QWERTY,
     L_MEDIA,
     L_NAV,
     L_MOUSE,
     L_SYM,
     L_NUM,
     L_FUN,
     _ART_BASE,
     _ART_NUM,
     _ART_CUS,
     _ART_PUNC,
     _ART_MOU,
     _ART_NAV,
     _ART_SYM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */


    [L_DVORAK] = LAYOUT_ortho_5x10(
  // ╭─────────────────────────────────────────────────────────────╮                 ╭───────────────────────────────────────────────────────────────────╮
           KC_QUOT,     KC_COMM,      KC_DOT,        KC_P,    KC_Y,                    KC_F,         KC_G,         KC_C,         KC_R,         KC_L,
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
      LGUI_T(KC_A), ALT_T(KC_O), CTL_T(KC_E), SFT_T(KC_U),    KC_I,                    KC_D, RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S),
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
           KC_SCLN,        KC_Q,        KC_J,        KC_K,    KC_X,                    KC_B,         KC_M,         KC_W,         KC_V,         KC_Z,
  // ╰─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────╯
XXXXXXX, XXXXXXX, LT(L_MEDIA, KC_ESC), LT(L_NAV, KC_SPC), LT(L_MOUSE, KC_TAB),   LT(L_SYM, KC_ENT), LT(L_NUM, KC_BSPC), LT(L_FUN, KC_DEL), XXXXXXX, XXXXXXX,
       MS_BTN3, MS_BTN1, XXXXXXX, MS_BTN2, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [L_QWERTY] = LAYOUT_ortho_5x10(
  // ╭─────────────────────────────────────────────────────────────╮                 ╭───────────────────────────────────────────────────────────────────╮
              KC_Q,        KC_W,        KC_E,        KC_R,    KC_T,                    KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
      LGUI_T(KC_A), ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F),    KC_G,                    KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
              KC_Z,        KC_X,        KC_C,        KC_V,    KC_B,                    KC_N,         KC_M,      KC_COMM,       KC_DOT,         KC_QUOT,
  // ╰─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────╯
XXXXXXX, XXXXXXX, LT(L_MEDIA, KC_ESC), LT(L_NAV, KC_SPC), LT(L_MOUSE, KC_TAB),   LT(L_SYM, KC_ENT), LT(L_NUM, KC_BSPC), LT(L_FUN, KC_DEL), XXXXXXX, XXXXXXX,
       MS_BTN3, MS_BTN1, XXXXXXX, MS_BTN2, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [L_MEDIA] = LAYOUT_ortho_5x10(
  // ╭─────────────────────────────────────────────────────────────╮                 ╭───────────────────────────────────────────────────────────────────╮
           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,                XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
           KC_LGUI,     KC_LALT,     KC_LCTL,     KC_LSFT, XXXXXXX,                 XXXXXXX,      KC_MRWD,      KC_VOLD,      KC_VOLU,      KC_MFFD,
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX,                 XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
  // ╰─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────╯
XXXXXXX, XXXXXXX,                _______,     XXXXXXX,     XXXXXXX,                 KC_MSTP,      KC_MPLY,      KC_MUTE,      XXXXXXX,      XXXXXXX,
       MS_BTN3, MS_BTN1, XXXXXXX, MS_BTN2, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [L_NAV] = LAYOUT_ortho_5x10(
  // ╭─────────────────────────────────────────────────────────────╮                 ╭───────────────────────────────────────────────────────────────────╮
           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,                XXXXXXX,      KC_PSTE,      KC_COPY,       KC_CUT,      KC_UNDO,
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
           KC_LGUI,     KC_LALT,     KC_LCTL,     KC_LSFT, XXXXXXX,                 KC_CAPS,      KC_LEFT,      KC_DOWN,        KC_UP,      KC_RGHT,
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX,                  KC_INS,      KC_HOME,      KC_PGDN,      KC_PGUP,       KC_END,
  // ╰─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────╯
XXXXXXX, XXXXXXX,                XXXXXXX,     _______,     XXXXXXX,                  KC_ENT,      KC_BSPC,       KC_DEL,      XXXXXXX,      XXXXXXX,
       MS_BTN3, MS_BTN1, XXXXXXX, MS_BTN2, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [L_MOUSE] = LAYOUT_ortho_5x10(
  // ╭─────────────────────────────────────────────────────────────╮                 ╭───────────────────────────────────────────────────────────────────╮
           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,                XXXXXXX,      MS_ACL0,      MS_ACL1,      MS_ACL2,      XXXXXXX,
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
           KC_LGUI,     KC_LALT,     KC_LCTL,     KC_LSFT, XXXXXXX,                 XXXXXXX,      MS_LEFT,      MS_DOWN,        MS_UP,      MS_RGHT,
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX,                 XXXXXXX,      MS_WHLL,      MS_WHLD,      MS_WHLU,       MS_WHLR,
  // ╰─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────╯
XXXXXXX, XXXXXXX,                XXXXXXX,     XXXXXXX,     _______,                 MS_BTN3,      MS_BTN1,      MS_BTN2,      XXXXXXX,       XXXXXXX,
       MS_BTN3, MS_BTN1, XXXXXXX, MS_BTN2, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [L_SYM] = LAYOUT_ortho_5x10(
  // ╭─────────────────────────────────────────────────────────────╮                 ╭───────────────────────────────────────────────────────────────────╮
           KC_LCBR,     KC_AMPR,     KC_ASTR,     KC_LPRN,  KC_RCBR,                XXXXXXX,      XXXXXXX,      XXXXXXX, DF(L_QWERTY), DF(L_DVORAK),
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
           KC_QUES,     KC_DLR ,     KC_PERC,     KC_CIRC, KC_PLUS,                 XXXXXXX,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
           KC_TILD,     KC_EXLM,       KC_AT,     KC_HASH, KC_PIPE,                 XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
  // ╰─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────╯
XXXXXXX, XXXXXXX,                    KC_LPRN,     KC_RPRN, KC_UNDS,                 _______,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
       MS_BTN3, MS_BTN1, XXXXXXX, MS_BTN2, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [L_NUM] = LAYOUT_ortho_5x10(
  // ╭─────────────────────────────────────────────────────────────╮                 ╭───────────────────────────────────────────────────────────────────╮
           KC_LBRC,        KC_7,        KC_8,        KC_9,  KC_RBRC,                XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
           KC_SLSH,        KC_4,        KC_5,        KC_6,  KC_EQL,                 XXXXXXX,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
            KC_GRV,        KC_1,        KC_2,        KC_3, KC_BSLS,                 XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
  // ╰─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────╯
XXXXXXX, XXXXXXX,                     KC_DOT,        KC_0, KC_MINS,                 XXXXXXX,      _______,      XXXXXXX,      XXXXXXX,       XXXXXXX,
       MS_BTN3, MS_BTN1, XXXXXXX, MS_BTN2, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [L_FUN] = LAYOUT_ortho_5x10(
  // ╭─────────────────────────────────────────────────────────────╮                 ╭───────────────────────────────────────────────────────────────────╮
            KC_F12,       KC_F7,       KC_F8,       KC_F9,  KC_PSCR,                XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
            KC_F11,       KC_F4,       KC_F5,       KC_F6, KC_SCRL,                 XXXXXXX,      KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,
  // ├─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────┤
            KC_F10,       KC_F1,       KC_F2,       KC_F3, KC_PAUS,                 XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
  // ╰─────────────────────────────────────────────────────────────┤                 ├───────────────────────────────────────────────────────────────────╯
XXXXXXX, XXXXXXX,                     KC_APP,      KC_SPC,  KC_TAB,                 XXXXXXX,      XXXXXXX,      _______,      XXXXXXX,       XXXXXXX,
       MS_BTN3, MS_BTN1, XXXXXXX, MS_BTN2, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )

};
