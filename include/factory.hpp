#pragma once

#include <iostream>
#include <memory>

#include "figure.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "square.hpp"

namespace bad {

class Factory {
public:
    std::shared_ptr<Figure> FigureCreate(std::istream& is);
};

}; // namespace bad
