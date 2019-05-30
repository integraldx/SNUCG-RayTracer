raytracer: *.cpp *.hpp
	g++ -c *.cpp `libpng-config --cflags`
	g++ -o raytracer *.o `libpng-config --ldflags` -lpthread

run: raytracer
	./raytracer

clean: 
	rm -f *.o *.png raytracer