/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:44:52 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/09 16:44:54 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Default constructor " << _name << " called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Constructor " << _name << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor " << _name << " called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap Copy assigment operator " << _name << " called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator = (other);
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor FragTrap " << _name << " called" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " requests a high-five!" << std::endl;
}

void    FragTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << "FragTrap " << _name << " cannot attack! No hit points left" << std::endl;
        return ;
    }
    if (_energyPoints == 0)
    {
        std::cout << "FragTrap " << _name << " cannot attack! No energy points left" << std::endl;
        return ;
    }
    _energyPoints -= 1;
    std::cout << "FragTrap " << _name <<  " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
