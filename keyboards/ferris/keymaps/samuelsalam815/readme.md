# Configuration Workflow

## Visually updating the keymap

1. Go to the [online qmk configurator](https://config.qmk.fm/)
2. Upload `intermediate_keymap.json`
3. Perform required edits using GUI

Make sure to remove the `ferris_sweep_` prefix from the 'KEYMAP NAME', otherwise `ferris_sweep` will be duplicated when the intermediate keymap is downloaded

4. Download updated config
5. Convert the JSON file to a c file that can flash the keyboard

run the following from the QMK MSYS terminal in the current directory
```bash
qmk json2c intermediate_keymap.json -o temp.c
```

6. Copy paste the contents of the `keymaps` array from the temporary file to `keymap.c`
7. Delete `temp.c`
8. Compile and flash with new firmware

Compile and then flash the right-hand keyboard by running the following from the QMK MSYS terminal in the current directory

```bash
qmk flash -bl uf2-split-right -e CONVERT_TO=elite_pi
```

The controller must be put into boot mode for this command to automatically flash it with the new firmware.
- a typical key map has a dedicated key for this, check the visual aids 
- If the current mapping doesn't have a reset key, then check firmware documentation for the magic boot mode.

## Updating the visual aids

The visual aids are created using <https://keyboard-layout-editor.com/>

Prefer using the browser developer tools to screen capture the html node instead of the ui to export to png.
- the UI button can produce images that do not appear as displayed in the browser

The visual aids are `.png` files and their text format are named `*-visual.json`
- `ferris-sweep-layout-visual.json` for the main key map
- `ferris-sweep-gaming-layout-visual.json` for the gaming layer

A separate aid exists for the gaming layer because the main key map visual aid would become too cluttered.

# See Also
Firmware Flashing documentation:
- for [choc-only form factor](https://github.com/keyboard-magpie/qmk_firmware/tree/mbuk-ferris/keyboards/ferris/sweep_choc_mbuk)
- for [choc/mx form factor](https://github.com/keyboard-magpie/qmk_firmware/tree/mbuk-ferris/keyboards/ferris/sweep_mx_mbuk)
