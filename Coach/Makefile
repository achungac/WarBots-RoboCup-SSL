#############################################################################
# Makefile for building: server_30015
# Generated by qmake (2.01a) (Qt 4.7.4) on: Mon Feb 27 19:50:20 2012
# Project:  server_30015.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile server_30015.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -Iinclude -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -Llibs/ -lprotobuf-2.4.0 -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = LinServer.cpp \
		pb/messages_robocup_ssl_wrapper.pb.cc \
		pb/messages_robocup_ssl_detection.pb.cc \
		pb/messages_robocup_ssl_geometry.pb.cc \
		pb/netraw.cpp \
		pb/grSim_Replacement.pb.cc \
		pb/grSim_Commands.pb.cc \
		pb/grSim_Packet.pb.cc \
		Robot.cpp \
		Goalie.cpp 
OBJECTS       = LinServer.o \
		messages_robocup_ssl_wrapper.pb.o \
		messages_robocup_ssl_detection.pb.o \
		messages_robocup_ssl_geometry.pb.o \
		netraw.o \
		grSim_Replacement.pb.o \
		grSim_Commands.pb.o \
		grSim_Packet.pb.o \
		Robot.o \
		Goalie.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		server_30015.pro
QMAKE_TARGET  = server_30015
DESTDIR       = 
TARGET        = server_30015

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: server_30015.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile server_30015.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile server_30015.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/server_300151.0.0 || $(MKDIR) .tmp/server_300151.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/server_300151.0.0/ && $(COPY_FILE) --parents LinServer.cpp pb/messages_robocup_ssl_wrapper.pb.cc pb/messages_robocup_ssl_detection.pb.cc pb/messages_robocup_ssl_geometry.pb.cc pb/netraw.cpp pb/grSim_Replacement.pb.cc pb/grSim_Commands.pb.cc pb/grSim_Packet.pb.cc Robot.cpp Goalie.cpp .tmp/server_300151.0.0/ && (cd `dirname .tmp/server_300151.0.0` && $(TAR) server_300151.0.0.tar server_300151.0.0 && $(COMPRESS) server_300151.0.0.tar) && $(MOVE) `dirname .tmp/server_300151.0.0`/server_300151.0.0.tar.gz . && $(DEL_FILE) -r .tmp/server_300151.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

LinServer.o: LinServer.cpp messages_robocup_ssl_wrapper.pb.h \
		messages_robocup_ssl_detection.pb.h \
		messages_robocup_ssl_geometry.pb.h \
		netraw.h \
		grSim_Packet.pb.h \
		grSim_Commands.pb.h \
		grSim_Replacement.pb.h \
		Robot.h \
		Goalie.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o LinServer.o LinServer.cpp

messages_robocup_ssl_wrapper.pb.o: pb/messages_robocup_ssl_wrapper.pb.cc messages_robocup_ssl_wrapper.pb.h \
		messages_robocup_ssl_detection.pb.h \
		messages_robocup_ssl_geometry.pb.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o messages_robocup_ssl_wrapper.pb.o pb/messages_robocup_ssl_wrapper.pb.cc

messages_robocup_ssl_detection.pb.o: pb/messages_robocup_ssl_detection.pb.cc messages_robocup_ssl_detection.pb.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o messages_robocup_ssl_detection.pb.o pb/messages_robocup_ssl_detection.pb.cc

messages_robocup_ssl_geometry.pb.o: pb/messages_robocup_ssl_geometry.pb.cc messages_robocup_ssl_geometry.pb.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o messages_robocup_ssl_geometry.pb.o pb/messages_robocup_ssl_geometry.pb.cc

netraw.o: pb/netraw.cpp netraw.h \
		pb/util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o netraw.o pb/netraw.cpp

grSim_Replacement.pb.o: pb/grSim_Replacement.pb.cc grSim_Replacement.pb.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o grSim_Replacement.pb.o pb/grSim_Replacement.pb.cc

grSim_Commands.pb.o: pb/grSim_Commands.pb.cc grSim_Commands.pb.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o grSim_Commands.pb.o pb/grSim_Commands.pb.cc

grSim_Packet.pb.o: pb/grSim_Packet.pb.cc grSim_Packet.pb.h \
		grSim_Commands.pb.h \
		grSim_Replacement.pb.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o grSim_Packet.pb.o pb/grSim_Packet.pb.cc

Robot.o: Robot.cpp messages_robocup_ssl_wrapper.pb.h \
		messages_robocup_ssl_detection.pb.h \
		messages_robocup_ssl_geometry.pb.h \
		netraw.h \
		grSim_Packet.pb.h \
		grSim_Commands.pb.h \
		grSim_Replacement.pb.h \
		Robot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Robot.o Robot.cpp

Goalie.o: Goalie.cpp messages_robocup_ssl_wrapper.pb.h \
		messages_robocup_ssl_detection.pb.h \
		messages_robocup_ssl_geometry.pb.h \
		netraw.h \
		grSim_Packet.pb.h \
		grSim_Commands.pb.h \
		grSim_Replacement.pb.h \
		Robot.h \
		Goalie.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Goalie.o Goalie.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

