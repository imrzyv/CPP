/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:36:41 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/03 11:36:42 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(const int value)
{
    _rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    _rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        _rawBits = other._rawBits;
    return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const 
{
    return _rawBits >> _fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const
{
    return _rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const
{
    return _rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return _rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return _rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const
{
    return _rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return _rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _rawBits++;
    return temp;
}

Fixed& Fixed::operator--()
{
    _rawBits--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _rawBits--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
