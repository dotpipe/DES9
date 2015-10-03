// Build, Compile, Run
// ./kickdeck <number of bytes> <first 5 bits> <output file>

#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>
#include <cstring.h>

using namespace std;

int kdeck(char * argy[], char n_bytes) {


    if (sizeof(tmp)>=n_bytes)
        return tmp;

    for (;v/8<=n_bytes;v++) {

        if (v<16)
            y=argy.c_str().substr(v,2);
        else
            y=tmp;

        switch (y) {
          case 00:
              tmp[v] <<=1;
             break;
          case 10:
              tmp[v] >>=8;
             break;
          case 01:
              tmp[v] >>=2;
             break;
          case 11:
              tmp[v] >>=4;
             break;
        }
    }

    return kdeck(tmp, n_bytes-3);
}

int main(int x, char ** argc, char * argv[]) {
    std::ofstream out (argv[3], std::ios::out | std::ios::binary);
    int tmp[33]= { "\0" };
    char y[33]= { "\0" };
    char argy[16]= { "\0" };
    int v=0;

    for ( int c=0;c<=2;c++)
        argy=argy[c*5]+argv[2];

    tmp=kdeck(argy,argv[0]);

    out << tmp;
    return 0;
}
