#pragma once

#include <iostream>

#define EPSILON 0.000001

namespace OSMathLib
{

	// Class to handle fractions and related functions
	template <class T> class fraction
	{
	public:
		// Default constructor initializes a 0/1 fraction
		fraction()
			: m_numerator(0)
			, m_denominator(1)
		{ }

		// Assignment constructor
		fraction(const T & numerator)
			: m_numerator(numerator)
			, m_denominator(1)
		{ }

		// Assignment constructor
		fraction(const T & numerator, const T & denominator)
			: m_numerator(numerator)
			, m_denominator(denominator)
		{ }

		// Setter and getter for the numerator
		void setnumerator(const T& numerator)
		{
			m_numerator = numerator;
		}
		T& getnumerator() const
		{
			return m_numerator;
		}

		// Setter and getter for the denominator
		void setdenominator(const T& denominator)
		{
			m_denominator = denominator;
		}
		T& getdenominator() const
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

		// Assisngment opperator
		fraction& operator=(const fraction& rhs)
		{
			m_numerator = rhs.m_numerator;
			m_denominator = rhs.m_denominator;
			return *this;
		}

	private:
		T m_numerator;
		T m_denominator;
	};
}