#include <iostream>
#include "Library.h"

int main() {
    Library library("My Library");

    Shelf shelf1("Shelf 1");
    shelf1.addBook(Book("Book 1", Author("Author 1")));
    shelf1.addBook(Book("Book 2", Author("Author 2")));

    Shelf shelf2("Shelf 2");
    shelf2.addBook(Book("Book 3", Author("Author 3")));

    Shelf shelf3("Shelf 3");
    shelf2.addBook(Book("Book 4", Author("Author 4")));

    // Adding
    library.addShelf(shelf1);
    library.addShelf(shelf2);
    library.addShelf(shelf3);

    //Replacing
    // Replace Shelf 1 with Shelf 3
    try {
        library.replaceShelf(shelf1.getName(), shelf3.getName());
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    // Deleting
    library.removeShelf(shelf3.getName());

    library.saveToFile("library.xml");

    Library loadedLibrary("Loaded Library");
    loadedLibrary.loadFromFile("library.xml");

    return 0;
}