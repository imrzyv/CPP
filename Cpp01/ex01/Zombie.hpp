#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;

public:
    //Zombie();
    Zombie(const std::string& name = "");
    ~Zombie();
    void    setName(const std::string& name);
    void    announce(void) const;
    
} ;

Zombie* zombieHorde(int N, const std::string& name);

#endif