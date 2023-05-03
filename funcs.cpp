#include "funcs.h"
#include "imageio.h"
#include <string>
#include <cmath>

    // TASK A - function that inverts all colors, so white shades become black, and black become white
    // Since black = 0, and white = 255, you should do the following transformation for each pixel color:
    // 0 → 255
    // 1 → 254
    // 2 → 253
void invert(std::string file){  // taking in the image as a parameter
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(file, image, height, width);
        // using a nested for loop to go through the coloumns and rows of the image 
    for(int row = 0; row < MAX_H; row++){
        for(int col = 0; col < MAX_W; col++){
            image[row][col] = 255 - image[row][col];    // subtracting 255 pixel colors to invert the image
        }
    }
    writeImage("taskA.pgm", image, height, width);  // output image
}

    // TASK B - function that  that inverts the colors only in the right half of the picture.
void invert_half(std::string file){
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(file, image, height, width);
    for(int row = 0; row < MAX_H; row++){
        for(int col = 0; col < MAX_W; col++){
                // modified the inner loop to only iterate over the columns on the right half of the image by 
                // setting the loop's starting point to w/2
                // which is the index of the first column in the right half of the image
			if(col>(width/2)){
            	image[row][col] = 255 - image[row][col];    // subtracting 255 pixel colors to invert the image
			}
        }
    }
    writeImage("taskB.pgm", image, height, width);	
}

    // TASK C - function that draws a white box exactly in the middle of the picture. 
    // The dimensions of the box should be 50% by 50% of the original picture’s width and height.
void box_image(std::string file){
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(file, image, height, width);
    for(int row = 0; row < MAX_H; row++){
        for(int col = 0; col < MAX_W; col++){
                // modified the inner loop to only iterate over the 50% by 50%  of the original picture
			if(col>(width/4) && col<(3*width/4) && row>(height/4) && row<(3*height/4)){
            	image[row][col] = 255;  // white = 255
			}
        }
    }
    writeImage("taskC.pgm", image, height, width);	
}

    // TASK D - function that creates a frame exactly one pixel thick 
void line_image(std::string file){
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(file, image, height, width);
    for(int row = 0; row < MAX_H; row++){
        for(int col = 0; col < MAX_W; col++){
                // checking the dimensions of the image to create the box in the middle of the image
			if(col>=(width/4) && col<=(3*width/4) && row>=(height/4) && row<=(3*height/4)){
				if(col==(width/4) || col==(3*width/4) || row==(height/4) || row==(3*height/4)){
            		image[row][col] = 255;  // set the pixel values of the frame to white
				}
			}
        }
    }
    writeImage("taskD.pgm", image, height, width);		
}

    // TASK E - function that scales the original picture to 200% of its size
    // increasing the size of the pictyre by the factor of 2, 
    // and copying each pixel of the input as a small 2x2 square in the output
void twice_image(std::string file){
    int height, width;
    int image[MAX_H][MAX_W];
    int newimage[MAX_H][MAX_W]; // create a new image array to hold the scaled image
    readImage(file, image, height, width);
        // copy the pixel value into a 2x2 square in the new image array
        // double the height and width of the image
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            newimage[row*2][col*2] = image[row][col];
            newimage[row*2][col*2+1] = image[row][col];
            newimage[row*2+1][col*2] = image[row][col];
            newimage[row*2+1][col*2+1] = image[row][col];
        }
    }
    writeImage("taskE.pgm", newimage, 2*height, 2*width);
}

    // TASK F - function that pixelates the input image
    // One way to pixelate an image is to effectively make every 2x2 non-overlapping window 
    // contain the same value (averaged over all the pixels in that window of the input).
void pixel_image(std::string file){
    int height, width;
    int image[MAX_H][MAX_W];
    int newimage[MAX_H][MAX_W];  // create a new image array to hold the scaled image 
    readImage(file, image, height, width);
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
                // set the pixel value in the new image array to the computed average
            int avg = round((image[row][col]+image[row][col+1] + image[row+1][col] + image[row+1][col+1]) / 4);
                newimage[row][col] = avg;
                newimage[row][col+1] = avg;
                newimage[row+1][col] = avg;
                newimage[row+1][col+1] = avg;
                col = col + 1;
                }
                row++;
        }
        writeImage("taskF.pgm", newimage, height, width);
}
