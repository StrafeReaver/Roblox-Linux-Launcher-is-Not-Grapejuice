CXX = clang++
CXXFLAGS = -std=c++20 -O2 -Wall -march=x86-64
SRC = RLLNG.cpp
BIN=RLLNG

all:
	${CXX} ${CXXFLAGS} ${SRC} -o ${BIN}
