#include <iostream>

void cleanText(char* text)
{
	char* copy = text;

	if (*text == '\0')
	{
		return;
	}

	if (strlen(text) == 1)
	{
		std::cout << *text;
	}

	char current = *text;
	while (*(++text) == current);
	std::cout << current;
	cleanText(text);

}
int main()
{
	char text[120];
	std::cin >> text;

	cleanText(text);
	return 0;
}