#pragma once

#include <iostream>
#include <type_traits>


#define EPSILON 0.000001

	// Class to handle fractions and related functions
template <class T>class fraction
{
public:
	// Default constructor initializes a 0/1 fraction
	fraction()
		: m_numerator(0)
		, m_denominator(1)
	{ }

	// Assignment constructor
	fraction(const T& numerator)
		: m_numerator(numerator)
		, m_denominator(1)
	{ }

	// Assignment constructor
	fraction(const T& numerator, const T& denominator)
		: m_numerator(numerator)
		, m_denominator(denominator)
	{ }

	// Setter and getter for the numerator
	void setnumerator(const T& numerator)
	{
		m_numerator = numerator;
	}
	T getnumerator() const
	{
		return m_numerator;
	}

	// Setter and getter for the denominator
	void setdenominator(const T& denominator)
	{
		m_denominator = denominator;
	}
	T getdenominator() const
	{
		return m_denominator;
	}

	// Print to the console shift left
	friend std::ostream& operator<<(std::ostream& os, const fraction& frac)
	{
		os << frac.m_numerator << "/" << frac.m_denominator;
		// Check for division by zero
		if (frac.m_denominator != 0)
			os << " = " << ((float)frac.m_numerator / (float)frac.m_denominator);
		return os;
	}

	// Assisngment opperator for fractions
	fraction& operator=(const fraction& rhs)
	{
		m_numerator = rhs.m_numerator;
		m_denominator = rhs.m_denominator;
		return *this;
	}

	// Assignment addition
	fraction& operator+=(const fraction& rhs)
	{
		// Add the 2 fractions based off the LCD
		int lcm = LCM(m_denominator, rhs.m_denominator);
		m_numerator = (m_numerator * (lcm / m_denominator)) + (rhs.m_numerator * (lcm / rhs.m_denominator));
		m_denominator = lcm;
		return *this;
	}

	// Assignment subtraction
	fraction& operator-=(const fraction& rhs)
	{
		// Subtracrt the 2 fractions based off the LCD
		int lcm = LCM(m_denominator, rhs.m_denominator);
		m_numerator = (m_numerator * (lcm / m_denominator)) - (rhs.m_numerator * (lcm / rhs.m_denominator));
		m_denominator = lcm;
		return *this;
	}

	// Assignment multiplication
	fraction& operator*=(const fraction& rhs)
	{
		// Multiply the 2 fractions
		m_numerator = m_numerator * rhs.m_numerator;
		m_denominator = m_denominator * rhs.m_denominator;
		return *this;
	}

	// Assignment division
	fraction& operator/=(const fraction& rhs)
	{
		// Multiply by the recipricol
		m_numerator = m_numerator * rhs.m_denominator;
		m_denominator = m_denominator * rhs.m_numerator;
		return *this;
	}

	// Addition of 2 fractions
	friend fraction operator+(fraction lhs, const fraction& rhs)
	{
		// Reuse addition assignmet
		lhs += rhs;
		return lhs;

	}

	// Subtraction of 2 fractions
	friend fraction operator-(fraction lhs, const fraction& rhs)
	{
		// Reuse subtraction assignmet
		lhs -= rhs;
		return lhs;
	}

	// Multiplication of 2 fractions
	friend fraction operator*(fraction lhs, const fraction& rhs)
	{
		// Reuse multiplication assignmet
		lhs *= rhs;
		return lhs;
	}

	// Division of 2 fractions
	friend fraction operator/(fraction lhs, const fraction& rhs)
	{
		// Reuse division assignmet
		lhs /= rhs;
		return lhs;
	}
	inline bool operator==(const fraction& rhs) const { return  ((m_numerator == rhs.m_numerator) && (m_denominator == rhs.m_denominator));}
	inline bool operator!=(const fraction& rhs) const { return !(*this == rhs); }

	inline bool operator< (const fraction& rhs) const { return (resolve() < rhs.resolve()); }
	inline bool operator> (const fraction& rhs) const { return rhs < *this; }
	inline bool operator<=(const fraction& rhs) const { return !(*this > rhs); }
	inline bool operator>=(const fraction& rhs) const { return !(*this < rhs); }

	void reduce()
	{
		// Reduce the fraction by its GCD 
		T gcd = GCM(m_numerator, m_denominator);
		m_numerator /= gcd;
		m_denominator /= gcd;
	}

	T& greatestcommonmultiple(const fraction& a, const fraction& b)
	{
		return GCM(a.m_denominator, b.m_denominator);
	}

	T& lowestcommonmultiple(const fraction& a, const fraction& b)
	{
		return GCM(a.m_denominator, b.m_denominator);
	}

private:
	T m_numerator;
	T m_denominator;

	T GCM(const T& a, const T& b)
	{
		// Everything divides 0  
		if (a == 0)
			return b;
		if (b == 0)
			return a;

		// base case 
		if (a == b)
			return a;

		// a is greater 
		if (a > b)
			return GCM(a - b, b);
		return GCM(a, b - a);
	}
	T LCM(const T& a, const T& b)
	{
		return (a * b) / GCM(a, b);
	}

	float resolve() const
	{
		return((float)m_numerator / (float)m_denominator);
	}

};