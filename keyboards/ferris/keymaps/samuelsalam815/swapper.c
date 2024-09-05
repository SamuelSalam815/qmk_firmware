#include "swapper.h"
bool should_end_swapping(struct swapper_keys *swapper, const uint16_t keycode)
{
    if(!swapper->is_active){
        return false;
    }

    if(keycode == swapper->trigger_key || keycode == swapper->backmod_key){
        return false;
    }

    for(int i = 0; i < swapper->ignored_keys_count; i++){
        if(keycode == swapper->ignored_keys[i])
        {
            return false;
        }
    }

    return true;
}

void update_swapper(
    const uint16_t keycode,
    const keyrecord_t *record,
    struct swapper_keys *swapper)
{
    if (keycode == swapper->trigger_key) {
        if (record->event.pressed) {
            if (!swapper->is_active) {
                swapper->is_active = true;
                register_code(swapper->held_key);
            }
            register_code(swapper->switch_key);
        } else {
            unregister_code(swapper->switch_key);
            // Don't unregister held key until some other key is hit or released.
        }
    } else if (should_end_swapping(swapper, keycode)) {
        unregister_code(swapper->held_key);
        swapper->is_active = false;
    }
}
