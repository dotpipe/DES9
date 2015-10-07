// Build, Compile, Run
// ./des -c <input file> <output file>
// ./des -d <input file> <output file>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

std::vector<bool> dmiro(std::vector<bool>::size_type n_bytes, std::vector<bool> tmp) {

    int y;

    if (sizeof(tmp)>=n_bytes)
        return tmp;
    
    tmp.reserve(n_bytes);

    for (auto v : tmp) {

       y=tmp.at(tmp.end()-v-1) + tmp.at(tmp.end()-v);

       if (strcmp((const char*)y,"00"))
              tmp[v]=(tmp[v]>>4);
       if (strcmp((const char*)y,"10"))
              tmp[v]=(tmp[v]>>3);
       if (strcmp((const char*)y,"11"))
              tmp[v]=(tmp[v]<<1);
       if (strcmp((const char*)y,"01"))
              tmp[v]=(tmp[v]>>2);
    }

    return dmiro( n_bytes-3, tmp);
}

std::vector<bool> mirror(std::vector<bool> tmp) {

    int y;

    if (sizeof(tmp)<=5)
        return tmp;

    for (auto v= tmp.end(); v != tmp.begin(); --v) {
       
       y=tmp.at(v-1-1) + tmp.at(v-1);

       if (strcmp((const char*)y,"00"))
              tmp[v]=(tmp[v]<<4);
       if (strcmp((const char*)y,"01"))
              tmp[v]=(tmp[v]<<2);
       if (strcmp((const char*)y,"10"))
              tmp[v]=(tmp[v]<<3);
       if (strcmp((const char*)y,"11"))
              tmp[v]=(tmp[v]>>1);
       tmp.pop_back();
    return mirror(tmp);
    }
}

int main(int x, char ** argc, char * argv[]) {
    fstream out;
    out.open (argv[4], ios::out | ios::binary);
    fstream in;
    in.open (argv[3], ios::in | ios::binary);
    in.seekg (0, in.end);
    std::string length = in.tellg();
    int lenint=in.tellg;
    in.seekg (0, in.beg);
    if (strcmp("-c",argv[0]) && in.is_open() && out.is_open()) {
        std::vector<bool> tmp;
        if (tmp.max_size()>=lenint) {}
        else return 0;
        char * tmpvar= new char[sizeof(char)*lenint];
        tmp.reserve(sizeof(tmpvar));
        in.read(tmpvar,lenint);
        
        for (int v : tmpvar)
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
        char argy[16]={ };
        std::cin >> argy;
        for (int c=1;c<=2;c++)
            argy[c*5-1]+=argy[0];
        std::vector<bool> tmp;
        for (int v : argy)
            tmp.push_back(argy[v]);
        std::cout << "enter byte size";
        std::cin >> lenint;
        if (lenint>=tmp.max_size())
            return 0;
        else
           std::cout << "Let's do this!";

        vector<bool>::size_type sz;
        tmp=dmiro(tmp.capacity(),tmp);
    
        out.write((const char*)&tmp,tmp.size());
        
    }
            
    return 0;
}
