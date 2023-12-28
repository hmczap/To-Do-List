objects = main.o View.o Task.o TDList.o

test: ${objects}
	g++ -o test ${objects}

main.o: main.cc
	g++ -c main.cc 

View.o: View.cc View.h
	g++ -c View.cc

Task.o: Task.cc Task.h
	g++ -c Task.cc

TDList.o: TDList.cc TDList.h
	g++ -c TDList.cc

clean: 
	rm -f test *.o