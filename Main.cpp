#include <iostream>
#include <opencv2/opencv.hpp>
#include<vector>
#include <array>
#include <string>

#include "BasicTransformation/BasicTransformation.h"


using namespace cv;
using namespace std;

// Function to convert vector<vector<int>> to cv::Mat
Mat grayscaleVectorToMat(const vector<vector<int>>& pixels) {
    // Get image dimensions
    int rows = pixels.empty() ? 0 : pixels.size();
    int cols = rows == 0 || pixels[0].empty() ? 0 : pixels[0].size();

    // Create a Mat object with the same dimensions
    Mat image(rows, cols, CV_8UC1);

    // Iterate through the pixels and assign values to the Mat object
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            image.at<uchar>(i, j) = static_cast<uchar>(pixels[i][j]);
        }
    }

    return image;
}

int main(int argc, char** argv )
{
    // Load Image
    Mat image = imread("C:/Users/marvi/Desktop/Projekt/Computer_Vision/lenna.png");
    // Check if the image was loaded successfully
    if (!image.data)
    {
        cout<<("No image is found")<<endl;
        return -1;
    }

    // Image attributes
    int imageRows = image.rows;
    int imageColumns = image.cols;

    // Vector to store pixle information
    vector<vector<array<int, 3>>> pixels(imageRows, vector<array<int, 3>>(imageColumns));

    // Get RGB-values of the image
    for(int x=0; x<imageColumns; x++){
        for(int y=0; y<imageRows; y++){
            Vec3b pixleVector = image.at<Vec3b>(y,x);

            // Save {0:Red, 1:Green, 2:Blue} Color value as an int-Array
            pixels[y][x] = {(int) pixleVector[2], (int) pixleVector[1], (int) pixleVector[0]};
        }
    }

    // Creating an object of BasicTransformation and calling constructor
    BasicTransformation gray(pixels);

    // Calling member function to convert to grayscale
    vector<vector<int>> grayscalePixels = gray.grayscale();

    BasicTransformation edge(grayscalePixels);
    vector<vector<int>> edges = edge.sobelEdgeDetection(true, 70);




    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", grayscaleVectorToMat(edges));
    waitKey(0);
    return 0;
}