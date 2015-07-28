#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/pos.kernel isodir/boot/pos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "pos" {
	multiboot /boot/pos.kernel
}
EOF
grub-mkrescue -d /usr/lib/grub/i386-pc/ -o pos.iso isodir
