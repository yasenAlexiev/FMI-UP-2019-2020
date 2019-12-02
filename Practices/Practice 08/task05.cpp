//03.12.2019 UP-FMI
//Autor: Victoriya Todorova, Guthub: @viktoriyatp
//Special thanks to the autor
//

#include <iostream>

#define maxsize 100

int main() {
	unsigned int n,m;
	std::cin >> n >> m;
    int nums[maxsize][maxsize];

    for (int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
			std::cin>>nums[i][j];
        }
    }

    int sumd1=0, sumd2=0;
    for (int i=0; i<n ; i++){
        sumd1 += nums[i][i];
    }
    for (int j=0; j<n ; j++){
    	sumd2 += nums[n-1-j][j];
    }

    if(n%2==0){
		std::cout << sumd1+sumd2-nums[n/2][n/2] << std::endl;
    } else {
		std::cout << sumd1+sumd2 << std::endl;
	}
	return 0;
}
