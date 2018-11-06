#include <cstring>
#include <iostream>
#include <cmath>
#include "Polynomial.hpp"
#include <vector>

int main()
{
    Polynomial p1;
    std::cin>>p1;
    std::cout<<"Polynomial 1: "<<p1<<'\n';

    Polynomial p2;
    std::cin>>p2;
    std::cout<<"Polynomial 2: "<<p2<<'\n';

    Polynomial p3;
    std::cin>>p3;

    std::cout<<"Calculare polinom : "<<p2[2]<<'\n';

    std::cout<<"P1 + P2: "<<p1+p2<<'\n';

    std::cout<<"P1 * P2: " <<p1*p2<<'\n';

    std::cout<<"P1 * constanta: "<<p1*2<<'\n';

    std::cout<<"constanta * P1: "<<2*p1<<'\n';

    std::cout<<"constanta + P2: "<<2+p2<<'\n';

    std::cout<<"P2 + constanta: "<<p2+2<<'\n';

    std::cout<<"P2 pozitiv: "<<+p2<<'\n';

    std::cout<<"P2 negativ: "<<-p2<<'\n';

    if(p1==p3)
    {
        std::cout<<"Comparare de polinoame daca sunt identice: ";
        std::cout<<"p1 == p3"<<'\n';
    }
    if(p1!=p3)
    {
        std::cout<<"Comparare de polinoame daca sunt identice: ";
        std::cout<<"p1 != p3"<<'\n';
    }
    Polynomial p4;
    std::cin>>p4;
    if(3==p4)
    {
        std::cout<<"Comparare de polinom cu o constanta: ";
        std::cout<<"3 == p4"<<'\n';
    }
    if(p4==3)
    {
        std::cout<<"Comparare de polinom cu o constanta: ";
        std::cout<<"p4 == 3"<<'\n';
    }
    if(p4!=3)
    {
        std::cout<<"Comparare de polinom cu o constanta: ";
        std::cout<<"p4 != 3"<<'\n';
    }
    if(3!=p4)
    {
        std::cout<<"Comparare de polinom cu o constanta: ";
        std::cout<<"3 != p4"<<'\n';
    }


    return 0;

}
