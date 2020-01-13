#include <iostream>
#include <string.h>
#include <math.h>

typedef unsigned short Usint;

char* itoa(Usint count) {
    Usint length = log10(count) + 1;
    char* numberStr = new (std::nothrow) char[length + 1];
    numberStr[length] = '\0';
    for(int i = length - 1; i >= 0; --i){
        numberStr[i] = (count % 10) + '0';
        count /= 10;
    }

    return numberStr;
}


char* generateRecursive(Usint number, Usint count) {
    if(count > number) {
        return "\0";
    }

    char* preffix = itoa(count);
    char* suffix = generateRecursive(number, count+1);

    char* str = new (std::nothrow) char[strlen(preffix) * count + strlen(suffix) + 1];
    strcpy(str, preffix);
    for(int i = 0; i < count - 1; ++i) {
        strcat(str, preffix);
    }
    strcat(str, suffix);
    delete[] preffix;
    if(*suffix != '\0') {
        delete[] suffix;
    }
    return str;
}

char* generate(Usint number) {
    return generateRecursive(number, 1);
}
int main() {

    // Да се напише рекурсивна функция, която по подадено число връща редица от
    // следния вид:
    // 122333444455555....nn...nnn
    //                    \n пъти/
    //---------------------------------

    Usint number;
    std::cin >> number;
    char* str = generate(number);
    std::cout << str << std::endl;
    delete[] str;

    return 0;
}
