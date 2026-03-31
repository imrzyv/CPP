/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:10:36 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/27 15:10:37 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()//idk revisit
{
    std::cout << "----- Valid bureaucrats -----" << std::endl;
    try
    {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;

        a.decrementGrade();
        std::cout << a << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;//idk
    }

    std::cout << std::endl;
    std::cout << "----- Grade too high in constructor -----" << std::endl;
    try
    {
        Bureaucrat b("Bob", 0);
        std::cout << b << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "----- Grade too low in constructor -----" << std::endl;
    try
    {
        Bureaucrat c("Charlie", 151);
        std::cout << c << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "----- Increment too high -----" << std::endl;
    try
    {
        Bureaucrat d("David", 1);
        std::cout << d << std::endl;
        d.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "----- Decrement too low -----" << std::endl;
    try
    {
        Bureaucrat e("Eve", 150);
        std::cout << e << std::endl;
        e.decrementGrade();
    }
    catch (std::exception& e2)
    {
        std::cout << "Exception: " << e2.what() << std::endl;
    }

    return 0;
}
