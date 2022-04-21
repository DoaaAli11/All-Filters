// Program: All Filters.cpp
// Purpose: This is a simple photo editor by using bmplib libaray
// Author 1: Doaa ALi El-Sayed Mohamed (20211034)
// Author 2: Ahmed Yasser Mohamed Mohamed (20211010)
// Author 3: Ahmed Ahmed Hamed Ahmed (20211003)
// Last version:    5 April 2022


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
//_________________________________________

void loadCImage1 ();
void loadCImage2 ();
void loadGImage1 ();
void loadGImage2 ();
void saveCImage ();
void saveGImage ();
void Black_whiteG();
void BW_color();
void invert_image ();
void MergeCImages ();
void MergeGImages ();
void flipG();
void flipC();
void LDCimage6 ();
void LDGimage6 ();
void Enlarge_image();
void shrinkG ();
void shrinkC ();
void blurG ();
void blurC ();


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

void invert_image() {
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

void Black_whiteG(){
    int avg{};
    for(size_t i{}; i < SIZE; ++i ){
        for (size_t j{}; j < SIZE; ++j){
            avg += Gimage1[i][j];
        }
    }
    for (size_t i{0}; i < SIZE; ++i ){
        for (size_t j{0}; j < SIZE; ++j){
            if (Gimage1[i][j] > (avg/(SIZE*SIZE))){
                Gimage1[i][j] = 255;
            }else{
                Gimage1[i][j] = 0;

            }
        }
    }
}
//_________________________________________

void BW_color() {
    int avg{};


    for (size_t i{}; i < SIZE; ++i) {
        for (size_t row{}; row < SIZE; ++row) {
            for (size_t col{}; col < RGB; ++col) {
                avg += Cimage1[i][row][col];
           }
       }
    }

    for (size_t i{}; i < SIZE; ++i) {
        for (size_t r{}; r < SIZE; ++r) {
            for (size_t c{}; c < RGB; ++c) {
                if (((avg) /(SIZE*SIZE*RGB)) < Cimage1[i][r][c]) {
                    for (size_t k{}; k < RGB; ++k){
                        Cimage1[i][r][k] = 255;
                    }
                } else {
                    for (size_t k{}; k < RGB; ++k){
                        Cimage1[i][r][k] = 0;

                    }

                }
            }
        }
    }
}
//_________________________________________

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

//_________________________________________
void Enlarge_image() {
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
void shrinkG(){
    unsigned int choice, jump, nsize, num, blank;
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

//_________________________________________
void shrinkC() {

    unsigned int choice, jump, nsize, num, blank;
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

//_________________________________________
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

//_________________________________________
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

//_______________________________________________


int main(){
    char C_or_G, choice;

    cout << "Welcom dear user, This is a photoshop program\n\nIs your photo:\n1-Gray\n2-Colored" << endl;
    cin>>C_or_G;

    if (C_or_G == '1'){
        loadGImage1();
        while (choice != '0'){

            cout<<"\nWhat filter do you want to apply:\n\n1-Black & White Filter\n2-Invert Image\n3-Merge Images\n4-Flip Image\n6-Darken and Lighten Image\n8-Enlarge Image\n9-Shrink Image\nC-Blur Image\nS-Save the image to a file\n0-End\n\n"<<endl;
            cin >> choice;
            if (choice == '1'){
                Black_whiteG();
                cout<<"\nDONE!\n";
            }

            else if (choice == '2'){
                invert_image();
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

            else if (choice == '6'){
                LDGimage6();
                cout<<"\nDONE!\n";
            }

            else if (choice == '8'){
                Enlarge_image();
                cout<<"\nDONE!\n";

            }

            else if (choice == '9'){
                shrinkG();
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
            cout<<"\nWhat filter do you want to apply:\n\n1-Black & White Filter\n3-Merge Images\n4-Flip Image\n6-Darken and Lighten Image\n9-Shrink Image\nC-Blur Image\nS-Save the image to a file\n0-End\n\n";
            cin >> choice ;
            if (choice == '1'){
                BW_color();
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

            else if (choice == '6'){
                LDCimage6();
                cout<<"\nDONE!\n";
            }

            else if (choice == '9'){
                shrinkC();
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
