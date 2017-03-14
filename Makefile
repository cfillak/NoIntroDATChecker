COMPILER = g++
LINKER = g++

datchecker : main.o rom.o dat.o
	$(LINKER) main.o rom.o dat.o -o datchecker

main.o : main.cpp rom.h
	$(COMPILER) -c main.cpp

rom.o : rom.cpp rom.h
	$(COMPILER) -c rom.cpp

dat.o : dat.cpp dat.h
	$(COMPILER) -c dat.cpp

clean :
	@rm -f *.o
