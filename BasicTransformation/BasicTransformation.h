#ifndef BASICTRANSFORMATION_H
#define BASICTRANSFORMATION_H

#include <vector>
#include <array>

class BasicTransformation {
private:
    std::vector<std::vector<std::array<int, 3>>> pixels;

public:
    BasicTransformation(std::vector<std::vector<std::array<int, 3>>> pixels);
    std::vector<std::vector<int>> grayscale();
};

#endif