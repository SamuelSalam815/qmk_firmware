#pragma once

#include QMK_KEYBOARD_H

// Implements cmd-tab like behaviour on a single key. On first tap of trigger
// cmdish is held and tabish is tapped -- cmdish then remains held until some
// other key is hit or released. For example:
//
//     trigger, trigger, a -> cmd down, tab, tab, cmd up, a
//     nav down, trigger, nav up -> nav down, cmd down, tab, cmd up, nav up
//
// This behaviour is useful for more than just cmd-tab, hence: cmdish, tabish.
//
// backmod is inteded for a key that is used for inverting the behavior
// e.g. alt-shift-tab switches tabs in the opposite direction to alt-tab so the backmod is shift.
void update_swapper(
    bool *active,
    const uint16_t cmdish,
    const uint16_t tabish,
    const uint16_t trigger,
    const uint16_t keycode,
    const keyrecord_t *record,
    const uint16_t backmod,
    const uint16_t *ignore_keys,
    const uint16_t ignore_keys_len
);
