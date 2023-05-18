#include <iostream>
#include <vector>
#include "Vector.hpp"
using namespace DSA;
using namespace std;

class Complex{
    int Real, Img;
    public:
    Complex(){
        Real = Img = 0;
    }
    Complex(int real, int img){
        Real = real;
        Img = img;
    }
    Complex Add(Complex c){
        Complex res;
        res.Real = this->Real + c.Real;
        res.Img = this->Img + c.Img;
        return res; 
    }
};

int main()
{
    Complex c1, c2, c3;  
    c3 = c1.Add(c2);
    return 0;    
}