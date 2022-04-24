// Program: All Filters.cpp
// Purpose: This is a simple photo editor by using bmplib libaray
// Author 1: Doaa ALi El-Sayed Mohamed (20211034)
// Author 2: Ahmed Yasser Mohamed Mohamed (20211010)
// Author 3: Ahmed Ahmed Hamed Ahmed (20211003)
// Last version:    23 April 2022


#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cmath>
#include "bmplib.cpp"
#include "bmplib.h"
//_________________________________________

unsigned char Cimage1[SIZE][SIZE][RGB], Cimage2[SIZE][SIZE][RGB];
unsigned char Gimage1[SIZE][SIZE], Gimage2[SIZE][SIZE];

//_________________________________________

#include"Save_Load.cpp"

//_________________________________________

void loadCImage1 ();
void loadCImage2 ();
void loadGImage1 ();
void loadGImage2 ();
void saveCImage ();
void saveGImage ();
//_________________________
void BW_gray();
void BW_color();
void invertGimage ();
void invertCimage ();
void MergeCImages ();
void MergeGImages ();
void flipG();
void flipC();
void Rotate_G();
void Rotate_C();
void LDCimage6 ();
void LDGimage6 ();
void edge_detectionG();
void edge_detectionRGB();
void enlargeGimage();
void enlargeCImage ();
void shrinkG ();
void shrinkC ();
void mirrorG();
void mirrorRGB();
void shuffleGImage ();
void shuffleCImage ();
void blurG ();
void blurC ();



//_______________________________________________

void BW_gray(){
    int avg{};
    for(size_t i{}; i < SIZE; ++i ){
        for (size_t j{}; j < SIZE; ++j){     // loop in rows and columns in the image
            avg += Gimage1[i][j];     // take the average of all pixels 
        }
    }
    for (size_t i{0}; i < SIZE; ++i ){
        for (size_t j{0}; j < SIZE; ++j){     // loop in rows and columns in the image
            if (Gimage1[i][j] > (avg/(SIZE*SIZE))){     // check if value of pixel > average
                Gimage1[i][j] = 255;        // set the value = 255 (white)
            }else{         // if value of pixel < average
                Gimage1[i][j] = 0;      // set the value = 0 (black)

            }
        }
    }
}
//_______________________________________________

void BW_color() {
    int avg{};


    for (size_t i{}; i < SIZE; ++i) {
        for (size_t row{}; row < SIZE; ++row) {
            for (size_t col{}; col < RGB; ++col) {  // loop in rows, columns and RGB in the image
                avg += Cimage1[i][row][col];        // take the average of all pixels 
           }
       }
    }

    for (size_t i{}; i < SIZE; ++i) {
        for (size_t r{}; r < SIZE; ++r) {
            for (size_t c{}; c < RGB; ++c) {  // loop in rows, columns and RGB in the image
                if (((avg) /(SIZE*SIZE*RGB)) < Cimage1[i][r][c]) {     // if value of average < pixel
                    for (size_t k{}; k < RGB; ++k){
                        Cimage1[i][r][k] = 255;     // set the value = 255 (white)
                    }
                } else {        // if value of average > pixel
                    for (size_t k{}; k < RGB; ++k){
                        Cimage1[i][r][k] = 0;    // set the value = 0 (black)

                    }
                }
            }
        }
    }
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

void MergeGImages () {
// to merge images we tak the avarge of same two pixels in both images
    for (int i = 0; i < SIZE; i++){   // loop in rows 
        for (int j = 0; j < SIZE; j++){   //loop in columns 
            Gimage1[i][j] = (Gimage1[i][j] + Gimage2[i][j]) / 2;  // take the averge and reassign the result in first image
        }
    }
}

//_______________________________________________

void MergeCImages () {
// to merge images we tak the avarge of same two pixels in both images

    for (int i = 0; i < SIZE; i++){    // loop in rows
        for (int j = 0; j < SIZE; j++){   //loop in columns 
            for (int k = 0; k < RGB; k++){   //loop in RGB

                Cimage1[i][j][k] = (Cimage1[i][j][k] + Cimage2[i][j][k]) / 2;   // take the averge and reassign the result in first image
            }
        }
    }
}

//_______________________________________________
void flipG(){
    char flip;
    cout << "Flip (h)orizontally or (v)ertically ?" << endl;
    cin >> flip;
    if(tolower(flip) == 'h'){            // if user chooses to flip horizontally
        for (int i{}; i < SIZE; ++i){
            for (int j{}; j < SIZE/2; ++j){    // loop on rows and half columns in image
                swap(Gimage1[i][j], Gimage1[i][SIZE-j-1]);     // swap each row on the top and its opposite

            }
        }

    }
    else{                      // if user chooses to flip vertically
        for (int i{}; i < SIZE; ++i){
            for (int j{}; j < SIZE / 2; ++j){      // loop on half rows and columns in image
                swap(Gimage1[j][i],Gimage1[SIZE-j-1][i]);     // swap each column on the right and its opposite on the left
            }
        }
    }
}

//_______________________________________________

void flipC(){
    char flip;
    cout << "Flip (h)orizontally or (v)ertically ?" << endl;
    cin >> flip;
    if(tolower(flip) == 'h'){      // if user chooses to flip horizontally
        for (int i{}; i < SIZE; ++i){
            for (int j{}; j < SIZE / 2; ++j){     // loop on rows and half columns in image
                for (int k{}; k < RGB; ++k){
                    swap(Cimage1[i][j][k], Cimage1[i][SIZE-j][k]);     // swap each row on the top and its opposite
                }
            }
        }

    }
    else{                  // if user chooses to flip vertically
        for (int i{}; i < SIZE; ++i){
            for (int j{}; j < SIZE / 2; ++j){     // loop on half rows and columns in image
                for (int k{}; k < RGB; ++k){
                    swap(Cimage1[j][i][k], Cimage1[SIZE-j-1][i][k]);       // swap each column on the right and its opposite on the left
                }
            }
        }
    }
}

//_______________________________________________
void G_upsideDown() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Gimage2[SIZE-i][SIZE-j] = Gimage1[i][j];        //makes the first column and row of pixels the first
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Gimage1[i][j] = Gimage2[i][j];      //loads the image into the 2d array Gimage1
        }
    }
}

void rotateG_TwoSeventy() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Gimage2[i][j] = Gimage1[j][i];      //makes rows columns and columns rows
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Gimage1[i][j] = Gimage2[i][j];      //loads the image into the 2d array Gimage1
        }
    }
}

void rotateG_Ninety() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Gimage2[i][j] = Gimage1[j][i];      //makes the rows columns and the columns rows
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Gimage1[SIZE-i][SIZE-j] = Gimage2[i][j];    //loads the image into the 2d array Gimage1
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
void C_upsideDown() {       //same as greyscale but with added RGB loop
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
    // this function to derken and lighten image (0 is black, 255 is white)
    char LD;
    cout << "Do you want to (d)arken or (l)ighten: ";
    cin >> LD;
    // darken image
    if (tolower(LD)=='d'){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                Gimage1[i][j] /=2;  // we take half value in each pixel to derken the image by 50%
            }
        }
    }
    // lighten image 
    else if (tolower(LD) == 'l'){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                if(Gimage1[i][j]>=128){   // if the value greater than half SIZE we can't double it becuse it will be out of range 
                    Gimage1[i][j] = 255;   // so we put the value at greatest light value which is 255
                }
                else{
                    Gimage1[i][j] *=2;  // we take double value in each pixel to lighten the image by 50%
                }
            }
        }
    }
}
//_______________________________________________

void LDCimage6 () {
    // this function to derken and lighten image (0 is black, 255 is white)
    char LD;
    cout << "Do you want to (d)arken or (l)ighten: ";
    cin >> LD;
    // darken image
    if (tolower(LD)=='d'){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                for(int k = 0; k < RGB; k++){
                    Cimage1[i][j][k] /=2 ;   // we take half value in each pixel to derken the image by 50%
                }
            }
        }
    }
    // lighten image 
    else if (tolower(LD) == 'l'){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                for(int k = 0; k < RGB; k++){
                    if(Cimage1[i][j][k]>=128){   // if the value greater than half SIZE we can't double it becuse it will be out of range 
                        Cimage1[i][j][k] = 255;    // so we put the value at greatest light value which is 255
                    }
                    else{
                        Cimage1[i][j][k] *=2;   // we take double value in each pixel to lighten the image by 50%
                    }
                }
            }
        }
    }
}

//_______________________________________________

void edge_detectionG() {
    BW_gray();          // change the image into black&white image
    for (int i{}; i < SIZE; ++i){
        for (int j{}; j < SIZE; ++j){
            Gimage2[i][j] = 255;      // set a white image2 
        }
    }

    for (int i{}; i < SIZE; ++i) {
        for (int j{}; j < SIZE; ++j) {
            if(Gimage1[i][j] == 0){   // check if all pixels around this black or not, then set this pixel = 0 (black)
                if(Gimage1[i][j-1] == 255 && Gimage1[i][j+1] == 0 || Gimage1[i][j-1] == 0 && Gimage1[i][j+1 ] == 255)
                    Gimage2[i][j] = Gimage1[i][j];

            }

        }
    }

    for (int i=0; i < SIZE; ++i) {
        for (int j=0; j < SIZE; ++j) {
                Gimage1[i][j] = Gimage2[i][j];     
        }
    }

}

//_______________________________________________

void edge_detectionRGB(){
    BW_color();      // change the image into black&white image
    for (int i{}; i < SIZE; ++i){
        for (int j{}; j < SIZE; ++j){
            for(int k{}; k < SIZE; ++k){
                Cimage2[i][j][k] = 255;          // set a white image2 
            }
        }
    }
    for (int i{}; i < SIZE; ++i) {
        for (int j{}; j < SIZE; ++j) {
            for(int k{}; k < RGB; ++k){

                if (Cimage1[i][j][k] == 0) {   // check if all pixels around this black or not, then set this pixel = 0 (black)
                    if ((Cimage1[i][j - 1][k] == 255 && Cimage1[i][j + 1][k] == 0 )||( Cimage1[i][j - 1][k] == 0 && Cimage1[i][j + 1][k] == 255) ){
                        Cimage2[i][j][k] = 0;
                    } else{
                        Cimage2[i][j][k] = 255;

                    }
                }
            }
        }
    }

    for (int i=0; i < SIZE; ++i) {
        for (int j=0; j < SIZE; ++j) {
            for(int k=0; k < RGB; ++k){
                Cimage1[i][j][k] = Cimage2[i][j][k];
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
            cout<<"invalid input."; // outputs invalid input if input is invalid
            return;
    }
    int row = 0;
    for(int k=startX; k<SIZE ; k++){    //makes a loop that is as big as the picture starting from the starting position
        int col =0 ;                    //declared at startX
        for (int i=startY ;i<SIZE ; i++){
            if (col>256) break;
            Gimage2[row][++col] = Gimage1[k][i];
            if (col>256) break;
            Gimage2[row][++col] = Gimage1[k][i];   //places each pixel twice to the right in order to enlarge the image
        }
        for (int j =0 ;j<SIZE ;j++){
            Gimage2[row+1][j] = Gimage2[row][j];    // copies the row above it
        }
        row+=2;
        if  (row>256) break;
    }

    for(int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            Gimage1[i][j] = Gimage2[i][j];
        }
    }

}


//_______________________________________________
void enlargeCImage() {          //same as g image but with added RGB
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
    // shrink image 
    int choice, jump, num, blank; //jump is the number we will divide by to sheink the image
    // we take how much user wanna shrink
    cout<<"\nHow much do you wanna shrink:\n1-1/2\n2-1/3\n3-1/4\n";
    cin>>choice;
    // check if it's not invalid input
    while (choice!=1&&choice!=2&&choice!=3)
    {
        cout<<"invalid input.";
        cout<<"\nHow much do you wanna shrink:\n1-1/2\n2-1/3\n3-1/4\n";
        cin>>choice;
    }

    switch (choice) {
        case 1:        // if shrink by 1/2
            jump = 2; // we set how many pixels we will jump 
            num = 4; // num of pixels making square that we will take the averge of them
            blank = SIZE/2; // the rest of the image 
            break;

        case 2:   // if shrink by 1/3
            jump = 3;
            num = 9;
            blank = SIZE/3;
            break;

        case 3:     // if shrink by 1/4
            jump = 4;
            num = 16;
            blank = SIZE/4;
            break;

            return;
    }

    int row = -1;    // define row for new image and set it = -1 and we will increase it
    
    for (int i = 0; i < SIZE; i+=jump){  // loop on old rows in old image
        
        int col = 0;  // define column of new image
        row++; // increase row so it will start from 0
        
        for (int j = 0; j < SIZE; j+=jump){   //loop on old columns in old image 
            
            int avrg =0;     
            
            for (int r =0; r<jump ; r++){    // loop on each square of pixels depends on the valu of num
                for (int c =0; c<jump ; c++){    // and take the sum of them 
                    
                    avrg += Gimage1[i+r][j+c];  
                }
            }
            
            avrg /= num ;  // take the average of square
            Gimage1[row][col] = avrg;  // set the pixel = average in order
            
            col++;  // increase column of new image
        }
    }

    // blank------------
    // start rows from blank (which was determined)
    // start columns from blank (which was determined)
    // then set the rest of image = 255 to be white
    for (int i = 0; i < blank; i++){  
        for (int j = blank; j < SIZE; j++){  
            Gimage1[i][j] = 255;
        }
    }

    for (int i = blank; i < SIZE; i++){
        for (int j = 0; j < blank; j++){
            Gimage1[i][j] = 255;
        }
    }

    for (int i = blank; i < SIZE; i++){
        for (int j = blank; j < SIZE; j++){
            Gimage1[i][j] = 255;
        }
    }

}

//_______________________________________________
void shrinkC() {

    int choice, jump, nsize, num, blank;    //jump is the number we will divide by to sheink the image
    // we take how much user wanna shrink
    cout<<"\nHow much do you wanna shrink:\n1-1/2\n2-1/3\n3-1/4\n";
    // check if it's not invalid input
    cin>>choice;
    while (choice!=1&&choice!=2&&choice!=3)
    {
        cout<<"invalid input.";
        cout<<"\nHow much do you wanna shrink:\n1-1/2\n2-1/3\n3-1/4\n";
        cin>>choice;
    }

    switch (choice) {
        case 1:     // if shrink by 1/2
            jump = 2;    // we set how many pixels we will jump 
            num = 4;     // num of pixels making square that we will take the averge of them
            blank = SIZE/2;   // the rest of the image 
            break;

        case 2:     // if shrink by 1/3
            jump = 3;
            num = 9;
            blank = SIZE/3;
            break;

        case 3:    // if shrink by 1/4
            jump = 4;
            num = 16;
            blank = SIZE/4;
            break;

            return;
    }

    int row = -1;   // define row for new image and set it = -1 and we will increase it
    
    for (int i = 0; i < nsize; i+=jump){   // loop on old rows in old image
       
        row++;    // increase row so it will start from 0
        int col = -1;    // define column of new image

        for (int j = 0; j < nsize; j+=jump){    //loop on old columns in old image 
           
            col++;

            for (int c = 0; c<RGB ; c++){

                int avrg = 0;

                for (int r =0; r<jump ; r++){   // loop on each square of pixels depends on the valu of num
                    for (int k = 0; k <jump; k++){   // and take the sum of them 
                       
                        avrg +=Cimage1[i+r][j+k][c];
                    }
                }

                avrg /= num;    // take the average of square
                Cimage1[row][col][c] = avrg;     // set the pixel = average in order
            }
        }
    }

    // blank------------
    // start rows from blank (which was determined)
    // start columns from blank (which was determined)
    // then set the rest of image = 255 to be white
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

void mirrorG(){
    char ch{};
    cout << "\nEnter the half of the image that you want to mirror 'L', 'R', 'U', 'D' " << endl;
    cin >> ch;

    if (tolower(ch) == 'r') {        // if mirror right half
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {    
                Gimage1[j][i] = Gimage1[j][SIZE - i]; // copy first column to last column, and increase the first and decrease the second
            }
        }
    }
    else if (tolower(ch) == 'l') {        // if mirror left half
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {    
                Gimage1[j][SIZE - i] = Gimage1[j][i];    // copy last column to first column, and decrease the first and increase the second
            }
        }
    }
    else if (tolower(ch) == 'u') {     // if mirror upper half
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {     
                Gimage1[i][j] = Gimage1[SIZE - i][j];      // copy first row to last row, and increase the first and decrease the second
            }
        }
    }
    else {        // if mirror down half
        for (int i{}; i < SIZE / 2; ++i) {    
            for (int j{}; j < SIZE; ++j) {
                Gimage1[SIZE - i][j] = Gimage1[i][j];     // copy last row to first row, and decrease the first and increase the second
            }
        }
    }

}

//_______________________________________________

void mirrorRGB() {
    char ch{};
    cout << "\nEnter the half of the image that you want to mirror 'L', 'R', 'U', 'D' " << endl;
    cin >> ch;
    if (tolower(ch) == 'r') {
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {
                for (int k{}; k < RGB; ++k) {
                    Cimage1[j][i][k] = Cimage1[j][SIZE - i][k];

                }
            }
        }
    }
    else if (tolower(ch) == 'l') {
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {
                for (int k{}; k < RGB; ++k) {
                    Cimage1[j][SIZE - i][k] = Cimage1[j][i][k];

                }
            }
        }
    }
    else if (tolower(ch) == 'u') {
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {
                for (int k{}; k < RGB; ++k) {
                    Cimage1[i][j][k] = Cimage1[SIZE - i][j][k];

                }
            }
        }
    }
    else {
        for (int i{}; i < SIZE / 2; ++i) {
            for (int j{}; j < SIZE; ++j) {
                for (int k{}; k < RGB; ++k) {
                    Cimage1[SIZE - i][j][k] = Cimage1[i][j][k];

                }
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

  // blur image function
    for (int i = 0; i < SIZE-1; i++) {   // loop on rows in image 
        for (int j = 0; j< SIZE-1; j++) {  // loop on columns in image

            int avrg = 0 ;  // define average

            for (int r = 0; r<3; r++){   //loop on each squar of pixels 3x3 
                for (int c=0; c<3; c++){   // then take sum of their value
                    avrg += Gimage1[i+r][j+c];
                }
            }

            avrg /= 9;  // take the average 
            Gimage1[i+1][j+1] = avrg;   // set each pixel the average of the square
        }
    }
}
    
//_______________________________________________

void blurC() {

    for (int i = 0; i < SIZE-1; i++) {   // loop on rows in image 
        for (int j = 0; j< SIZE-1; j++) {    // loop on columns in image
            for (int k = 0; k < RGB ; k++)   // loop on RGB
            {
                // blur color

                int avrg = 0 ;   // define average

                for (int r = 0; r<3; r++){    //loop on each squar of pixels 3x3 
                    for (int c=0; c<3; c++){    // then take sum of their value
                        avrg += Cimage1[i+r][j+c][k]; 
                    }
                }

                avrg /= 9;    // take the average 
                Cimage1[i+1][j+1][k] = avrg;    // set each pixel the average of the square
                
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

            cout<<"\nWhat filter do you want to apply:\n\n1- Black & White Filter\n2- Invert Image\n3- Merge Images\n4- Flip Image\n5- Rotate Image\n6- Darken and Lighten Image\n7- Detect Image Edges\n8- Enlarge Image\n9- Shrink Image\nA- Mirror 1/2 Image\nB- Shuffle Image\nC- Blur Image\nS- Save the image to a file\n0- End\n\n"<<endl;
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

            else if (choice == '7'){
                edge_detectionG();
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

            else if (tolower(choice) == 'a'){
                mirrorG();
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

            else{
                cout<<"Invalid Input!\nTry Again!\n";
            }
            
        }
    }


    else if (C_or_G == '2'){
        loadCImage1();
        while (choice != '0'){
            cout<<"\nWhat filter do you want to apply:\n\n1- Black & White Filter\n2- Invert Image Color\n3- Merge Images\n4- Flip Image\n5- Rotate Image\n6- Darken and Lighten Image\n7- Detect Image Edges\n8- Enlarge Image\n9- Shrink Image\nA- Mirror 1/2 Image\nB- Shuffle Image\nC- Blur Image\nS- Save the image to a file\n0- End\n\n";
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

            else if (choice == '7'){
                edge_detectionRGB();
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

            else if (tolower(choice) == 'a'){
                mirrorRGB();
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

            else{
                cout<<"Invalid Input!\nTry Again!\n";
            }

        }
    }
    return 0;
}
