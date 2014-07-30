AM_CFLAGS = 

AM_CPPFLAGS = -Wall -Werror

ACLOCAL_AMFLAGS = -I m4

#hardware_platform = $(MACHINE)
hardware_platform = i686-linux-gnu

lib_LTLIBRARIES = libhalwifi.la
#bin_PROGRAMS =

libhalwifi_ladir = $(top_builddir)/source/wifi/.libs

libhalwifi_la_CPPFLAGS = -I$(top_builddir)/include $(CPPFLAGS)

libhalwifi_la_SOURCES = wifi_hal.c

libhalwifi_la_LIBADD = 
