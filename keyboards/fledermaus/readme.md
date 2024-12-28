# fledermaus


![fledermaus](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Jeff Luetzenberg](https://github.com/jluetzenberg)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make fledermaus:default

Flashing example for this keyboard:

    make fledermaus:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available


## WIP Notes

### Step One
Step one, using only the default keymap and updated pin locations, we have it 'working'.
Specifically, I'm seeing the 'abcdefghij' text printed out. What's not working
is 0,1 and 2,1. Not sure why these keys aren't working; 1,1 works so it's not a
row-level issue. I'll have to review those switches internally, which is
unfortunate. Additionally, it is as I feared and the 'down' direction on the
switch is not connected. Not sure if I should try to salvage that or accept what
I have. Regardless, thanks to the issue with 0,1 and 2,1 I'm going to have to
open it back up.

Some notes though: left thumbs print CDE and right thumbs print FGH, as expected
since they're wired up to 3,{2,3,4,5,6,7}. The mouse switch works as expected as
well, with the pins connected such that the directions when looking at it are:
up (c0), right (c1), down (c2[broken]), left (c3), press (c4).

### Step Two
Add the cirque trackpad
