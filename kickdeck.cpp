// Build, Compile, Run
// ./des -c <input file> <output file>
// ./des -d <input file> <output file>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

std::vector<bool> dmiro(std::vector<bool>::size_type n_bytes, std::vector<bool> tmp) {

    int y;

    if (sizeof(tmp)>=n_bytes)
        return tmp;
    
    tmp.push_back(0010);

    for (auto v : tmp) {

       y=tmp.at(v-1-1) + tmp.at(v-1);

       if (strcmp((const char*)y,"00"))
              (v>>4);
       if (strcmp((const char*)y,"10"))
              (v>>3);
       if (strcmp((const char*)y,"11"))
              (v<<1);
       if (strcmp((const char*)y,"01"))
              (v>>2);
    }

    return dmiro( n_bytes, tmp);
}

std::vector<bool> mirror(std::vector<bool> tmp) {

    int y;

    if (sizeof(tmp)<=5)
        return tmp;

    for (auto v : tmp) {
       
       y=tmp.at(v-1-1) + tmp.at(v-1);

       if (strcmp((const char*)y,"00"))
              (v<<4);
       if (strcmp((const char*)y,"01"))
              (v<<2);
       if (strcmp((const char*)y,"10"))
              (v<<3);
       if (strcmp((const char*)y,"11"))
              (v>>1);
       tmp.pop_back();
    }
    return mirror(tmp);
}

int main(int x, char ** argc, char * argv[]) {
    fstream out;
    out.open (argv[4], ios::out | ios::binary);
    fstream in;
    in.open (argv[3], ios::in | ios::binary);
    in.seekg (0, in.end);
    std::ostringstream length;
    length << in.tellg();
    int lenint=std::stol(length.str());
    in.seekg (0, in.beg);
    if (strcmp("-c",argv[0]) && in.is_open() && out.is_open()) {
        std::vector<bool> tmp;
        if (tmp.max_size()>=lenint) {}
        else return 0;
        char * tmpvar= new char[sizeof(char)*lenint];
        tmp.reserve(sizeof(tmpvar));
        in.read(tmpvar,lenint);
        
        for (int v=0;v<=sizeof(tmpvar);v++)
            tmp.push_back(tmpvar[v]);
        tmp=mirror(tmp);
        lenint=lenint*8;
        out << lenint;
        out << endl;
        out.write((const char*)&tmp,tmp.size());
        out << endl;
    }
    if (strcmp("-d",argv[0])) {
        std::cout << "enter 5 bits";
        char argy[6]={ };
        std::cin >> argy;
        std::cout << "enter byte size";
        std::cin >> lenint;
        std::vector<bool, lenint*8+1> tmp;
        if (lenint*8>=tmp.max_size())
            return 0;
        else
           std::cout << "Let's do this!";

        tmp=dmiro(tmp.capacity(),tmp);
    
        out.write((const char*)&tmp,tmp.size());
        
    }
            
    return 0;
}
