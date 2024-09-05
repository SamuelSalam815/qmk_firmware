#pragma once

#include QMK_KEYBOARD_H

// Stores keys for a general 'alt-tab' behavior. For example can be used for 'ctrl-tab' also.
struct swapper_keys{
    // Whether the swapping mechnaism is active
    bool is_active;

    // The key code which can be pressed to activate swapping mechanism.
    // The intention is to repeatedly press this key instead of having to hold a key down.
    const uint16_t trigger_key;

    // The key code to hold down while swapping. For 'alt-tab' it is the 'alt' key code.
    const uint16_t held_key;

    // The key code used to perform the swap. For 'alt-tab' it is the 'tab' key code.
    const uint16_t switch_key;

    // The key code which can be held so that the switch goes backwards. For 'alt-tab' it is the 'shift' key code.
    const uint16_t backmod_key;
    
    // An array of key codes which should be ignored for the purposes disabling the swapping mechanism.
    // The intention is to allow keys like the arrow keys to navigate whithout having to hold down a separate key.
    const uint16_t *ignored_keys;

    // The number of key codes in the array of key codes to ignore.
    const uint16_t ignored_keys_count;
};

// Implements ctrl-tab like behaviour on a single key. 
// On first tap of the trigger key the 'held key' is held and the 'switch key' is tapped.
// The 'held key' then remains held until some other, non-ignored key is pressed or released. 
//
// This behaviour is useful for more than just ctrl-tab, 
// so a different swapper for each swap-like key combo can be used - for example for alt-tab.
void update_swapper(
    const uint16_t keycode,
    const keyrecord_t *record,
    struct swapper_keys *swapper
);