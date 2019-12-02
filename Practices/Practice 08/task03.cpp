//03.12.2019 UP-FMI
//Autor: Victoriya Todorova, Guthub: @viktoriyatp
//Special thanks to the autor
//

#include<iostream>

#define maxsize 100

int main() {
    unsigned int n,m;
    double sumOfTheNums[maxsize][maxsize];

	std::cout << "Enter size of matrix: ";
	std::cin >> n >> m;

    for (int i=0; i<n ; i++){
        for(int j=0; j<m;j++){
			std::cin >> sumOfTheNums[i][j];
        }
    }

    double sum = 0;
    for (int i=0; i<n ; i++){
        for(int j=0; j<m;j++){
            sum += sumOfTheNums[i][j];
        }
    }

	std::cout << sum << std::endl;

	return 0;
}
