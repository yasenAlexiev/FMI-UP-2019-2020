//03.12.2019 UP-FMI
//Autor: Victoriya Todorova, Guthub: @viktoriyatp
//Special thanks to the autor
//

#include <iostream>

#define MAX 1000

int findMax(int index , unsigned int points[][3]){
    int maxPoints = points[index][0];
    for(int i = 1; i < 3; ++i ){
        if( maxPoints < points[index][i] ) {
            maxPoints = points[index][i];
        }
    }
    return maxPoints;
}


int main() {
	unsigned pointsForManyPlayers[MAX][3];
	size_t numPlayers;

	do{
		std::cout << "Enter number of players: ";
		std::cin >> numPlayers;
	} while (numPlayers < 0 || numPlayers > MAX);

	for(int i = 0; i < numPlayers; ++i) {
		for(int j = 0; j < 3; ++j) {	
			std::cin >> pointsForManyPlayers[i][j];
		}
	}

	for(int i = 0; i < numPlayers; ++i) {
		std::cout << findMax(i, pointsForManyPlayers) << std::endl;
	}

	return 0;
}
