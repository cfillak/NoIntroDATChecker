COMPILER = g++
LINKER = g++

datchecker : main.o rom.o dat.o
	$(LINKER) main.o rom.o dat.o -o datchecker

main.o : src/main.cpp src/rom.hpp
	$(COMPILER) -c src/main.cpp

rom.o : src/rom.cpp src/rom.hpp
	$(COMPILER) -c src/rom.cpp

dat.o : src/dat.cpp src/dat.hpp
	$(COMPILER) -c src/dat.cpp

clean :
	@rm -f *.o
