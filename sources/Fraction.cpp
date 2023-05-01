#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "Fraction.hpp" 
using namespace std;

Fraction::Fraction(int a , int b){
    if(b==0) throw invalid_argument("can not divide by 0");
    up = a;
    down = b;
}
Fraction::Fraction(): up(1) , down(1){}
Fraction::Fraction(float number): up(number*1000) , down(1000){}
Fraction Fraction::operator +(const Fraction& f) const{
    if (f.up == 0){
        Fraction s(this->up , this->down);
        return reduce(s);
    }
    else if (this->up == 0){
        return reduce(f);
    }
    int lcm = find_lcm(this->down , f.down);
    int new_up = (lcm/this->down*this->up) + (lcm/f.down*f.up);
    //reduce Fraction to minimal
    Fraction temp(new_up , lcm);
    return reduce(temp);
}
Fraction Fraction::operator +(double d) const{
    Fraction f1(this->up , this->down);
    Fraction f2(d*1000 , 1000);
    return f1 + f2;
}
Fraction Fraction::operator -(const Fraction& f) const{
    Fraction me(this->up , this->down);
    Fraction reduced1 = reduce(me);
    Fraction reduced2 = reduce(f);
    if (f.up == 0){
        return reduced1;
    }
    else if (this->up == 0){
        Fraction s2(reduced2.up , reduced2.down);
        return s2;
    }
    int lcm = find_lcm(reduced1.down , reduced2.down);
    int new_up = (lcm/reduced1.down*reduced1.up) - (lcm/reduced2.down*reduced2.up);
    //reduce Fraction to minimal
    Fraction temp(new_up , lcm);
    return reduce(temp);
}
Fraction Fraction::operator -(int num) const{
    Fraction f1 (this->up , this->down);
    Fraction f2 (num , 1);
    return f1-f2;
}
Fraction Fraction::operator *(const Fraction& f) const{
    if(this->up == 0 || f.up == 0){
        Fraction zero(0,1);
        return zero;
    }
    Fraction f1(this->up , this->down);
    Fraction reduced1 = reduce(f1);
    Fraction reduced2 = reduce(f);
    int new_up = reduced1.up*reduced2.up;
    int new_down = reduced1.down*reduced2.down;
    //reduce Fraction to minimal
    Fraction temp(new_up , new_down);
    return reduce(temp);
}
Fraction operator *(double d ,const Fraction& f) {
    Fraction multi(d*1000 , 1000);            
    return multi * f;
} 
Fraction Fraction::operator /(const Fraction& f) const{
    if(f.up == 0 || f.down == 0 || this->down == 0){
    throw_with_nested("Can not divide by 0!");
    }
    else if(this->up == 0){
        Fraction s(0 , 1);
        return s;
    }
    int up1 = this->up * f.down;
    int up2 = f.up * this->down;
    //reduce Fraction to minimal
    Fraction temp(up1 , up2);
    return reduce(temp);
}
bool Fraction::operator ==(const Fraction& f) const{
    if(this->up == 0 && f.up == 0){
        return true;
    }
    float up1 = this->up;
    float down1 = this->down;
    float up2 = f.up;
    float down2 = f.down;
    if(up1/down1 == up2/down2) return true;
    return false;
    }
bool Fraction::operator !=(const Fraction& f) const{
float up1 = this->up;
float down1 = this->down;
float up2 = f.up;
float down2 = f.down;
if(up1/down1 != up2/down2) return true;
return false;
}
bool Fraction::operator >(const Fraction& f) const{
    float up1 = this->up;
    float down1 = this->down;
    float up2 = f.up;
    float down2 = f.down;
    if(up1/down1 > up2/down2) return true;
    return false;
    }
bool Fraction::operator >(double d) const{
    float up = this->up;
    float down = this->down;
    if((up/down) > d) return true;
    return false;
    }
bool Fraction::operator >=(const Fraction& f) const{
    float up1 = this->up;
    float down1 = this->down;
    float up2 = f.up;
    float down2 = f.down;
    if(up1/down1 >= up2/down2) return true;
    return false;
    }
bool Fraction::operator <(const Fraction& f) const{
    float up1 = this->up;
    float down1 = this->down;
    float up2 = f.up;
    float down2 = f.down;
    if(up1/down1 < up2/down2) return true;
    return false;
    }
bool Fraction::operator <=(const Fraction& f) const{
    float up1 = this->up;
    float down1 = this->down;
    float up2 = f.up;
    float down2 = f.down;
    if(up1/down1 <= up2/down2) return true;
    return false;
    }
Fraction Fraction::operator ++(){
    this->up = this->up+this->down;
    Fraction temp(this->up, this->down);
    return reduce(temp);
}
Fraction Fraction::operator ++(int dummy){
    Fraction temp(this->up , this->down);
    this->up = this->up+this->down;
    return reduce(temp);
}
Fraction Fraction::operator --(){
    this->up = this->up - this->down;
    Fraction temp(this->up , this->down);
    return reduce(temp);
}
Fraction Fraction::operator --(int dummy) {
    Fraction temp(this->up , this->down);
    this->up = this->up - this->down;
    return reduce(temp);}
ostream& operator <<(ostream& os , const Fraction& f){
    os << f.up << '/' << f.down;
    return os;
    } //friend
istream& operator >>(istream& input , Fraction& f){
    input >> f.up >> f.down;
    return input;
    } //friend
int Fraction::find_gcd(int a , int b) const{          //gcd took from https://www.programiz.com/cpp-programming/examples/hcf-gcd
    a = abs(a);
    b = abs(b);
    while(a != b) {
    if(a > b)
        a -= b;
    else
        b -= a;
    }
    return a;
}
int Fraction::find_lcm(int a , int b) const{ //lcm took from https://www.programiz.com/cpp-programming/examples/lcm
    int lcm = (a > b) ? a : b; 
    do
    {
        if (lcm % a == 0 && lcm % b == 0)
        {
            break;
        }
        else
            ++lcm;
    } while (true);
    return lcm;
}
Fraction Fraction::reduce(const Fraction& f) const{
    int new_up = f.up;
    int new_down = f.down;
    if(f.down < 0){
        new_up = f.up * -1;
        new_down = f.down * -1;
    }
    int gcd = find_gcd(new_up , new_down);
    return Fraction(new_up/gcd , new_down/gcd);
}
int Fraction::get_up(){
    return up;
}
int Fraction::get_down(){
    return down;
}