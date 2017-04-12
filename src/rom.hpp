#ifndef ROM_H
#define ROM_H


#include <string>
#include <iostream>

using namespace std;

class ROM
{
    public:

        ROM();
        ROM(string name, int size, int crc, int md5, int sha1);
        
        string getName();
        void setName(string name);
        int getSize();
        void setSize(int size);
        int getCRC();
        void setCRC(int crc);
        int getMD5();
        void setMD5(int md5);
        int getSHA1();
        void setSHA1(int sha1);

    private:

        string name;
        int size;
        int crc;
        int md5;
        int sha1;


};
#endif
