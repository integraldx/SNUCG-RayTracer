main: *.cpp
	g++ -c *.cpp `libpng-config --cflags`
	g++ -o main.out *.o `libpng-config --ldflags`

run: 
	make main
	./main.out

clean: 
	rm -f *.o *.out *.png