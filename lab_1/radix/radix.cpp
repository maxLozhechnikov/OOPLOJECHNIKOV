#include <iostream>
#include <fstream>
#include <string>

int charToDigit(char letter)
{
	if (letter == '0' || letter == '1' || letter == '2' || letter == '3' || letter == '4' || letter == '5' || letter == '6' || letter == '7'|| letter == '8' || letter == '9') {
		return (int)letter - 48;
	}
	else {
		int i(letter);
		i = i - 87;
		return i;
	}
}

void outputNewValue(int newValue, int newNotation, std::string outString)
{
	do {
		int i = newValue % newNotation;
		newValue = newValue / newNotation;
		if (i < 10) {
			i += 48;
		}
		else {
			i += 87;
		}
		char ch = (char)(i);
		outString.insert(outString.begin(), ch);
	} while (newValue != 0);
	std::cout << outString;
}

int trans(int oldNotation, std::string value)
{
	size_t rank = 0;
	int newValue = 0;
	while (rank < value.length())
	{
		char letter = value.at(rank);
		int num1 = charToDigit(letter);
		rank++;
		newValue = newValue + (num1 * pow(oldNotation, (value.length() - rank)));
	}
	return newValue;
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout << "Invalid argument count\n"
			<< "Usage: radix.exe <source notation> <destination notation> <value> \n";
		return 1;
	}
	int oldNotation = std::stoi(argv[1]);
	int newNotation = std::stoi(argv[2]);
	std::string value = argv[3];
	int newValue = trans(oldNotation, value);
	std::ofstream output;
	output.open("output.txt");
	std::string outString;
	outputNewValue(newValue, newNotation, outString);
}