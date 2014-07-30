AM_CFLAGS = 

AM_CPPFLAGS = -Wall -Werror

ACLOCAL_AMFLAGS = -I m4

#hardware_platform = $(MACHINE)
hardware_platform = i686-linux-gnu

lib_LTLIBRARIES = libhalcm.la
#bin_PROGRAMS =

libhalcm_ladir = $(top_builddir)/source/cm/.libs

libhalcm_la_CPPFLAGS = -I$(top_builddir)/include $(CPPFLAGS)

libhalcm_la_SOURCES = cm_hal.c

libhalcm_la_LIBADD = 
