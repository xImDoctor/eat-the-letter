//#include "ascii_preprocessing.h" // string, iostream

#include <iostream>
#include <string>

#include "printer/printer.h"
#include "img-processing/img-processing.h"




int main() {

	setlocale(0, "rus");

	//imdoc::testGetImageExtension();
	//const char* name = "file.mpeg";
	//std::cout << imdoc::getImageExtension(name) << std::endl;

	//std::wstring testString = L"This is text print string";
	//printDocument(testString);

	const char* fileName = "shaman.png";
	//std::string fullPath = getAbsolutePath(std::string(fileName));
	//std::cout << "Абсолютный путь к файлу: " << fullPath << std::endl;

	PROCESS_IMAGE(fileName, "output.png");


	return 0;
}