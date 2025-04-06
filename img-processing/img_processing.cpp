#include "img-processing.h"


void imdoc::processImagePNG(const char* inputPath, const char* outputPath) {
    FreeImage_Initialise();

    // load PNG
    FIBITMAP* bitmap = FreeImage_Load(FIF_PNG, inputPath, PNG_DEFAULT);
    if (!bitmap) {
        std::cerr << "Ошибка загрузки изображения\n";
        return;
    }

    FIBITMAP* grayBitmap = FreeImage_ConvertToGreyscale(bitmap);    // convert to gray map
    FreeImage_Unload(bitmap);                                       // free original image

    // save result
    if (FreeImage_Save(FIF_PNG, grayBitmap, outputPath, PNG_DEFAULT))
        std::cout << "Файл сохранен: " << outputPath << std::endl;
    else
        std::cerr << "Ошибка сохранения!\n";

    // free memory
    FreeImage_Unload(grayBitmap);
    FreeImage_DeInitialise();
}


void imdoc::processImageJPEG(const char* inputPath, const char* outputPath) {
    FreeImage_Initialise();

    // load png
    FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, inputPath, JPEG_DEFAULT);
    if (!bitmap) {
        std::cerr << "Ошибка загрузки изображения\n";
        return;
    }

    FIBITMAP* grayBitmap = FreeImage_ConvertToGreyscale(bitmap);    // convert to gray map
    FreeImage_Unload(bitmap);                                       // free original image

    // save gray result
    if (FreeImage_Save(FIF_JPEG, grayBitmap, outputPath, JPEG_DEFAULT))
        std::cout << "Файл сохранен: " << outputPath << std::endl;
    else
        std::cerr << "Ошибка сохранения!\n";

    // free memory
    FreeImage_Unload(grayBitmap);
    FreeImage_DeInitialise();
}

void imdoc::rescaleImageJPEG(const char* imagePath, const char* outputPath, int scaleFactor) {

    FIBITMAP* grayBitmap = FreeImage_Load(FIF_JPEG, imagePath, JPEG_DEFAULT);
    if (!grayBitmap) {
        std::cerr << "Ошибка загрузки изображения: " << imagePath << '\n';
        return;
    }

    int width = FreeImage_GetWidth(grayBitmap);
    int height = FreeImage_GetHeight(grayBitmap);


    int scaledWidth = width / scaleFactor;
    int scaledHeight = height / scaleFactor;

    FIBITMAP* resizedBitmap = FreeImage_Rescale(grayBitmap, scaledWidth, scaledHeight, FILTER_BILINEAR);
    FreeImage_Unload(grayBitmap);

    std::cout << "Размер изображения изменён с " << width << 'x' << height << " до " << scaledWidth << 'x' << scaledHeight << std::endl;

    // save gray result
    if (FreeImage_Save(FIF_JPEG, resizedBitmap, outputPath, JPEG_DEFAULT))
        std::cout << "Изменённое изображение сохранено: " << outputPath << std::endl;
    else
        std::cerr << "Ошибка сохранения!\n";

    FreeImage_Unload(resizedBitmap);
    FreeImage_DeInitialise();
}

void imdoc::rescaleImagePNG(const char* imagePath, const char* outputPath, int scaleFactor) {

    FIBITMAP* grayBitmap = FreeImage_Load(FIF_PNG, imagePath, PNG_DEFAULT);
    if (!grayBitmap) {
        std::cerr << "Ошибка загрузки изображения: " << imagePath << '\n';
        return;
    }

    int width = FreeImage_GetWidth(grayBitmap);
    int height = FreeImage_GetHeight(grayBitmap);


    int scaledWidth = width / scaleFactor;
    int scaledHeight = height / scaleFactor;

    FIBITMAP* resizedBitmap = FreeImage_Rescale(grayBitmap, scaledWidth, scaledHeight, FILTER_BILINEAR);
    FreeImage_Unload(grayBitmap);

    std::cout << "Размер изображения изменён с " << width << 'x' << height << " до " << scaledWidth << 'x' << scaledHeight << std::endl;

    // save gray result
    if (FreeImage_Save(FIF_PNG, resizedBitmap, outputPath, PNG_DEFAULT))
        std::cout << "Изменённое изображение сохранено: " << outputPath << std::endl;
    else
        std::cerr << "Ошибка сохранения!\n";

    FreeImage_Unload(resizedBitmap);
    FreeImage_DeInitialise();
}

void imdoc::transformJPGtoASCII(const char* imagePath, std::ofstream& outputFile) {

    if (!outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла вывода\n";
        return;
    }

    FIBITMAP* grayBitmap = FreeImage_Load(FIF_JPEG, imagePath, JPEG_DEFAULT);
    if (!grayBitmap) {
        std::cerr << "Ошибка загрузки изображения: " << imagePath << '\n';
        return;
    }

    int width = FreeImage_GetWidth(grayBitmap);
    int height = FreeImage_GetHeight(grayBitmap);


    BYTE pixelValue;
    for (int y = height-1; y >= 0; y--) {

        for (int x = 0; x < width; x++) {

            FreeImage_GetPixelIndex(grayBitmap, x, y, &pixelValue);
            int brightness = (int)pixelValue;
            std::cout << imdoc::getASCIIChar(brightness) << ' ';
            outputFile << imdoc::getASCIIChar(brightness) << ' ';
        }

        std::cout << std::endl;
        outputFile << '\n';
    }

    FreeImage_Unload(grayBitmap);
    FreeImage_DeInitialise();

    outputFile.close();
    std::cout << std::endl << "Запись в файл окончена!" << std::endl;
}


void imdoc::transformPNGtoASCII(const char* imagePath, std::ofstream& outputFile) {

    if (!outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла вывода\n";
        return;
    }

    FIBITMAP* grayBitmap = FreeImage_Load(FIF_PNG, imagePath, PNG_DEFAULT);
    if (!grayBitmap) {
        std::cerr << "Ошибка загрузки изображения: " << imagePath << '\n';
        return;
    }

    int width = FreeImage_GetWidth(grayBitmap);
    int height = FreeImage_GetHeight(grayBitmap);


    BYTE pixelValue;
    for (int y = height - 1; y >= 0; y--) {

        for (int x = 0; x < width; x++) {

            FreeImage_GetPixelIndex(grayBitmap, x, y, &pixelValue);
            int brightness = (int)pixelValue;
            std::cout << imdoc::getASCIIChar(brightness) << ' ';
            outputFile << imdoc::getASCIIChar(brightness) << ' ';
        }

        std::cout << std::endl;
        outputFile << '\n';
    }

    FreeImage_Unload(grayBitmap);
    FreeImage_DeInitialise();

    outputFile.close();
    std::cout << std::endl << "Запись в файл окончена!" << std::endl;

}