#include <iostream>
#include <opencv2/opencv.hpp>
#include<vector>
#include <array>


using namespace cv;
using namespace std;

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
    vector<vector<array<int, 3>>> pixles(imageRows, vector<array<int, 3>>(imageColumns));

    // Get RGB-values of the image
    for(int x=0; x<imageColumns; x++){
        for(int y=0; y<imageRows; y++){
            Vec3d pixleVector = image.at<Vec3d>(y,x);

            // Save {0:Red, 1:Green, 2:Blue} Color value as an int-Array
            pixles[x][y] = {(int) pixleVector[2], (int) pixleVector[1], (int) pixleVector[0]};
        }
    }




    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}