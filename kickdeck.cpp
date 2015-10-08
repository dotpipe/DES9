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

std::vector<bool> dmiro(long n_bytes, std::vector<bool> tmp) {

    int y;

    if (tmp.size()>=n_bytes*8+1)
        return tmp; 
    else
        tmp.push_back(std::vector<bool>);

    for (std::vector<bool>::iterator v : tmp) {
        std::cout << v;
       

       if (strcmp((const char*)y,"00"))
              tmp.insert(0,v>>4);
       if (strcmp((const char*)y,"10"))
              tmp.insert(0,v>>3);
       if (strcmp((const char*)y,"11"))
              tmp.insert(0,v<<1);
       if (strcmp((const char*)y,"01"))
              tmp.insert(0,v>>2);
        y=tmp.at(tmp.end()-v-1) + tmp.at(tmp.end()-v);
    }

    return dmiro( n_bytes, tmp);
}

std::vector<bool> mirror(std::vector<bool> tmp) {

    int y;

    if (sizeof(tmp)<=5)
        return tmp;

    for (auto v : tmp) {

       if (strcmp((const char*)y,"00"))
              tmp.insert(0,v<<4);
       if (strcmp((const char*)y,"01"))
              tmp.insert(0,v<<2);
       if (strcmp((const char*)y,"10"))
              tmp.insert(0,v<<3);
       if (strcmp((const char*)y,"11"))
              tmp.insert(0,v>>1);
       else tmp.pop_back();
       
       y=tmp.at(tmp.end()-v-1) + tmp.at(tmp.end()-v);
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
    in.seekg (0, in.beg);b
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
        std::vector<bool> tmp;
        tmp.reserve(30000000);
        if (lenint*8+1>=tmp.max_size())
            return 0;
        else
            tmp.insert(tmp.begin(),argy,argy+5);
        std::cout << "Let's do this!" << tmp << endl;

        tmp=dmiro(lenint,tmp);
    
        out.write((const char*)&tmp,tmp.size());
        
    }
            
    return 0;
}
