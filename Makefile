raytracer: *.cpp *.hpp
	g++ -c -std=c++17 *.cpp `libpng-config --cflags`
	g++ -o raytracer *.o `libpng-config --ldflags` -lpthread

run: raytracer
	./raytracer

clean: 
	rm -f *.o *.png raytracer