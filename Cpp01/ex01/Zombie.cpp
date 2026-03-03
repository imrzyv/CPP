#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : name(name)
{
}

Zombie::~Zombie(){
    std::cout << name << " destroyed." << std::endl;
}

void Zombie::setName(const std::string& name){
    this->name = name;
}

void Zombie::announce(void) const{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}