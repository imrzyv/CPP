#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

private:

    Contact contacts[8];
    int     count;
    int     oldest;

public:

    PhoneBook();
    void    add_contacts();
    void    search_contacts() const;
} ;

#endif