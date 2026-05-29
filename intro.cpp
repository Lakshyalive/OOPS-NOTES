#include<iostream>
#include<string>
using namespace std;
#pragma region OOPS Introduction
/*
objects / instance - real world entities. 
                   - physical instances of a class that represents a real world entity.

classes - blueprint of objects/ entities. we can also visualize it as a group of objects like class in college containing grp of 
          students. and students are objects of class by being real world entities.
        - 

methods / member functions - function written inside a class.

properties / attribures / data members - variables that live inside a class. represents characteristics of object. like car is a class the 
                                         model , color, topspeed, etc can be its properties. and instance like toyota can use the car class 
                                         as blueprint.

Access modifiers - special keyword 
                 - Private (by default all the attributes and methods are private) - data and methods are only accessible inside the class.
                 - Public - data & methods accessible to everyone.
                 - Protected - data & methods accessible inside class and to its derived class.
            NOTE - in class access modifier is private by default but in struct it is public but default.

setter - it is used to set value of private attribute outside the class.
getter - it is used to get the value of private attribute outside the class.
by using setter and getter we can indirectly access private attribute using public functions(setter and getter).
*/
#pragma endregion OOPS Introduction

class Teacher{
private:
    double salary;

public:
    //properties / attributes.
    string name;
    string dept;
    string subject;  

    // Methods / Member function
    void changeDept(string newDept){
        dept = newDept;
    }
    //setter - it is used to set value of private attribute outside the class.
    void setSalary(double s){
        salary = s;
    }
    //getter - it is used to get the value of private attribute outside the class.
    double getSalary(){
        return salary;
    }
};

int main() {
    Teacher t1; // i have created a object(instance) of class Teacher.
    t1.name = "Lakshya Soni"; // to access the data members of class we use '.' operator.
    t1.dept = "AI";
    t1.subject = "OOPS";
    t1.setSalary(100000); // to initialize the private data member we use the setter function.
    cout<<t1.name<<t1.getSalary()<<endl;
    return 0;
}