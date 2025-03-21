#include "ascii_preprocessing.h" // string, iostream


int main() {

	setlocale(0, "rus");

	imdoc::testGetImageExtension();

	const char* name = "file.mpeg";
	std::cout << imdoc::getImageExtension(name) << std::endl;


	return 0;
}