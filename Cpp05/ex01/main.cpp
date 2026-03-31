/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:27:47 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/30 18:27:48 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()//idk revisit
{
    std::cout << "----- Valid objects -----" << std::endl;
    try
    {
        Bureaucrat a("Alice", 50);
        Form f("TaxForm", 60, 30);

        std::cout << a << std::endl;
        std::cout << f << std::endl;

        a.signForm(f);

        std::cout << f << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "----- Bureaucrat too weak -----" << std::endl;
    try
    {
        Bureaucrat b("Bob", 100);
        Form g("SecretForm", 50, 20);

        std::cout << b << std::endl;
        std::cout << g << std::endl;

        b.signForm(g);

        std::cout << g << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "----- Invalid form grades -----" << std::endl;
    try
    {
        Form bad1("BadHigh", 0, 10);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Form bad2("BadLow", 10, 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
