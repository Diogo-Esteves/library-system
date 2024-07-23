#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Shelf.h"
#include "tinyxml2.h"

class Library {
public:
    Library(const std::string& name);
    void addShelf(const Shelf& shelf);
    void removeShelf(const std::string& shelfName);
    void replaceShelf(const std::string& shelfNameNew, const std::string& shelfNameOld);
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);

private:
    std::string name;
    std::vector<Shelf> shelves;
};

#endif // LIBRARY_H