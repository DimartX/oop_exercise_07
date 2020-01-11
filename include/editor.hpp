#pragma once

#include <iostream>
#include <memory>
#include <stack>

#include "factory.hpp"
#include "command.hpp"
#include "document.hpp"

namespace bad {

struct Editor {
public:
    Editor() :
        document(nullptr)
    {};

    void CreateDocument(const std::string& name);
    void LoadDocument(const std::string& name);
    void SaveDocument(const std::string& name);
    void PrintDocument(std::ostream& os) const;
    
    void InsertFigure(std::shared_ptr<figure>& newFigure);
    void DeleteFigure(int index);
    
    void Undo();

    bool DocumentExists();
    
    ~Editor() = default;
private:
    std::unique_ptr<Document> document;
};

}; // namespace bad
