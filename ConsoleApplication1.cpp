#include <iostream>

#include <fstream>

#include <string>

using std::string;

using namespace std;

void countAndWriteDigitsPerLine(string filename, string outputFilename)

{

	int number = 0;

	string myText;

	ifstream Read(filename);

	ofstream Write(outputFilename);

	while (getline(Read, myText)) {

		for (int i = 0; i < myText.size(); i++) {

			if (isdigit(myText[i])) {

				number++;

			}

		}

		Write << number;

		Write << "\n";

		number = 0;

	}

	Read.close();

	Write.close();

}

unsigned int countMaxDigits(string filename)

{

	int number = 0;

	int max = 0;

	string Text;

	ifstream Read(filename);

	while (getline(Read, Text)) {

		for (int i = 0; i < Text.size(); i++) {

			if (isdigit(Text[i])) {

				number++;

			}

		}

		if (number > max) {

			max = number;

		}

		number = 0;

	}

	Read.close();

	return max;

}

int main() {

	countAndWriteDigitsPerLine("filename.txt", "outputFilename.txt");

	cout << countMaxDigits("filename.txt");

}