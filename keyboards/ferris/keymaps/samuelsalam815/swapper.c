#include "swapper.h"
bool contains(const uint16_t *arr, const uint16_t len, const uint16_t target)
{
    if(len == 0)
    {
        return false;
    }

    for(int i = 0; i < len; i++)
    {
        if(arr[i] == target)
        {
            return true;
        }
    }

    return false;
}
void update_swapper(
    bool *active,
    const uint16_t cmdish,
    const uint16_t tabish,
    const uint16_t trigger,
    const uint16_t keycode,
    const keyrecord_t *record,
    const uint16_t backmod,
    const uint16_t *ignore_keys,
    const uint16_t ignore_keys_len)
{
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (*active && keycode != backmod && !contains(ignore_keys, ignore_keys_len, keycode)) {
        unregister_code(cmdish);
        *active = false;
    }
}
