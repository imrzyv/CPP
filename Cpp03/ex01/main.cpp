/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:02:22 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/09 17:02:23 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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

    std::cout << "ScavTrap tests: " << std::endl;
    ScavTrap s("S");
    ScavTrap t("T");

    s.setAttackDamage(3);
    t.setAttackDamage(5);

    s.attack("a random target");
    s.takeDamage(4);
    s.beRepaired(2);

    t.attack("another target");
    t.takeDamage(10);
    t.attack("a new target");
    t.beRepaired(1);

    ScavTrap v("EnergyGuy");
    v.setAttackDamage(1);
    for (int i = 0; i < 12; ++i)
        v.attack("dummy");

    std::cout << "Assign tests: " << std::endl;
    ClapTrap cpy(a);
    ClapTrap assign("Assign");
    assign = a;
    ScavTrap s1(s);
    ScavTrap s2;
    s2 = s;
    std::cout << "Done!" << std::endl;

    return 0;
}
