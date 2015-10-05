// Build, Compile, Run
// ./des -c <input file> <output file>
// ./des -d <input file> <output file>

#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>
#include <cstring.h>

using namespace std;

int miro(std::vector<int> tmp, long int n_bytes) {

    char[3] y = { "\0" };

    if (sizeof(tmp)>=n_bytes)
        return tmp;

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

    return miro(tmp, n_bytes);
}

int mirror(std::vector<int> tmp) {

    char[3] y = { "\0" };

    if (sizeof(tmp)<=5)
        return tmp;

    for (int v : tmp) {

       y=tmp.c_str().substr(tmp.c_str().len()-v-2,2);

       switch (y) {
          case "00":
              tmp[v] >>=1;
             break;
          case "10":
              tmp[v] <<=8;
             break;
          case "01":
              tmp[v] <<=2;
             break;
          case "11":
              tmp[v] <<=4;
             break;
       }
    }
    tmp.reserve(tmp.capacity()-2);

    return mirror(tmp);
}

int main(int x, char ** argc, char * argv[]) {
    std::ofstream out (argv[4], std::ios::out | std::ios::binary);
    std::ofstream in (argv[3], std::ios::in | std::ios::binary);
    std::vector<int> tmp;
    if (strcmp("-c",argv[0])) {
        in.seekg (0, in.end);
        int length = in.tellg();
        in.seekg (0, in.beg);

        if (tmp.max_size() > length && in && out) {
            tmp.reserve(length+1);
            in.read(tmp,length);
            tmp=mirror(tmp);
            out << length*8 << endl;
        }
        else {
            printf("Too many bits in %d, Upgrade, today!",argv[1]);
            return 0;
        }
    }
    if (strcmp("-d",argv[0]) {

        int length=in.getline();
        char * argy[16]=in.getline();

        tmp.reserve(length*8+10);

        for (int c=0;c<=2;c++)
            argy[c*5]=argy;

        tmp=miro(tmp,length);

    }

    out << tmp;
    return 0;
}
