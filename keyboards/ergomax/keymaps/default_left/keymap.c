/* Copyright 2018-2019 LouWii
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _UP 1

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

#define LUP_TG TG(_UP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT( /* Base */
               KC_ESC,  KC_F2,   KC_F3,   KC_F4, KC_F5, KC_F6,               \
    KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,  KC_5,  KC_LBRACKET,         \
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,  LUP_TG,              \
    KC_CAPS,   KC_A,    KC_S,    KC_D,    KC_F,  KC_G,                       \
    KC_LSHIFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,  KC_NO,               \
    KC_NO,     KC_LGUI, KC_LALT, KC_NO,   KC_LCTRL,                          \
                                                        KC_NO,    KC_NO,     \
                                              KC_BSPC,  KC_DEL,   KC_PGUP,   \
                                                                  KC_PGDOWN  \
  ),
  [_UP] = LAYOUT(
               KC_F1,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,           \
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         \
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LUP_TG,          \
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                  \
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         \
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           \
                                                       KC_TRNS,   KC_TRNS,   \
                                              KC_TRNS, KC_TRNS,   KC_TRNS,   \
                                                                  KC_TRNS    \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
