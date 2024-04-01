#include "BasicTransformation.h"
#include <iostream>
#include <cmath>

using namespace std;

vector<vector<int>> BasicTransformation::grayscale() {
    // Vector to store gray-information
    vector<vector<int>> gray(pixels.size(), vector<int>(pixels[0].size()));

    for(int x=0; x<pixels.size(); x++){
        for(int y=0; y<pixels[0].size(); y++){
            //Apply NTSC-formula
            gray[x][y] = round(0.299 * pixels[x][y][0] + 0.587*pixels[x][y][1] + 0.114*pixels[x][y][2]) / 3;
        }
    }
    return gray;
}

// Function to apply Sobel operator for edge detection
vector<vector<int>> BasicTransformation::sobelEdgeDetection(const bool binary, const int threashold) {
    // Sobel operator kernels
    const int sobelKernelX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    const int sobelKernelY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    int height = grayPixels.size();
    int width = grayPixels[0].size();

    vector<vector<int>> edgeImage(height, vector<int>(width, 0));

    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            int pixelX = 0;
            int pixelY = 0;

            // Apply Sobel operator for X and Y direction
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    pixelX += grayPixels[y + i][x + j] * sobelKernelX[i + 1][j + 1];
                    pixelY += grayPixels[y + i][x + j] * sobelKernelY[i + 1][j + 1];
                }
            }

            // Edge magnitude
            int magnitude = round(sqrt(pixelX * pixelX + pixelY * pixelY));
            if(binary){
                edgeImage[y][x] = magnitude <= threashold? 0 : 255;
            }else{
                edgeImage[y][x] = magnitude;
            }
        }
    }

    return edgeImage;
}
