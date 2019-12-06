//03.12.2019 UP-FMI
//Autor: Victoriya Todorova, Guthub: @viktoriyatp
//Special thanks to the autor
//

#include <iostream>

int main() {
    unsigned int n,m;
    int k;
	std::cin >> n >> m >> k;
    int fill[maxsize][maxsize];
    for (int i=0; i<n ; i++){
        for(int j=0; j<m;j++){
            fill[i][j]=k;
        }
    }

    for (int i=0; i<n ; i++){
        for(int j=0; j<m;j++){
			std::cout << fill[i][j];
        }
		std::cout<<endl;
    }
    return 0;
}
