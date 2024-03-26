#ifndef HOUGHTRANSFORMATION_H
#define HOUGHTRANSFORMATION_H

#include <vector>
#include <array>

class HoughTransformation {
private:
    std::vector<std::vector<std::array<int, 3>>> pixels;

public:
    HoughTransformation(std::vector<std::vector<std::array<int, 3>>> pixels);
    std::vector<std::vector<std::array<int, 3>>> normal();
};

#endif