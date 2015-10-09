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
#include <iterator>
#include <exception>

using namespace std;

std::vector<int> dmiro(long n_bytes, std::vector<int> tmp) {
    
std::cout << n_bytes;
    int *e;
    if (tmp.size()>=n_bytes*8+1)
        return tmp; 
    else
        tmp.push_back(std::vector<int>);
    
    for (int v : tmp) {
        try {
            if (strcmp((const int*)y,"00"))
              tmp.push_back(v>>4);
            if (strcmp((const int*)y,"10"))
              tmp.push_back(v>>3);
            if (strcmp((const int*)y,"11"))
              tmp.push_back(v<<1);
            if (strcmp((const int*)y,"01"))
              tmp.push_back(v>>2);
              int *y[3]= { tmp[v-1], tmp[v], '\0' };
        }
        catch (std::exception &e) {
            tmp.reserve(n_bytes*8+1);
            throw e;
        }
    }
    return dmiro( n_bytes, tmp);
}

std::vector<int> mirror(std::vector<int> tmp) {

    if (sizeof(tmp)<=5)
        return tmp;

    for (int v=tmp.end();v<=tmp.begin();--v) {
        try {

       if (strcmp((const int*)y,"00"))
              tmp.push_back(v<<4);
       if (strcmp((const int*)y,"01"))
              tmp.push_back(v<<2);
       if (strcmp((const int*)y,"10"))
              tmp.push_back(v<<3);
       if (strcmp((const int*)y,"11"))
              tmp.push_back(v>>1);
       else tmp.pop_back();
        bool *y[3]={ tmp[v-1], tmp[v], '\0' };
        }
        
        //catch
        
    }
    return mirror(tmp);
}

int main(int x, char ** argc, char * argv[]) {
    int *e;
    fstream out;
    out.open (argv[2], ios::out | ios::binary);
    fstream in;
    in.open (argv[1], ios::in | ios::binary);
    in.seekg (0, in.end);
    std::istringstream length;
    length << in.tellg();
    long lenint=std::stol(length.str());
    in.seekg (0, in.beg);
    if (strcmp("-c",argv[0]) && in.is_open() && out.is_open()) {
        std::vector<int> tmp;
        if (tmp.max_size()>=lenint) {}
        else return 0;
        int * tmpvar= new int[sizeof(int)*lenint*8+1];
        tmp.reserve(sizeof(tmpvar)+1);
        in.read(tmpvar,length);
        
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
        in.close();
        std::cout << "enter 5 bits";
        int argy;
        std::cin >> argy;
        std::cout << "enter byte size";
        std::cin >> lenint;
        try {
        std::vector<int> tmp (6,0);
        tmp.reserve(30000);
        if (lenint*8+1<=tmp.max_size())
            return 0;
        tmp[0].push_back(argy);
        }
        catch (std::exception &e) {
            tmp.reserve(100000);
            throw e;
        }
        std::cout << "Let's do this!" << endl;

        tmp=dmiro(lenint,tmp);
    
        out.write((const char*)&tmp,tmp.size());
        
    }
            
    return 0;
}
