/* Copyright 2024 magdalipka
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

enum layers { _QWERTY, _SPECIAL, _NUMBERS, _FUNCTION, _GAME_QWERTY, _GAME_NUMBERS, _GAME_ARROWS };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_planck_mit(
      KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENT,
      KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_BSLS, KC_BSPC,
      KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RALT,
      KC_TAB, KC_LALT, _______, KC_LGUI, MO(_NUMBERS), KC_SPC, MO(_SPECIAL), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
      ),

    [_SPECIAL] = LAYOUT_planck_mit(
      _______, KC_PLUS, KC_EXLM, KC_AT,   KC_HASH, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, _______,
      _______, KC_MINS, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_QUOT, KC_DQUO, _______,
      _______, KC_TILD, KC_AMPR, KC_ASTR, KC_GRV,  XXXXXXX, XXXXXXX, KC_SCLN, KC_COLN, KC_UNDS, KC_EQL, KC_INS,
      _______, _______, _______, XXXXXXX, MO(_FUNCTION), _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
      ),

    [_NUMBERS] = LAYOUT_planck_mit(
      XXXXXXX, XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, XXXXXXX, KC_4, KC_5, KC_6, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
      _______, XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
      _______, _______, XXXXXXX, KC_0, _______, _______, MO(_FUNCTION), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
      ),

    [_FUNCTION] = LAYOUT_planck_mit(
      QK_BOOT, XXXXXXX, RGB_MOD, RGB_HUD, RGB_HUI, KC_BRID, KC_BRIU, XXXXXXX, KC_F1, KC_F2, KC_F3, XXXXXXX,
      DB_TOGG, BL_TOGG, BL_STEP, RGB_VAD, RGB_VAI, KC_VOLD, KC_VOLU, XXXXXXX, KC_F4, KC_F5, KC_F6, XXXXXXX,
      XXXXXXX, BL_DOWN, BL_UP  , RGB_SAD, RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX, KC_F7, KC_F8, KC_F9, XXXXXXX,
      XXXXXXX, RGB_SPD, RGB_SPI, XXXXXXX, XXXXXXX, RGB_TOG, XXXXXXX, KC_F10, KC_F11, KC_F12, TO(_GAME_QWERTY)
      ),

    [_GAME_QWERTY] = LAYOUT_planck_mit(
      KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
      KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_BSLS, KC_ENT,
      KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RALT,
      KC_TAB, KC_LALT, KC_CAPS_LOCK, MO(_GAME_ARROWS), MO(_GAME_NUMBERS), KC_SPC, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, TG(_GAME_QWERTY)
      ),

    [_GAME_NUMBERS] = LAYOUT_planck_mit(
      _______, KC_1, KC_2, KC_3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, KC_4, KC_5, KC_6, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, KC_7, KC_8, KC_9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, _______, KC_0, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX
      ),

    [_GAME_ARROWS] = LAYOUT_planck_mit(
      _______, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, _______, XXXXXXX, _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
      )

};

#ifdef RGB_MATRIX_ENABLE

__attribute__((weak)) RGB rgblight_hsv_to_rgb(HSV hsv) { return hsv_to_rgb(hsv); }

void set_white(uint8_t index) {
    HSV hsv = rgb_matrix_config.hsv;
    hsv.h   = 0;
    hsv.s   = 0;
    RGB rgb = rgblight_hsv_to_rgb(hsv);
    rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        set_white(41);
    }
    if (IS_LAYER_ON(_GAME_QWERTY)) {
        set_white(0);
    }
    if (IS_LAYER_ON(_NUMBERS) || IS_LAYER_ON(_GAME_NUMBERS)) {
        set_white(12);
    }
    if (IS_LAYER_ON(_SPECIAL) || IS_LAYER_ON(_GAME_ARROWS)) {
        set_white(24);
    }
    if (IS_LAYER_ON(_FUNCTION)) {
        set_white(12);
        set_white(24);
    }
    return false;
}

#endif
