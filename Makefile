INCLUDE_DIRS = 
LIB_DIRS = 
CC = g++

CDEFS=
CFLAGS= -O0 -g $(INCLUDE_DIRS) $(CDEFS)
LIBS=

OPT_DRIVER= optiontest
GRAPH_DRIVER= graphicstest

HFILES= graphics.hpp Options.hpp
OPT_CFILES= optiontest.cc Options.cc
GRAPH_CFILES= graphicstest.cc graphics.cc

SRCS= ${HFILES} ${OPT_CFILES} ${GRAPH_CFILES}
OPT_OBJS= ${OPT_CFILES:.cc=.o}
GRAPH_OBJS= ${GRAPH_CFILES:.cc=.o}

all:	${OPT_DRIVER} ${GRAPH_DRIVER}

clean:
	-rm -f *.o *.NEW *~
	-rm -f ${OPT_DRIVER} ${GRAPH_DRIVER} ${DERIVED} ${GARBAGE}

${GRAPH_DRIVER}: ${GRAPH_OBJS}
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(GRAPH_OBJS) $(LIBS)

${OPT_DRIVER}:	${OPT_OBJS}
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OPT_OBJS) $(LIBS)

depend:

graphicstest.o: graphicstest.cc
	$(CC) $(LDFLAGS) $(CFLAGS) -c $<

graphics.o: graphics.cc
	$(CC) $(LDFLAGS) $(CFLAGS) -c $<

optiontest.o: optiontest.cc
	$(CC) $(LDFLAGS) $(CFLAGS) -c $<

Options.o: Options.cc
	$(CC) $(LDFLAGS) $(CFLAGS) -c $<

