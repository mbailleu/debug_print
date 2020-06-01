.PHONY: all clean

all: test

test: src/test.o src/debug_print.o
	g++ -std=c++17 -O0 -g $^ -o $@

src/test.o: src/test.cpp include/debug_print.h include/map.h
	g++ -std=c++17 -O0 -g $< -o $@ -c -I "include"

src/debug_print.o: src/debug_print.cpp include/debug_print.h include/map.h
	g++ -std=c++17 -O0 -g $< -o $@ -c -I "include"

include/map.h:
	curl https://raw.githubusercontent.com/swansontec/map-macro/master/map.h -o $@
