##########################################################################
# If not stated otherwise in this file or this component's Licenses.txt
# file the following copyright and licenses apply:
#
# Copyright 2015 RDK Management
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
##########################################################################
AM_CFLAGS = -D_ANSC_LINUX
AM_CFLAGS += -D_ANSC_USER
AM_CFLAGS += -D_ANSC_LITTLE_ENDIAN_
AM_CFLAGS += -fPIC
AM_CFLAGS += -D_GNU_SOURCE
AM_CFLAGS += -DSC_POSIX_SEM
AM_LDFLAGS = -lpthread
AM_LDFLAGS += -lz

AM_CPPFLAGS = -Wall -Werror -fPIC
ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libbridge_utils.la

libbridge_utils_la_LDFLAGS = -lpthread 

libbridge_utils_la_CPPFLAGS = -I${PKG_CONFIG_SYSROOT_DIR}$(includedir)/ccsp $(CPPFLAGS)

libbridge_utils_la_SOURCES =  bridge_util_oem.c
