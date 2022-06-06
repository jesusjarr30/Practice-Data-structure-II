#ifndef FILELIST_H
#define FILELIST_H
#include <iostream>
#include <fstream>
#include "Personaje.h"
using namespace std;

class FileList
{
    private:
        string filename;
    public:
        FileList(string);
        void add(Personaje obj);
        void showall();
        Personaje* find(string);
        bool find_nombre(string);
        void remove(string);
        

};

#endif // FILELIST_H
