HOST?=$(shell ../default-host.sh)
HOSTARCH:=$(shell ../target-triplet-to-arch.sh $(HOST))

CFLAGS?=-O2 -g
CPPFLAGS?=
LDFLAGS?=
LIBS?=

DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
INCLUDEDIR?=$(PREFIX)/include
LIBDIR?=$(EXEC_PREFIX)/lib

CFLAGS:=$(CFLAGS) -Wall -Wextra
CPPFLAGS:=$(CPPFLAGS) -D__is_pos_libc -Iinclude
LIBK_CFLAGS:=$(CFLAGS) -ffreestanding -fbuiltin
LIBK_CPPFLAGS:=$(CPPFLAGS) -D__is_pos_kernel

ARCHDIR:=arch/$(HOSTARCH)

include $(ARCHDIR)/make.config

CFLAGS:=$(CFLAGS) $(ARCH_CFLAGS)
CPFLAGS:=$(CPPFLAGS) $(ARCH_CPPFLAGS)
LIBK_CFLAGS:=$(LIBK_CFLAGS) $(KERNEL_ARCH_CFLAGS)
LIBK_CPFLAGS:=$(LIBK_CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)

FREEOBJS:=\
$(ARCH_FREEOBJS) \
ctype/isalnum.o \
ctype/isalpha.o \
ctype/isblank.o \
ctype/iscntrl.o \
ctype/isdigit.o \
ctype/isgraph.o \
ctype/islower.o \
ctype/isprint.o \
ctype/ispunct.o \
ctype/isspace.o \
ctype/isupper.o \
ctype/isxdigit.o \
ctype/tolower.o \
ctype/toupper.o \
\
errno/errno.o \
\
math/acos.o \
math/acosh.o \
math/asin.o \
math/asinh.o \
math/atan2.o \
math/atan.o \
math/atanh.o \
math/cbrt.o \
math/ceil.o \
math/cos.o \
math/cosh.o \
math/erf.o \
math/erfc.o \
math/exp2.o \
math/exp.o \
math/expm1.o \
math/fabs.o \
math/floor.o \
math/frexp.o \
math/hypot.o \
math/ilogb.o \
math/ldexp.o \
math/lgamma.o \
math/llrint.o \
math/llround.o \
math/log1p.o \
math/log2.o \
math/log10.o \
math/log.o \
math/logb.o \
math/lrint.o \
math/lround.o \
math/modf.o \
math/nearbyint.o \
math/pow.o \
math/rint.o \
math/round.o \
math/scalbn.o \
math/sin.o \
math/sinh.o \
math/sqrt.o \
math/tan.o \
math/tanh.o \
math/tgamma.o \
\
stdio/printf.o \
stdio/putchar.o \
stdio/puts.o \
\
stdlib/abort.o \
\
string/memcmp.o \
string/memcpy.o \
string/memmove.o \
string/memset.o \
string/strlen.o \

HOSTEDOBJS:=\
$(ARCH_HOSTEDOBJS) \

OBJS:=\
$(FREEOBJS) \
$(HOSTEDOBJS) \

LIBK_OBJS:=$(FREEOBJS:.o=.libk.o)

BINARIES=libc.a libg.a libk.a

all: $(BINARIES)

.PHONY: all clean install install-headers install-libs

libc.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

libg.a:
	$(AR) rcs $@

libk.a: $(LIBK_OBJS)
	$(AR) rcs $@ $(LIBK_OBJS)

%.o: %.c
	$(CC) -c $< -o $@ -std=c11 $(CFLAGS) $(CPPFLAGS)

%.o: %.S
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

%.libk.o: %.c
	$(CC) -c $< -o $@ -std=c11 $(LIBK_CFLAGS) $(LIBK_CPPFLAGS)

%.libk.o: %.S
	$(CC) -c $< -o $@ $(LIBK_CFLAGS) $(LIBK_CPPFLAGS)

clean:
	rm -f $(BINARIES) $(OBJS) $(LIBK_OBJS) *.o */*.o */*/*.o

install: install-headers install-libs

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -RTv include $(DESTDIR)$(INCLUDEDIR)

install-libs: $(BINARIES)
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp $(BINARIES) $(DESTDIR)$(LIBDIR)
