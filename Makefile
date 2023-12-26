objects = main.o Task.o View.o

all: todolist
test: test

todolist: $(objects)
	g++ -o todolist $(objects)

test: main.o View.o
	g++ -o test main.o View.o

main.o: main.cc
	g++ -c main.cc 

View.o: View.cc View.h
	g++ -c View.cc 

clean: 
	rm -f todolist test *.o