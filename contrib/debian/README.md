
Debian
====================
This directory contains files used to package wincashcoind/wincashcoin-qt
for Debian-based Linux systems. If you compile wincashcoind/wincashcoin-qt yourself, there are some useful files here.

## wincashcoin: URI support ##


wincashcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install wincashcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your wincashcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/wincashcoin128.png` to `/usr/share/pixmaps`

wincashcoin-qt.protocol (KDE)

