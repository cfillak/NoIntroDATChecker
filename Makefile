COMPILER = g++
LINKER = g++

datchecker : main.o rom.o
	$(LINKER) main.o rom.o -o datchecker

main.o : main.cpp rom.h
	$(COMPILER) -c main.cpp

rom.o : rom.cpp rom.h
	$(COMPILER) -c rom.cpp
