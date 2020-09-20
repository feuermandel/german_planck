/* Feuermandel Keyboard Layout
 */
#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_german.h"
//#include "backlight.h"
#include "debug.h"
#include "version.h"

enum layers {
  _LAYER0,
  _LAYER1,
  _LAYER2,
  _LAYER3
};

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3



/*
// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
     {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
     {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
     {9, 2, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
     {11, 2, HSV_PURPLE}
                 );

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
     my_capslock_layer,
     my_layer1_layer,    // Overrides caps lock layer
     my_layer2_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
   // Both layers will light up if both kb layers are active
   rgblight_set_layer_state(1, layer_state_cmp(state, 1));
   rgblight_set_layer_state(2, layer_state_cmp(state, 2));
return state;
}
	    //
bool led_update_user(led_t led_state) {
   rgblight_set_layer_state(0, led_state.caps_lock);
   return true;
}

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_LAYER0] = { /* LAYER0
    * ,-----------------------------------------------------------------------.
    * | Esc | q   | w   | e   | r   | t   | z   | u   | i   | o   | p   | BS  |
    * |-----------------------------------------------------------------------|
    * | Tab | a   | s   | d   | f   | g   | h   | j   | k   | l   |  ß   |Ent |
    * |-----------------------------------------------------------------------|
    * |LSFT | y   | x   | c   | v   | b   | n   | m   |  ,  |  .  | Up  | Ent |
    * |-----------------------------------------------------------------------|
    * | LCTL| GUI | LALT |Lay1| TG1 |   Space   |TG2  |RATL |Left | Down|Right|
    * `-----------------------------------------------------------------------'
    */
  {KC_ESC,  KC_Q,    KC_W,   KC_E,    KC_R,  KC_T,  DE_Z,  KC_U,  KC_I,  KC_O,  KC_P, KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,   KC_D,    KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  DE_SS,  KC_ENT},
  {KC_LSHIFT,    DE_Y,    KC_X,   KC_C,    KC_V, KC_B, KC_N, KC_M, DE_COMM, DE_DOT,  KC_UP, KC_ENT},
  {KC_LCTL, KC_LGUI, KC_LALT, TO(1), MO(1), KC_SPACE, KC_NO, MO(2),  KC_ALGR, KC_LEFT, KC_DOWN,   KC_RGHT}
},

[_LAYER1] = { /* LAYER1
    * ,-----------------------------------------------------------------------.
    * | ESC | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 0   | BS  |
    * |-----------------------------------------------------------------------|
    * |  F1 | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |
    * |-----------------------------------------------------------------------|
    * |LSFT | ^°  | <>  |Print|Pause| -_  | # ' |+ *  | ` ´ | Ins | Pos1|PGup |
    * |-----------------------------------------------------------------------|
    * | LCTL| GUI | LALT|Lay2 | TG1 |   Space   |TG2  |RATL | Del | End |PGdwn|
    * `-----------------------------------------------------------------------'
    */
  {KC_ESC,  DE_1,  DE_2,   DE_3, DE_4, DE_5 ,DE_6, DE_7 ,DE_8,  DE_9 ,DE_0,   KC_BSPC},
  {KC_F1,  KC_F2,    KC_F3,   KC_F4,    KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12},
  {KC_LSHIFT, DE_CIRC,   DE_LABK,    KC_PSCR, KC_PAUSE, DE_MINS, DE_HASH, DE_PLUS, DE_ACUT,  KC_INS, KC_HOME, KC_PGUP},
  {KC_LCTL, KC_LGUI, KC_LALT, TO(2), MO(0), KC_SPACE, KC_NO, MO(2),  KC_ALGR, KC_DEL, KC_END,   KC_PGDN}
},

[_LAYER2] = { /* LAYER2
    * ,-----------------------------------------------------------------------.
    * | Esc | q   | w   | e   | r   | t   | z   | ü   | i   | ö   | p   |Pause|
    * |-----------------------------------------------------------------------|
    * | Tab | ä   | s   | d   | f   | g   | h   | j   | k   | l   |  ß  |Prnt |
    * |-----------------------------------------------------------------------|
    * |LSFT | y   | x   | c   | v   | b   | n   | m   |  ,  |  .  | Up  |RGui |
    * |-----------------------------------------------------------------------|
    * | LCTL| GUI | LALT |Lay1| TG1 |   Space   |TG2  |RATL |Left | Down|Right|
    * `-----------------------------------------------------------------------'
    */
  {KC_ESC,  KC_Q,    KC_W,   KC_E,    KC_R,  KC_T,  DE_Z,  DE_UE,  KC_I,  DE_OE,  KC_P, KC_PAUSE},
  {KC_TAB,  DE_AE,    KC_S,   KC_D,    KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  DE_SS,  KC_PSCR},
  {KC_LSHIFT,    DE_Y,    KC_X,   KC_C,    KC_V, KC_B, KC_N, KC_M, DE_COMM, DE_DOT,  KC_UP, KC_RGUI},
  {KC_LCTL, KC_LGUI, KC_LALT, TO(3), MO(1), KC_SPACE, KC_NO, MO(2),  KC_ALGR, KC_LEFT, KC_DOWN,   KC_RGHT}
},




[_LAYER3] = { /* LAYER3
    * ,--------------------------------------------------------------------------.
    * | ESC |RGBTG |RGB_FF|RGB_RW|HUE+ |HUE- |     |     |     |     | Vol+| BS  |
    * |--------------------------------------------------------------------------|
    * |     |      | SAD  | SAI  | VAD | VAI |PLAIN|BREAT|RAINW|SWIRL| Vol-|     |
    * |--------------------------------------------------------------------------|
    * | LSFT|BL_TG |BL_INC|BL_DEC|     | ASDN|ASUP |ASRP |ASON |ASOFF| Up  | Ent |
    * |--------------------------------------------------------------------------|
    * | LCTL| GUI  | LALT | Lay0 | TG1 |   Space   |TG2  |RATL |Left | Down|Right|
    * `--------------------------------------------------------------------------'
    */
  {KC_ESC, RGB_TOG,  RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD , KC_NO, KC_NO , KC_NO,  KC_NO ,KC__VOLUP,  KC_BSPC},
  {KC_NO,  KC_NO, RGB_SAD, RGB_SAI,  RGB_VAD, RGB_VAI,   RGB_M_P,  RGB_M_B, RGB_M_R  , RGB_M_SW,  KC__VOLDOWN,  KC_NO},
  {KC_LSHIFT, BL_TOGG,   BL_INC,   BL_DEC,   KC_NO, KC_ASDN, KC_ASUP, KC_ASRP, KC_ASON, KC_ASOFF, KC_UP, KC_ENT},
  {KC_LCTL, KC_LGUI, KC_LALT, TO(0), MO(0), KC_SPACE, KC_NO, MO(1),  KC_ALGR, KC_LEFT, KC_DOWN,   KC_RGHT}
},

};

//layer_state_t layer_state_set_user(layer_state_t state) {
//  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//}

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(2),              // to RAISE
    [2] = ACTION_LAYER_MOMENTARY(3),              // to LOWER
    [3] = ACTION_LAYER_TAP_KEY(4,KC_SPC),         // to Function
    [4] = ACTION_LAYER_TOGGLE(5),                 // toggle Gaming
    [5] = ACTION_MODS_TAP_KEY(KC_LSFT, KC_CAPS),  //Shift on press, Caps on tap
};

// changes underglow based on current layer
//#define RBG_VAL 120
layer_state_t layer_state_set_user(layer_state_t state) {
  switch(biton32(state)) {
  case _LAYER1:
    // green-ish
    rgblight_sethsv_noeeprom(223, 203, 73);
    break;
  case _LAYER2:
    // Red
    rgblight_sethsv_noeeprom(0, 255, 120);
    break;
  case _LAYER3:
    // Dark Blue
    rgblight_sethsv_noeeprom(255, 204, 229);
    break;
  default:
    // Default colors
    rgblight_sethsv_noeeprom(4, 25, 110);
    break;
  }
  return state;
}
