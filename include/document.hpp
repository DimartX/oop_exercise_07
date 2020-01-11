#pragma once

#include <iostream>
#include <memory>

#include "factory.hpp"
#include "figure.hpp"

namespace bad {

struct Document {
public:

    Document(std::string& name) :
        name_(name)
    {}
    
    void Insert(std::shared_ptr<figure>& ptr);
    void Insert(std::shared_ptr<figure>& ptr, int index);
    
    void Erase(int index);
    void Erase();
    
    void Save(const string& name) const;
    void Load(const string& name);
    void Print(std::ostream& os) const;

    void Undo();
    
    void Size() {
        return buffer_.size();
    }
    
private:
    friend class InsertCommand;
    friend class DeleteCommand;
    
private:
    std::string documentName_;
    Factory factory_;
    std::vector<std::shared_ptr<Figure>> buffer_;
    std::stack<std::unique_ptr<Command>> history;    
};

}; // namespace bad
