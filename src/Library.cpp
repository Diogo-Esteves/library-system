#include "Library.h"
#include <stdexcept>

Library::Library(const std::string& name) : name(name) {}

void Library::addShelf(const Shelf& shelf) {
    shelves.push_back(shelf);
}

void Library::removeShelf(const std::string& shelfName) {
    shelves.erase(std::remove_if(shelves.begin(), shelves.end(),
        [&shelfName](const Shelf& shelf) { return shelf.getName() == shelfName; }), shelves.end());
}

void Library::replaceShelf(const std::string& shelfNameNew, const std::string& shelfNameOld) {
    auto it = std::find_if(shelves.begin(), shelves.end(),
        [&shelfNameOld](const Shelf& shelf) { return shelf.getName() == shelfNameOld; });

    if (it != shelves.end()) {
        *it = Shelf(shelfNameNew);
    }
    else {
        throw std::runtime_error("Shelf not found: " + shelfNameOld);
    }
}

void Library::saveToFile(const std::string& filename) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement* root = doc.NewElement("Library");
    root->SetAttribute("name", name.c_str());
    doc.InsertFirstChild(root);

    for (const auto& shelf : shelves) {
        tinyxml2::XMLElement* shelfElement = doc.NewElement("Shelf");
        shelfElement->SetAttribute("name", shelf.getName().c_str());
        root->InsertEndChild(shelfElement);

        for (const auto& book : shelf.getBooks()) {
            tinyxml2::XMLElement* bookElement = doc.NewElement("Book");
            bookElement->SetAttribute("title", book.getTitle().c_str());
            bookElement->SetAttribute("author", book.getAuthor().getName().c_str());
            shelfElement->InsertEndChild(bookElement);
        }
    }

    doc.SaveFile(filename.c_str());
}

void Library::loadFromFile(const std::string& filename) {
    tinyxml2::XMLDocument doc;
    if (doc.LoadFile(filename.c_str()) != tinyxml2::XML_SUCCESS) {
        throw std::runtime_error("Failed to load file");
    }

    tinyxml2::XMLElement* root = doc.FirstChildElement("Library");
    if (!root) {
        throw std::runtime_error("Invalid file format");
    }

    name = root->Attribute("name");

    for (tinyxml2::XMLElement* shelfElement = root->FirstChildElement("Shelf"); shelfElement; shelfElement = shelfElement->NextSiblingElement("Shelf")) {
        Shelf shelf(shelfElement->Attribute("name"));

        for (tinyxml2::XMLElement* bookElement = shelfElement->FirstChildElement("Book"); bookElement; bookElement = bookElement->NextSiblingElement("Book")) {
            Book book(bookElement->Attribute("title"), Author(bookElement->Attribute("author")));
            shelf.addBook(book);
        }

        addShelf(shelf);
    }
}