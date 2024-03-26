#include "BasicTransformation.h"
#include <iostream>

using namespace std;

//3D-Tensor of pixeldata
vector<vector<array<int, 3>>> pixels;

BasicTransformation::BasicTransformation(vector<vector<array<int, 3>>> pixels) {
    //Initialize variables
    this->pixels = pixels;
}

vector<vector<int>> BasicTransformation::grayscale() {
    // Vector to store gray-information
    vector<vector<int>> gray(pixels.size(), vector<int>(pixels[0].size()));

    for(int x=0; x<pixels.size(); x++){
        for(int y=0; y<pixels[0].size(); y++){
            gray[x][y] = (pixels[x][y][0] + pixels[x][y][1] + pixels[x][y][2]) / 3;
        }
    }
    return gray;
}
