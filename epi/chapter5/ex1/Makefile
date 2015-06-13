
all:
	@g++ -g -Wall -Werror -o main main.cpp

# to be called with: make run arg=123
run:
	@./main $(arg)

gdb:
	@gdb main

valgrind:
	@valgrind ./main
