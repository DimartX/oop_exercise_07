#pragma once

#include <iostream>
#include <memory>

#include "document.hpp"

namespace bad {

struct Editor {
public:
    Editor() :
        document_(nullptr)
    {};

    void CreateDocument(const std::string& name);
    void LoadDocument(const std::string& name);
    void SaveDocument(const std::string& name);
    void PrintDocument(std::ostream& os) const;
    
    void InsertFigure(std::shared_ptr<Figure>& newFigure);
    void DeleteFigure(int index);
    
    void Undo();

    bool DocumentExists();
    
    ~Editor() = default;
private:
    std::unique_ptr<Document> document_;
};

}; // namespace bad
