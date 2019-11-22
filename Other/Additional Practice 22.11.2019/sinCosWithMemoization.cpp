#include <iostream>
#include <math.h>


double sumSinCosWITHOUTMemoizationButStuped(size_t n) {
	double result = 0;	
	double sinCurrentSum;
	double cosCurrentSum;
	for(int i = 1; i <=n; ++i) {
			
		sinCurrentSum = 0;
		cosCurrentSum = 0;
		// Бавно, защото на всяка стъпка се смята отново и отново предишните
		// sin(1), sin(2), ... , sin(i-1) и
		// cos(1), cos(2), ... , cos(i-1)
		for(int j = 1; j <= i; ++j) {
			sinCurrentSum += sin(j); // изчисляване на i-тия числител
			cosCurrentSum += cos(j); // изчисляване на i-тия знаменател
		}
		result += sinCurrentSum/cosCurrentSum; // сумиране на резултата + настоящата дроб
	}
	return result;
}



//Мемоизация! (Не мемоРизация, а мемоизация, нищо че идеята е свързана с 
//memory) (този който го е нарекъл така, сигурно не е можел да казва Р.)
//
//Мемоизация е метод в програмирането при който оптимизираме бързината на
//даден алгоритъм, чрез запазването на вече смятани неща. Така те ще бъдат
//преизползвани, а не смятани наново. Мемоизацията е свързана пряко с 
//динамичното програмиране/оптимиране.
//В тази задача може да се използва мемоизация, защото функциите sin и cos
//са тежки функции за компютъра да ги смята, за това ще пазим стойностите на
//sin(1), sin(2), ..., sin(n) в един масив и cos(1), cos(2), ...., cos(n) - 
//в друг.

#define MAX_N 2<<12
// Нека на i-та позиция се записва sin(i) =>
//sinArray[0] // dummy element(Неизползваем)
double sinArray[MAX_N];
// Същото и за cos(i) на i-та позиция
//cosArray[0] // dummy element
double cosArray[MAX_N];

double sumSinCosWithMemoization(size_t n) {
	double result = 0;	
	double sinCurrentSum;
	double cosCurrentSum;
	for(int i = 1; i <=n; ++i) {
		sinArray[i] = sin(i); // попълване на i-та позиция в масива sinArray
		cosArray[i] = cos(i); // попълване на i-та позиция в масива cosArray
			
		sinCurrentSum = 0;
		cosCurrentSum = 0;
		for(int j = 1; j <= i; ++j) {
			sinCurrentSum += sinArray[j]; // изчисляване на i-тия числител
			cosCurrentSum += cosArray[j]; // изчисляване на i-тия знаменател
		}
		result += sinCurrentSum/cosCurrentSum; // сумиране на резултата + настоящата дроб
	}
	return result;
}

//За тази задача точно, съществува и по-умен и бърз начин да се напише, дори
//и без мемоизация. Но това не означава, че мемоизацията не е полезна и да
//забързва алгоритъма много.
double sumSinCosWITHOUTMemoizationButSmart(size_t n) {	
	double result = 0;	
	double sinPreviosSum = 0; // Пазим сумата на предишния числител/знаменател
	double cosPreviosSum = 0; // и на i-та стъпка само добавяме sin(i) към числителя и cos(i) към знаменателя
	for(int i = 1; i <=n; ++i) {
		sinPreviosSum += sin(i);
		cosPreviosSum += cos(i);
			
		result += (sinPreviosSum/cosPreviosSum);
	}
	return result;
}

int main() {
	size_t n = 1000; // < MAX_N моля :)

	clock_t start, end;


	start = clock();
	std::cout << "Result: " << sumSinCosWITHOUTMemoizationButStuped(n) << std::endl;
	end = clock();
	std::cout << "sumSinCosWITHOUTMemoizationButStuped() with n = " << n << " for " <<
				(end-start)/double(CLOCKS_PER_SEC) << " seconds" << std::endl;

	
	
	start = clock();
	std::cout << "Result : " << sumSinCosWithMemoization(n) << std::endl;
	end = clock();	
	std::cout << "sumSinCosWithMemoization() with n = " << n << " for " <<
				(end-start)/double(CLOCKS_PER_SEC) << " seconds" << std::endl;



	start = clock();
	std::cout << "Result: " << sumSinCosWITHOUTMemoizationButSmart(n) << std::endl;
	end = clock();
	std::cout << "sumSinCosWITHOUTMemoizationButSmart() with n = " << n << " for " <<
				(end-start)/double(CLOCKS_PER_SEC) << " seconds" << std::endl;

	return 0;
}
