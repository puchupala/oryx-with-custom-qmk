/**
 * @mainpage Kanade addons for keymaps generated by Oryx configurator
 *
 * Installation
 * ------------
 *
 * 1. Download keymap source from Oryx configurator.
 * 2. Copy the source to `keyboards/zsa/voyager/keymaps/kanade`.
 * 3. Add the following to `rules.mk`:
 *    ```
 *    KEY_OVERRIDE_ENABLE = yes
 *    CAPS_WORD_ENABLE = yes
 *    ```
 * 4. Add the following to `config.h`:
 *    ```
 *    #define CHORDAL_HOLD
 *    #define VOYAGER_USER_LEDS
 *    #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
 *    ```
 * 5. Add the following to `keymap.c`:
 *    ```
 *    #include "kanade.c"
 *    ```
 * 6. Make sure that layer-tap key in `delete_key_override` match the key in
 *    `keymap.c`.
 *
 */

///////////////////////////////////////////////////////////////////////////////
// Others
///////////////////////////////////////////////////////////////////////////////

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) return true;  // Bypass Achordion for thumb keys.
  return get_chordal_hold_default(tap_hold_record, other_record);
}

// Send `delete` when `left shift` + `backspace` are pressed.
// Note that `backspace` is a layer2 layer-tap key.
// Only apply to left shift to prevent accidental trigger when holding layer-tap key.
const key_override_t delete_key_override = ko_make_basic(MOD_BIT(KC_LSFT), LT(2, KC_BSPC), KC_DEL);

// This globally defines all key overrides to be used.
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

void caps_word_set_user(bool active) {
  if (active) {
    STATUS_LED_1(true);
    STATUS_LED_2(true);
    STATUS_LED_3(true);
    STATUS_LED_4(true);
  } else {
    STATUS_LED_1(false);
    STATUS_LED_2(false);
    STATUS_LED_3(false);
    STATUS_LED_4(false);
  }
}
