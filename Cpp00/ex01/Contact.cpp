#include "Contact.hpp"
#include <iostream>
#include <iomanip>//?

void    Contact::set_contact(std::string fn,
                            std::string ln,
                            std::string nn,
                            std::string pn,
                            std::string ds)
{
    first_name = fn;
    last_name = ln;
    nickname = nn;
    phone_nb = pn;
    darkest_secret = ds;
}

void    Contact::display_full() const
{
    std::cout << "First name: " << first_name << std::endl;
    std::cout << "Last name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phone_nb << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

std::string format_field(const std::string &str) {

    if (str.length() > 10)
        return (str.substr(0,9) + ".");
    return (std::string(10 - str.length(), ' ') + str);
}

void    Contact::display_short(int index) const {

    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << format_field(first_name);
    std::cout << "|" << format_field(last_name);
    std::cout << "|" << format_field(nickname);
    std::cout << "|" << std::endl;
}