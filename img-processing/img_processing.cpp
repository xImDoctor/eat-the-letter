#include "img-processing.h"


void processImagePNG(const char* inputPath, const char* outputPath) {
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


void processImageJPEG(const char* inputPath, const char* outputPath) {
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


void showPNGtoASCII(const char* imagePath) {

    FIBITMAP* bitmap = FreeImage_Load(FIF_PNG, imagePath, PNG_DEFAULT);
    if (!bitmap) {
        std::cerr << "Ошибка загрузки изображения: " << imagePath << '\n';
        return;
    }

    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            RGBQUAD color;
            FreeImage_GetPixelColor(bitmap, x, y, &color);
            int brightness = (color.rgbRed + color.rgbGreen + color.rgbBlue) / 3;
            std::cout << brightness << " ";
        }
        std::cout << std::endl;
    }

}