/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "print.h"
#include "rgb_matrix_map.h"


#define RGB_CREAM 0xff, 0xfd, 0xd0

enum layers {
    _BL = 0,
    _GL, // Gaming layer
    _PL, // Programming layer
    _FN, // function layer
};

#define D_MUTE RCS(KC_RCBR)
#define D_DEAF RCS(KC_LCBR)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [_BL] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_F14,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_GL] = LAYOUT(
        KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          D_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          D_DEAF,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    [_PL] = LAYOUT(
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP,
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_PGDN,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_END,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    [_FN] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,
        XXXXXXX, RGB_MOD, RGB_VAI, RGB_SPI, QK_BOOT, EE_CLR,  DB_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,           TO(_PL),
        XXXXXXX, RGB_RMOD,RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,           TO(_GL),
        RGB_TOG,          RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, TO(_BL),  TO(_BL),
        XXXXXXX, AG_SWAP, AG_NORM,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_GL),  XXXXXXX
    )
};
// clang-format on

uint8_t base_red = 0x00;
uint8_t base_grn = 0x00;
uint8_t base_blu = 0x00;
uint8_t base_sat = 0xff;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool color_changed = true;
    uint8_t current_layer = get_highest_layer(layer_state);

    if (current_layer == _FN && record->event.pressed) {
        // F10 is red, F11 is green, F12 is blue
        switch (keycode) {
            case KC_F10:
                base_red += 5;
                break;
            case KC_F11:
                base_grn += 5;
                break;
            case KC_F12:
                base_blu += 5;
                break;
            default:
                color_changed = false;
                break;
        }

        if (color_changed) {
            uprintf("Colors: 0x%x 0x%x 0x%x\n", base_red, base_grn, base_blu);
            return false;
        }
    }
    return true;
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    led_t led_state = host_keyboard_led_state();
    uint8_t current_layer = get_highest_layer(layer_state);

    // set entire layer to color
    rgb_matrix_set_color_all(base_red, base_grn, base_blu);

    switch (current_layer) {
        case _FN:
            rgb_matrix_set_color(LED_F10, base_red, 0, 0);
            rgb_matrix_set_color(LED_F11, 0, base_grn, 0);
            rgb_matrix_set_color(LED_F12, 0, 0, base_blu);
            rgb_matrix_set_color(LED_HOME, RGB_PURPLE);
            break;
        case _PL:
            rgb_matrix_set_color(LED_PGUP, RGB_PURPLE);
            break;
        case _GL:
            rgb_matrix_set_color(LED_PGDN, RGB_PURPLE);
            break;
        case _BL:
            rgb_matrix_set_color(LED_END, RGB_PURPLE);
            break;
        default:
            break;
    }

    // Caps Lock RGB setup
    if (led_state.caps_lock) {
        rgb_matrix_set_color(LED_DEL, RGB_RED);
    } else {
        rgb_matrix_set_color(LED_DEL, RGB_OFF);
    }

    return false;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BL] = { ENCODER_CCW_CW(RALT(KC_F14), RSFT(KC_F14)) }, 
    [_GL] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_PL] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_FN] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif
