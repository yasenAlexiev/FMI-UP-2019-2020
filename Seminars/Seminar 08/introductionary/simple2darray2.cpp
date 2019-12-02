#include<iostream>
using namespace std;

int main () {

    const int totalWeekHours = 7*24;
    double weekHours[totalWeekHours];

    for(int i=0; i< 7; ++i) {
        for(int j=0; j< 24; ++j) {
            cin>> weekHours[i*24 + j];
        }
    }

    return 0;
}
