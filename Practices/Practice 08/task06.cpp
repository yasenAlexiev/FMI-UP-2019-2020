//03.12.2019 UP-FMI
//Autor: Victoriya Todorova, Guthub: @viktoriyatp
//Special thanks to the autor
//

#include <iostream>

#define maxsize 100

int SumOfColumn(int F[][maxsize], int rows, int NumberColumn){
    int sumC=0;
    for(int i=0; i<rows; i++){
        sumC += F[i][NumberColumn];
    }
    return sumC;
}

int SumOfRow(int F[][maxsize], int m, int numRow){
    int sumR=0;
    for(int i=0; i<m; i++){
        sumR += F[numRow][i];
    }
    return sumR;
}

void FindPairs(int arr[], int size) {

    for(int i=0; i < size - 1; i++){
    	for(int j = i + 1; j < size; ++j) {
    		if( arr[i]	== arr[j] ) {
    			std::cout << '(' << i << ", " << j << ") with sum " << arr[i] << std::endl;
    			break;
    		}
    	}
	}

}

void IndexEqualSums(int F[][maxsize],int sizeCols, int sizeRows){
    int sumc[maxsize] = {0, };
    int sumr[maxsize] = {0, };
    
    for( int i=0; i < sizeRows; i++ ){
		sumr[i] = SumOfRow(F, sizeCols, i);
    }

    for( int i=0; i < sizeCols; i++ ){
		sumc[i] = SumOfColumn(F, sizeRows, i);
    }
	
	std::cout << "Pairs for columns: " << std::endl;
	FindPairs( sumc, sizeCols );
	
	std::cout << "Pairs for rows: " << std::endl;
	FindPairs( sumr, sizeRows );
}

int main() {
    int F[maxsize][maxsize];
    int n,m;
	std::cout << "Enter size of matrix: ";
	std::cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
			std::cin>>F[i][j];
        }
    }

    int column, row;
	std::cin >> column;
	std::cout << "Sum of numbers on column is: " << SumOfColumn(F,n,column) << std::endl;

	std::cin >> row;
	std::cout << "Sum of numbers on row is: " << SumOfRow(F,m,row) << std::endl;

	std::cout << "\nDuplicate sums in matrix: " << std::endl;
	IndexEqualSums(F, m, n);
    return 0;
}
