#include "image.h"
#include "CImg.h"

using namespace cimg_library;

void showOneImage(string nomDir) {
	CImg<unsigned char> image;
	const char * path = nomDir.c_str();
	unsigned char grid_color[3] = { 0,0,255 };

	// Load an image file into it
	image.load(path);
	image = image.get_resize(512, 770, -100, -100, 5, 0, 0, 0, 0, 0);

	// Declare a display and dispay the image into it

	CImgDisplay disp(image, "Image");
	
	// Wait for the display window to close
	while (!disp.is_closed()) {
		disp.wait();
		//if (disp.is_resized()) disp.resize();
		
	}
	delete[] path;
}