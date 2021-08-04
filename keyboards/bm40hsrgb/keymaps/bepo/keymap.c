/* Copyright 2020 tominabox1
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
#include "keymap_bepo.h"

enum layers {
  _BEPO,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Bépo
 * ,-----------------------------------------------------------------------------------------------.
 * |       Esc |   B  |   É  |   P  |   O  |   È  |   ˰  |   V  |   D  |   L  |   J  | Bksp        |
 * |-----------+------+------+------+------+------+------+------+------+------+------+-------------|
 * |         W |   A  |   U  |   I  |   E  |   ,  |   C  |   T  |   S  |   R  |   N  |  M          |
 * |-----------+------+------+------+------+------+------+------+------+------+------+-------------|
 * | Shift/Tab |   Z  |   Y  |   X  |   .  |   K  |   ’  |   Q  |   G  |   H  |   F  | Shift/Enter |
 * |-----------+------+------+------+------+------+------+------+------+------+------+-------------|
 * |  Ctrl / ( | GUI  | Alt  |  À   |Lower |    Space    |Raise |   Ç  | AltGr|  GUI | Ctrl / )    |
 * `-----------------------------------------------------------------------------------------------'
 */
[_BEPO] = LAYOUT_planck_mit(
    KC_ESC,                BP_B,    BP_EACU,    BP_P,    BP_O,    BP_EGRV,    BP_DCIR,    BP_V,    BP_D,    BP_L,    BP_J,    KC_BSPC,
    BP_W,                  BP_A,    BP_U,       BP_I,    BP_E,    BP_COMM,    BP_C,       BP_T,    BP_S,    BP_R,    BP_N,    BP_M,
    LSFT_T(KC_TAB),        BP_Z,    BP_Y,       BP_X,    BP_DOT,  BP_K,       BP_QUOT,    BP_Q,    BP_G,    BP_H,    BP_F,    KC_SFTENT,
    MT(MOD_LCTL, BP_LPRN), KC_LGUI, KC_LALT,    BP_AGRV, LOWER,         KC_SPC,           RAISE,   BP_CCED, KC_RALT, KC_RGUI, MT(MOD_RCTL, BP_RPRN)
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   $  |   "  |   «  |   »  |   (  |   )  |   @  |   +  |   -  |   /  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  <   |  >   |  [   |  ]   |      |   =  |   %  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  {   |  }   |      |      |      | PgUp |  Up  | PgDn |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    BP_DLR,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN, BP_AT,   BP_PLUS,    BP_MINS,    BP_SLSH, BP_ASTR, _______,
    _______, _______, BP_LABK, BP_RABK, BP_LBRC, BP_RBRC, _______, BP_EQL,     BP_PERC,    _______, _______, _______,
    _______, _______, _______, _______, BP_LCBR, BP_RCBR, _______, _______,    _______,    KC_PGUP, KC_UP,   KC_PGDOWN,
    _______, _______, _______, _______, _______,     _______,      _______,    KC_MNXT,    KC_LEFT, KC_DOWN, KC_RGHT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    BP_HASH,  BP_1,    BP_2,    BP_3,    BP_4,    BP_5,    BP_6,    BP_7,    BP_8,    BP_9,    BP_0,    KC_DEL,
    _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______,  _______, _______, _______,
    _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void rgb_matrix_indicators_user(void) {

    //layer indicators

    if(IS_LAYER_ON(_LOWER)) {
        rgb_matrix_set_color_all(0, 0, 255);
    }

    if(IS_LAYER_ON(_RAISE)) {
        // rgb_matrix_set_color(39, 50, 10, 20); //index, r, g, b
        rgb_matrix_set_color_all(255, 0, 0);
    }

}

