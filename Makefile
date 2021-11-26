OBJS = vector.o matrix.o solar_angle.o

HEADERS = solar_angle.h

PREFIX = $(HOME)
LIB_DIR = $(PREFIX)/lib
INC_DIR = $(PREFIX)/include

LINKER_OPTS = -Wl,-R$(LIB_DIR) -L$(LIB_DIR)

OPTS = -Wall -O3 -I$(INC_DIR)

.PHONY: all clean

all: main

main: $(OBJS)
	g++ -o $@ $(OBJS) $(LINKER_OPTS)

%.o: %.cpp $(HEADERS)
	g++ -c $< $(OPTS)

clean:
	rm -rf *.o main
