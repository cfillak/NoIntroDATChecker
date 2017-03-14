#include "rom.h"
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
    string line;
    cout << datFileName << '\n';
    ifstream datfile(datFileName);

    if (datfile.is_open())
    {
        while ( getline (datfile,line) )
        {
            if (line.compare(1,5,"rom (") == 0)
            {
                int namepos = line.find("name", 0);
                int sizepos = line.find("size", namepos);
                int crcpos = line.find("crc", sizepos);
                int md5pos = line.find("md5", crcpos);
                int sha1pos = line.find("sha1", md5pos);

                string name = line.substr(namepos, sizepos-namepos);
                name = name.substr(6);
                name = name.substr(0, name.length()-2);
                cout << name << '\n';

                string size = line.substr(sizepos, crcpos-sizepos);
                size = size.substr(5);
                cout << size << '\n';

                string crc = line.substr(crcpos, md5pos-crcpos);
                crc = crc.substr(4);
                cout << crc << '\n';

                string md5 = line.substr(md5pos, sha1pos-md5pos);
                md5 = md5.substr(4);
                cout << md5 << '\n';

                string sha1 = line.substr(sha1pos);
                sha1 = sha1.substr(5);
                cout << sha1 << '\n';

            }

        }
    datfile.close();
    }
    return 0;
}
