#include "Polynomial.hpp"

Polynomial::Polynomial() : degree(1), coefs(new double[1]) {
	coefs[0] = 0.0;
}


Polynomial::Polynomial(int number, double coefficients[]) :
	degree(number), coefs(new double[number]) {
	for (int i = 0; i < degree; i++) {
		coefs[i] = coefficients[i];
	}
}


Polynomial::Polynomial(const Polynomial & pol) :
	degree(pol.degree), coefs(new double[pol.degree]) {
	for (int i = 0; i < degree; i++) {
		coefs[i] = pol.coefs[i];
	}
}


Polynomial::Polynomial(double const_term) : degree(1), coefs(new double[1]) {
	coefs[0] = const_term;
}


Polynomial::~Polynomial()
{
    delete[] coefs;
}


Polynomial & Polynomial::operator=(const Polynomial & pol)
{
    if(this==&pol)
    {
        return *this;
    }
    else
    {
        delete[] coefs;
        coefs=new double [pol.degree];
        degree=pol.degree;
        for(int i=0;i<degree;i++)
        {
            coefs[i]=pol.coefs[i];
        }
    }
    return *this;
}


Polynomial & Polynomial::operator+=(const Polynomial & pol)
{
    int newSize=0;
    if(degree>pol.degree)
         newSize=degree;

        else{
                newSize=pol.degree;
        }
    double *newCoef=new double [newSize];
    for(int i=0;i<newSize;i++)
    {
        newCoef[i]=0;
    }
    for(int i=0;i<newSize;i++)
    {
        newCoef[i]+=pol.coefs[i];
    }
    for(int i=0;i<newSize;i++)
    {
        newCoef[i]+=coefs[i];
    }
    delete[] coefs;
    coefs=newCoef;
    degree=newSize;
    return *this;
}


Polynomial & Polynomial::operator+=(double x)
{
    for(int i=0;i<degree;i++)
    {
        if(i==0){coefs[i]+=x;}
    }
    return *this;
}


Polynomial  & Polynomial::operator*=(const Polynomial & pol)
{
	int newSize = pol.degree + degree - 1;
	double *newCoef = new double[newSize];

	for (int i = 0; i < newSize; i++)
		newCoef[i] = 0;

	for (int i = 0; i < degree; i++)
	{
		for (int j = 0; j < pol.degree; j++)

			newCoef[i + j] += coefs[i] * pol.coefs[j];
	}

		delete[] coefs;
		coefs = newCoef;
		degree = newSize;
		return *this;
}


Polynomial & Polynomial::operator*=(double x)
{
    for(int i=0;i<degree;i++)
    {
        coefs[i]*=x;
    }
    return *this;
}


Polynomial operator+(const Polynomial & left, const Polynomial & right)
{
    Polynomial answer(left);
    answer+=right;
    return answer;
}


Polynomial operator*(const Polynomial & pol, double x)
{
    Polynomial answer(pol);
    answer*=x;
    return answer;
}


Polynomial operator+(const Polynomial & left, double x)
{
    Polynomial answer(left);
    answer+=x;
    return answer;
}


Polynomial operator*(const Polynomial & left, const Polynomial & right)
{
    Polynomial answer(left);
    answer*=right;
    return answer;
}


Polynomial operator*(double x, const Polynomial & right)
{
    Polynomial answer(right);
    answer*=x;
    return answer;
}


Polynomial operator+(double x, const Polynomial & right)
{
    Polynomial answer(right);
    answer+=x;
    return answer;
}


Polynomial & Polynomial::operator+()
{
    return *this;
}


Polynomial & Polynomial::operator-()
{
    for(int i=0;i<degree;i++)
    {
        coefs[i]*=-1;
    }
    return *this;
}


double & Polynomial::operator[](int x)
{
    for(int i=0;i<degree;i++)
    {
        if(coefs[i]==x)
            return coefs[i];
    }
}


bool operator==(const Polynomial & left, const Polynomial & right)
{
    if(left.degree!=right.degree)
        return false;
    for(int i=0;i<left.degree;i++)
    {
        if(left.coefs[i]!=right.coefs[i])
        {
            return false;
        }
    }
    return true;
}


bool operator==(double left, const Polynomial & right)
{
    if(right.degree!=1)
        return false;
    for(int i=0;i<right.degree;i++)
    {
        if(right.coefs[i]!=left)
        {
            return false;
        }
    }
    return true;
}


bool operator==(const Polynomial & left, double x)
{

    if(left.degree!=1)
        return false;
    for(int i=0;i<left.degree;i++)
    {
        if(left.coefs[i]!=x)
        {
            return false;
        }
    }
    return true;
}


bool operator!=(const Polynomial & left, const Polynomial & right)
{
    if(left.degree!=right.degree)
        return true;
    for(int i=0;i<left.degree;i++)
    {
        if(left.coefs[i]!=right.coefs[i])
        {
            return true;
        }
    }
    return false;
}


bool operator!=(double left, const Polynomial & right)
{

    if(right.degree!=1)
        return true;
    for(int i=0;i<right.degree;i++)
    {
        if(right.coefs[i]!=left)
        {
            return true;
        }
    }
    return false;

}


bool operator!=(const Polynomial & left, double right)
{

    if(left.degree!=1)
        return true;
    for(int i=0;i<left.degree;i++)
    {
        if(left.coefs[i]!=right)
        {
            return true;
        }
    }
    return false;
}



std::istream &operator>>(std::istream &is, Polynomial &right)
{
    std::cout<<"Enter the degree of your polynomial : ";
    is>>right.degree;
        delete [] right.coefs;
    right.coefs=new double [right.degree];
    for(int i=right.degree-1;i>=0;i--)
    {
        std::cout<<"Enter the coefficient for x^"<<i<<": ";
        is>>right.coefs[i];
    }
    return is;
}


std::ostream &operator<<(std::ostream &os, const Polynomial & right)
{

    for(int i=right.degree-1;i>=0;i--)
        os<<right.coefs[i]<<"x^ "<<i<<" + ";

    return os;
}
