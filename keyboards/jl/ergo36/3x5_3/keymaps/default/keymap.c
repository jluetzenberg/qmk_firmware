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

/*
To get this to work, I used:
> pipx install qmk
> sudo zypper install arm-none-eabi-gcc
> sudo zypper install avr-gcc avrdude dfu-programmer dfu-util
> sudo zypper addrepo https://download.opensuse.org/repositories/CrossToolchain:avr/openSUSE_Tumbleweed/CrossToolchain:avr.repo
> sudo zypper refresh
> sudo zypper install cross-avr-gcc
> qmk setup -H ~/Projects/qmk_firmware
> sudo cp /home/jeff/Projects/qmk_firmware/util/udev/50-qmk.rules /etc/udev/rules.d/
    / error happens when I try to run > qmk compile -kb clueboard/66/rev3 -km default
    / error is that avr/pgmspace.h is not found
    / ////// gpt output: I found the file in /usr/lib64/gcc/avr/10.3.0/include/pgmspace.h
    / based on the above, I found that there wasn't an avr directory in gcc, so installing
> sudo zypper install avr-libc
    / same error present. going to just go for it on my controller
> qmk compile -kb jl/ergo36/3x5_3 -km default
    error: common/pico_base/include/pico/assert.h: assert.h: No such file or directory
    / based on what that seems to mean is that I'm missing essential c dev tools
> sudo zypper install -t pattern devel_basis
    / the exact same error shows up

    / Going to try the docker approach
> util/docker_build.sh planck/rev6:default
    / succeeded

    / docker build is working but the flashed firmware is not working
    / still getting the assert.h issue, so trying:
> sudo zypper install -t pattern devel_C_C++
    / but no luck. gpt advised
> sudo zypper install cross-avr-binutils cross-avr-gcc cross-avr-gcc-c++ cross-avr-libc
*/

enum dilemma_keymap_layers {
     L_QWERTY = 0,
     L_DVORAK,
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

#include "../../artseyio/aliases.c"
#include "../../artseyio/combos.c"

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
  //========================================================================================================================================
  // MIRYOKU SECTION
  // Layers used for primary two-handed Miryoku layout, in QWERTY and Dvorak flavors
  //========================================================================================================================================

  [L_QWERTY] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
              KC_Q,        KC_W,        KC_E,        KC_R,    KC_T,        KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
  // ├─────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
      LGUI_T(KC_A), ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F),    KC_G,        KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
  // ├─────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
              KC_Z,        KC_X,        KC_C,        KC_V,    KC_B,        KC_N,         KC_M,      KC_COMM,       KC_DOT,         KC_QUOT,
  // ╰─────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
       LT(L_MEDIA, KC_ESC), LT(L_NAV, KC_SPC), LT(L_MOUSE, KC_TAB),   LT(L_SYM, KC_ENT), LT(L_NUM, KC_BSPC), LT(L_FUN, KC_DEL),
  //  ╰────────────────────────────────────────────────────────────╯ ╰───────────────────────────────────────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT,  QK_BOOT
  ),

  [L_DVORAK] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
           KC_QUOT,     KC_COMM,      KC_DOT,        KC_P,    KC_Y,        KC_F,         KC_G,         KC_C,         KC_R,         KC_L,
  // ├─────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
      LGUI_T(KC_A), ALT_T(KC_O), CTL_T(KC_E), SFT_T(KC_U),    KC_I,        KC_D, RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S),
  // ├─────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
           KC_SCLN,        KC_Q,        KC_J,        KC_K,    KC_X,        KC_B,         KC_M,         KC_W,         KC_V,         KC_Z,
  // ╰─────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
       LT(L_MEDIA, KC_ESC), LT(L_NAV, KC_SPC), LT(L_MOUSE, KC_TAB),   LT(L_SYM, KC_ENT), LT(L_NUM, KC_BSPC), LT(L_FUN, KC_DEL),
  //  ╰────────────────────────────────────────────────────────────╯ ╰───────────────────────────────────────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [L_MEDIA] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, XXXXXXX, XXXXXXX,    KC_MSTP, KC_MPLY, KC_MUTE,
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),


  [L_NAV] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, _______, XXXXXXX,     KC_ENT, KC_BSPC, KC_DEL,
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [L_MOUSE] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, MS_ACL0, MS_ACL1, MS_ACL2, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, _______,    MS_BTN3, MS_BTN1, MS_BTN2,
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [L_SYM] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_QUES, KC_DLR , KC_PERC, KC_CIRC, KC_PLUS,    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_LPRN, KC_RPRN, KC_UNDS,    _______, XXXXXXX, XXXXXXX,
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),


  [L_NUM] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_SLSH,    KC_4,    KC_5,    KC_6,  KC_EQL,    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                          KC_DOT,    KC_0, KC_MINS,    XXXXXXX, _______, XXXXXXX,
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [L_FUN] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PSCR,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_SCRL,    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_PAUS,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                          KC_APP,  KC_SPC,  KC_TAB,    XXXXXXX, XXXXXXX, _______,
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  //========================================================================================================================================
  // ARTSEYIO SECTION
  // Layers used for one-handed layout
  //========================================================================================================================================

  [_ART_BASE] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       BASE_1_4, BASE_1_3, BASE_1_2, BASE_1_1, XXXXXXX,    XXXXXXX, BASE_1_1, BASE_1_2, BASE_1_3, BASE_1_4,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       BASE_2_4, BASE_2_3, BASE_2_2, BASE_2_1, XXXXXXX,    XXXXXXX, BASE_2_1, BASE_2_2, BASE_2_3, BASE_2_4,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [_ART_NUM] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       NUM_1_4, NUM_1_3, NUM_1_2, NUM_1_1, XXXXXXX,    XXXXXXX, NUM_1_1, NUM_1_2, NUM_1_3, NUM_1_4,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       NUM_2_4, NUM_2_3, NUM_2_2, NUM_2_1, XXXXXXX,    XXXXXXX, NUM_2_1, NUM_2_2, NUM_2_3, NUM_2_4,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [_ART_CUS] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       CUS_1_4, CUS_1_3, CUS_1_2, CUS_1_1, XXXXXXX,    XXXXXXX, CUS_1_1, CUS_1_2, CUS_1_3, CUS_1_4,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       CUS_2_4, CUS_2_3, CUS_2_2, CUS_2_1, XXXXXXX,    XXXXXXX, CUS_2_1, CUS_2_2, CUS_2_3, CUS_2_4,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [_ART_PUNC] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       PUNC_1_4,PUNC_1_3,PUNC_1_2,PUNC_1_1,XXXXXXX,    XXXXXXX, PUNC_1_1,PUNC_1_2,PUNC_1_3,PUNC_1_4,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       PUNC_2_4,PUNC_2_3,PUNC_2_2,PUNC_2_1,XXXXXXX,    XXXXXXX, PUNC_2_1,PUNC_2_2,PUNC_2_3,PUNC_2_4,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [_ART_MOU] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       MOU_1_4, MOU_1_3, MOU_1_2, MOU_1_1, XXXXXXX,    XXXXXXX, MOU_1_1, MOU_1_2, MOU_1_3, MOU_1_4,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       MOU_2_4, MOU_2_3, MOU_2_2, MOU_2_1, XXXXXXX,    XXXXXXX, MOU_2_1, MOU_2_2, MOU_2_3, MOU_2_4,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [_ART_NAV] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       NAV_1_4, NAV_1_3, NAV_1_2, NAV_1_1, XXXXXXX,    XXXXXXX, NAV_1_1, NAV_1_2, NAV_1_3, NAV_1_4,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       NAV_2_4, NAV_2_3, NAV_2_2, NAV_2_1, XXXXXXX,    XXXXXXX, NAV_2_1, NAV_2_2, NAV_2_3, NAV_2_4,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),

  [_ART_SYM] = LAYOUT_4x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       SYM_1_4, SYM_1_3, SYM_1_2, SYM_1_1, XXXXXXX,    XXXXXXX, SYM_1_1, SYM_1_2, SYM_1_3, SYM_1_4,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       SYM_2_4, SYM_2_3, SYM_2_2, SYM_2_1, XXXXXXX,    XXXXXXX, SYM_2_1, SYM_2_2, SYM_2_3, SYM_2_4,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
           KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT, QK_BOOT
  ),
};
// clang-format on
