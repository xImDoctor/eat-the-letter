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
            processImagePNG(file, output); \
        } else if (imdoc::getImageExtension(file) == "jpg") { \
            processImageJPEG(file, output); \
        } \
        else { \
            std::cerr << "Ошибка: не подходящее расширение файла " << file << '\n'; \
            std::exit(-1); \
        } \
    } while(0)



void processImagePNG(const char* inputPath, const char* outputPath);

void processImageJPEG(const char* inputPath, const char* outputPath);

void showJPGtoASCII(const char* imagePath);


#endif