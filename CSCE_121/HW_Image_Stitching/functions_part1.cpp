#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

// Copy code from last week for local run. Gradescope will use it's own copy

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height) {
  // TODO: implement image loading
  // Reading file
  ifstream inputFS;
  inputFS.open(filename);

  if (!inputFS.is_open()) {
    throw runtime_error("Failed to open <filename>");
  }
  
  string type;
  inputFS >> type;
  if (type != "P3" && type != "p3") {
    throw runtime_error("Invalid type <type>");
  }

  if (!(inputFS >> width >> height) || height > 1080 || width > 1920) {
    throw runtime_error("Invalid dimensions");
  }

  int maxvalue;
  inputFS >> maxvalue;

  int actual = 0;
  int expected = width * height * 3;
  for (unsigned int row = 0; row < height; row++) {
    for (unsigned int col = 0; col < width; col++) {
      if (inputFS >> image[col][row].r) {
        actual++;
      }
      if (image[col][row].r >= 256 || image[col][row].r < 0) {
        throw runtime_error("Invalid color value");
      }

      if (inputFS >> image[col][row].g) {
        actual++;
      }
      if (image[col][row].g >= 256 || image[col][row].g < 0) {
        throw runtime_error("Invalid color value");
      }

      if (inputFS >> image[col][row].b) {
        actual++;
      }
      if (image[col][row].b >= 256 || image[col][row].b < 0) {
        throw runtime_error("Invalid color value");
      }
    }
  }

  if (actual < expected) {
    throw runtime_error("Invalid color value");
  }
  int extra;
  if (inputFS >> extra) {
    throw runtime_error("Too many values");
  }
}


void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height) {
  // TODO: implement writing image to file
  ofstream outputFile;
  outputFile.open(filename);

  if (!outputFile.is_open()) {
    throw invalid_argument("Failed to open <filename>");
  }

  outputFile << "P3" << endl;
  outputFile << width << " " << height << endl;
  outputFile << "255" << endl;

  for (unsigned int row = 0; row < height; row++) {
    for (unsigned int col = 0; col < width; col++) {
      outputFile << image[col][row].r << endl;
      outputFile << image[col][row].g << endl;
      outputFile << image[col][row].b << endl;
    }
  }
}


Pixel bilinear_interpolation(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, double x, double y) {
  unsigned int x_floor = floor(x);
  unsigned int x_ceil = ceil(x);
  unsigned int y_floor = floor(y);
  unsigned int y_ceil = ceil(y);

  if (x_floor == x_ceil) {
    x_ceil++;
  }
  if (y_floor == y_ceil) {
    y_ceil++;
  }

  if (x_floor > width) {
    x_floor = width;
  }
  if (x_ceil > width) {
    x_ceil = width;
  }
  if (y_floor > height) {
    y_floor = height;
  }
  if (y_ceil > height) {
    y_ceil = height;
  }

  double P1r = image[x_floor][y_floor].r;
  double P1g = image[x_floor][y_floor].g;
  double P1b = image[x_floor][y_floor].b;

  double P2r = image[x_ceil][y_floor].r; 
  double P2g = image[x_ceil][y_floor].g; 
  double P2b = image[x_ceil][y_floor].b; 

  double P3r = image[x_floor][y_ceil].r; 
  double P3g = image[x_floor][y_ceil].g; 
  double P3b = image[x_floor][y_ceil].b; 

  double P4r = image[x_ceil][y_ceil].r; 
  double P4g = image[x_ceil][y_ceil].g; 
  double P4b = image[x_ceil][y_ceil].b; 

  double I1r = (x - x_floor) * P2r + (x_ceil - x) * P1r;
  double I1g = (x - x_floor) * P2g + (x_ceil - x) * P1g;
  double I1b = (x - x_floor) * P2b + (x_ceil - x) * P1b;

  double I2r = (x - x_floor) * P4r + (x_ceil - x) * P3r;
  double I2g = (x - x_floor) * P4g + (x_ceil - x) * P3g;
  double I2b = (x - x_floor) * P4b + (x_ceil - x) * P3b;

  double F1r = (y_ceil - y) * I1r + (y - y_floor) * I2r;
  double F1g = (y_ceil - y) * I1g + (y - y_floor) * I2g;
  double F1b = (y_ceil - y) * I1b + (y - y_floor) * I2b;

  int Fr = round(F1r);
  int Fg = round(F1g);
  int Fb = round(F1b);

  Pixel pixel;
  pixel.r = Fr;
  pixel.g = Fg;
  pixel.b = Fb;

  return pixel;
}

