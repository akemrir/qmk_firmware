/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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
#include "v60_type_r.h"

#define _____ KC_TRNS
#define XXXXX KC_NO
#define _DEF 0
#define _V60_FN 1
#define _RGB 2
#define _COLORS 3

enum unicode_name {
  GRIN, // grinning face 😊
  TJOY, // tears of joy 😂
  SMILE, // grining face with smiling eyes 😁
};

const uint32_t PROGMEM unicode_map[] = {
  [GRIN] = 0x1F600,
  [TJOY] = 0x1F602,
  [SMILE] = 0x1F601,
};

/* UNICODEMAP_ENABLE */
/* X(SMILE) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Default Layer
   * ,-----------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   Bs  |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |FN0   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |
   * |-----------------------------------------------------------|
   * |LShift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RShift   |
   * |-----------------------------------------------------------|
   * |Ctrl|Alt |Gui |      Space/L3           |Gui |Alt |Ctrl|Fn1|
   * `-----------------------------------------------------------'
   */

  [_DEF] = LAYOUT_60_ansi(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
      LT(_RGB, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,   \
      KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,                                      KC_RALT,   MO(_V60_FN), LT(_COLORS, KC_APP),  KC_RCTL \
      ),

  /* Keymap 1: FN Layer
   * ,-----------------------------------------------------------.
   * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |PSc|SLk|Pau| Ins |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   | Lt| Dn| Up| Rt|Hom|PgU|        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |Mut|VDn|VUp|End|PgD|          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  /* standardowa V60 typ R */
  [_V60_FN] = LAYOUT_60_ansi(
      KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL, \
      _____,   _____,  KC_UP, RGB_MOD,    RGB_RI,  RGB_GI,  RGB_BI,  _____, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,    _____,          KC_INS, \
      _____,   KC_LEFT,  KC_DOWN,  KC_RIGHT, RGB_RD,  RGB_GD,  RGB_BD,   _____, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,          _____,          \
      _____,   BL_INC,  BL_BRTG,  BL_DEC,  KC_MPLY,  KC_VOLD,  KC_VOLU, KC_MUTE, KC_END,  KC_PGDN,  KC_DOWN,           _____,  \
      _____,   RGB_VAI,  RGB_VAD,            _____,                                                           _____,  _____, _____, _____),
  /* Keymap 3: LED Modification Layer
   * ,-----------------------------------------------------------.
   * |   |BLT|BLC|UGT|UGP|UGB|UGR|   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |     |RD+|GN+|BL+|HU+|SA+|VA+|   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |RD-|GN-|BL-|HU-|SA-|VA-|   |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [_RGB] = LAYOUT_60_ansi(
      _____,  BL_TOGG, BL_STEP, RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R,  _____,   _____,   _____,   _____,   _____, _____, _____, \
      _____,  RGB_RI,  RGB_GI,  RGB_BI,  RGB_HUI, RGB_SAI, RGB_VAI,  _____,   _____,   _____,   _____,   _____,   _____, _____, \
      _____,  RGB_RD,  RGB_GD,  RGB_BD,  RGB_HUD, RGB_SAD, RGB_VAD,  _____,   _____,   _____,   _____,   _____,  KC_MPRV, \
      _____,  _____,   _____,  _____,  KC_MPLY, KC_VOLD, KC_VOLU,  KC_MUTE,   KC_MPRV,   KC_MNXT,   _____,   KC_MNXT, \
      _____,   _____,   _____,               _____,                                                      _____,   _____,  _____,  _____  \
      ),

  /* [_DEF] = LAYOUT_60_ansi( */
  /*     KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL, \ */
  /*     KC_TRNS,   KC_TRNS,  KC_UP, RGB_MOD,    RGB_RI,  RGB_GI,  RGB_BI,  KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,    KC_TRNS,          KC_INS, \ */
  /*     KC_TRNS,   KC_LEFT,  KC_DOWN,  KC_RIGHT, RGB_RD,  RGB_GD,  RGB_BD,   KC_TRNS, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,          KC_TRNS,          \ */
  /*     KC_TRNS,   BL_DEC,  BL_TOGG,  BL_DEC,  BL_BRTG,  KC_VOLD,   KC_VOLU, KC_MUTE, KC_END,  KC_PGDN,  KC_DOWN,           KC_TRNS,  \ */
  /*     KC_TRNS,   KC_TRNS,  KC_TRNS,            KC_TRNS,                                                           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS */
  /*     ), */

  [_COLORS] = LAYOUT_60_ansi(
      _____,  KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18,  KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23, KC_F24, _____, \
      _____,  _____,  _____,  _____,  _____, _____, _____,  _____,   _____,   _____,   _____,   _____,   _____, _____, \
      _____,  _____,  _____,  _____,  _____, _____, _____,  _____,   _____,   _____,   _____,   _____,  _____, \
      _____,  _____,   _____,  _____,  _____, _____, _____,  _____,   _____,   _____,   _____,   _____, \
      _____,   _____,   _____,               _____,                                                      _____,   _____,  _____,  _____  \
      ),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};


void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    // output low
    DDRE  |=  (1<<PE6);
    PORTE &= ~(1<<PE6);
  }
  else {
    // Hi-Z
    DDRE  &= ~(1<<PE6);
    PORTE &= ~(1<<PE6);
  }
}

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   switch(keycode) { */
/*     case BUTTER: */
/*       if (record->event.pressed) { */
/*         rgblight_sethsv(55, 100, 100); */
/*       } */
/*       return false; */
/*     case CHOCOLATE: */
/*       if (record->event.pressed) { */
/*         rgblight_setrgb(233, 185, 110); */
/*       } */

/*       return false; */
/*   } */
/*   return true; */
/* } */

/* bool CTRLDOWN = false; */
/* bool WINDOWN = false; */
/* bool SHIFTDOWN = false; */
/* void matrix_scan_user(void) { */
/*   uint8_t layer = biton32(layer_state); */

/*   switch (layer) { */
/*     case 0: */
/*       rgblight_setrgb(0,240, 255); */
/*       break; */
/*     case 1: */
/*       rgblight_setrgb(0,255, 100); */
/*       break; */
/*     case 2: */
/*       rgblight_setrgb(10,255, 0); */
/*       break; */
/*     case 3: */
/*       rgblight_setrgb(255,0, 85); */
/*       break; */
/*     case 4: */
/*       rgblight_setrgb(240,255, 0); */
/*       break; */
/*     default: */
/*       // none */
/*       break; */
/*   } */
/*   if ( SHIFTDOWN) { */
/*     rgblight_setrgb(255,255, 255); */
/*   } */
/*   if ( CTRLDOWN) { */
/*     rgblight_setrgb(240,255, 0); */
/*   } */
/*   if ( WINDOWN) { */
/*     rgblight_setrgb(255,255, 255); */
/*   } */
/* }; */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*     case KC_LGUI: */
/*       if (record->event.pressed) { */
/*         WINDOWN = true; */
/*         } else { */
/*         WINDOWN = false; */
/*       } */
/*       return true; */
/*     case LGUI_T(KC_ENT): */
/*       if (record->event.pressed) { */
/*         WINDOWN = true; */
/*         } else { */
/*         WINDOWN = false; */
/*       } */
/*       return true; */
/*     case CTL_T(KC_ESC): */
/*       if (record->event.pressed) { */
/*         CTRLDOWN = true; */
/*         } else { */
/*         CTRLDOWN = false; */
/*       } */
/*       return true; */
/*     case KC_LSFT: */
/*       if (record->event.pressed) { */
/*         SHIFTDOWN = true; */
/*         } else { */
/*         SHIFTDOWN = false; */
/*       } */
/*       return true; */
/*     case KC_RSFT: */
/*       if (record->event.pressed) { */
/*         SHIFTDOWN = true; */
/*         } else { */
/*         SHIFTDOWN = false; */
/*       } */
/*       return true; */
/*     default: */
/*       return true; // Process all other keycodes normally */
/*   } */
/* }; */

