#include "rom.hpp"
#include "pugixml.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int parse(string datFileName);

int main(int argc, char ** argv)
{
    if (argc < 2)
    {
        // Double quotes for strings, single for character literals
        cout << "Usage: ./datchecker [datfile.dat]" << '\n';
        return 0;
    }
    parse(argv[1]);
    // ROM *testRom = new ROM("mario.gb", 256, 1111, 2222, 3333);


}


int parse(string datFileName)
{
    
}
