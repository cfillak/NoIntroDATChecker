#include "rom.hpp"

// using std::string;

string ROM::getName()
{
    return name;
}

void ROM::setName(string name)
{
    this->name = name;
}

int ROM::getSize()
{
    return size;
}

void ROM::setSize(int size)
{
    this->size = size;
}

int ROM::getCRC()
{
    return crc;
}

void ROM::setCRC(int crc)
{
    this->crc = crc;
}

int ROM::getMD5()
{
    return md5;
}

void ROM::setMD5(int md5)
{
    this->md5 = md5;
}

int ROM::getSHA1()
{
    return sha1;
}

void ROM::setSHA1(int sha1)
{
    this->sha1 = sha1;
}

ROM::ROM()
{
    name = "";
    size = -1;
    crc = -1;
    md5 = -1;
    sha1 = -1;
}

ROM::ROM(string name, int size, int crc, int md5, int sha1)
{
    this->name = name;
    this->size = size;
    this->crc = crc;
    this->md5 = md5;
    this->sha1 = sha1;
}
