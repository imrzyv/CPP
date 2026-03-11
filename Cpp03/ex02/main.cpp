/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:45:38 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/09 16:45:39 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "ClapTrap tests: " << std::endl;
    ClapTrap a("A");
    ClapTrap b("B");

    a.setAttackDamage(3);
    b.setAttackDamage(5);

    a.attack("a random target");
    a.takeDamage(4);
    a.beRepaired(2);

    b.attack("another target");
    b.takeDamage(10);
    b.attack("should fail");
    b.beRepaired(1);

    ClapTrap e("EnergyGuy");
    e.setAttackDamage(1);
    for (int i = 0; i < 12; ++i)
        e.attack("dummy");

    std::cout << "ScavTrap tests" << std::endl;
    ScavTrap s("S");
    s.attack("target");
    s.guardGate();

    std::cout << "FragTrap tests: " << std::endl;
    FragTrap f("F");
    f.attack("target");
    f.takeDamage(40);
    f.beRepaired(10);
    f.highFivesGuys();

    std::cout << "Assign tests: " << std::endl;
    ClapTrap cpy(a);
    ClapTrap assign("Assign");
    assign = a;

    std::cout << "Done!" << std::endl;

    return 0;
}
