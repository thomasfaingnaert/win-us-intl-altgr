# United States (International) with AltGr dead keys
## Introduction
Windows includes a keyboard layout called "United States (International)", which allows typing many special characters easily.
The layout defines several keys as "dead keys", such as the apostrophe (`'`) and double quotes (`"`).
This means that to enter a single `'`, you have to press `'` followed by a space.
This can be annoying when you need to enter a lot of these characters, since each now requires two keys to be pressed.

In Linux, there is a keyboard layout named "USA International (AltGr dead keys)" that solves this problem and still allows typing special characters.
If you want to type `'`, you just press `'`.
If you want to use `'` as a dead key, you use AltGr (right alt): e.g. `AltGr+' a` will produce `á`.

This repo is a modified version of the default Windows "United States (International)" keyboard layout that mimics the behaviour found in Linux.
All five dead keys (`` ` ``, `~`, `^`, `'` and `"`) are now only dead when AltGr is pressed, otherwise they function as normal keys.
Note that the original layout already defines several AltGr combinations, e.g. `AltGr+'` becomes `´`.
If you want to type these characters in the modified layout, you should follow the old keycombination with a space: e.g. `AltGr+' <SPACE>` will produce `´`.

## How to Build or Install
You can download the latest installer from the releases tab of this repo (https://github.com/thomasfaingnaert/win-us-intl-altgr/releases).

If you prefer to build from source, you can open the .KLC source file in Microsoft Keyboard Layout Creator.
After opening the file, choose Project > Build DLL and Setup Package in the menu to create an installer.

## Related

There's now a revised version [altgr-weur.eu](https://altgr-weur.eu/windows.html) of the AltGr-International layout.
