// Build, Compile, Run
// ./kickdeck <number of bytes> <first 5 bits> <output file>

#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>
#include <cstring.h>

using namespace std;

int kdeck(char * argy[], char n_bytes) {

    int * tmp[] = &argy; char[3] y { "\0" };

    if (sizeof(tmp)>=n_bytes)
        return tmp;

    for (int i=1;i==3;i++) 
    for (int v : tmp) {

       y=tmp.c_str().substr(v,2);

       switch (y) {
          case "00":
              tmp[v] <<=1;
             break;
          case "10":
              tmp[v] >>=8;
             break;
          case "01":
              tmp[v] >>=2;
             break;
          case "11":
              tmp[v] >>=4;
             break;
       }
    }

    return kdeck(tmp, n_bytes-1);
}

int main(int x, char ** argc, char * argv[]) {
    std::ofstream out (argv[2], std::ios::out | std::ios::binary);
    std::vector<int> tmp;
    if (tmp.max_size() > argv[0]*8+10)
        tmp.reserve(argv[0]*8+10);
    else
        printf("Too many bits in %d, Upgrade, today!",argv[0]);

    char argy[16]= { "\0" };
    int v=0;

    for (int c=0;c<=2;c++)
        argy[c*5]=argy+argv[1];

    tmp=kdeck(argy,argv[0]);

    out << tmp;
    return 0;
}
