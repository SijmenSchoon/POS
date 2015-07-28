#!/bin/sh
set -e
. ./headers.sh

for PROJECT in $PROJECTS; do
  DESTDIR="$PWD/sysroot" $MAKE -C $PROJECT clean
  DESTDIR="$PWD/sysroot" $MAKE -C $PROJECT -j3
  DESTDIR="$PWD/sysroot" $MAKE -C $PROJECT install
done
