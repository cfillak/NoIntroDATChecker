COMPILER = g++
LINKER = g++


datchecker : main.o pugixml.o hl_md5.o hl_md5wrapper.o hl_sha1.o hl_sha1wrapper.o
	$(LINKER) main.o pugixml.o hl_md5.o hl_md5wrapper.o hl_sha1.o hl_sha1wrapper.o -o datchecker

main.o : src/main.cpp src/pugixml.hpp src/hashlibpp.h
	$(COMPILER) -c src/main.cpp

pugixml.o : src/pugixml.cpp src/pugixml.hpp
	$(COMPILER) -c src/pugixml.cpp

hl_md5.o : src/hl_md5.cpp src/hl_md5.h
	$(COMPILER) -c src/hl_md5.cpp

hl_md5wrapper.o : src/hl_md5wrapper.cpp src/hl_md5wrapper.h
	$(COMPILER) -c src/hl_md5wrapper.cpp

hl_sha1.o : src/hl_sha1.cpp src/hl_sha1.h
	$(COMPILER) -c src/hl_sha1.cpp

hl_sha1wrapper.o : src/hl_sha1wrapper.cpp src/hl_sha1wrapper.h
	$(COMPILER) -c src/hl_sha1wrapper.cpp

clean :
	@rm -f *.o
