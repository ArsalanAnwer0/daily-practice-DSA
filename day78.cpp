// Learning C++
#include<iostream>
#include<string>
#include<fstream>


using namespace std;

// class BankAccount{
//     public:
//     string name;
//     int balance;

//     int withdraw(int amount){
//         balance = balance - amount;
//         return balance;
//     }

//     void print(){
//         cout << name << " has " << balance << " dollars " << endl;
//     }

// };

// class Employee{
//     public:
//     string name;

//     Employee() : salary(0.00){}

//     void set_salary(double salary1){
//         if(salary1 < 0) salary1 = 0.00;
//         else salary = salary1;
//     }

//     double get_salary(){
//         return salary;
//     }
//     void print_bonus(){
//         cout << name << " bonus: " << calculate_bonus() << endl;
//     }

//     private:
//     double salary;
//     double calculate_bonus(){
//         return salary*0.10;
//     }

// };


// class Cat{
//     private:
//     string name;
//     string color;
//     string favorite_toy;

//     public:
//     void print_cat(){
//         cout << "Name " << name << endl;
//         cout << "Color " << color << endl;
//         cout << "Favourite Toy " << favorite_toy << endl;
//     }
//     Cat(){
//         name = "Unknown";
//         color = "Unknown";
//         favorite_toy = "Unknown";
//     }
//     Cat(string n){
//         name = n;
//         color = "Unknown";
//         favorite_toy = "Unknown";
//     }
//     Cat(string n,string c,string ft);
// };

// Cat::Cat(string n,string c,string ft){
//         name = n;
//         color = c;
//         favorite_toy = ft;
//     }

// class Number{
//     private:
//     double* number;
//     public:
//     Number(double num){
//         number = (double* ) malloc(sizeof(double));
//         *number = num;
//         cout << "Constructor executing! " << endl;
//         cout << "Number " << *number << endl;
//     }

//     ~Number(){
//         cout << "Destructor executing!" << endl;
//         cout << "Number: " <<  *number << endl;
//         free(number);
//     }
// };
   

//    void test(){
//     Number six(6);
//    }









// class Animal{
//     public:
//     string species;
//     static int total;
//     const string name = "arsalan";
//     Animal(string animal_species){
//         species = animal_species;
//         total++;
//     }
//     ~Animal(){
//         total--;
//     }

// };

// int Animal::total = 0;

// class square{
//     private:
//     int side_length;
//     static int total_squares;
//     static void increment_square(){
//         total_squares++;
//     }

//     public:
//     square(int length){
//         side_length = length;
//         increment_square();
//     }
//     int area(){
//         cout << "Side length " << this->side_length << endl;
//         return side_length*side_length;
//     }
//     static int get_total(){
//         return total_squares;
//     }
// };
// int square::total_squares = 0;


// class Square{
//     public:
//     int side_length;
//     string color;

//     void print(){
//         cout << "Side length "   << side_length;
//         cout << " , color " << color << endl; 
//         }
//     Square(){
//         side_length = 0;
//         color = "Black";
//     }    
//     Square(int side_length2, string color2){
//         this->side_length = side_length2;
//         this->color = color2;
//     }
//     Square(int set_length){
//         side_length = set_length;
//         color = "Blue";
//     }
// };

// class Rectangle{
//     public:
//     int length;
//     int width;
//     int area;
//     string color;

//     Rectangle(int l, int w){
//         length = l;
//         width = w;
//         area = length * width;
//         cout << "Constructor 1" << endl;
//     }
//     Rectangle(int l, int w, string c): Rectangle(l,w){
//         cout << "Constructor 2" << endl;
//         color = c; 
//     }

//     void print(){
//         cout << "Length: " << length << endl;
//         cout << "Width: " << width << endl;
//         cout << "Area: " << area << endl;
//         cout << "Color: " << color << endl;
        
//     }
// };

// class counter{
//     private:
//     int count;
//     public:
//     counter(){
//         count = 0;
//     }
//     void print(){
//         cout << "Count: " << count << endl;
//     }
//     void increment(){
//         count++;
//     }
// };


// void increment(int& x){
//     x++;
//     cout << x << endl;
// }

// void swao(int& x, int& y){
//     int temp = x;
//     x = y;
//     y = temp;
// }

// void increment3x(counter& counter){
//     counter.increment();
//     counter.increment();
//     counter.increment();
// }





// class Simple{
//     public:
//     int x;


// };

// class Stack{
//     public:
//     Simple simple;
// };

// class heap{
//     public:
//     Simple *simple;

//     heap(int set_x){
//         simple = new Simple;
//         simple->x = set_x;
//     }
// };








// class BasicNumber{
//     public:
//     int n;

//     BasicNumber(int set_n){
//         n = set_n;    
//     }

//     BasicNumber(const BasicNumber& basic_number){
//         n = 2 * basic_number.n;
//         cout << "Copy constructor called? " << n  << endl;
//     }
// };


// class number{
//     public:
//     int* n;
//     number(int set_n){
//         n = (int *) malloc(sizeof(int));
//         *n = set_n;
//     }
//     number(const number& otherNumber){
//         n = (int * ) malloc (sizeof(int));
//         *n = *(otherNumber.n);

//     }
//     ~number(){
//         free(n);
//     }
//     int get(){
//         return *n;
//     }
// };














// int add(int x, int y){
//     return x+y;
// }
// int add(int x, int y, int z){
//     return x+y+z;
// }


// class Add{
//     public:
//     int add(int x,int y){
//         return x+y;
//     }
//     double add(double x, double y){
//         return x+y;
//     }
// };



// class Number{
//     public:
//     int n;
//     Number(int set_n){
//         n = set_n;
//     }
//     Number operator+(const Number &numA){
//         // cout << this->n << endl;
//         // cout << numA.n << endl;
//         // return Number(this->n + numA.n);
//         return Number(0);
//     }
//     bool operator==(const Number &numA){
//         if(this->n == numA.n){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };








// class Rectangle{
//     public:
//     int length, width;
//     string color;

//     Rectangle(int set_length, int set_width, string set_color){
//         length = set_length;
//         width = set_width;
//         color = set_color;
//     }
//     void print(){
//         cout << "Length: " << length << endl;
//         cout << "Width: " << width << endl;
//         cout << "Color: " << color << endl;
//     }
//     Rectangle& setColor(string set_color){
//         color = set_color;
//         return *this;
//     }
//     Rectangle& setLength(int set_length){
//         length = set_length;
//         return *this;
//     }
//     Rectangle& setWidth(int set_width){
//         width = set_width;
//         return *this;
//     }
// };





// class Student;

// void create_report(Student *student);

// class Student{
//     public:
//     string name;
//     int age;

//     Student(string name, int age){
//         //cout << "This is a memory address! " << this << endl;
//         this->name = name;
//         this->age = age;
//     }
//     void increase_age(){
//         this->age = this->age + 1;
//     }
//     void increase_and_output_age(){
//         this->increase_age();
//         cout << "Age: " << this->age << endl;
//     }
//     void graduate(){
//         cout << "Congratulations! " << endl;
//         create_report(this);
//     }
//     Student& set_name(string name){
//         this->name = name;
//         return *this;
//     }
//     Student& set_age(int age){
//         this->age = age;
//         return *this;
//     }
// };

// void create_report(Student *student){
//     cout << student->name << " " << student->age << endl;
// }







// void increment(int &x){
//     x++;
// }

// int &max(int arr[], int length){
//     int max_index = 0;
//     for(int i=1;i<length;i++){
//         if(arr[i] > arr[max_index]){
//             max_index = i;
//         }
//     }
//     return arr[max_index];
// }

// int func(int x){
//     return 3*x;
// }

// int (&triple)(int) = func;


















class Major {
public:
    string name;

    Major() : name("undeclared") {
        cout << "Major constructed (undeclared)" << endl;
    }

    Major(string name) : name(name) {
        cout << "Major constructed (" << name << ")" << endl;
    }
};

class Minor{
    public:
    string name;

    Minor(string name):name(name){

    }
    

};

class Student {
public:
    string name;
    int start_year;
    int grad_year;
    const string id;
    Major major;  // Changed to lowercase to avoid confusion
    Minor minor2;
    Minor &minor1;
    Student(string name, int start_year, string major_name,Minor &minor)
        : name(name),
          start_year(start_year),
          grad_year(start_year + 4),
          id(name + to_string(start_year)),  // Properly constructing ID
          major(major_name),              // Initializing directly
          minor2(Minor("Physics")),
          minor1(minor)
    {
        cout << "Student Object constructed!" << endl;
    }
};
class MatureStudent: Student{
    public:
    int age;

    MatureStudent(int age,string name, long int start_year,string major,Minor& minor): 
    Student(name,start_year,major,minor),
    age(age){}    
};
int main() {
    long int year = 9999999999;
    Minor minor("Economics"); 
    Student s("Arsalan", 2022, "Computer Science",minor);
    cout << s.minor1.name << endl;
    return 0;









































    // int a = 5;
    // int &b = a;

    // b++;
    // a++;
    // cout << a << " " << b << endl;

    // int c = 20;
    // b = c;
    // cout << b << endl;
    // cout << a << endl;

    // int array[] = {1,2,3,4,5};
    // int &ref = array[2];
    // ref+=10;
    // cout << endl << array[2] << endl;

    // int m = 4;
    // increment(m);
    // cout << "M "<< m << endl;

    // int &max_val = max(array,5);

    // cout << max_val << endl;

    // max_val++;

    // cout << max_val << endl;

    // cout << func(5) << endl;
    // cout << triple(5) << endl;




    



























    // Student student1("Lucas",20);
    // student1.set_name("John").set_age(55);
    // student1.graduate();





























    // Rectangle rectangle1(4,5,"Red");
    // rectangle1.print();

    // rectangle1.setColor("Orange").setLength(10).setWidth(56);
    // rectangle1.print();


























    // Number a(5);
    // Number b(10);

    // Number c = a + b;
    // cout << c.n << endl;

    // if(a == c) cout << "A == C" << endl;
    // else cout << "A does not equal C" << endl;

    // Number d(15);

    // if(c == d) cout << "C == D" << endl;
    // else cout << "C does not equal D" << endl;




























    // Add add_obj;
    // cout << add_obj.add(10,5) << endl;
    // cout << add_obj.add(10.5,5.5);


    // cout << add(5,10) << endl;
    // cout << add(10,5,2) << endl;
    // cout << add(10.5,5.5,2.5) << endl;
























    // number numA(8);
    // cout << "numA: " << numA.get() << endl;

    // number numB = numA;
    // cout << "numB: " << numB.get() << endl;

    // *(numA.n) = 20;

    // cout << "numA: " << numA.get() << endl;
    // cout << "numB: " << numB.get() << endl;

     












    // BasicNumber num1(7);
    // cout << "num1: " << num1.n << endl;
    // BasicNumber num2 = num1;
    // cout << "num2: " << num2.n << endl;

    // BasicNumber num3(5);
    // BasicNumber num4(10);

    // // assignment operator
    // num3 = num4;








































    // heap heapA(4);
    // heap heapB(0);

    // heapB =  heapA;

    // cout << "heapA.simple->x " << heapA.simple->x << endl;
    // cout << "heapB.simple->x " << heapB.simple->x << endl;

    // heapB.simple->x = 20;

    // cout << "heapA.simple->x " << heapA.simple->x << endl;
    // cout << "heapB.simple->x " << heapB.simple->x << endl;



    // Stack stackA;
    // stackA.simple.x = 4;
    // Stack stackB;
    // stackB.simple.x = 6;

    // stackB = stackA;

    // cout << "Stack A " << stackA.simple.x << endl;
    // cout << "Stack B " << stackB.simple.x << endl;

    // stackB.simple.x = 20;

    // // cout << "Stack A " << stackA.simple.x << endl;
    // cout << "Stack B " << stackB.simple.x << endl;



    // Simple simpleA;
    // simpleA.x=4;
    
    // Simple simpleB;
    // simpleB.x=0;

    // simpleB = simpleA;

    // cout << "A " << simpleA.x << endl; 
    // cout << "B " << simpleB.x << endl; 

    // simpleB.x = 20;

    // cout << "A " << simpleA.x << endl; 
    // cout << "B " << simpleB.x << endl; 



























    // int b = 4;
    // int c = 8;
    // cout << "Before b and c : " <<  b << " "<< c << endl;
    // swap(b,c);
    // cout << "After b and c : " <<  b << " "<< c << endl;

    // counter counter1;
    // counter1.print();
    // increment3x(counter1);
    // counter1.print();
























    // Rectangle rectangle1(5,10,"Yellow");
    // rectangle1.print();































    // Square squares[3] = {Square(8,"red"),
    //                      Square(10,"Yellow"),
    //                      Square(12,"Purple")};
    // Square squares[3] = {2,Square(4,"White")};
    // for(int i=0;i<3;i++){
    //     squares[i].print();
    // }












    // square square1(5);
    // cout << square1.area() << endl;
    // cout << square::get_total(); 
    // square square2(1);
    // cout << square2.area() << endl;
    // cout << square::get_total();
     







    // Animal *lion = new Animal("Lion");
    // Animal *tiger = new Animal("Tiger");
    // Animal *bear = new Animal("bear");

    // cout << lion->species << endl;
    // cout << tiger->species << endl;
    // cout << bear->species <<  endl;

    // cout << Animal::total << endl;

    // delete lion;
    // delete tiger;
    // delete bear;
    // cout << Animal::total << endl;





















    // ifstream inFile;
    // inFile.open("file.txt");
    // if(inFile.fail()){
    //     cout << "Error opening file" << endl;
    //     return 1;
    // }

    /*
    int number = 0;
    inFile >> number;
    inFile >> number;

    if(inFile.fail()){
        cout << "File format incorrect" << endl;
        return 1;
    }

    cout << number << endl;
    */

    // double x1 = 0, x2 = 0, x3 = 0;
    // while(true){
    //     inFile >> x1 >> x2 >> x3;
    //     if(inFile.eof()) break;
    //     else
    //     cout << x1 << " " << x2 << " " << x3 << endl;
    // }

    // double a[3][3];
    // int i = 0;
    // while(inFile >> a[i][0] >> a[i][1] >> a[i][2])
    // i++;

    // cout << endl;

    // for(int j=0;j<3;j++){
    //     cout << a[j][0] << " ";
    //     cout << a[j][1] << " ";
    //     cout << a[j][2] << endl;
    // }

    // string line;
    // // inFile >> line;
    // getline(inFile,line);
    // cout << line << endl;


    // inFile.close();


















    // ofstream outFile;
    // outFile.open("file.txt",ofstream::app);
    // if(outFile.fail()){
    //     cout << "Error opening file." << endl;
    //     return 1;
    // }
    // outFile << "content" << endl;
    // double x = 4.5;
    // int y = 10;
    // string z = "Arsalan";
    // outFile << x << endl;
    // outFile << y << endl;
    // outFile << z << endl;
    // outFile.close();



 







    // Number *five = new Number(5);
    // delete five;
    // test();  
    // Number seven(7); 
    // Cat cat1("Garfield","Orange","Ball Of Yarn");
    // cat1.print_cat();


    // Employee employee1;
    // employee1.name = "Kevin";
    // cout << employee1.name << endl;

    // employee1.set_salary(1000);
    // cout << "Salary: " << employee1.get_salary() << endl;

    // employee1.print_bonus();

    // BankAccount account1;
    // account1.name = "Arsalan";
    // account1.balance = 50;

    // account1.print();

    // BankAccount account2;
    // account2.name = "John";
    // account2.balance = 200;

    // account2.print();

























    // cout << "test";

    // cout << endl;

    // cout <<"abc";
    // cout <<"123";
    // cout <<"xyz";
    // cout << endl;

    // cout << "Another line of text\n";
    // cout << "let's learn how to " << "use cout!" << endl;
    
    // cout << "line 1 " << endl << "line 2 " << "line 3" << endl;
    
    // int x = 20;

    // cout << "x: " << x << endl;
    
    // int age = 45;

    // cout << "His father is " << age << " years old! ";

    // int x;

    // cout << "Enter an integer: ";
    // cin >> x;

    // cout << "You entered the integer: " << x << endl;

    // int d;
    // cout << "Enter d: ";
    // if(cin >> d){
    //     cout << "You entered integer: " << d;
    // }
    // else{
    //     cin.clear();
    //     cout << "Invalid input" << endl;
    // }
    // cin.ignore(1000,'\n');
    // double height = 0;
    // double width = 0;
    // double area = 0;
    // cout << "Enter height and width: ";
    // cin >> height;
    // cin >> width;

    // area = height * width;
    // cout << height << " x " << width << " = " << area;
    
    // string name;
    // cout << "Enter your name: ";
    // getline(cin,name);
    // cout << "Hello " << name;

    // int price = 20;
    // if(price <= 90 ){
    //     cout << "Good deal" << endl;
    // }
    // else if(price <= 50){
    //     cout << "Amazing deal!" << endl;
    // }
    // else if(price >= 200){
    //     cout << "Very bad price" << endl;
    // }
    // else cout << "Not a good deal!" << endl;

    // cout << "if statement done! " << endl;

    // int i = 1;

    // while(i<=5){
    //     cout << i << " ";
    //     if(i==2) i+2;
    // }

    // cout << "While loop done! " << endl;

    // int sum = 0;
    // int number = 0;
    // while(number!=-1){
    //     cout << "Enter positive number: ";
    //     cin >> number;
    //     if(number <= 0 && number != -1){
    //         cout << "Number must be a positive integer!" << endl;
    //         break;
    //     }
    //     if(number!=-1) sum +=number;
    // }
    // cout << "Sum: " << sum;

    // string test1 = "abcdefghi";
    // cout << test1 << endl;

    // cout << "size: " << test1.size() << endl;

    // cout << "test[1]: " << test1[1] << endl;

    // cout << "test1.at[3]: " << test1.at(3) << endl;

    // test1[2] = 'C';

    // cout << test1[2] << endl;

    // test1.append("hahaha");
    // cout << test1 << endl;

    // cout << "length: " << test1.length() << endl;

    // string test2 = "123",test3;
    // test3 = test1+test2;
    // cout << test3 <<  endl;
    // test3 = "hello";

    // string test4 = to_string(100);
    // double d = stod(test4);
    // cout << "Double: " << d;

    // string test5 = "A test string";
    // string sub = test5.substr(2,4);
    // cout << sub << endl;


    

    

    return 0;
}