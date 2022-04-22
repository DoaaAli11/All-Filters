// Program: All Filters.cpp
// Purpose: This is a simple photo editor by using bmplib libaray
// Author 1: Doaa ALi El-Sayed Mohamed (20211034)
// Author 2: Ahmed Yasser Mohamed Mohamed (20211010)
// Author 3: Ahmed Ahmed Hamed Ahmed (20211003)
// Last version:    21 April 2022


#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cmath>
#include "bmplib.cpp"
#include "bmplib.h"
//_________________________________________

unsigned char Cimage1[SIZE][SIZE][RGB], Cimage2[SIZE][SIZE][RGB];
unsigned char Gimage1[SIZE][SIZE], Gimage2[SIZE][SIZE], Gimage3[SIZE][SIZE];
unsigned char image[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char image5[SIZE][SIZE];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char image4[SIZE][SIZE][RGB];
unsigned char image6[SIZE][SIZE][RGB];
//_________________________________________

void load_image(unsigned char arr[][SIZE]);
void save_image(unsigned char arr[][SIZE]);
void loadImage(unsigned char arr0[][SIZE]);
void saveImage(unsigned arr[][SIZE][RGB]);
void loadCImage1 ();
void loadCImage2 ();
void loadGImage1 ();
void loadGImage2 ();
void saveCImage ();
void saveGImage ();
void BW_gray();
void BW_color();
void invertGimage ();
void invertCimage ();
void MergeCImages ();
void MergeGImages ();
void Rotate_G();
void Rotate_C();
void flipG();
void flipC();
void LDCimage6 ();
void LDGimage6 ();
void enlargeGimage();
void enlargeCImage ();
void shrinkG ();
void shrinkC ();
void shuffleGImage ();
void shuffleCImage ();
void blurG ();
void blurC ();
void mirrorG();
void mirrorRGB();
void edge_detectionG();
void edge_detectionRGB();

//_________________________________________

void load_image(unsigned char arr[][SIZE]){
    char file_name[100];
    cout << "Enter The Source Image: " << endl;
    cin >> file_name;
    strcat(file_name, ".bmp");
    readGSBMP(file_name,arr);
}

//_________________________________________

void save_image(unsigned char arr[][SIZE]){
    char ImageName[100];
    cout << "Enter the target image name: ";
    cin >> ImageName;
    strcat(ImageName, ".bmp");
    writeGSBMP(ImageName, arr);

}

//_________________________________________
void loadImage(unsigned char arr0[][SIZE][RGB]){
    char filename[100];
    cout << "Enter the source Image: ";
    cin >> filename;
    strcat(filename, ".bmp");
    readRGBBMP(filename, arr0);

}

//_________________________________________

void saveImage(unsigned char arr[][SIZE][RGB]){
    char target_image[100];
    cout <<"Enter the target file: ";
    cin >> target_image;
    strcat(target_image, ".bmp");
    writeRGBBMP(target_image, arr);

}

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


//_______________________________________________

void invertGimage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {    //loops through entire 2d matrix
            if (Gimage1[i][j] == 255) {   // if it is black make it white
                Gimage1[i][j] = 0;
            }
            else if(Gimage1[i][j] == 0) { // if it is white make it black
                Gimage1[i][j] = 255;
            }
            else{
                Gimage1[i][j] = 255 - Gimage1[i][j];    //if it is grey make it the opposite shade of grey
            }
        }
    }
}

//_______________________________________________
void invertCImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {    //loops through entire 3d matrix
            for (int k = 0; k < RGB; k++){
                if (Cimage1[i][j][k] == 255) {   // if it is black make it white
                    Cimage1[i][j][k] = 0;
                }
                else if(Cimage1[i][j][k] == 0) { // if it is white make it black
                    Cimage1[i][j][k] = 255;
                }
                else{
                    Cimage1[i][j][k] = 255 - Cimage1[i][j][k];    //if it is grey make it the opposite shade of grey
                }
            }
        }
    }
}

//_______________________________________________

void BW_gray(){
    load_image(image);
    int avg{};
    for(size_t i{}; i < SIZE; ++i ){
        for (size_t j{}; j < SIZE; ++j){
            avg += image[i][j];
        }
    }
    for (size_t i{0}; i < SIZE; ++i ){
        for (size_t j{0}; j < SIZE; ++j){
            if (image[i][j] > (avg/(SIZE*SIZE))){
                image[i][j] = 255;
            }else{
                image[i][j] = 0;

            }
        }
    }
    save_image(image);
}
//_______________________________________________

void BW_color() {
    loadImage(image2);
    int avg{};
    for (size_t i{}; i < SIZE; ++i) {
        for (int j{}; j < SIZE; ++j) {
            for (int k{}; k < RGB; ++k) {
                avg += image2[i][j][k];
            }if(avg/3 > 127){
                for (int c{}; c < RGB; ++c ){
                    image2[i][j][c] = 255;
                }
            } else{
                for (int c{}; c < RGB; ++c ){
                    image2[i][j][c] = 0;
                }

            }avg = 0;

        }
    }
    saveImage(image2);
}

//_______________________________________________

void MergeCImages () {

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k < RGB; k++){

                Cimage1[i][j][k] = (Cimage1[i][j][k] + Cimage2[i][j][k]) / 2;
            }
        }
    }
}

//_______________________________________________

void MergeGImages () {

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            Gimage1[i][j] = (Gimage1[i][j] + Gimage2[i][j]) / 2;
        }
    }
}
//_______________________________________________
void flipG(){
    char flip;
    cout << "Flip (h)orizontally or (v)ertically ?" << endl;
    cin >> flip;
    if(tolower(flip) == 'h'){
        for (int i{}; i < SIZE; ++i){
            for (int j{}; j < SIZE/2; ++j){
                swap(Gimage1[i][j], Gimage1[i][SIZE-j-1]);

            }
        }

    }
    else{
        for (int i{}; i < SIZE; ++i){
            for (int j{}; j < SIZE / 2; ++j){
                swap(Gimage1[j][i],Gimage1[SIZE-j-1][i]);
            }
        }
    }
}

//_______________________________________________

void flipC(){
    char flip;
    cout << "Flip (h)orizontally or (v)ertically ?" << endl;
    cin >> flip;
    if(tolower(flip) == 'h'){
        for (int i{}; i < SIZE; ++i){
            for (int j{}; j < SIZE / 2; ++j){
                for (int k{}; k < RGB; ++k){
                    swap(Cimage1[i][j][k], Cimage1[i][SIZE-j][k]);
                }
            }
        }

    }
    else{
        for (int i{}; i < SIZE; ++i){
            for (int j{}; j < SIZE / 2; ++j){
                for (int k{}; k < RGB; ++k){
                    swap(Cimage1[j][i][k], Cimage1[SIZE-j-1][i][k]);
                }
            }
        }
    }
}

//_______________________________________________
void G_upsideDown() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Gimage2[SIZE-i][SIZE-j] = Gimage1[i][j];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Gimage1[i][j] = Gimage2[i][j];
        }
    }
}

void rotateG_TwoSeventy() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Gimage2[i][j] = Gimage1[j][i];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Gimage1[i][j] = Gimage2[i][j];
        }
    }
}

void rotateG_Ninety() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Gimage2[i][j] = Gimage1[j][i];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Gimage1[SIZE-i][SIZE-j] = Gimage2[i][j];
        }
    }
}

void Rotate_G() {
    int x;
    cout << "Rotate: 1 for 90 degrees / 2 for 180 / 3 for 270: ";
    cin >> x;
    if (x==1){
        rotateG_Ninety();
    }else if (x == 2){
        G_upsideDown();
    }else if (x == 3){
        rotateG_TwoSeventy();

    }else{
        cout << "invalid input";
    }
}

//_______________________________________________
void C_upsideDown() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k=0; k<RGB; k++) {
                Cimage2[SIZE-i][SIZE-j][k] = Cimage1[i][j][k];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k=0; k<RGB; k++){
                Cimage1[i][j][k] = Cimage2[i][j][k];
            }
        }
    }
}

void rotateC_TwoSeventy() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k=0; k<RGB; k++){
                Cimage2[i][j][k] = Cimage1[j][i][k];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k=0; k<RGB; k++){
                Cimage1[i][j][k] = Cimage2[i][j][k];
            }
        }
    }
}

void rotateC_Ninety() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k=0; k<RGB; k++){
                Cimage2[i][j][k] = Cimage1[j][i][k];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k=0; k<RGB; k++){
                Cimage1[SIZE-i][SIZE-j][k] = Cimage2[i][j][k];
            }
        }
    }
}

void Rotate_C() {
    int x;
    cout << "1 for 90 degrees 2 for 180 3 for 270: ";
    cin >> x;
    if (x==1){
        rotateC_Ninety();
    }else if (x == 2){
        C_upsideDown();
    }else if (x == 3){
        rotateC_TwoSeventy();
    }else{
        cout << "invalid input";
    }
}

//_______________________________________________

void LDGimage6 (){
    char LD;
    cout << "Do you want to (d)arken or (l)ighten: ";
    cin >> LD;
    if (tolower(LD)=='d'){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                Gimage1[i][j] /=2;
            }
        }
    }
    else if (tolower(LD) == 'l'){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                if(Gimage1[i][j]>=128){
                    Gimage1[i][j] = 255;
                }
                else{
                    Gimage1[i][j] *=2;
                }
            }
        }
    }
}
//_______________________________________________

void LDCimage6 () {
    string LD;
    cout << "Do you want to (d)arken or (l)ighten: ";
    cin >> LD;
    if (LD=="d"){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                for(int k = 0; k < RGB; k++){
                    Cimage1[i][j][k] /=2 ;
                }
            }
        }
    }
    else if (LD == "l"){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                for(int k = 0; k < RGB; k++){
                    if(Cimage1[i][j][k]>=128){
                        Cimage1[i][j][k] = 255;
                    }
                    else{
                        Cimage1[i][j][k] *=2;
                    }
                }
            }
        }
    }
}

//_______________________________________________
void enlargeGimage() {
    unsigned int choice, startX, startY;
    cout<<"\nwhich quarter of the picture do you wish to enlarge?";
    cin>>choice;    //takes input from user
    switch (choice) {   //changes where the program starts from according to the coordinates input from user
        case 1:
            startX = startY = 0;
            break;
        case 2:
            startX = 0;
            startY = SIZE/2;
            break;

        case 3:
            startX = SIZE/2;
            startY = 0;
            break;
        case 4:
            startX = SIZE/2;
            startY = SIZE/2;
            break;
        default :
            cout<<"invalid input."; // makes sure that the user inputs the correct input
            return;
    }
    int row = 0;
    for(int k=startX; k<SIZE ; k++){    //makes a loop that is as big as the picture starting from the starting position
        int col =0 ;                    //declared at startX
        for (int i=startY ;i<SIZE ; i++){
            if (col>256) break;
            Gimage3[row][++col] = Gimage1[k][i];
            if (col>256) break;
            Gimage3[row][++col] = Gimage1[k][i];   //places each pixel twice to the right in order to enlarge the image
        }
        for (int j =0 ;j<SIZE ;j++){
            Gimage3[row+1][j] = Gimage3[row][j];    // copies the row above it
        }
        row+=2;
        if  (row>256) break;
    }

    for(int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            Gimage1[i][j] = Gimage3[i][j];
        }
    }

}


//_______________________________________________
void enlargeCImage() {
    unsigned int choice, startX, startY;
    cout<<"\nwhich quarter of the picture do you wish to enlarge?";
    cin>>choice;
    switch (choice) {

        case 1:
            startX = startY = 0;
            break;

        case 2:
            startX = 0;
            startY = SIZE/2;
            break;
        case 3:
            startX = SIZE/2;
            startY = 0;
            break;
        case 4:
            startX = SIZE/2;
            startY = SIZE/2;
            break;
        default :
            cout<<"invalid input.";
            return;
    }
    int row = 0;
    for(int k=startX; k<SIZE ; k++){
        int col =0 ;
        int col2 = 0;
        for (int i=startY ;i<SIZE ; i++){
            col +=1;
            col2 = col + 1;
            if (col>256) break;
            for (int j = 0; j<RGB; j++){
                Cimage2[row][col][j] = Cimage1[k][i][j];
                if (col2>256) break;
                Cimage2[row][col2][j] = Cimage1[k][i][j];
            }
            col = col2;
        }
        for (int j =0 ;j<SIZE ;j++){
            for (int i = 0; i<RGB; i++){
                Cimage2[row+1][j][i]=Cimage2[row][j][i];
            }
        }
        row+=2;
        if  (row>256) break;
    }
    for(int k=0; k<SIZE ; k++){
        for (int j=0; j<SIZE; j++){
            for (int i=0; i<RGB; i++){
                Cimage1[k][j][i] = Cimage2[k][j][i];
            }
        }
    }
}


//_______________________________________________
void shrinkG(){
    int choice, jump, nsize, num, blank;
    cout<<"\nHow much do you wanna shrink:\n1-1/2\n2-1/3\n3-1/4\n";
    cin>>choice;
    while (choice!=1&&choice!=2&&choice!=3)
    {
        cout<<"invalid input.";
        cout<<"\nHow much do you wanna shrink:\n1-1/2\n2-1/3\n3-1/4\n";
        cin>>choice;
    }

    switch (choice) {
        case 1:
            jump = 2;
            nsize = SIZE;
            num = 4;
            blank = SIZE/2;
            break;
        case 2:
            jump = 3;
            nsize = SIZE-1;
            num = 9;
            blank = SIZE/3;
            break;

        case 3:
            jump = 4;
            nsize = SIZE;
            num = 16;
            blank = SIZE/4;
            break;

            return;
    }

    int k = -1;
    for (int i = 0; i < nsize; i+=jump){  // jump
        int z = 0;
        k++;
        for (int j = 0; j < nsize; j+=jump){   //nsize
            int avrg =0;
            for (int r =0; r<jump ; r++){
                for (int c =0; c<jump ; c++){
                    avrg += Gimage1[i+r][j+c];
                }
            }
            avrg /= num ;  // num
            Gimage1[k][z] = avrg;
            z++;
        }
    }


    for (int k = 0; k < blank; k++){  // blank
        for (int z = blank; z < SIZE; z++){
            Gimage1[k][z] = 255;
        }
    }

    for (int k = blank; k < SIZE; k++){
        for (int z = 0; z < blank; z++){
            Gimage1[k][z] = 255;
        }
    }

    for (int k = blank; k < SIZE; k++){
        for (int z = blank; z < SIZE; z++){
            Gimage1[k][z] = 255;
        }
    }

}

//_______________________________________________
void shrinkC() {

    int choice, jump, nsize, num, blank;
    cout<<"\nHow much do you wanna shrink:\n1-1/2\n2-1/3\n3-1/4\n";
    cin>>choice;
    while (choice!=1&&choice!=2&&choice!=3)
    {
        cout<<"invalid input.";
        cout<<"\nHow much do you wanna shrink:\n1-1/2\n2-1/3\n3-1/4\n";
        cin>>choice;
    }

    switch (choice) {
        case 1:
            jump = 2;
            nsize = SIZE;
            num = 4;
            blank = SIZE/2;
            break;
        case 2:
            jump = 3;
            nsize = SIZE-1;
            num = 9;
            blank = SIZE/3;
            break;

        case 3:
            jump = 4;
            nsize = SIZE;
            num = 16;
            blank = SIZE/4;
            break;

            return;
    }

    int k = -1;

    for (int i = 0; i < nsize; i+=jump){
        k++;
        int z = -1;

        for (int j = 0; j < nsize; j+=jump){
            z++;

            for (int c = 0; c<RGB ; c++){

                int avrg = 0;

                for (int r =0; r<jump ; r++){
                    for (int k = 0; k <jump; k++){

                        avrg +=Cimage1[i+r][j+k][c];
                    }
                }

                avrg /= num;
                Cimage1[k][z][c] = avrg;
            }
        }
    }


    for (int k = 0; k < blank; k++){
        for (int z = blank; z < SIZE; z++){
            for (int v = 0; v < RGB; v++){
                Cimage1[k][z][v] = 255;
            }
        }
    }
    for (int k = blank; k < SIZE; k++){
        for (int z = 0; z < blank; z++){
            for (int v = 0; v < RGB; v++){
                Cimage1[k][z][v] = 255;
            }
        }
    }
    for (int k = blank; k < SIZE; k++){
        for (int z = blank; z < SIZE; z++){
            for (int v = 0; v < RGB; v++){
                Cimage1[k][z][v] = 255;
            }
        }
    }
}

//_______________________________________________
void shuffleGImage() {
    //row and column affect where the square is going to go
    //k and i affect which square is going to be copied
    int oneA,twoA,oneB,twoB,oneC,twoC,oneD,twoD,half=SIZE/2;
    int row = 0;
    cout << "insert the order of the pictures: ";
    int a, b, c ,d;
    cin >> a >> b >> c >> d;
    if (a == 4) {
        oneA = half;
        twoA = half;
    }else if(a == 1) {
        oneA = 0;
        twoA = 0;
    }else if(a == 2) {
        oneA = 0;
        twoA = half;
    }else if(a == 3) {
        oneA=half;
        twoA=0;
    } else {
        cout << "invalid input.";
    }
    if (b == 4) {
        oneB = half;
        twoB = half;
    }else if(b == 1) {
        oneB = 0;
        twoB = 0;
    }else if(b == 2) {
        oneB = 0;
        twoB = half;
    }else if(b == 3) {
        oneB=half;
        twoB=0;
    } else {
        cout << "invalid input.";
    }
    if (c == 4) {
        oneC = half;
        twoC = half;
    }else if(c == 1) {
        oneC = 0;
        twoC = 0;
    }else if(c == 2) {
        oneC = 0;
        twoC = half;
    }else if(c == 3) {
        oneC=half;
        twoC=0;
    } else {
        cout << "invalid input.";
    }
    if (d == 4) {
        oneD = half;
        twoD = half;
    }else if(d == 1) {
        oneD = 0;
        twoD = 0;
    }else if(d == 2) {
        oneD = 0;
        twoD = half;
    }else if(d == 3) {
        oneD=half;
        twoD=0;
    } else {
        cout << "invalid input.";
    }
    //first section
    int x;
    int y;
    x= (oneA==0)? half:SIZE;
    y= (twoA==0)? half:SIZE;
    for(int k=oneA; k<x ; k++) {
        int col = 0;
        for (int i = twoA; i < y; i++) {
            col++;
            if (col > 256) break;
            Gimage2[row][col] = Gimage1[k][i];   //bottom right to top left
        }
        row++;
    }
    //end of first section
    x= (oneB==0)? half:SIZE;
    y= (twoB==0)? half:SIZE;
    row = 0;
    for(int k=oneB; k<x ; k++) {
        int col = half;
        for (int i = twoB; i < y; i++) {    //top left to top right
            col++;
            if (col > 256) break;
            Gimage2[row][col] = Gimage1[k][i];   //bottom right to top left
        }
        row++;
    }
    //end of second section
    x= (oneC==0)? half:SIZE;
    y= (twoC==0)? half:SIZE;
    row = half;
    for (int k = oneC; k < x; k++) {
        int col = 0;
        for (int i = twoC; i < y; i++) {    //bottom left to bottom left
            col++;
            if (col > 256) break;
            Gimage2[row][col] = Gimage1[k][i];   //bottom right to top left
        }
        row++;
    }
    //end of third section
    x= (oneD==0)? half:SIZE;
    y= (twoD==0)? half:SIZE;
    row = half;
    for(int k=oneD; k<x ; k++) {
        int col = half;
        for (int i = twoD; i < y; i++) { //top right to bottom right
            col++;
            if (col > 256) break;
            Gimage2[row][col] = Gimage1[k][i];   //bottom right to top left
        }
        row++;
    }
    //end of fourth section
    for (int i=0;i<SIZE;i++){
        for (int k=0;k<SIZE;k++){
            Gimage1[i][k] = Gimage2[i][k];
        }
    }
/*
    for (int i = 0; i<SIZE; i++){
        for (int j =0; j<SIZE; j++){
            Gimage1[i][j] =
        }
    }*/

}

//_______________________________________________
void shuffleCImage() {
    //row and column affect where the square is going to go
    //k and i affect which square is going to be copied
    int oneA,twoA,oneB,twoB,oneC,twoC,oneD,twoD,half=SIZE/2;
    int row = 0;
    cout << "insert the order of the pictures: ";
    int a, b, c ,d;
    cin >> a >> b >> c >> d;
    if (a == 4) {
        oneA = half;
        twoA = half;
    }else if(a == 1) {
        oneA = 0;
        twoA = 0;
    }else if(a == 2) {
        oneA = 0;
        twoA = half;
    }else if(a == 3) {
        oneA=half;
        twoA=0;
    } else {
        cout << "invalid input.";
    }
    if (b == 4) {
        oneB = half;
        twoB = half;
    }else if(b == 1) {
        oneB = 0;
        twoB = 0;
    }else if(b == 2) {
        oneB = 0;
        twoB = half;
    }else if(b == 3) {
        oneB=half;
        twoB=0;
    } else {
        cout << "invalid input.";
    }
    if (c == 4) {
        oneC = half;
        twoC = half;
    }else if(c == 1) {
        oneC = 0;
        twoC = 0;
    }else if(c == 2) {
        oneC = 0;
        twoC = half;
    }else if(c == 3) {
        oneC=half;
        twoC=0;
    } else {
        cout << "invalid input.";
    }
    if (d == 4) {
        oneD = half;
        twoD = half;
    }else if(d == 1) {
        oneD = 0;
        twoD = 0;
    }else if(d == 2) {
        oneD = 0;
        twoD = half;
    }else if(d == 3) {
        oneD=half;
        twoD=0;
    } else {
        cout << "invalid input.";
    }
    //first section
    int x;
    int y;
    x= (oneA==0)? half:SIZE;
    y= (twoA==0)? half:SIZE;
    for(int k=oneA; k<x ; k++) {
        int col = 0;
        for (int i = twoA; i < y; i++) {
            col++;
            for(int j = 0; j < RGB; j++){
                if (col > 256) break;
                Cimage2[row][col][j] = Cimage1[k][i][j];   //bottom right to top left
            }
        }
        row++;
    }
    //end of first section
    x= (oneB==0)? half:SIZE;
    y= (twoB==0)? half:SIZE;
    row = 0;
    for(int k=oneB; k<x ; k++) {
        int col = half;
        for (int i = twoB; i < y; i++) {    //top left to top right
            col++;
            for(int j = 0; j < RGB; j++){
                if (col > 256) break;
                Cimage2[row][col][j] = Cimage1[k][i][j];   //bottom right to top left
            }
        }
        row++;
    }
    //end of second section
    x= (oneC==0)? half:SIZE;
    y= (twoC==0)? half:SIZE;
    row = half;
    for (int k = oneC; k < x; k++) {
        int col = 0;
        for (int i = twoC; i < y; i++) {    //bottom left to bottom left
            col++;
            for(int j = 0; j < RGB; j++){
                if (col > 256) break;
                Cimage2[row][col][j] = Cimage1[k][i][j];   //bottom right to top left
            }
        }
        row++;
    }
    //end of third section
    x= (oneD==0)? half:SIZE;
    y= (twoD==0)? half:SIZE;
    row = half;
    for(int k=oneD; k<x ; k++) {
        int col = half;
        for (int i = twoD; i < y; i++) { //top right to bottom right
            col++;
            for(int j = 0; j < RGB; j++){
                if (col > 256) break;
                Cimage2[row][col][j] = Cimage1[k][i][j];   //bottom right to top left
            }
        }
        row++;
    }
    //end of fourth section
    for (int i=0;i<SIZE;i++){
        for (int k=0;k<SIZE;k++){
            for (int j=0;j<RGB;j++){
                Cimage1[i][k][j] = Cimage2[i][k][j];
            }
        }
    }
}


//_______________________________________________
void blurG() {

    for (int i = 0; i < SIZE-1; i++) {
        for (int j = 0; j< SIZE-1; j++) {

            // blur color
            int avrg = 0 ;
            for (int r = 0; r<3; r++){
                for (int c=0; c<3; c++){
                    avrg += Gimage1[i+r][j+c];
                }
            }
            avrg /= 9;
            Gimage1[i+1][j+1] = avrg;

        }
    }
}

//_______________________________________________
void blurC() {

    for (int i = 0; i < SIZE-1; i++) {
        for (int j = 0; j< SIZE-1; j++) {
            for (int k = 0; k < RGB ; k++)
            {
                // blur color
                for (int l =0;l<RGB; l++){
                    int avrg = 0 ;
                    for (int r = 0; r<3; r++){
                        for (int c=0; c<3; c++){
                            avrg += Cimage1[i+r][j+c][l];
                        }
                    }
                    avrg /= 9;
                    Cimage1[i+1][j+1][l] = avrg;
                }
            }
        }
    }
}

void mirrorG(){
    char ch{};
    cout << " Enter the half of the image that you want to mirror 'L', 'R', 'U', 'D' " << endl;
    cin >> ch;

    if (tolower(ch) == 'r') {
        load_image(image);
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {
                image[j][i] = image[j][SIZE - i];
            }
        }
    }
    else if (tolower(ch) == 'l') {
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {
                image[j][SIZE - i] = image[j][i];
            }
        }
    }
    else if (tolower(ch) == 'u') {
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {
                image[i][j] = image[SIZE - i][j];
            }
        }
    }
    else {
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {
                image[SIZE - i][j] = image[i][j];
            }
        }
    }
    save_image(image);
}


//_______________________________________________

void mirrorRGB() {
    char ch{};
    cout << " Enter the half of the image that you want to mirror 'L', 'R', 'U', 'D' " << endl;
    cin >> ch;
    loadImage(image2);
    if (tolower(ch) == 'r') {
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {
                for (int k{}; k < RGB; ++k) {
                    image2[j][i][k] = image2[j][SIZE - i][k];

                }
            }
        }
    }
    else if (tolower(ch) == 'l') {
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {
                for (int k{}; k < RGB; ++k) {
                    image2[j][SIZE - i][k] = image2[j][i][k];

                }
            }
        }
    }
    else if (tolower(ch) == 'u') {
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {
                for (int k{}; k < RGB; ++k) {
                    image2[i][j][k] = image2[SIZE - i][j][k];

                }
            }
        }
    }
    else {
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {
                for (int k{}; k < RGB; ++k) {
                    image2[SIZE - i][j][k] = image2[i][j][k];

                }
            }
        }
    }
    saveImage(image2);
}

//_______________________________________________


void edge_detectionG() {
    BW_gray();
    for (int i{}; i < SIZE; ++i){
        for (int j{}; j < SIZE; ++j){
            image3[i][j] = 255;
        }
    }

    for (int i{}; i < SIZE; ++i) {
        for (int j{}; j < SIZE; ++j) {
            if(image[i][j] == 0){
                if(image[i][j-1] == 255 && image[i][j+1] == 0 || image[i][j-1] == 0 && image[i][j+1 ] == 255)
                    image3[i][j] = image[i][j];

            }

        }
    }
    save_image(image3);
}

//_______________________________________________

void edge_detectionRGB(){
    BW_color();
    for (int i{}; i < SIZE; ++i){
        for (int j{}; j < SIZE; ++j){
            for(int k{}; k < SIZE; ++k){
                image4[i][j][k] = 255;
            }
        }
    }
    for (int i{}; i < SIZE; ++i) {
        for (int j{}; j < SIZE; ++j) {
            for(int k{}; k < RGB; ++k){

                if (image2[i][j][k] == 0) {
                    if ((image2[i][j - 1][k] == 255 && image2[i][j + 1][k] == 0 )||( image2[i][j - 1][k] == 0 && image2[i][j + 1][k] == 255) ){
                        image4[i][j][k] = 0;
                    } else{
                        image4[i][j][k] = 255;

                    }
                }
            }
        }
    }

    saveImage(image4);
}

int main(){
    char C_or_G, choice;

    cout << "Welcom dear user, This is a photoshop program\n\nIs your photo:\n1-Gray\n2-Colored" << endl;
    cin>>C_or_G;

    if (C_or_G == '1'){
        loadGImage1();
        while (choice != '0'){

            cout<<"\nWhat filter do you want to apply:\n\n1-Black & White Filter\n2-Invert Image\n3-Merge Images\n4-Flip Image\n5-Rotate Image\n6-Darken and Lighten Image\n8-Enlarge Image\n9-Shrink Image\nB-Shuffle Image\nC-Blur Image\nS-Save the image to a file\n0-End\n\n"<<endl;
            cin >> choice;
            if (choice == '1'){
                BW_gray();
                cout<<"\nDONE!\n";
            }

            else if (choice == '2'){
                invertGimage();
                cout<<"\nDONE!\n";
            }

            else if (choice == '3'){
                loadGImage2();
                MergeGImages();
                cout<<"\nDONE!\n";
            }

            else if (choice == '4'){
                flipG();
                cout<<"\nDONE!\n";
            }

            else if (choice == '5'){
                Rotate_G();
                cout<<"\nDONE!\n";
            }

            else if (choice == '6'){
                LDGimage6();
                cout<<"\nDONE!\n";
            }

            else if (choice == '8'){
                enlargeGimage();
                cout<<"\nDONE!\n";

            }

            else if (choice == '9'){
                shrinkG();
                cout<<"\nDONE!\n";
            }

            else if (tolower(choice) == 'b'){
                shuffleGImage();
                cout<<"\nDONE!\n";
            }

            else if (tolower(choice) == 'c'){
                blurG();
                cout<<"\nDONE!\n";
            }

            else if (tolower(choice) == 's'){
                saveGImage();
                cout<<"\nSAVED!\n";
            }

            else if (choice == '0'){
                cout << "Thanks for using our program!";
                break;
            }
        }
    }


    else if (C_or_G == '2'){
        loadCImage1();
        while (choice != '0'){
            cout<<"\nWhat filter do you want to apply:\n\n1-Black & White Filter\n2-Invert Image Color\n3-Merge Images\n4-Flip Image\n5-Rotate Image\n6-Darken and Lighten Image\n8-Enlarge Image\n9-Shrink Image\nB-Shuffle Image\nC-Blur Image\nS-Save the image to a file\n0-End\n\n";
            cin >> choice ;
            if (choice == '1'){
                BW_color();
                cout<<"\nDONE!\n";
            }
            else if (choice == '2'){
                invertCImage();
                cout<<"\nDONE!\n";
            }

            else if (choice == '3'){
                loadCImage2();
                MergeCImages();
                cout<<"\nDONE!\n";
            }

            else if (choice == '4'){
                flipC();
                cout<<"\nDONE!\n";
            }
            else if (choice == '5'){
                Rotate_C ();
                cout<<"\nDONE!\n";
            }

            else if (choice == '6'){
                LDCimage6();
                cout<<"\nDONE!\n";
            }

            else if (choice == '8'){
                enlargeCImage();
                cout << "\nDONE!\n";
            }

            else if (choice == '9'){
                shrinkC();
                cout<<"\nDONE!\n";
            }
            else if (tolower(choice) == 'b'){
                shuffleCImage();
                cout<<"\nDONE!\n";
            }
            else if (tolower(choice) == 'c'){
                blurC();
                cout<<"\nDONE!\n";
            }

            else if (tolower(choice) == 's'){
                saveCImage();
                cout<<"\nSAVED!\n";
            }

            else if (choice == '0'){
                cout << "Thanks for using our program!";
                break;
            }
        }
    }
    return 0;
}

