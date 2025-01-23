#include<iostream>
using namespace std;

class EquilateralTriangle
{
    public:
    float a;
    float circumference;
    float area;

    public:
    void setA(float length){
        a = length;
        circumference = a*3;
        area = (1.73 * a * a) / 4;
    }
    friend void PrintResults(EquilateralTriangle et);
};

void PrintResults(EquilateralTriangle et){
    cout << "Circumference "<< et.circumference << endl;
    cout << "Area " << et.area << endl; 
} 

int main(){

    EquilateralTriangle et;
    et.setA(3);
    PrintResults(et);
    return 0;
}