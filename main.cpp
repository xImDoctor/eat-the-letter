#include <iostream>
#include <string>


/* Get image extension from file name as substring after last dot if it exists.
   Removes dot. If no extension returns "NONE".
   Returns string object. */
std::string getImageExtension(const char* fileName) {

	//if (!fileName)
		//return std::string("NONE");

	std::string fileNameString(fileName);
	size_t lastDotPos = fileNameString.find_last_of('.');

	if (lastDotPos == std::string::npos)
		return std::string("NONE");

	std::string fileExtension = fileNameString.substr(lastDotPos+1, fileNameString.size()-lastDotPos); // plus one to remove dot from result (skip it)

	return fileExtension;
}

// method to test GetImageExtension
void testGetImageExtension() {

	const char* fileNames[] = { "file.jpeg", "file.png", "fdsf", "ds23.mp3", "" };
	for (const char* name : fileNames)
		std::cout << name << " -> " << getImageExtension(name) << std::endl;

}

// test symbs
const std::string ASCII_SYMBOLS = "@%#/+=-:.";


char getASCIIChar(int pixelBrightness) {

	return ASCII_SYMBOLS[pixelBrightness * (ASCII_SYMBOLS.size() - 1) / 255];
}


int main() {

	setlocale(0, "rus");

	testGetImageExtension();


	return 0;
}