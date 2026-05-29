#include<iostream>
#include<string>
using namespace std;
#pragma region Inheritance
/*
Inheritance - it is a oops concept when properties & member func of base/parent class are passes on to the derived/child class.
            - used for code reusability.
            - modes of inheritance - private, public, protected.

Sequence of constructor - when we make obj of derived/child class then first the constructor of base/parent class is called then of 
                          derived/child class.
Sequence of Destructor  - whenever an object goes out of scope( memory deallocation ho ta hai) first the destructor of child/derived class 
                          is called then of parent/base class.

In the case of perameterizes constructors when child object is created we first follow the order of sequence of constructor(parent to child)
so in child constructor we first pass the value to parent perameterized constructor using 
--------------------------------------"child_class_name : Parent_class_name(perameters)".
*/
#pragma endregion Inheritance
//
class Person {
public:
    string name;
    int age; 

    Person() {

    }
    Person(string name , int age){
        this->name=name;
        this->age=age;
    }
    // Person() { //-------------------------------- these codes are example of sequence of constructor.
    //     cout<<"constructor of parent.."<<endl;
    // }
    // ~Person() { //--------------------------------these codes are example of sequence of destructor.
    //     cout<<"Deconstructor of Parent...\n";
    // }
};

class Student : virtual public Person { //Single Inheritance and also virtual inheritance.
public:
    int rollno;

    Student(string name , int age , int rollno) : Person(name , age) {  //expicite calling to parent class. function calling
        this->rollno = rollno;
    }

    // Student() { //-------------------------------- these codes are example of sequence of constructor.
    //     cout<<"constructor of child.."<<endl;
    // }

    // ~Student() { //------------------------------- these codes are example of sequence of destructor.
    //     cout<<"Deconstructor of child...\n";
    // }

    void getInfo() {
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<rollno<<endl;
    } 
};

class Teacher : virtual public Person { // Hierarchical Inheritance person is the base class and student and teacher are derived classes.
protected:
    int salary;
public:
    string subject;
    Teacher(string subject , int salary) {
        this->subject=subject;
        this->salary=salary;
    }
    Teacher(string name , int age , string subject , int salary) : Person(name , age) {
        this->name = name;
        this->age = age;
        this->subject = subject;
        this->salary = salary;
    }
    void getInfo() {
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<subject<<endl;
        cout<<salary<<endl;
    } 
};

class TA : public Student , public Teacher { //multiple inheritance and Diamond Problem.
public:
    TA(string name , int age , string subject , int rollno, int salary): Student(name, age, rollno), Teacher(subject, salary) {
        /*this->Student::name=name;   here this will create a ambigious problem as class Student and Teacher both inherit name and age 
                                      from Person class so we end up with two copies of name & age. here both becomes ambigious and compiler
                                      doesnt know which to use.
                                      this is classical DIAMOND PROBLEM
                                      so to solve this what i have done is i have spicified that use the Student name & age.
                                      this is called SCOPE RESOLUTION. 
                                      i can use this method to temparary solve this problem but to permanently solve this i will use 
                                      VIRTUAL INHERITANCE. make the common base class( Person ) as virtual class in Student and Teacher.
                                    
        this->Student::age=age; 
        */
        this->name=name;
        this->age=age;
        this->rollno = rollno;
        this->subject=subject;
        this->salary=salary;
    }
    void getInfo() {
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<subject<<endl;
        cout<<rollno<<endl;
        cout<<salary<<endl;
    }
};

int main() {
    TA o1("lakshya soni", 20 ,"OOPS", 14, 200000);
    o1.getInfo();
}