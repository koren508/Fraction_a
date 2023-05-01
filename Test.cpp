#include "doctest.h"
#include "sources/Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;


TEST_CASE("constructor"){
    CHECK_NOTHROW(Fraction(-1,3));
    CHECK_NOTHROW(Fraction(3,-1));
    CHECK_NOTHROW(Fraction(0,1));
    CHECK_THROWS(Fraction(1,0));
    Fraction a;
    CHECK(a.get_up() == 1);
    CHECK(a.get_down() == 1);
    Fraction b(0.123);
    CHECK(b.get_up() == 123);
    CHECK(b.get_down() == 1000);
    Fraction c(5,5);
    CHECK(c == a);
}
TEST_CASE("aritmatic"){
    Fraction a(1,2);
    Fraction b(1,3);
    CHECK_EQ(a+b , Fraction(5,6));
    CHECK_EQ(a+0.500 , Fraction(3,3));
    CHECK_EQ(a-b , Fraction(1,6));
    CHECK_EQ(b-a , Fraction(-1,6));
    CHECK_EQ(a*b , Fraction(1,6));
    Fraction c(0,7);
    CHECK_EQ(a*c , Fraction(0,1));
    CHECK_EQ(a*0.500 , Fraction(1,4));
    CHECK_THROWS(a/c);
    CHECK_NOTHROW(c/a);
}
TEST_CASE("Reduced function"){
    Fraction a(1,3);
    Fraction b(2,6);
    Fraction c(-3 , -9);
    Fraction d(10,30);
    CHECK(a == b);
    CHECK(a == c);
    CHECK_FALSE(a < d);
}
TEST_CASE("unary operators"){
    //postfix
    Fraction a(1,3);
    CHECK(a++ == Fraction(1,3));
    CHECK(a-- == Fraction(4,3)); // a now is Fraction(4,3)
    CHECK(a == Fraction(1,3));   // a now is Fraction(1,3)
    //prefix
    a = Fraction(1,3); //init again
    CHECK(++a == Fraction(4,3)); // a now is Fraction(4,3)
    CHECK(--a == Fraction(1,3)); // a now is Fraction(1,3)
    CHECK(a == Fraction(1,3));       // a now is Fraction(4,3)
    CHECK(Fraction(3,6) > Fraction(1,3));
    CHECK(Fraction(1,3) < Fraction(3,6));
    CHECK(Fraction(1,3) <= Fraction(2,6));
    CHECK(Fraction(1,3) <= Fraction(1,3));
    CHECK(Fraction(1,3) >= Fraction(2,6));
    CHECK(Fraction(1,3) >= Fraction(1,3));
}
