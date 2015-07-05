SHELL := /bin/bash
SRC = $(shell ls -tr *.cpp | tail -n 1)

all: $(SRC)
	@echo "Compiling $<.."
	@g++ -std=c++11 -O0 -g -o a.out $< && time ./a.out

clean:
	@rm -f a.out
