TARGET=goc

RELEASEDIR=bin

ifeq ($(RELEASE), true)
	CFLAGS=-O2 -D "NDEBUG"
	LDFLAGS=
else
	CFLAGS=-g -pg
	LDFLAGS=-pg
endif


CFLAGS+= -g \
	-I${BOOST_ROOT}/include \
	-I${SRC_ROOT}/d_common/ \
	-I${JEMALLOC_ROOT}/include \
	-I${LUA_ROOT}/src \
	-I${SRC_ROOT}/d_3rd/jsoncpp/include \

OBJCommon=	\
	Global.o

OBJS=${OBJCommon} main.o
OBJSUnion=$(sort ${OBJS1})

DEPS=$(patsubst %.o,%.d,$(OBJSUnion))

getObjOfSuffix= ${patsubst %${2}, %.o, ${wildcard ${addsuffix ${2}, ${basename ${1}}}}}

COBJS=${call getObjOfSuffix, ${OBJSUnion}, .c}
CXXOBJS=${call getObjOfSuffix, ${OBJSUnion}, .cpp}


LIB= 	\
	${JEMALLOC_ROOT}/lib/libjemalloc.a \
	${SRC_ROOT}/d_3rd/jsoncpp/libjsoncpp.a \

SO_LIB= \
	-L${BOOST_ROOT}/lib -lboost_system -lboost_program_options -lboost_thread \
	-L${LOG4CXX_LIB_PATH} -L${LUA_ROOT}/src -lluajit

LDFLAGS+= \
	-lpthread -ldl -llog4cxx -export-dynamic


.PHONY: all clean copy dirmake


all: ${TARGET}

${TARGET}: ${OBJS} ${LIB}
	${CXX} -o $@ $^ ${LDFLAGS} ${SO_LIB}

${CXXOBJS}:%.o:%.cpp
	${CXX} -c -o $@ $< ${CFLAGS}

${COBJS}:%.o:%.c
	${CC} -c -o $@ $< ${CFLAGS}

${PCH}.gch:${PCH}
	${CXX}  $< ${CFLAGS}

%.d : %.c
	${CC} -MM -MD ${CFLAGS} $< -o $@ -MT ${@:.d=.o}

%.d : %.cpp
	${CXX} -MM -MD ${CFLAGS} $< -o $@ -MT ${@:.d=.o}

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif

clean:
	rm -f ${OBJSUnion} ${TARGET} ${DEPS} *.con

dirmake:
	-(test ! -d $(RELEASEDIR) && mkdir -p $(RELEASEDIR))|tee

copy: dirmake
	cp ${TARGET} ${RELEASEDIR}
	#cp ${TARGET2} ${RELEASEDIR}
	#cp ${LIBFILES} ${RELEASEDIR}
	#for f in ${AUXFILES}; do cp $$f ${RELEASEDIR}/$$f.sample; done
