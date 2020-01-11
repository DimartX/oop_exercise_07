#include <iostream>

#include "editor.hpp"
#include "factory.hpp"

void help() {
    std::cout << "create <document_name>\n"
                 "add <figure_name> <points>\n"
                 "remove <figure_index>\n"
                 "undo\n"
                 "load <filename>\n"
                 "save <filename>\n"
                 "print\n"
                 "exit\n";
}

void create(bad::Editor& editor) {
    std::string name;
    std::cin >> name;
    try {
        editor.CreateDocument(name);
        std::cout << "Document created" << std::endl;
    } catch (...) {
        std::cout << "Error: Creating document";
    }
}

void add(bad::Editor& editor, bad::Factory& factory) {
    try {
        std::shared_ptr<bad::Figure> newFigure = factory.FigureCreate(std::cin);
        editor.InsertFigure(newFigure);
        std::cout << "Ok" << std::endl;
    } catch (std::logic_error& e) {
        std::cout << "Error: " << e.what();
    }
}

void remove(bad::Editor& editor) {
    int index;
    std::cin >> index;
    try {
        editor.DeleteFigure(index);
        std::cout << "Ok" << std::endl;
    } catch (std::logic_error& e) {
        std::cout << "Error: " << e.what();
    }
}

void undo(bad::Editor& editor) {
    try {
        editor.Undo();
        std::cout << "Ok" << std::endl;
    } catch (std::logic_error& e) {
        std::cout << "Error: " << e.what();
    }
}

void load(bad::Editor& editor) {
    std::string name;
    std::cin >> name;
    try {
        editor.LoadDocument(name);
        std::cout << "Document " << name << " loaded" << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << "Error: " << e.what();
    }
}

void save(bad::Editor& editor) {
    std::string name;
    std::cin >> name;
    try {
        editor.SaveDocument(name);
        std::cout << "Document " << name << " saved" << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << "Error: " << e.what();
    }
}

void print(bad::Editor& editor) {
    editor.PrintDocument(std::cout);
}

int main() {
    bad::Editor editor;
    bad::Factory factory;

    std::cout << "Enter help to find out how it works" << std::endl;
    
    while (std::cin) {
        std::string command;
        std::cin >> command;

        if (command == "create") {
            create(editor);
        }
        else if (command == "add") {
            add(editor, factory);
        }
        else if (command == "remove") {
            remove(editor);
        }
        else if (command == "undo") {
            undo(editor);
        }
        else if (command == "load") {
            load(editor);
        }
        else if (command == "save") {
            save(editor);
        }
        else if (command == "print") {
            print(editor);
        }
        else if (command == "help") {
            help();
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "Wrong command" << std::endl;
        }
    }
    return 0;
}
