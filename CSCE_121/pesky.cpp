#include <iostream>
#include <fstream>

using namespace std;

struct Pixel {
    int r;
    int g;
    int b;
};

void mySwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int getMedian(int a, int b, int c) {
    // sort local copies
    if (b<a) {
        mySwap(a,b);
    }
    if (c<a) {
        mySwap(a,c);
    }
    if (c<b) {
        mySwap(b,c);
    }
    // return middle value

    return b;
}

Pixel** makeImage(int width, int height) {
    Pixel** img = new Pixel*[width];
    for (int col=0; col < width; ++col) {
        img[col] = new Pixel[height];
    }
    return img;
}

// (ifstream, image, width, height)
// we'll assume good input
void loadImage(ifstream& ifs, Pixel**& img, int& width, int& height) {
    // get preample data including width and height
     string type;
    ifs >> type; // should be P3
    ifs >> width >> height;
    int colorMax = -1;
    ifs >> colorMax;

    // allocate memory for the iamge based on width and height
    img = makeImage(width, height);

    // load up
    for (int row=0; row<height; ++row) {
        for (int col=0; col<width; ++col) {
            ifs >> img[col][row].r;
            ifs >> img[col][row].g;
            ifs >> img[col][row].b;
        }
    }
}

// (ofstream, image, width, height)
void outputImage(ofstream& ofs, const Pixel*const* img, int width, int height) {
    ofs << "P3" << endl;
    ofs << width << " " << height << endl;
    ofs << 255 << endl;
    for (int row=0; row<height; ++row) {
        for (int col=0; col<width; ++col) {
            ofs << img[col][row].r << " ";
            ofs << img[col][row].g << " ";
            ofs << img[col][row].b << " ";
        }
        ofs << endl;
    }
}

// (image, what else?)
void deleteImage(Pixel**& img, int width) {
    for (int col=0; col<width; ++col) {
        delete [] img[col];
    }
    delete [] img;
}

int main() {
    try {
        ifstream file1("first.ppm");
        ifstream file2("second.ppm");
        ifstream file3("third.ppm");
        ofstream outFile("result.ppm");
        if (!file1.is_open() || !file2.is_open() || !file3.is_open() || !outFile.is_open()) {
            cout << "Unable to open input files" << endl;
            return 1;
        }

        Pixel** img1 = nullptr;
        Pixel** img2 = nullptr;
        Pixel** img3 = nullptr;
        Pixel** result = nullptr;
        int width = -1;
        int height = -1;
        int loadWidth = -1;
        int loadHeight = -1;

        // Load & create 2D arrays
        loadImage(file1, img1, width, height);
        loadImage(file2, img2, loadWidth, loadHeight);
        if (width != loadWidth || height != loadHeight) {
            cout << "Images are incompatible." << endl;
            return 1;
        }
        loadImage(file3, img3, loadWidth, loadHeight);
        if (width != loadWidth || height != loadHeight) {
            cout << "Images are incompatible." << endl;
            return 1;
        }

        // Make result image
        result = makeImage(width, height);

        // Process that pesky tourist
        for (int col=0; col<width; col++) {
            for (int row=0; row<height; row++) {
                result[col][row].r = 
                    getMedian(img1[col][row].r, img2[col][row].r, img3[col][row].r);
                result[col][row].g = 
                    getMedian(img1[col][row].g, img2[col][row].g, img3[col][row].g);
                result[col][row].b = 
                    getMedian(img1[col][row].b, img2[col][row].b, img3[col][row].b);
            }
        }

        // output result image
        outputImage(outFile, result, width, height);

        // delete images to avoid memory leaks
        deleteImage(img1, width);
        deleteImage(img2, width);
        deleteImage(img3, width);
        deleteImage(result, width);

    }
    catch (...) {
        cout << "Encountered an unexpected error!" <<endl;
    }
}