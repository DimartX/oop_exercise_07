#include "editor.hpp"

namespace bad {

void Editor::CreateDocument(const std::string& name) {
    document_ = std::unique_ptr<Document>( new Document(name));
}

void Editor::LoadDocument(const std::string& name) {
    try {
        document_ = std::unique_ptr<Document>( new Document(name));
        document_->Load(name);
    }
    catch (std::logic_error& e) {
        throw e; 
    }
}

void Editor::SaveDocument(const std::string& name) {
    if (document_ == nullptr) {
        throw std::logic_error("There is no document");
        return;
    }
    document_->Save(name);
}

void Editor::PrintDocument(std::ostream& os) const { 
    if (document_ == nullptr) {
        throw std::logic_error("There is no document");
        return;
    }
    document_->Print(os);
}

void Editor::InsertFigure(std::shared_ptr<Figure>& newFigure) {
    if (document_ == nullptr) {
        throw std::logic_error("There is no document");
        return;
    }
    document_->Insert(newFigure);
}

void Editor::DeleteFigure(int index) {
    if (document_ == nullptr) {
        throw std::logic_error("There is no document");
        return;
    }
    if (index > document_->Size() || index < 0) {
        throw std::logic_error("Out of bound");
    }
    document_->Erase(index);
}
    
void Editor::Undo() {
    try {
        document_->Undo();
    } catch(std::logic_error& e) {
        throw e;
    }
}

bool Editor::DocumentExists() {
    return document_ != nullptr;
}

}; // namespace bad
