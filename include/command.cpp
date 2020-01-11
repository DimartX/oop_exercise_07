#include "command.hpp"

void InsertCommand::Undo() {
    document_->Erase();
}

void DeleteCommand::Undo() {
    document_->Insert(figure_, index_);
}




