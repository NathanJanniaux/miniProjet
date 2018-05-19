#include "App.h"
#include "CImg.h"
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace cimg_library;
using namespace std;

App::App() {

}

/*void App::displayWindow() {
	unsigned char grid_color[3] = { 0,0,255 };
	// Declare an image to draw the grid
	CImg<unsigned char> grid(600, 600, 1, 3, 255);
	for (int i = 1; i<3; i++) grid.draw_line(0, 200 * i, 600, 200 * i, grid_color);
	for (int j = 1; j<3; j++) grid.draw_line(200 * j, 0, 200 * j, 600, grid_color);

	// Declare a display to draw the scene
	CImgDisplay disp(grid, "Tic-tac-toe", 0, false, false);

	// Center the window on the screen
	disp.move((CImgDisplay::screen_width() - disp.width()) / 2,
		(CImgDisplay::screen_height() - disp.height()) / 2);
	// Handle window resize
	if (disp.is_resized()) disp.resize();
	CImg<unsigned char> scene = grid;
	//CImgList<T> list= new CImgList (2, 60, 60, 1,1);

	// Main loop, exit if the display window is closed or if ESC or Q key is hit
	while (!disp.is_closed() && !disp.is_keyESC() && !disp.is_keyQ()) {
		CImg<unsigned char> image;
		scene.display(disp);
		image.load("0.ppm");
		image = image.get_resize(512/4, 770/4, -100, -100, 5, 0, 0, 0, 0, 0);
		CImgDisplay disp2(image, "Tic-tac-toe", 0, false, false);
		scene.display(disp2);
	}
	system("pause");
}*/


void App::displayWindow() {
	// Load up all images into CImg structures
	CImg<unsigned char> p0("0.ppm");
	CImg<unsigned char> p1("1.ppm");
	CImg<unsigned char> p2("2.ppm");
	CImg<unsigned char> p3("3.ppm");
	CImg<unsigned char> p4("4.ppm");
	CImg<unsigned char> p5("5.ppm");
	CImg<unsigned char> p6("6.ppm");
	CImg<unsigned char> p7("7.ppm");
	CImg<unsigned char> p8("8.ppm");
	vector<CImg<unsigned char>> listImage = { p0, p1, p2, p3, p4, p5, p6, p7, p8 };

	for (vector<CImg<unsigned char> >::iterator it = listImage.begin(); it != listImage.end(); ++it)
	{
		float coeff = 0;
		if (it->height() > it->width()) {
			coeff = 184 /((float) it->width());
		}
		else {
			coeff = 184 /((float) it->height());
		}
		it->resize(it->width()*coeff, it->height()*coeff, -100, -100, 5, 0, 0.5, 0, 0, 0);
	}

	// Declare output and intermediate variables
	CImg<unsigned char> row0, row1, row2, grid;

	// Append horizontally into a row
	row0 =listImage[0].append(listImage[1], 'x', 0.5).append(listImage[2],'x', 0.5);

	// Append horizontally into a row
	row1 = listImage[3].append(listImage[4], 'x', 0.5).append(listImage[5], 'x', 0.5);

	row2 = listImage[6].append(listImage[7], 'x', 0.5).append(listImage[8], 'x',0.5);


	// Append vertically into a column
	grid = row0.append(row1, 'y', 0.5).append(row2, 'y', 0);

	grid.display();
	

}
