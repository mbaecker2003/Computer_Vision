#ifndef BASICTRANSFORMATION_H
#define BASICTRANSFORMATION_H

#include <vector>
#include <array>

class BasicTransformation {
private:
    std::vector<std::vector<std::array<int, 3>>> pixels;
    std::vector<std::vector<int>> grayPixels;

public:
    BasicTransformation(const std::vector<std::vector<std::array<int, 3>>>& pixels) {
        this->pixels = pixels;
    }

    BasicTransformation(const std::vector<std::vector<int>>& grayPixels) {
        this->grayPixels = grayPixels;
    }
    std::vector<std::vector<int>> grayscale();
    std::vector<std::vector<int>> sobelEdgeDetection(const bool binary, const int threashold);
};

#endif