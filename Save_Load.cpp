
//_________________________________________

void loadGImage1 () {
    char imageFileName[100];

    // Get grey image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, Gimage1);
}


//_______________________________________________

void loadGImage2 () {
    char imageFileName[100];

    // Get grey image file name
    cout << "Please enter name of image file to merge with: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, Gimage2);
}


//_______________________________________________

void saveGImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the target file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, Gimage1);
}

//_______________________________________________

void loadCImage1 () {
    char imageFileName[100];

    // Get colored image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, Cimage1);
}

//_______________________________________________

void loadCImage2 () {
    char imageFileName[100];

    // Get colored image file name
    cout << "Please enter name of image file to merge with: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, Cimage2);
}

//_______________________________________________

void saveCImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the target file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, Cimage1);
}