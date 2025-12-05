#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/perry_os.kernel isodir/boot/perry_os.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "perry_os" {
	multiboot /boot/perry_os.kernel
}
EOF
grub-mkrescue -o perry_os.iso isodir
