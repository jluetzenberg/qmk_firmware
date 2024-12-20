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
     L_QWERTY = 0,
     L_DVORAK,
     L_MEDIA,
     L_NAV,
     L_MOUSE,
     L_SYM,
     L_NUM,
     L_FUN
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
// Layer Switching
DF(layer) - Set the base layer until the keyboard loses power
PDF(layer) - Set the base layer in EEPROM
OSL(layer) - Momentarily switch to a different layer until a key is pressed
LT(layer, kc) - turn on layer when held, kc when tapped
// leader
QK_LEAD - begins a leader sequence
// Mouse Keys
MS_UP - mouse up
MS_DOWN - mouse down
MS_LEFT - mouse left
MS_RGHT - mouse right
MS_BTN1-8 - mouse button 1-8
MS_WHLU - mouse wheel up
MS_WHLD - mouse wheel down
MS_WHLL - mouse wheel left
MS_WHLR - mouse wheel right
MS_ACL0 - mouse acceleration 0
MS_ACL1 - mouse acceleration 1
MS_ACL2 - mouse acceleration 2
// MOod-Tap key
MT(mod, kc) - mod when held, kc when tapped
LGUI_T(kc) - left gui when held, kc when tapped
CTL_T(kc) - left control when held, kc when tapped. Preface with 'R' for right control
SFT_T(kc) - left shift when held, kc when tapped
ALT_T(kc) - left alt when held, kc when tapped
// Repeat
QK_REP - repeat the last pressed key
QK_AREP - perform alternate of the last key
*/

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_QWERTY] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
              KC_Q,        KC_W,        KC_E,        KC_R,    KC_T,        KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
  // ├─────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
      LGUI_T(KC_A), ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F),    KC_G,        KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), //TODO: hold-tap mod keys
  // ├─────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
              KC_Z,        KC_X,        KC_C,        KC_V,    KC_B,        KC_N,         KC_M,      KC_COMM,       KC_DOT,         KC_QUOT,
  // ╰─────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
       LT(L_MEDIA, KC_ESC), LT(L_NAV, KC_SPC), LT(L_MOUSE, KC_TAB),   LT(L_SYM, KC_ENT), LT(L_NUM, KC_BSPC), LT(L_FUN, KC_DEL), 
  //  ╰────────────────────────────────────────────────────────────╯ ╰───────────────────────────────────────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [L_DVORAK] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
           KC_QUOT,     KC_COMM,      KC_DOT,        KC_P,    KC_Y,        KC_F,         KC_G,         KC_C,         KC_R,         KC_L,
  // ├─────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
      LGUI_T(KC_A), ALT_T(KC_O), CTL_T(KC_E), SFT_T(KC_U),    KC_I,        KC_D, RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S), //TODO: hold-tap mod keys
  // ├─────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
           KC_SCLN,        KC_Q,        KC_J,        KC_K,    KC_X,        KC_B,         KC_M,         KC_W,         KC_V,         KC_Z,
  // ╰─────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
       LT(L_MEDIA, KC_ESC), LT(L_NAV, KC_SPC), LT(L_MOUSE, KC_TAB),   LT(L_SYM, KC_ENT), LT(L_NUM, KC_BSPC), LT(L_FUN, KC_DEL), 
  //  ╰────────────────────────────────────────────────────────────╯ ╰───────────────────────────────────────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [L_MEDIA] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, XXXXXXX, XXXXXXX,    KC_MSTP, KC_MPLY, KC_MUTE
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),


  [L_NAV] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, _______, XXXXXXX,     KC_ENT, KC_BSPC, KC_DEL
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [L_MOUSE] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, MS_ACL0, MS_ACL1, MS_ACL2, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, _______,    MS_BTN3, MS_BTN1, MS_BTN2
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [L_SYM] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    _______, XXXXXXX, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),



  [L_BLANK] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
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
