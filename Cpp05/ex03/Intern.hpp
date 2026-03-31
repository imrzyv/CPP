/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:00:23 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/30 19:00:25 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class Intern
{
private:
    AForm*  makeShrubbery(const std::string& target) const;
    AForm*  makeRobotomy(const std::string& target) const;
    AForm*  makePresidential(const std::string& target) const;
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
    AForm*  makeForm(const std::string& formName, const std::string& target) const;
};

#endif
