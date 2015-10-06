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

std::vector<char> miro(std::vector<char>::size_type n_bytes, std::vector<char> tmp) {

    int y;

    if (sizeof(tmp)>=n_bytes)
        return tmp;

    for (long unsigned int v = tmp.begin(); v != tmp.end(); ++v) {

       y=tmp.at(tmp.end()-v-1) + tmp.at(tmp.end()-v);

       if (strcmp((const char*)y,"00"))
              tmp[v] =(tmp[v]<<1);
       if (strcmp((const char*)y,"10"))
              tmp[v] =(tmp[v]>>8);
       if (strcmp((const char*)y,"01"))
              tmp[v] =(tmp[v]>>2);
       if (strcmp((const char*)y,"11"))
              tmp[v] =(tmp[v]>>4);
    }

    return miro( n_bytes, tmp);
}

std::vector<char> mirror(std::vector<char> tmp) {

    int y;

    if (sizeof(tmp)<=5)
        return tmp;

    for (long unsigned int v= tmp.end(); v != tmp.begin(); --v) {
       
       y=tmp.at(v-1-1) + tmp.at(v-1);

       if (strcmp((const char*)y,"00"))
              tmp[v] =(tmp[v]>>1);
       if (strcmp((const char*)y,"10"))
              tmp[v] =(tmp[v]<<8);
       if (strcmp((const char*)y,"01"))
              tmp[v] =(tmp[v]<<2);
       if (strcmp((const char*)y,"11"))
              tmp[v] =(tmp[v]<<4);
    }

    return mirror(tmp);
}

int main(int x, char ** argc, char * argv[]) {
    fstream out;
    out.open (argv[4], ios::out | ios::binary);
    fstream in;
    in.open (argv[3], ios::in | ios::binary);
    std::vector<char> tmp;
    if (strcmp("-c",argv[0])) {
        in.seekg (0, in.end);
        int length = in.tellg();
        in.seekg (0, in.beg);

        if (tmp.max_size() > length && in && out) {
            tmp.reserve(length+1);
            in.read(tmp,length);
            tmp=mirror(tmp);
            out << length*8 << endl;
            out << tmp << endl;
        }
        else {
            printf("Too many bits in %s, Upgrade, today!",argv[1]);
            return 0;
        }
    }
    if (strcmp("-d",argv[0])) {
        std::string length;
        getline(in,length);
        std::string argy;
        getline(in,argy);

        tmp.reserve(length+10);

        for (int c=1;c<=2;c++)
            argy[c*5]+=argy[0];

        tmp=miro((int)length,tmp);

    }

    out << (const char*)tmp;
    return 0;
}
