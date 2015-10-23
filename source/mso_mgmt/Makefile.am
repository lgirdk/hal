AM_CFLAGS = -D_ANSC_LINUX
AM_CFLAGS += -D_ANSC_USER
AM_CFLAGS += -D_ANSC_LITTLE_ENDIAN_

AM_CPPFLAGS = -Wall -Werror
ACLOCAL_AMFLAGS = -I m4
hardware_platform = i686-linux-gnu

lib_LTLIBRARIES = libhal_msomgmt.la
libhal_msomgmt_la_CPPFLAGS = -I$(top_srcdir)/./include $(CPPFLAGS)
libhal_msomgmt_la_SOURCES = mso_mgmt_hal.c
libhal_msomgmt_la_LDFLAGS =
