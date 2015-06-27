SHELL := /bin/bash
SRC = $(shell ls -tr *.cpp | tail -n 1)

all: $(SRC)
	@echo "Compiling $<.."
	@g++ -std=c++11 -g -o a.out $< && time ./a.out < input

clean:
	@rm -f a.out
