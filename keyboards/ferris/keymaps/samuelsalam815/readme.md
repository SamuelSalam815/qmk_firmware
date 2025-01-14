# Configuration Workflow

## Visually updating the keymap

1. Go to the [online qmk configurator](https://config.qmk.fm/)
2. Upload `ferris_sweep_intermediate_keymap.json`
3. Perform required edits using GUI
4. Download updated config

Edit the `keymap` field to not include a duplicate instance of `ferris_sweep` at the start

5. Convert the json file to a c file that can flash the keyboard

run the following from the QMK MSYS terminal in the current directory
```bash
qmk json2c ferris_sweep_intermediate_keymap.json -o temp.c
```

6. Copy paste the contents of the `keymaps` array from the temporary file to `keymap.c`

7. Delete `temp.c`

8. Compile and flash with new firmware

flash the right-hand keyboard by running the following from the QMK MSYS terminal in the current directory

```bash
qmk flash -bl uf2-split-right -e CONVERT_TO=elite_pi
```

# See Also
Firmware Flashing documentation:
- for [choc-only form factor](https://github.com/keyboard-magpie/qmk_firmware/tree/mbuk-ferris/keyboards/ferris/sweep_choc_mbuk)
- for [choc/mx form factor](https://github.com/keyboard-magpie/qmk_firmware/tree/mbuk-ferris/keyboards/ferris/sweep_mx_mbuk)
