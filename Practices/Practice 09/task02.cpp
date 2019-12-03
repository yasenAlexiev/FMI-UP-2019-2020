// Autor: Viktoriya Todorova, Github: @viktoriyatp

#include<iostream>

using namespace std;

#define maxsize 100

int main() {
    unsigned int size;
    cin>>size;

    int numbers[maxsize];
    for(int i=0; i<size; i++){
        cin>>numbers[i];
    }
    
    int temp;
    for(int i=0;i<size-1; i++){
        for(int j =i+1 ; j<size; j++){
            if(numbers[i] > numbers[j]) {
                temp=numbers[i];
                numbers[i]=numbers[j];
                numbers[j]=temp;
            }

        }
    }

    for(int i=0;i<size; i++){
        cout<<numbers[i]<<" ";
    }
    
    return 0;
}
