#include "bitwise-combo.h"

bool process_bitwise_combo(
    uint16_t keycode,
    keyrecord_t *record,
    int8_t *num_pressed_keys,
    uint8_t *output_index_accumulator,
    const uint16_t* combo_keys,
    const uint16_t num_combo_keys,
    const uint16_t* output_keys,
    const uint16_t num_output_keys) {
  int index = -1;
  for (int i = 0; i < num_combo_keys; ++i) {
    if (keycode == combo_keys[i]) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    return true;
  }

  if (record->event.pressed) {
    (*num_pressed_keys)++;
    *output_index_accumulator |= (1 << index);
    return false;
  }

  (*num_pressed_keys)--;
  if (*num_pressed_keys > 0){
    return false;
  }

  *num_pressed_keys = 0;
  if (*output_index_accumulator <= num_output_keys) {
    tap_code(output_keys[(*output_index_accumulator) - 1]);
  }

  *output_index_accumulator = 0;

  return false;
}
