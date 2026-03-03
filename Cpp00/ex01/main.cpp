#include <iostream>
#include "PhoneBook.hpp"

int main() {

    PhoneBook   phonebook;
    std::string command;

    while(true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phonebook.add_contacts();
        else if (command == "SEARCH")
            phonebook.search_contacts();
        else if (command == "EXIT")
            break ;
    }
    return (0);
}