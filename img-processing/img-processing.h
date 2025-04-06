#ifndef _IMAGE_PREPROCESSING_H_
#define _IMAGE_PREPROCESSING_H_

#include "../ascii-preprocessing/ascii_preprocessing.h"

#include <FreeImage.h>
#include <iostream>
#include <fstream>

//#define PROCESS_IMAGE(file, output) \
    (getExtension(file) == "png" ? processImagePNG(file, output) : processImageJPEG(file, output))

#define PROCESS_IMAGE(file, output) \
        if (imdoc::getImageExtension(file) == "png") { \
            imdoc::processImagePNG(file, output); \
        } else if (imdoc::getImageExtension(file) == "jpg") { \
            imdoc::processImageJPEG(file, output); \
        } \
        else { \
            std::cerr << "Ошибка: не подходящее расширение файла " << file << '\n'; \
            std::exit(-1); \
        } \


#define RESCALE_IMAGE(file, output, scale, changeScale) \
        if (imdoc::getImageExtension(file) == "png") { \
            if (!changeScale) \
                imdoc::rescaleImagePNG(file, output); \
            else \
                imdoc::rescaleImagePNG(file, output, scale); \
        } else if (imdoc::getImageExtension(file) == "jpg" || imdoc::getImageExtension(file) == "jpeg") { \
            if (!changeScale) \
                imdoc::rescaleImageJPEG(file, output); \
           else \
                imdoc::rescaleImageJPEG(file, output, scale); \
        } \
        else { \
            std::cerr << "Ошибка: не подходящее расширение файла " << file << '\n'; \
            std::exit(-1); \
        } 


#define TRANSFORM_IMAGE_TO_ASCII(processedFile, outputTextFile) \
        if (imdoc::getImageExtension(processedFile) == "png") { \
            imdoc::transformPNGtoASCII(processedFile, outputTextFile); \
        } else if (imdoc::getImageExtension(processedFile) == "jpg" || imdoc::getImageExtension(processedFile) == "jpeg") { \
            imdoc::transformJPGtoASCII(processedFile, outputTextFile); \
        } \
        else { \
            std::cerr << "Ошибка: не подходящее расширение файла " << processedFile << '\n'; \
            std::exit(-1); \
        } 


namespace imdoc {

    void processImagePNG(const char* inputPath, const char* outputPath);
    void processImageJPEG(const char* inputPath, const char* outputPath);

    void rescaleImagePNG(const char* inputPath, const char* outputPath, int scaleFactor=5);
    void rescaleImageJPEG(const char* inputPath, const char* outputPath, int scaleFactor=5);

    void transformJPGtoASCII(const char* imagePath, std::ofstream& outputFile);
    void transformPNGtoASCII(const char* imagePath, std::ofstream& outputFile);

}

#endif