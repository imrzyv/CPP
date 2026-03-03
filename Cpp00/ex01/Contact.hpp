#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {

private:

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_nb;
    std::string darkest_secret;

public:

    void    set_contact(std::string fn,
                        std::string ln,
                        std::string nn,
                        std::string pn,
                        std::string ds);
    void    display_full() const;
    void    display_short(int index) const;
} ;

#endif 