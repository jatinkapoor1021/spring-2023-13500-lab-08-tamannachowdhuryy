#include <iostream>
#include "funcs.h"
#include "imageio.h"

int main() {
	std::cout << "Running...\n";

	invert("inImage.pgm"); // Task A

	invert_half("inImage.pgm"); // Task B

	box("inImage.pgm"); // Task C

	frame("inImage.pgm"); // Task D

	scale("inImage.pgm"); // Task E

	pixelate("inImage.pgm"); // Task F

	std::cout << "Completed.\n";

	return 0;
}
