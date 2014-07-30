AM_CFLAGS = 

AM_CPPFLAGS = -Wall -Werror

ACLOCAL_AMFLAGS = -I m4

#hardware_platform = $(MACHINE)
hardware_platform = i686-linux-gnu

lib_LTLIBRARIES = libhalmoca.la
#bin_PROGRAMS =

libhalmoca_ladir = $(top_builddir)/source/moca/.libs

libhalmoca_la_CPPFLAGS = -I$(top_builddir)/include $(CPPFLAGS)

libhalmoca_la_SOURCES = moca_hal.c

libhalmoca_la_LIBADD = 
