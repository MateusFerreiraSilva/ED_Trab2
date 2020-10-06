#include<bits/stdc++.h>
using namespace std;

int main() {
    unsigned char* buffer;
    buffer = (unsigned char*) malloc (sizeof(unsigned char) * 6);

    int aux = 0;
    for(int i = 0; i < 6; i++)
        buffer[aux++] = i;

    aux = 0;
    for(int i = 0; i < 6; i++) {
            printf("%hhu\n", buffer[aux++]);
    } // for

}