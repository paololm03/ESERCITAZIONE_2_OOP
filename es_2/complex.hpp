#pragma once

template<typename I> requires std::integral<I>
class complex
{
    /* Private members */
    I real_n, im_n;
	
public:
    /* Default constructor */
    complex()
        : real_n(0), im_n(0)
    {}
    
    explicit complex(I n)
        : real_n(n), im_n(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }
    
    /* User-defined constructor. Takes two parameters, numerator and
     * denominator */
    complex(I n, I m)
        : real_n(n), im_n(m)
    {}
    
    /* Return the numerator. The `const` means that this function does
     * not modify the instance on which it is called.
     */
    I real(void) const {
        return real_n;
    }
    
    /* Return the denominator. The `const` means that this function does
     * not modify the instance on which it is called.
     */
    I imag(void) const {
        return im_n;
    }
    
    /*Return the complex conjugate*/
    complex<I> conj(void) const {
        return complex(real_n, -im_n);
    }


    /* Define the += operator between complex numbers. When you do
     * 
     *  z1 += z2
     *
     * this function gets called. Notice that this function
     * takes only one parameter: we take the instance `other`
     * and we add it to the instance on which += is called.
     */
    complex& operator+=(const complex& other) {
        I a = real_n;
        I b = im_n;
        I c = other.real_n;
        I d = other.im_n;
        real_n = a + c;
        im_n = b + d;
        return *this;
	}
	
	/* Define operator+ in terms of operator +=. Notice that + does
	 * not modify the instance on which is called, therefore is marked
	 * const (the second const). */
	complex operator+(const complex& other) const {
        complex ret = *this;
        ret += other;
        return ret;
    }

    /* Define the += operator between a complex on the left
     * and an I on the right. When you do
     * 
     *  r1 += i
     *
     * this function gets called.
     */
    complex& operator+=(const I& other) {
        real_n += other;
        return *this;
	}
	
	/* Define operator+ in terms of operator +=. Notice that + does
	 * not modify the instance on which is called, therefore is marked
	 * const (the second const). */
	complex operator+(const I& other) const {
        complex ret = *this;
        ret += other;
        return ret;
    }
    
    /* This is the UNARY minus. It computes the opposite: z2 = -z1; Notice
     * that the UNARY minus does not modify the instance on which is called,
     * therefore it is marked const.
     */
    complex operator-() const {
        return complex(-real_n, -im_n);
    }

    /* Define the *= operator between complex numbers. When you do
     * 
     *  z1 *= z2
     *
     * this function gets called.
     */
    complex& operator*=(const complex& other) {
        I a = real_n;
        I b = im_n;
        I c = other.real_n;
        I d = other.im_n;
        real_n = a*c - b*d;
        im_n = b*c + a*d;
        return *this;
	}

    /* Define the *= operator between a complex on the left
     * and an I on the right. When you do
     * 
     *  z1 *= r
     *
     * this function gets called.
     */
    complex& operator*=(const I& other) {
        real_n *= other;
        im_n *= other;
        return *this;
	}

    complex operator*(const I& other) const {
        complex ret = *this;
        ret *= other;
        return ret;
    }

    /* Define operator* in terms of operator *=.*/
	complex operator*(const complex& other) const {
        complex ret = *this;
        ret *= other;
        return ret;
    }
};

/* This operator is defined outside the complex class and is needed
 * to compute the sum of an I on the left and a complex<I> on the
 * right. */
template<typename I>
complex<I>
operator+(const I& i, const complex<I>& z)
{
    return z + i;
}

/* This operator is defined outside the complex class and is needed
 * to compute the product of an I on the left and a complex<I> on the
 * right. */
 template<typename I>
 complex<I>
 operator*(const I& i, const complex<I>& z)
 {
     return z * i;
 }

 /* Free function to compute the conjugate of a complex */
template<typename I>
complex<I> conj(const complex<I>& z) {
    return z.conj();
}

/* Overload of <<, to make the complex printable. */
template<typename I>
std::ostream&
operator<<(std::ostream& os, const complex<I>& z) {
    if (z.imag() > 0)
        os << z.real() << "+" << z.imag() << "i";
    else if (z.imag() < 0)
        os << z.real() << "-" << -z.imag() << "i";
    else
        os << z.real();
    return os;
}
