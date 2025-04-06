#ifndef _ASCII_PREPROCESSING_H_
#define _ASCII_PRERPOCESSING_H_

#include <string>
#include <iostream>
#include <Windows.h>

namespace imdoc {

	/* Get image extension from file name as substring after last dot if it exists.
	   Removes dot. If no extension returns "NONE".
	   Returns string object. */
	std::string getImageExtension(const char* fileName);

	/* Get absolute path of file in string relativePath using Windows.h GetFullPathNameA*/
	std::string getAbsolutePath(const std::string& relativePath);

	// method to test GetImageExtension
	void testGetImageExtension();

	// test symbs
	const std::string ASCII_SYMBOLS = "@%#/+=-:.";

	char getASCIIChar(int pixelBrightness);
}

#endif