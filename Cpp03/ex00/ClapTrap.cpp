/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:03:16 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/09 17:03:17 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assigment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor " << _name << " called" << std::endl;
}

const std::string   ClapTrap::getName() const
{
    std::cout << "getName member function called" << std::endl;
    return (_name);
}

unsigned int    ClapTrap::getHitPoints(void)const
{
    std::cout << "getHitPoints member function called" << std::endl;
    return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void)const
{
    std::cout << "getEnergyPoints member function called" << std::endl;
    return (_energyPoints);
}
unsigned int ClapTrap::getAttackDamage(void)const
{
    std::cout << "getAttackDamage member function called" << std::endl;
    return (_attackDamage);
}

void    ClapTrap::setAttackDamage(unsigned int dmg)
{
    _attackDamage = dmg;
}

void    ClapTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot attack! No hit points left" << std::endl;
        return ;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot attack! No energy points left" << std::endl;
        return ;
    }
    _energyPoints -= 1;
    std::cout << "ClapTrap " << _name <<  " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
        std::cout << "ClapTrap " << _name << " is already destryed! No more hit points!" << std::endl;
    else if (amount >= _hitPoints)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " is destroyed! No more hit points!" << std::endl;
    }
    else if (amount < _hitPoints)
    {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damage points! Current hit points count: " << _hitPoints << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot repair itself! No hit points left" << std::endl;
        return ;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot repair itself! No energy points left" << std::endl;
        return ;
    }
    _energyPoints -=1;
    std::cout << "ClapTrap " << _name << " repairs itself and regains " << amount << " hit points!" << std::endl;
    _hitPoints += amount;
    std::cout << "Current hit points count: " << _hitPoints << "." << std::endl;
}
