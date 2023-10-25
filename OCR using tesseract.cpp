#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>
using namespace std;


int main()
{
    char* outText;

    tesseract::TessBaseAPI* api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init("D:/computer vision/OCR/tessdata", "eng")) {
        cout << "Could not initialize tesseract." << endl;
        exit(1);
    }

    // Open input image with leptonica library
    Pix* image = pixRead("D:/computer vision/OCR/Resources/text.png");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    cout << "OCR outputs:" << outText << endl;
    //printf("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    delete api;
    delete[] outText;
    pixDestroy(&image);

    return 0;
}