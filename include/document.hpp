#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <memory>

namespace bad {
struct Document;
}

#include "command.hpp"
#include "factory.hpp"
#include "figure.hpp"

namespace bad {

struct Document {
public:

    Document(const std::string& name) :
        documentName_(name)
    {}
    
    void Insert(std::shared_ptr<Figure>& ptr);
    void Insert(std::shared_ptr<Figure>& ptr, int index);
    
    void Erase(int index);
    void Erase();
    
    void Save(const std::string& name);
    void Load(const std::string& name);
    void Print(std::ostream& os) const;

    void Undo();
    
    int Size() {
        return buffer_.size();
    }
    
private:
    std::string documentName_;
    Factory factory_;
    std::vector<std::shared_ptr<Figure>> buffer_;
    std::stack<std::unique_ptr<Command>> history_;    
};

}; // namespace bad
