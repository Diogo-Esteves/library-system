#include "Book.h"

Book::Book(const std::string& title, const Author& author) : title(title), author(author) {}

std::string Book::getTitle() const {
    return title;
}

Author Book::getAuthor() const {
    return author;
}