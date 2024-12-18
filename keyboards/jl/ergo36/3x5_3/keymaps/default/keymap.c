/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum dilemma_keymap_layers {
    LAYER_QWERTY = 0,
    LAYER_DVORAK,
};

#define NAV QK_TRI_LAYER_LOWER
#define SYM QK_TRI_LAYER_UPPER

/*
// Auto Correct
AC_ON - auto correct on
AC_OFF - auto correct on
AC_TOGG - auto correct toggle
// Dynamic Macro
DM_REC1	Start recording Macro 1
DM_REC2	Start recording Macro 2
DM_PLY1	Replay Macro 1
DM_PLY2	Replay Macro 2
DM_RSTP	Finish the macro that is currently being recorded.
*/

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_LCTL,     NAV, KC_LGUI,     KC_SPC,     SYM,    KC_A
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),

  [LAYER_DVORAK] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,       KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_O,    KC_E,    KC_U,    KC_U,       KC_D,    KC_H,    KC_T,    KC_N,    KC_S, //TODO: hold-tap mod keys
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,       KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_LCTL,     NAV, KC_LGUI,     KC_SPC,     SYM,    KC_A, //TODO: proper thumb commands
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, QK_BOOT
  ),

  [LAYER_NAV] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,    XXXXXXX, KC_HOME,   KC_UP,  KC_END,  KC_DEL,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_VOLD,    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       QK_BOOT, EE_CLR, KC_MPRV, KC_MNXT, KC_MPLY,    XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX,  KC_ENT,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, _______, KC_LSFT,     KC_SPC, _______, KC_ESC
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),

  [LAYER_SYM] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_ESC, KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD,    KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC,  KC_GRV,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_MINS, KC_ASTR,  KC_EQL, KC_UNDS,  KC_DLR,    KC_HASH, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_PLUS, KC_PIPE,   KC_AT, KC_SLSH, KC_PERC,    KC_SCLN, KC_BSLS, KC_AMPR, KC_QUES, KC_EXLM,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                          KC_ESC, _______, KC_LSFT,     KC_SPC, _______, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),

  [LAYER_NUM] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,   KC_0,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  KC_F11,     KC_F12, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, _______, KC_LSFT,     KC_SPC, _______, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),
};
// clang-format on
