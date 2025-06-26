#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int j = 1; j < argc; ++j)
	{
		std::string str = argv[j];
		for (size_t i = 0; i < str.length(); ++i)
		{
			if (std::islower(str[i]))
				std::cout << static_cast<char>(std::toupper(str[i]));
			else
				std::cout << str[i];
		}
	}
	std::cout << std:: endl;
	return (0);
}