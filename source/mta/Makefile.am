AM_CFLAGS = -D_ANSC_LINUX
AM_CFLAGS += -D_ANSC_USER
AM_CFLAGS += -D_ANSC_LITTLE_ENDIAN_

AM_CPPFLAGS = -Wall -Werror
ACLOCAL_AMFLAGS = -I m4
hardware_platform = i686-linux-gnu

lib_LTLIBRARIES = libhal_mta.la
libhal_mta_la_CPPFLAGS = -I$(top_srcdir)/./include $(CPPFLAGS)
libhal_mta_la_SOURCES = mta_hal.c
libhal_mta_la_LDFLAGS = 