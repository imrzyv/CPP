/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:02:51 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/09 17:02:52 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
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

    ClapTrap cpy(a);
    ClapTrap assign("Assign");
    assign = a;

    return 0;
}
