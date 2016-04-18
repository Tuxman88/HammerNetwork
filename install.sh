#!/bin/bash

# This file is part of Hammer Network. Hammer Network is free software: you can
# redistribute it and/or modify it under the terms of the GNU General Public
# License as published by the Free Software Foundation, version 2.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License along with
# this program; if not, write to the Free Software Foundation, Inc., 51
# Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

echo "Checking for files needed..."

echo ">> hammernetwork (main binary)"
if [ ! -f hammernetwork ]; then
   echo "NOT FOUND. Try compiling the program."
   exit
fi

echo ">> hammer_network.desktop (menu entry file)"
if [ ! -f "resources/menus/hammer-network.desktop" ]; then
   echo "NOT FOUND. Try uncompressing the package again."
   exit
fi

echo ">> main-128x128.png (program icon)"
if [ ! -f "resources/img/icon/main-128x128.png" ]; then
   echo "NOT FOUND. Try uncompressing the package again."
   exit
fi

echo "Trying to install icon to /usr/share/icons/"
install resources/img/icon/main-128x128.png /usr/share/icons/hammer-network.png

echo "Trying to install menu entry to /usr/share/applications/"
install resources/menus/hammer-network.desktop /usr/share/applications/

echo "Trying to install binary to /usr/bin/"
install hammernetwork /usr/bin/