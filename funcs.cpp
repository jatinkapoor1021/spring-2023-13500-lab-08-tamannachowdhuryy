/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab8 A,B,C,D,E,F

This program will changed the photos to the way it needs to be. For example Task A will make the photo inverted
*/

#include <iostream>
#include "imageio.h"
#include "funcs.h"
#include <cmath>
#include <cstdlib>

// Task A
void invert(std::string file) {
	int image[MAX_H][MAX_W];
	int height, width;

	readImage(file, image, height, width);

	for (int i = 0; i < MAX_H; i++) { // for loop for row 
		for (int j = 0; j < MAX_W; j++) {  //for loop for col
			image[i][j] = abs(image[i][j] - 255); // subtracting by 255 b/c thats the white color we need to make tge image inverted
		}
	}

	writeImage("taskA.pgm", image, height, width); // this will print the image out like it was shown in the lab 
}


// Task B
void invert_half(std::string file) { // this is where the image will be half inverted 
	int image[MAX_H][MAX_W]; // made an int for the image for the max height adn width 
	int height, width; // int for the regular height and width 

	readImage(file, image, height, width); // this will read the file given (cat for main.cpp) will read it and get the height and width 

	for (int i= 0; i < MAX_H; i++) { // we will do the same thing in task a where we put it in a for loop 
		for (int j = width / 2; j < MAX_W; j++) { // this time we will divide it in half so one side will stay normal and the other will change to inverted
			image[i][j] = abs(image[i][j] - 255);
		}
	}

	writeImage("taskB.pgm", image, height, width); // this will change the image and rename it as taskB and print out the new image for the height and width that it was given 
}


// Task C
void box(std::string file) { // this will put a box in the middle of the picture 
	int image[MAX_H][MAX_W]; // we declear the image max and width and height
	int height, width;
	readImage(file, image, height, width); // then the image will read for us to change the code later on

	for (int i = height / 4; i < height * 3/4; i++) { // for loop but this time we will make the height divide by 4 and multiply by 3/4 to get the box to be in the middle
		for (int j = width / 4; j < width * 3/4; j++) {
			image[i][j] = 255; // the image will display just white so we won't subtract it 
		}
	}

	writeImage("taskC.pgm", image, height, width); // will reprint the image with the new edits from the code 
}


// Task D
void frame(std::string file) { // this where we put a frame in the middle of the image 
	int image[MAX_H][MAX_W]; // declare max hieght and width 
	int height, width;
	readImage(file, image, height, width); // will read the original image so it can make the edits laster 

	for (int i = height / 4; i < height * 3/4; i++) { // doing the same thing from task C 
		for (int j = width / 4; j < width * 3/4; j++) { 
			if (i == height / 4 || i == height * 3/4 - 1 || j == width / 4 || j == width * 3/4 - 1) { // this time we will be using an if statement where we divide the height by 4 and give the computer or statements so it knows what to do when making the border 
				image[i][j] = 255; // this will make the boarder white 
			}
		}
	}

	writeImage("taskD.pgm", image, height, width); // replaces the image with the edits 
}


// Task E
void scale(std::string file) { // this will scale the image to be bigger 
	int image[MAX_H][MAX_W]; // images max hieght and width 
	int output[MAX_H][MAX_W]; // the output of hieght and width 
	int height, width;
	readImage(file, image, height, width); // will then read the image of the hieght and width 

	for (int i = 0; i < height; i++) {  // same code from the previous tasks
		for (int j = 0; j < width; j++) {
			output[i * 2][j * 2] = image[i][j]; // the output will print the row and colunm and multiply it by e 
			output[i * 2][j * 2 + 1] = image[i][j]; // do the same thing except add by 1
			output[i * 2 + 1][j * 2] = image[i][j];
			output[i * 2 + 1][j * 2 + 1] = image[i][j];
		}
	}
	height *= 2; //  mulptipy by 2 for hieght and width to double the image 
	width *= 2;

	writeImage("taskE.pgm", output, height, width); // replaces the image with the new one
} 


// Task F
void pixelate(std::string file) { // this will make the image kinda blury 
	int image[MAX_H][MAX_W];
	int height, width;
	readImage(file, image, height, width); // same thing from the previous codes 

	for (int i = 0; i < height; i += 2) {
		for (int j = 0; j < width; j += 2) {
			int avg = (image[i][j] + image[i][j+1] + image[i+1][j] + image[i+1][j+1]) / 4; // go through and make the changed from column to row to make it pixilated
			image[i][j] = avg;
			image[i][j+1] = avg;
			image[i+1][j] = avg;
			image[i+1][j+1] = avg;
		}
	}

	writeImage("taskF.pgm", image, height, width); // this will print the final image 
}
