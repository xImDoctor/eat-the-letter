#ifndef _IMAGE_PREPROCESSING_H_
#define _IMAGE_PREPROCESSING_H_

#include "../ascii_preprocessing.h"

#include <FreeImage.h>
#include <iostream>


//#define PROCESS_IMAGE(file, output) \
    (getExtension(file) == "png" ? processImagePNG(file, output) : processImageJPEG(file, output))

#define PROCESS_IMAGE(file, output) \
    do { \
        if (imdoc::getImageExtension(file) == "png") { \
            imdoc::processImagePNG(file, output); \
        } else if (imdoc::getImageExtension(file) == "jpg") { \
            imdoc::processImageJPEG(file, output); \
        } \
        else { \
            std::cerr << "Ошибка: не подходящее расширение файла " << file << '\n'; \
            std::exit(-1); \
        } \
    } while(0)

#define SHOW_IMAGE_TO_ASCII(processedFile) \
    do { \
        if (imdoc::getImageExtension(processedFile) == "png") { \
            imdoc::showPNGtoASCII(processedFile); \
        } else if (imdoc::getImageExtension(processedFile) == "jpg" || imdoc::getImageExtension(processedFile) == "jpeg") { \
            imdoc::showJPGtoASCII(processedFile); \
        } \
        else { \
            std::cerr << "Ошибка: не подходящее расширение файла " << processedFile << '\n'; \
            std::exit(-1); \
        } \
    } while(0)


namespace imdoc {

    void processImagePNG(const char* inputPath, const char* outputPath);
    void processImageJPEG(const char* inputPath, const char* outputPath);

    void showJPGtoASCII(const char* imagePath);
    void showPNGtoASCII(const char* imagePath);
}

#endif