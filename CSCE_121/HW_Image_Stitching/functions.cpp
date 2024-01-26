#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

void loadCorners(std::string filename, Corner imageCorners[MAX_CORNERS], unsigned int& numberOfCorners){
    // Read load corners file

    ifstream inputFS;
    inputFS.open(filename);

    if (!inputFS.is_open()) {
        throw runtime_error("Failed to open <filename>");
    }
  
    numberOfCorners = 0;
    for (int i = 0; i < 100; i++) {
        if (inputFS >> imageCorners[i].x && inputFS >> imageCorners[i].y) {
            numberOfCorners++;  
        }
    }

    int extra;
    if (inputFS >> extra) {
        throw runtime_error("Too many corners in <filename>.");
    }
}

double errorCalculation(Pixel image1[][MAX_HEIGHT], const unsigned int width1, const unsigned int height1,
                      Corner image1corner,
                      Pixel image2[][MAX_HEIGHT], const unsigned int width2, const unsigned int height2,
                      Corner image2corner){
            
    // Error calculation
    double error = 0;
    double red;
    double blue;
    double green;

    if (static_cast<int>(image1corner.x - ERROR_NEIGHBORHOOD_SIZE / 2) < 0 || static_cast<int>(image1corner.x + ERROR_NEIGHBORHOOD_SIZE / 2) > static_cast<int>(width1)) {
        return INFINITY;
    }
    else if (static_cast<int>(image1corner.y - ERROR_NEIGHBORHOOD_SIZE / 2) < 0 || static_cast<int>(image1corner.y + ERROR_NEIGHBORHOOD_SIZE / 2) > static_cast<int>(height1)) {
        return INFINITY;
    }
    else if (static_cast<int>(image2corner.x - ERROR_NEIGHBORHOOD_SIZE / 2) < 0 || static_cast<int>(image2corner.x + ERROR_NEIGHBORHOOD_SIZE / 2) > static_cast<int>(width2)) {
        return INFINITY;
    }
    else if (static_cast<int>(image2corner.y - ERROR_NEIGHBORHOOD_SIZE / 2) < 0 || static_cast<int>(image2corner.y + ERROR_NEIGHBORHOOD_SIZE / 2) > static_cast<int>(height2)) {
        return INFINITY;
    }
    else {
        for (int k = -1 * static_cast<int>(ERROR_NEIGHBORHOOD_SIZE) / 2; k <= static_cast<int>(ERROR_NEIGHBORHOOD_SIZE) / 2; k++) {
            for (int j = -1 * static_cast<int>(ERROR_NEIGHBORHOOD_SIZE) / 2; j <= static_cast<int>(ERROR_NEIGHBORHOOD_SIZE) / 2; j++) {
                red = image1[image1corner.x + k][image1corner.y + j].r - image2[image2corner.x + k][image2corner.y + j].r;
                green = image1[image1corner.x + k][image1corner.y + j].g - image2[image2corner.x + k][image2corner.y + j].g;
                blue = image1[image1corner.x + k][image1corner.y + j].b - image2[image2corner.x + k][image2corner.y + j].b;
                error += abs(red) + abs(green) + abs(blue);
            }
        }
    }
    return error;
}

void matchCorners(CornerPair matchedPairs[MAX_CORNERS], unsigned int &matched_count,
                  Pixel image1[][MAX_HEIGHT], const unsigned int width1, const unsigned int height1,
                  Corner image1corners[], unsigned int image1CornerCount,
                  Pixel image2[][MAX_HEIGHT], const unsigned int width2, const unsigned int height2,
                  Corner image2corners[], unsigned int image2CornerCount){

    // Greedy corner matching goes here

    double minimumerror;
    Corner minimumcorner;
    double currenterror;
    matched_count = 0;
    unsigned int usedcorners[MAX_CORNERS];
    unsigned int index;
    bool used;

    for (unsigned int i = 0; i < image1CornerCount; i++) {
        minimumerror = INFINITY;
        for (unsigned int j = 0; j < image2CornerCount; j++) {
            used = false;
            currenterror = errorCalculation(image1, width1, height1, image1corners[i], image2, width2, height2, image2corners[j]);
            for (unsigned int k = 0; k < matched_count; k++) {
                if (j == usedcorners[k]) {
                    used = true;
                    break;
                }
            }
            if (used == true) {
                continue;
            }
            if (currenterror < minimumerror) {
                minimumerror = currenterror;
                minimumcorner.x = image2corners[j].x;
                minimumcorner.y = image2corners[j].y;
                index = j;
            }
        }

        if (minimumerror == INFINITY) {
            continue;
        }
        if (minimumerror < INFINITY) {
            matchedPairs[matched_count].image1Corner = image1corners[i];
            matchedPairs[matched_count].image2Corner = minimumcorner;
            matchedPairs[matched_count].error = minimumerror;
            usedcorners[matched_count] = index;
            matched_count++;
        }
    }
}

void mapCoordinates(const double H[3][3], unsigned int x, unsigned int y,
                    double& mapped_x, double& mapped_y){

    // Mapping function for this week
    double x_prime = H[0][0] * static_cast<double>(x) + H[0][1] * static_cast<double>(y) + H[0][2];
    double y_prime = H[1][0] * static_cast<double>(x) + H[1][1] * static_cast<double>(y) + H[1][2];
    double z_prime = H[2][0] * static_cast<double>(x) + H[2][1] * static_cast<double>(y) + H[2][2];

    mapped_x = x_prime / z_prime;
    mapped_y = y_prime / z_prime;

}

void mergeImages( Pixel image1[][MAX_HEIGHT], unsigned int &width1, unsigned int &height1,
                  Pixel image2[][MAX_HEIGHT], const unsigned int width2, const unsigned int height2,
                  double H[3][3] ){
        
    // Similar to image scaling function from last week with some additional steps.

    double map_x;
    double map_y;
    Pixel I1_pixel;
    Pixel I2_pixel;
    Pixel New_pixel;
    bool I1_defined;
    bool I2_defined;
    
    for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
        for (unsigned int col = 0; col < MAX_WIDTH; col++) {
            I1_defined = false;
            I2_defined = false;
            mapCoordinates(H, col, row, map_x, map_y);
            if (map_x >= 0 && map_y >= 0 && map_x < width2 && map_y < height2) {
                I2_pixel = bilinear_interpolation(image2, width2, height2, map_x, map_y);
                I2_defined = true;
            }

            if (row < height1 && col < width1) {
                I1_pixel = image1[col][row];
                I1_defined = true;
            }

            if (I1_defined == true && I2_defined == true) {
                New_pixel = {static_cast<short>((I1_pixel.r + I2_pixel.r) / 2), static_cast<short>((I1_pixel.g + I2_pixel.g) / 2), static_cast<short>((I1_pixel.b + I2_pixel.b) / 2)};
            }
            else if (I1_defined == true && I2_defined == false) {
                New_pixel = I1_pixel;
            }
            else if (I1_defined == false && I2_defined == true) {
                New_pixel = I2_pixel;
            }
            else {
                continue;
            }

            image1[col][row] = New_pixel;
        }
    }

    width1 = MAX_WIDTH;
    height1 = MAX_HEIGHT;
}
