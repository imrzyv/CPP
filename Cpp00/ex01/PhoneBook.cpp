#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : count(0), oldest(0) {}

std::string get_input(const std::string &prompt) {

    std::string input;
    while (input.empty())
    {
        std::cout << prompt;
        std::getline(std::cin, input);
    }
    return (input);
}

void    PhoneBook::add_contacts() {

    Contact c;

    c.set_contact(get_input("First name: "), get_input("Last name: "), get_input("Nickname: "),
                            get_input("Phone number: "), get_input("darkest secret: "));
    contacts[oldest] = c;
    oldest = (oldest + 1) % 8;
    if (count < 8)
        count++;
}

void    PhoneBook::search_contacts() const {

    if (count == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return ;
    }
    std::cout << "|    Index |First Name| Last Name| Nickname |" << std::endl;
    for (int i = 0; i < count; i++)
        contacts[i].display_short(i);
    std::cout << "Index: ";
    int idx;
    std::cin >> idx;
    std::cin.ignore();
    if (idx < 0 || idx >= count)
    {
        std::cout << "Invalid index." << std::endl;
        return ;
    }
    contacts[idx].display_full();
}