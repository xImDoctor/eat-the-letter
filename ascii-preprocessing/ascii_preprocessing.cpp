#include "ascii_preprocessing.h"


/* Get image extension from file name as substring after last dot if it exists.
   Removes dot. If no extension returns "NONE".
   Returns string object. */
std::string imdoc::getImageExtension(const char* fileName) {

	//if (!fileName)
		//return std::string("NONE");

	std::string fileNameString(fileName);
	size_t lastDotPos = fileNameString.find_last_of('.');

	if (lastDotPos == std::string::npos)
		return std::string("NONE");

	std::string fileExtension = fileNameString.substr(lastDotPos + 1, fileNameString.size() - lastDotPos); // plus one to remove dot from result (skip it)

	return fileExtension;
}

// get absolute path using relative one
std::string imdoc::getAbsolutePath(const std::string& relativePath) {

	char fullPath[MAX_PATH];
	if (GetFullPathNameA(relativePath.c_str(), MAX_PATH, fullPath, nullptr))
		return std::string(fullPath);

	// return string with exception msg if file not found
	return std::string("Exception: file not found");
}

// method to test GetImageExtension
void imdoc::testGetImageExtension() {

	const char* fileNames[] = { "file.jpeg", "file.png", "fdsf", "ds23.mp3", "" };
	for (const char* name : fileNames)
		std::cout << name << " -> " << imdoc::getImageExtension(name) << std::endl;

}


char imdoc::getASCIIChar(int pixelBrightness) {

	return imdoc::ASCII_SYMBOLS[pixelBrightness * (imdoc::ASCII_SYMBOLS.size() - 1) / 255];
}
