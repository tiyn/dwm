# dwm

This is my patched version of dwm. The base version is directly from
suckless.org.
This belongs to my larbs installation script and depends heavily on its scripts
and programs.
It is supposed to work in the environment after the larbs-base-installation.
This is my patched version of dwm. The base version is directly from suckless.org.

## Patches

The list below shows the currently applied patches to the master branch.

- dwm-actualfullscreen-20191112-cb3f58a.diff (enables true fullscreen)
- dwm-bottomstack-20160719-56a31dc.diff (adds bottomstack and
bottomstackhorizontal layout)
- dwm-center-6.1.diff (adds ability to center floating windows at launch)
- dwm-deck-6.0.diff (adds deck layout)
- dwm-noborder-6.2.diff (removes border if there is only one window)
- dwm-pertag-20170513-ceac8c9.diff (allows having a layout/mwfact/barpos/nmaster
per tag)
- dwm-statuscmd-6.2.diff (enables dwmblocks compatibility)

## Hotkeys

There are various shortcuts and hotkeys used in this version. Included in my
build are the following.

| ModKey | Shift | Key | Function |
| ------ | ----- | --- | -------- |
| Super | Shift | Escape | Quit dwm |
| Super | Shift | b | Toggle dwmbar |
| Super | Shift | c | Enable deck(/card) layout |
| Super | Shift | d | Toggle floating/tiled for selected window |
| Super | Shift | f | Toggle fullscreen |
| Super | | h | (Tiling/Deck) Focus window higher in stack than current |
| Super | Shift | h | (Tiling/Deck) Make current window the master window |
| Super | | j | (Tiling/Deck) Focus window lower in stack than current |
| Super | Shift | j | (Tiling/Deck) Make current window the master window |
| Super | | k | (Tiling/Deck) Focus window higher in stack than current |
| Super | Shift | k | (Tiling/Deck) Make current window the master window |
| Super | | l | (Tiling/Deck) Focus window lower in stack than current |
| Super | Shift | m | Enable monocle layout |
| Super | Shift | o | (Tiling/Deck) Increase master window size |
| Super | | q | Close current window |
| Super | Shift | t | Enable tiling layout |
| Super | Shift | u | Enable bottomstack layout |
| Super | Shift | v | Enable bottomstackhorizontal layout |
| Super | Shift | z | (Tiling/Deck) Decrease master window size |
| Super | | 0 | Show all tags |
| Super | Shift | 0 | Add current window to all tag |
| Super | | 1/2/.../9 | Show tag 1/2/.../9 |
| Super | Shift | 1/2/.../9 | Add current window to tag 1/2/.../9 |
| Super | | . | Show monitor lower in stack |
| Super | Shift | . | Add to monitor lower in stack |
| Super | | , | Show monitor higher in stack |
| Super | Shift | , | Add to monitor higher in stack |
