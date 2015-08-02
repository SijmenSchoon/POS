#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/kernel.elf isodir/boot/kernel.elf
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "pos" {
	multiboot /boot/kernel.elf
}
EOF
grub-mkrescue -d /usr/lib/grub/i386-pc/ -o pos.iso isodir
