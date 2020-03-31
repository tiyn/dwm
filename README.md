# dwm
This is my patched version of dwm. The base version is directly from suckless.org.
This belongs to my larbs installation script and depends heavily on its scripts and programs.
It is supposed to work in the environment after the larbs-base-installation.

## Patches
The list below shows the currently applied patches to the master branch.
- dwm-alpha-6.2.diff
- dwm-noborder-6.2.diff
- dwm-pertag-20170513-ceac8c9.diff

## Hotkeys
There are various shortcuts and hotkeys used in this version. Included in my build are the following.
```
Super + Shift + Escape            ->      Quit dwm
Super +         Return            ->      Spawn st
Super +         b                 ->      Spawn firefox
Super + Shift + b                 ->      Toggle dwmbar
Super + Shift + d                 ->      Toggle floating/tiled for selected window
Super +         f                 ->      Spawn vifm in st
Super + Shift + f                 ->      Enable fullscreen layout
Super +         h                 ->      (Tiling) Focus window higher in stack than current
Super + Shift + h                 ->      (Tiling) Make current window the master window
Super +         i                 ->      Spawn intellij-idea-ultimate-edition
Super +         j                 ->      (Tiling) Focus window lower in stack than current
Super + Shift + j                 ->      (Tiling) Make current window the master window
Super +         k                 ->      (Tiling) Focus window higher in stack than current
Super + Shift + k                 ->      (Tiling) Make current window the master window
Super +         l                 ->      (Tiling) Focus window lower in stack than current
Super +         m                 ->      Spawn thunderbird
Super + Shift + o                 ->      (Tiling) Increase master window size
Super +         p                 ->      Spawn ncmpcpp in st
Super +         q                 ->      Close current window
Super + Shift + r                 ->      (dmenu) dmenu_run
Super +         s                 ->      (dmenu) startpagesearch
Super + Shift + t                 ->      Enable tiling layout
Super + Shift + z                 ->      (Tiling) Decrease master window size
Super +         0                 ->      Show all tags
Super + Shift + 0                 ->      Add current window to all tag
Super +		  +	1/2/.../9		  ->	  Show tag 1/2/.../9
Super + Shift +	1/2/.../9		  ->	  Add current window to tag 1/2/.../9
Super +		  +	.				  ->	  Show monitor lower in stack
Super + Shift + .				  ->	  Add to monitor lower in stack
Super +		  +	,				  ->	  Show monitor higher in stack
Super + Shift + ,				  ->	  Add to monitor higher in stack
Super +         F5                ->      enable 2 Screen Monitor
Super +         F6                ->      toggle touchpad
Super +         F7                ->      (dmenu) mounting drives
Super +         F8                ->      (dmenu) unmounting drives
Super +         F9                ->      Restart NetworkManager
Super +         F10               ->      (dmenu) prompt, if yes: slock
Super +         F11               ->      (dmenu) prompt, if yes: reboot
Super +         F12               ->      (dmenu) prompt, if yes: shutdown
                AudioMute         ->      Volume mute
                AudioMicMute      ->      Mic Mute
                AudioLowerVolume  ->      Volume lower
                AudioRaiseVolume  ->      Volume raise
                MonBrightnessDown ->      Brightness decrease
                MonBrightnessUp   ->      Brightness increase
```
