#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU_6.2-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/core/film.o \
	${OBJECTDIR}/core/matrix.o \
	${OBJECTDIR}/core/tonemapper.o \
	${OBJECTDIR}/film/box_film.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/tonemapper/clamp_tonemapper.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m64 -march=native
CXXFLAGS=-m64 -march=native

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pixel

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pixel: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pixel ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/core/film.o: core/film.cc
	${MKDIR} -p ${OBJECTDIR}/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Icore -Ifilm -Itonemapper -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/film.o core/film.cc

${OBJECTDIR}/core/matrix.o: core/matrix.cc
	${MKDIR} -p ${OBJECTDIR}/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Icore -Ifilm -Itonemapper -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/matrix.o core/matrix.cc

${OBJECTDIR}/core/tonemapper.o: core/tonemapper.cc
	${MKDIR} -p ${OBJECTDIR}/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Icore -Ifilm -Itonemapper -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/tonemapper.o core/tonemapper.cc

${OBJECTDIR}/film/box_film.o: film/box_film.cc
	${MKDIR} -p ${OBJECTDIR}/film
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Icore -Ifilm -Itonemapper -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/film/box_film.o film/box_film.cc

${OBJECTDIR}/main.o: main.cc
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Icore -Ifilm -Itonemapper -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cc

${OBJECTDIR}/tonemapper/clamp_tonemapper.o: tonemapper/clamp_tonemapper.cc
	${MKDIR} -p ${OBJECTDIR}/tonemapper
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Icore -Ifilm -Itonemapper -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tonemapper/clamp_tonemapper.o tonemapper/clamp_tonemapper.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
