#ifndef _IMAGE_PREPROCESSING_H_
#define _IMAGE_PREPROCESSING_H_

#include "../ascii-preprocessing/ascii_preprocessing.h"

#include <FreeImage.h>
#include <iostream>
#include <fstream>

//#define PROCESS_IMAGE(file, output) \
    (getExtension(file) == "png" ? processImagePNG(file, output) : processImageJPEG(file, output))


/*  PROCESS_IMAGE chooses correct function to process image to gray one using file extension. Better to use relative path.
    file - const char* inputPath - input image file,
    output - const char* outputPath - output image file.

    Macros contains processImagePNG, processImageJPEG. */
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

/*
        RESCALE_IMAGE chooses correct function to rescale image by scale factor times. Better to use relative path.
        file - const char* imagePath - input image file,
        output - const char* outputPath - output image file.
        scale - int scaleFactor - rescaling factor (rescale by scaleFactor times)
        scaleChange - flag (0 or 1) - if scaleChange is 0 than user scale is not counted using default scaleFactor=5 instead.
        
        Macros contains rescaleImagePNG, rescaleImageJPEG with various parameters depending on scaleChange flag.
*/
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


/*
        TRANSFORM_IMAGE_TO_ASCII chooses correct function to transform the image processed to gray-colored one into ascii-art (using char symbols) and write
        it to output file.
        processedFile - const char* imagePath - input image file processed to gray colors,
        outputTextFile - std::ofstream& outputFile - output text file to write ascii-art in.

        Macros contains transformPNGtoASCII, transformJPGtoASCII.
*/
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