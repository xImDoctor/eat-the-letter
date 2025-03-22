//#include "ascii_preprocessing.h" // string, iostream

#include "printer/printer.h"
#include "img-processing/img-processing.h"	// ascii_preprocessing.h


std::string getAbsolutePath(const std::string& relativePath) {

	char fullPath[MAX_PATH];
	if (GetFullPathNameA(relativePath.c_str(), MAX_PATH, fullPath, nullptr))
		return std::string(fullPath);

	// return string with exception msg if file not found
	return std::string("Exception: file not found");
}



int main() {

	setlocale(0, "rus");

	//imdoc::testGetImageExtension();
	//const char* name = "file.mpeg";
	//std::cout << imdoc::getImageExtension(name) << std::endl;

	//std::wstring testString = L"This is text print string";
	//printDocument(testString);

	const char* fileName = "kit.jpg";
	const char* outputName = "output.jpg";
	//std::string fullPath = getAbsolutePath(std::string(fileName));
	//std::cout << "Абсолютный путь к файлу: " << fullPath << std::endl;

	PROCESS_IMAGE(fileName, outputName);

	showJPGtoASCII(outputName);


	return 0;
}