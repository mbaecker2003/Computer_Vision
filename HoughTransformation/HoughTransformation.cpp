#include "HoughTransformation.h"
#include <iostream>

//To get the definition of pixels
#include "../BasicTransformation/BasicTransformation.h"

using namespace std;

HoughTransformation::HoughTransformation(vector<vector<array<int, 3>>> pixels) {
    //Initialize variables
    this->pixels = pixels;
}

vector<vector<array<int, 3>>> HoughTransformation::normal() {
    // Vector to store gray-information
    return pixels;
}
