#include "factory.hpp"
#include <algorithm>

namespace bad {

std::shared_ptr<Figure> Factory::FigureCreate(std::istream& is) {
    std::string figureName;
    is >> figureName;
    std::transform(figureName.begin(), figureName.end(), figureName.begin(), ::tolower);
    std::shared_ptr<Figure> figure;
    if (figureName == "triangle") {
        figure = std::shared_ptr<Figure>(new Triangle(is));
    }
    else if (figureName == "rectangle") {
        try {
            figure = std::shared_ptr<Figure>(new Rectangle(is));
        } catch (std::logic_error& e) {
            throw e;
        }
    }
    else if (figureName == "square") {
        try {
            figure =  std::shared_ptr<Figure>(new Square(is));
        } catch (std::logic_error& e) {
            throw e;
        }
    }
    else {
        throw std::logic_error("There is no such figure\n");
    }
    return figure;
}

}; // namespace bad
