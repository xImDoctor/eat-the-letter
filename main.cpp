//#include "ascii_preprocessing.h" // string, iostream

#include "printer/printer.h"
#include "img-processing/img-processing.h"	// ascii_preprocessing.h





int main() {

	setlocale(0, "rus");

	//std::wstring testString = L"This is text print string";
	//printDocument(testString);

	const char* fileName = "kit.jpg";
	const char* outputName = "output.jpg";
	const char* textASCIIfileName = "image_to_ascii.txt"

	PROCESS_IMAGE(fileName, outputName);	//processJPG, processPNG

	std::ofstream textASCII(textASCIIfileName);

	SHOW_IMAGE_TO_ASCII(outputName, textASCII);		//showJPG, showPNG



	return 0;
}