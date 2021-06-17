#pragma once


template <class T> class ComplexNumber
{
public:
	// Default constructor initializes a 0 + 0i complex number
	ComplexNumber()
		: m_real(0)
		, m_imaginary(0)
	{ }

	// Assignment constructor to real + 0i complex number 
	ComplexNumber(const T& real)
		: m_real(real)
		, m_imaginary(0)
	{ }

	// Assignment constructor with both real and imaginary parts
	ComplexNumber(const T& real, const T& imaginary)
		: m_real(real)
		, m_imaginary(imaginary)
	{ }

	// Setter and getter for the real part
	void setreal(const T& real)
	{
		m_real = real;
	}
	T getreal() const
	{
		return m_real;
	}

	// Setter and getter for the imaginary part
	void setimaginary(const T& imaginary)
	{
		m_imaginary = imaginary;
	}
	T geimaginary() const
	{
		return m_imaginary;
	}

	// Print to the console shift left
	friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& complexnumber)
	{
		os << complexnumber.m_real << "+" << complexnumber.m_imaginary << "i";
		return os;
	}

	// Assisngment opperator for a complex number
	ComplexNumber& operator=(const ComplexNumber& rhs)
	{
		m_real = rhs.m_real;
		m_imaginary = rhs.m_imaginary;
		return *this;
	}

	// Assignment addition
	ComplexNumber& operator+=(const ComplexNumber& rhs)
	{
		// Add both parts respectively
		m_real += rhs.m_real;
		m_imaginary += rhs.m_imaginary;
		return *this;
	}

	// Assignment subtraction
	ComplexNumber& operator-=(const ComplexNumber& rhs)
	{
		// Subtract both parts respectively
		m_real -= rhs.m_real;
		m_imaginary -= rhs.m_imaginary;
		return *this;
	}

	// Assignment multiplication
	ComplexNumber& operator*=(const ComplexNumber& rhs)
	{
		// Multiply the 2 complex numbers
		// (x + yi) * (u + vi) = (xu + xvi + yui + yvii) = (xu - yv) + (xv + yu)i
		T real = m_real;	// make a copy of the this real part
		m_real = (m_real * rhs.m_real) - (m_imaginary * rhs.m_imaginary);
		m_imaginary = (real * rhs.m_imaginary) + (m_imaginary * rhs.m_real);
		return *this;
	}

	// Assignment division
	ComplexNumber& operator/=(const ComplexNumber& rhs)
	{
		// Multiply by the recipricol
		// TODO: Multiply by the recipricol and divide by the scalar produced by rhs*rhs.recipricol()
		return *this;
	}

	// Addition of 2 fractions
	friend ComplexNumber operator+(ComplexNumber lhs, const ComplexNumber& rhs)
	{
		// Reuse addition assignmet
		lhs += rhs;
		return lhs;

	}

	// Subtraction of 2 fractions
	friend ComplexNumber operator-(ComplexNumber lhs, const ComplexNumber& rhs)
	{
		// Reuse subtraction assignmet
		lhs -= rhs;
		return lhs;
	}

	// Multiplication of 2 fractions
	friend ComplexNumber operator*(ComplexNumber lhs, const ComplexNumber& rhs)
	{
		// Reuse multiplication assignmet
		lhs *= rhs;
		return lhs;
	}

	// Division of 2 fractions
	friend ComplexNumber operator/(ComplexNumber lhs, const ComplexNumber& rhs)
	{
		// Reuse division assignmet
		lhs /= rhs;
		return lhs;
	}
	inline bool operator==(const ComplexNumber& rhs) const { return  ((m_real == rhs.m_real) && (m_imaginary == rhs.m_imaginary)); }
	inline bool operator!=(const ComplexNumber& rhs) const { return !(*this == rhs); }

	inline bool operator< (const ComplexNumber& rhs) const { /* TODO: find length from origin*/  return false; }
	inline bool operator> (const ComplexNumber& rhs) const { return rhs < *this; }
	inline bool operator<=(const ComplexNumber& rhs) const { return !(*this > rhs); }
	inline bool operator>=(const ComplexNumber& rhs) const { return !(*this < rhs); }

private:
	T m_real;
	T m_imaginary;
};