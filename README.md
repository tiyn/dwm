# dwm
This is my patched version of dwm. The base version is directly from suckless.org.
This belongs to my larbs installation script and depends heavily on its scripts and programs.
It is supposed to work in the environment after the larbs-base-installation.

## Patches
The list below shows the currently applied patches to the master branch.
- dwm-actualfullscreen-20191112-cb3f58a.diff (enables true fullscreen)
- dwm-alpha-6.2.diff (adds transparency)
- dwm-center-6.1.diff (adds ability to center floating windows at launch)
- dwm-deck-6.0.diff (adds deck layout)
- dwm-noborder-6.2.diff (removes border if there is only one window)
- dwm-pertag-20170513-ceac8c9.diff (allows having a layout/mwfact/barpos/nmaster per tag)

## Hotkeys
There are various shortcuts and hotkeys used in this version. Included in my build are the following.
| ModKey | Shift | Key               | Function                                                  |
| ------ | ----- | ----------------- | --------------------------------------------------------- |
| Super  | Shift | Escape            | Quit dwm                                                  |
| Super  |       | Return            | Spawn st                                                  |
| Super  |       | b                 | Spawn firefox                                             |
| Super  | Shift | b                 | Toggle dwmbar                                             |
| Super  | Shift | c                 | Enable deck(/card) layout                                 |
| Super  | Shift | d                 | Toggle floating/tiled for selected window                 |
| Super  |       | f                 | Spawn vifm in st                                          |
| Super  | Shift | f                 | Toggle fullscreen                                         |
| Super  |       | h                 | (Tiling/Deck) Focus window higher in stack than current   |
| Super  | Shift | h                 | (Tiling/Deck) Make current window the master window       |
| Super  |       | i                 | Spawn intellij-idea-ultimate-edition                      |
| Super  |       | j                 | (Tiling/Deck) Focus window lower in stack than current    |
| Super  | Shift | j                 | (Tiling/Deck) Make current window the master window       |
| Super  |       | k                 | (Tiling/Deck) Focus window higher in stack than current   |
| Super  | Shift | k                 | (Tiling/Deck) Make current window the master window       |
| Super  |       | l                 | (Tiling/Deck) Focus window lower in stack than current    |
| Super  |       | m                 | Spawn thunderbird                                         |
| Super  | Shift | m                 | Enable monocle layout	                                 |
| Super  | Shift | o                 | (Tiling/Deck) Increase master window size                 |
| Super  |       | p                 | Spawn ncmpcpp in st                                       |
| Super  |       | q                 | Close current window                                      |
| Super  | Shift | r                 | (dmenu) dmenu_run                                         |
| Super  |       | s                 | (dmenu) startpagesearch                                   |
| Super  | Shift | t                 | Enable tiling layout                                      |
| Super  | Shift | z                 | (Tiling/Deck) Decrease master window size                 |
| Super  |       | 0                 | Show all tags                                             |
| Super  | Shift | 0                 | Add current window to all tag                             |
| Super  | 		 | 1/2/.../9		 | Show tag 1/2/.../9                                        |
| Super  | Shift | 1/2/.../9		 | Add current window to tag 1/2/.../9                       |
| Super  | 		 | .				 | Show monitor lower in stack                               |
| Super  | Shift | .				 | Add to monitor lower in stack                             |
| Super  |		 | ,				 | Show monitor higher in stack                              |
| Super  | Shift | ,				 | Add to monitor higher in stack                            |
| Super  |       | F5                | enable 2 Screen Monitor                                   |
| Super  |       | F6                | toggle touchpad                                           |
| Super  |       | F7                | (dmenu) mounting drives                                   |
| Super  |       | F8                | (dmenu) unmounting drives                                 |
| Super  |       | F9                | Restart NetworkManager                                    |
| Super  |       | F10               | (dmenu) prompt, if yes: slock                             |
| Super  |       | F11               | (dmenu) prompt, if yes: reboot                            |
| Super  |       | F12               | (dmenu) prompt, if yes: shutdown                          |
|        |       | AudioMute         | Volume mute                                               |
|        |       | AudioMicMute      | Mic Mute                                                  |
|        |       | AudioLowerVolume  | Volume lower                                              |
|        |       | AudioRaiseVolume  | Volume raise                                              |
|        |       | MonBrightnessDown | Brightness decrease                                       |
|        |       | MonBrightnessUp   | Brightness increase                                       |
