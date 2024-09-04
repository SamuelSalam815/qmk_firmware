#pragma once

#include "quantum.h"

// Returns whether to continue processing the current key press
//     This method uses the key presses of the combo keys as a binary representation.
//     For example if the first and third combo keys are press and held, then this is treated as 1 + 4 = 5.
//     
//     When all the combo keys are released, the number produced is used as an index 
//     into the output keys. The output key that gets looked up will be sent as a tap.
bool process_bitwise_combo(
    uint16_t keycode,
    keyrecord_t *record,
    int8_t *num_pressed_keys,
    uint8_t *output_index_accumulator,
    const uint16_t *combo_keys,
    const uint16_t num_combo_keys,
    const uint16_t *output_keys,
    const uint16_t num_output_keys);
