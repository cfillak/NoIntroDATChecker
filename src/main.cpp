// #include "rom.hpp"
#include "pugixml.hpp"

#include "hl_exception.h"
#include "hl_wrapperfactory.h"
#include "hl_hashwrapper.h"
#include "hl_md5.h"
#include "hl_md5wrapper.h"
#include "hl_sha1.h"
#include "hl_sha1wrapper.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using namespace pugi;
// using namespace MD5;
std::string SetDir = "";

int parse(const char * DatFileName);

string StringToUpper(string strToConvert)
{
   for (string::iterator p = strToConvert.begin(); strToConvert.end() != p; ++p) {
       *p = toupper(*p);
   }
   return strToConvert;
}

string md5Rom(const char * RomPath)
{
    md5wrapper::hashwrapper *wrap = new md5wrapper();
    string md5(wrap->getHashFromFile(SetDir + "/" + RomPath));
    return StringToUpper(md5);
}

string sha1Rom(const char * RomPath)
{
    sha1wrapper::hashwrapper *wrap = new sha1wrapper();
    string sha1(wrap->getHashFromFile(SetDir + "/" + RomPath));
    return StringToUpper(sha1);
}


int main(int argc, char ** argv)
{
    if (argc < 2)
    {
        // Double quotes for strings, single for character literals
        cout << "Usage: ./datchecker [datfile.dat]" << '\n';
        return 0;
    }
    SetDir = argv[2];
    // cout << setDir << endl;
    parse(argv[1]);
    // setDir = argv[2];

}


int parse(const char * DatFileName)
{
    xml_document DatFile;
    xml_parse_result result = DatFile.load_file(DatFileName, parse_default, encoding_auto);
    xml_node root = DatFile.child("datafile");

    for (xml_node MyNode = root.child("header"); MyNode; MyNode = MyNode.next_sibling("game"))
    {
        for (xml_attribute_iterator ait = MyNode.child("rom").attributes_begin(); ait != MyNode.child("rom").attributes_end(); ++ait)
        {
            if (strncmp(ait->name(), "name", 4) == 0) {
                cout << " " << ait->name() << "=" << ait->value() << endl;
                string md5 = md5Rom(ait->value());
                string sha1 = sha1Rom(ait->value());
                cout << "md5: " << md5 << endl;
                cout << "sha1: " << sha1 << endl;
            }

        }

    }

    return 0;
}
