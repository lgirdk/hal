AM_CFLAGS = -D_ANSC_LINUX
AM_CFLAGS += -D_ANSC_USER
AM_CFLAGS += -D_ANSC_LITTLE_ENDIAN_

AM_CPPFLAGS = -Wall -Werror
ACLOCAL_AMFLAGS = -I m4
hardware_platform = i686-linux-gnu

lib_LTLIBRARIES = libhal_cm.la
libhal_cm_la_CPPFLAGS = -I$(top_builddir)/./include $(CPPFLAGS)
libhal_cm_la_SOURCES = cm_hal.c
libhal_cm_la_LDFLAGS = 