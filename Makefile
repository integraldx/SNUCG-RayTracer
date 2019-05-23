main: *.cpp
	g++ -c main.cpp `libpng-config --cflags`
	g++ -o main.out main.o `libpng-config --ldflags`

run: 
	make main
	./main.out

clean: 
	rm -f *.o *.out *.png