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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/camera/pinhole_camera.o \
	${OBJECTDIR}/core/film.o \
	${OBJECTDIR}/core/interaction.o \
	${OBJECTDIR}/core/ray.o \
	${OBJECTDIR}/core/renderer.o \
	${OBJECTDIR}/core/scene.o \
	${OBJECTDIR}/core/sse_matrix.o \
	${OBJECTDIR}/core/tonemapper.o \
	${OBJECTDIR}/core/transform.o \
	${OBJECTDIR}/film/box_film.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/tonemapper/clamp_tonemapper.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/vector_test_class.o \
	${TESTDIR}/tests/vector_test_runner.o

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
LDLIBSOPTIONS=-Wl,-rpath,'.' -Wl,-rpath,'.'

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pixel

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pixel: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pixel ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/camera/pinhole_camera.o: camera/pinhole_camera.cpp
	${MKDIR} -p ${OBJECTDIR}/camera
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/camera/pinhole_camera.o camera/pinhole_camera.cpp

${OBJECTDIR}/core/film.o: core/film.cc
	${MKDIR} -p ${OBJECTDIR}/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/film.o core/film.cc

${OBJECTDIR}/core/interaction.o: core/interaction.cc
	${MKDIR} -p ${OBJECTDIR}/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/interaction.o core/interaction.cc

${OBJECTDIR}/core/ray.o: core/ray.cc
	${MKDIR} -p ${OBJECTDIR}/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/ray.o core/ray.cc

${OBJECTDIR}/core/renderer.o: core/renderer.cc
	${MKDIR} -p ${OBJECTDIR}/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/renderer.o core/renderer.cc

${OBJECTDIR}/core/scene.o: core/scene.cc
	${MKDIR} -p ${OBJECTDIR}/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/scene.o core/scene.cc

${OBJECTDIR}/core/sse_matrix.o: core/sse_matrix.cc
	${MKDIR} -p ${OBJECTDIR}/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/sse_matrix.o core/sse_matrix.cc

${OBJECTDIR}/core/tonemapper.o: core/tonemapper.cc
	${MKDIR} -p ${OBJECTDIR}/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/tonemapper.o core/tonemapper.cc

${OBJECTDIR}/core/transform.o: core/transform.cc
	${MKDIR} -p ${OBJECTDIR}/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/transform.o core/transform.cc

${OBJECTDIR}/film/box_film.o: film/box_film.cc
	${MKDIR} -p ${OBJECTDIR}/film
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/film/box_film.o film/box_film.cc

${OBJECTDIR}/main.o: main.cc
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cc

${OBJECTDIR}/tonemapper/clamp_tonemapper.o: tonemapper/clamp_tonemapper.cc
	${MKDIR} -p ${OBJECTDIR}/tonemapper
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tonemapper/clamp_tonemapper.o tonemapper/clamp_tonemapper.cc

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/vector_test_class.o ${TESTDIR}/tests/vector_test_runner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   -Wl,-rpath,'.' -Wl,-rpath,'.' `cppunit-config --libs`   


${TESTDIR}/tests/vector_test_class.o: tests/vector_test_class.cc 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/vector_test_class.o tests/vector_test_class.cc


${TESTDIR}/tests/vector_test_runner.o: tests/vector_test_runner.cc 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/vector_test_runner.o tests/vector_test_runner.cc


${OBJECTDIR}/camera/pinhole_camera_nomain.o: ${OBJECTDIR}/camera/pinhole_camera.o camera/pinhole_camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/camera
	@NMOUTPUT=`${NM} ${OBJECTDIR}/camera/pinhole_camera.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/camera/pinhole_camera_nomain.o camera/pinhole_camera.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/camera/pinhole_camera.o ${OBJECTDIR}/camera/pinhole_camera_nomain.o;\
	fi

${OBJECTDIR}/core/film_nomain.o: ${OBJECTDIR}/core/film.o core/film.cc 
	${MKDIR} -p ${OBJECTDIR}/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/core/film.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/film_nomain.o core/film.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/core/film.o ${OBJECTDIR}/core/film_nomain.o;\
	fi

${OBJECTDIR}/core/interaction_nomain.o: ${OBJECTDIR}/core/interaction.o core/interaction.cc 
	${MKDIR} -p ${OBJECTDIR}/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/core/interaction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/interaction_nomain.o core/interaction.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/core/interaction.o ${OBJECTDIR}/core/interaction_nomain.o;\
	fi

${OBJECTDIR}/core/ray_nomain.o: ${OBJECTDIR}/core/ray.o core/ray.cc 
	${MKDIR} -p ${OBJECTDIR}/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/core/ray.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/ray_nomain.o core/ray.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/core/ray.o ${OBJECTDIR}/core/ray_nomain.o;\
	fi

${OBJECTDIR}/core/renderer_nomain.o: ${OBJECTDIR}/core/renderer.o core/renderer.cc 
	${MKDIR} -p ${OBJECTDIR}/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/core/renderer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/renderer_nomain.o core/renderer.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/core/renderer.o ${OBJECTDIR}/core/renderer_nomain.o;\
	fi

${OBJECTDIR}/core/scene_nomain.o: ${OBJECTDIR}/core/scene.o core/scene.cc 
	${MKDIR} -p ${OBJECTDIR}/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/core/scene.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/scene_nomain.o core/scene.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/core/scene.o ${OBJECTDIR}/core/scene_nomain.o;\
	fi

${OBJECTDIR}/core/sse_matrix_nomain.o: ${OBJECTDIR}/core/sse_matrix.o core/sse_matrix.cc 
	${MKDIR} -p ${OBJECTDIR}/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/core/sse_matrix.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/sse_matrix_nomain.o core/sse_matrix.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/core/sse_matrix.o ${OBJECTDIR}/core/sse_matrix_nomain.o;\
	fi

${OBJECTDIR}/core/tonemapper_nomain.o: ${OBJECTDIR}/core/tonemapper.o core/tonemapper.cc 
	${MKDIR} -p ${OBJECTDIR}/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/core/tonemapper.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/tonemapper_nomain.o core/tonemapper.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/core/tonemapper.o ${OBJECTDIR}/core/tonemapper_nomain.o;\
	fi

${OBJECTDIR}/core/transform_nomain.o: ${OBJECTDIR}/core/transform.o core/transform.cc 
	${MKDIR} -p ${OBJECTDIR}/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/core/transform.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/core/transform_nomain.o core/transform.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/core/transform.o ${OBJECTDIR}/core/transform_nomain.o;\
	fi

${OBJECTDIR}/film/box_film_nomain.o: ${OBJECTDIR}/film/box_film.o film/box_film.cc 
	${MKDIR} -p ${OBJECTDIR}/film
	@NMOUTPUT=`${NM} ${OBJECTDIR}/film/box_film.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/film/box_film_nomain.o film/box_film.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/film/box_film.o ${OBJECTDIR}/film/box_film_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cc 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/tonemapper/clamp_tonemapper_nomain.o: ${OBJECTDIR}/tonemapper/clamp_tonemapper.o tonemapper/clamp_tonemapper.cc 
	${MKDIR} -p ${OBJECTDIR}/tonemapper
	@NMOUTPUT=`${NM} ${OBJECTDIR}/tonemapper/clamp_tonemapper.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -O2 -Wall -Icore -Ifilm -Itonemapper -Icamera -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tonemapper/clamp_tonemapper_nomain.o tonemapper/clamp_tonemapper.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/tonemapper/clamp_tonemapper.o ${OBJECTDIR}/tonemapper/clamp_tonemapper_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
