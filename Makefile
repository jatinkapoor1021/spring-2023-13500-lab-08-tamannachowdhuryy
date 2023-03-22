main: main.o funcs.o imageio.o
	g++ -o main main.o funcs.o imageio.o

funcs.o: funcs.cpp funcs.h imageio.h

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h


clean:
	rm -f sample.o imageio.o funcs.o
