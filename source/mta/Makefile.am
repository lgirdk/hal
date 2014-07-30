AM_CFLAGS = 

AM_CPPFLAGS = -Wall -Werror

ACLOCAL_AMFLAGS = -I m4

#hardware_platform = $(MACHINE)
hardware_platform = i686-linux-gnu

lib_LTLIBRARIES = libhalmta.la
#bin_PROGRAMS =

libhalmta_ladir = $(top_builddir)/source/mta/.libs

libhalmta_la_CPPFLAGS = -I$(top_builddir)/include $(CPPFLAGS)

libhalmta_la_SOURCES = mta_hal.c

libhalmta_la_LIBADD = 
