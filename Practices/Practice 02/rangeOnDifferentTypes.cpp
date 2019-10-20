#include <iostream>
#include <limits.h>

int main() {
	std::cout << SCHAR_MIN << "\tMinimum value for a variable of type signed char. \n" <<
				 SCHAR_MAX << "\tMaximum value for a variable of type signed char. \n" <<
				 UCHAR_MAX << "\tMaximum value for a variable of type unsigned char. \n" <<
				 CHAR_MIN  << "\tMinimum value for a variable of type char.\n" <<
				 CHAR_MAX  << "\tMaximum value for a variable of type char.\n\n" <<
				 SHRT_MIN  << "\tMinimum value for a variable of type short.\n" <<
				 SHRT_MAX  << "\tMaximum value for a variable of type short.\n" <<
				 USHRT_MAX << "\tMaximum value for a variable of type unsigned short.\n\n" <<
				 INT_MIN   << "\tMinimum value for a variable of type int.\n" <<
				 INT_MAX   << "\tMaximum value for a variable of type int.\n" <<
				 UINT_MAX  << "\tMaximum value for a variable of type unsigned int.\n" <<
				 LONG_MIN  << "\tMinimum value for a variable of type long.\n" <<
				 LONG_MAX  << "\tMaximum value for a variable of type long.\n" <<
				 ULONG_MAX << "\tMaximum value for a variable of type unsigned long.\n";

	return 0;
}
