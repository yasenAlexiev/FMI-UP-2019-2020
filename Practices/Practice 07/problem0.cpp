#include <iostream>
using namespace std;

int main () {
    int n;
    cin>> n;

    int n0 = (n & 1<<0)>>0;
    int n1 = (n & 1<<1)>>1;
    int n2 = (n & 1<<2)>>2;
    int n3 = (n & 1<<3)>>3;
    int n4 = (n & 1<<4)>>4;
    int n5 = (n & 1<<5)>>5;
    int n6 = (n & 1<<6)>>6;
    int n7 = (n & 1<<7)>>7;

    cout<< n7<< n6<< n5<< n4<< n3<< n2<< n1<< n0<< endl;

    int n8Bits[8];
    for(int i = 0; i< 8; ++i) {
        n8Bits[i] = (n & (1<<i))>>i;
    }

    for(int i = 7; i>= 0; --i) {
        cout<< n8Bits[i];
    }
    cout<< endl;

    return 0;
}
