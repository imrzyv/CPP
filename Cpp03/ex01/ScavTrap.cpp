/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:02:09 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/09 17:02:11 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Default constructor " << _name << " called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Constructor " << _name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor " << _name << " called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap Copy assigment operator " << _name << " called" << std::endl;
    if (this != &other)
        ClapTrap::operator =(other);
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor ScavTrap " << _name << " called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " cannot attack! No hit points left" << std::endl;
        return ;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " cannot attack! No energy points left" << std::endl;
        return ;
    }
    _energyPoints -= 1;
    std::cout << "ScavTrap " << _name <<  " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
