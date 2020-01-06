#include <iostream>
#include <string.h>

int main() {

	char str[80];
	strcpy (str,"these ");
	strcat (str,"strings ");
	strcat (str,"are ");
	strcat (str,"concatenated.");
	std::cout << str << std::endl;	

	char str1[80];
	strcat (str1,"these ");
	strcat (str1,"strings ");
	strcat (str1,"are ");
	strcat (str1,"concatenated.");
	std::cout << str1 << std::endl;	

	return 0;
}
