#include <vector>
#include <iostream>
#include <math.h>

class Polynomial
{
public:
    ///constructors
    Polynomial();
    Polynomial(int number, double coefficients[]);
    Polynomial(const Polynomial & pol);
    explicit Polynomial(double const_terms);
    ~Polynomial();
    ///overload assingments
     Polynomial &operator=(const Polynomial & pol);
     Polynomial &operator+=(const Polynomial & pol);
     Polynomial &operator+=(double x);
     Polynomial &operator*=(const Polynomial & pol);
     Polynomial &operator*=(double x);
     Polynomial &operator-=(const Polynomial & pol);
     Polynomial &operator-=(double x);

     Polynomial &operator+();
     Polynomial &operator-();


     double &operator()(double x);
     double &operator[](int x);

     friend Polynomial operator+(const Polynomial & left, const Polynomial & right);
     friend Polynomial operator+(const Polynomial & left, double x);
     friend Polynomial operator+(double x, const Polynomial & left);

     friend Polynomial operator-(const Polynomial & left, const Polynomial & right);
     friend Polynomial operator-(const Polynomial & left, double x);
     friend Polynomial operator-(double x, const Polynomial & right);

     friend Polynomial operator*(const Polynomial & left, const Polynomial & right);
     friend Polynomial operator*(const Polynomial & left, double x);
     friend Polynomial operator*(double x, const Polynomial & right);


     friend Polynomial operator/(const Polynomial & left, const Polynomial & right);
     friend Polynomial operator/(const Polynomial & left, double x);
     friend Polynomial operator/(double x, const Polynomial & right);

     friend Polynomial operator%(const Polynomial & left, const Polynomial & right);
     friend Polynomial operator%(const Polynomial & left, double x);
     friend Polynomial operator%(double x, const Polynomial & right);

     friend bool operator==(const Polynomial & left, const Polynomial & right);
     friend bool operator==(double left, const Polynomial & right);
     friend bool operator==(const Polynomial & left, double right);

     friend bool operator!=(const Polynomial & left, const Polynomial & right);
     friend bool operator!=(double left, const Polynomial & right);
     friend bool operator!=(const Polynomial & left, double right);


     friend std::istream &operator>>(std::istream &is, Polynomial &right);
     friend std::ostream &operator<<(std::ostream &os, const Polynomial & right);


private:
    int degree;
    double *coefs;
};





