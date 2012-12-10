#
# Makefile.am for core/wfm/src
#

# -Woverloaded-virtual catches mis-overridden callbacks
AM_CXXFLAGS = -DY2LOG=\"Mock\"			\
	-DSUSEVERSION=\"${SUSEVERSION}\"	\
	-DLOCALEDIR=\"${localedir}\"		\
	-fno-inline				\
	-Woverloaded-virtual


# to look for the packagemanager in the prefix first (really first?)
AM_LDFLAGS = -L${libdir}

plugin_LTLIBRARIES = libpy2Mock.la

libpy2Mock_la_SOURCES =				\
	Y2MockComponent.cc Y2MockComponent.h	\
	Y2CCMock.cc Y2CCMock.h			\
	MockModule.cc MockModule.h		\
	log.h


libpy2Mock_la_LDFLAGS = -version-info 2:0
libpy2Mock_la_LIBADD = \
	-lycp		\
	-ly2		\
	-ly2util

INCLUDES = -I$(includedir)

CLEANFILES = $(BUILT_SOURCES)
