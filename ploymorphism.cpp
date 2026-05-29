#include<iostream>
#include<string>
using namespace std;
#pragma region Polymorphism
/*
Polymorphism - Poly means multiple and morph means forms.
             - it is the ability of object to change is form with respect to context.
             - Text book "the ability of object to take on different forms or behave in different ways depending on the context in which 
                          they are used".
             - two types:-
                        - Compile time polymorphism - constructor overloading , function overloading( same name but different parameters
                                                    (either no. of para different or type of para different)). And Operator overloading.
                                                    - As the name suggest it happens at compile time / statically hota hai.
                        - Run time polymorphism - As the name suggest it happens at the run time / dynamic hota hai.
                                                - Function overriding - parent & child both contains the same function with different 
                                                                        implementation. 
                                                                      - depending on whose object is made that classes function is called.
                                                - Virtual Function - these are defined by the keyword "virtual" inside base class and are 
                                                                     are always declared with the base class and they are overridden
                                                                     in a child class.
                                                                   - it is called during runtime.

Constructor Overloading - example of polymosphism
*/
#pragma endregion Polymorphism

class Parent {
public:
    string name;
    
    // below is the code for polymorphism.
    Parent() {
        cout<<"Non-Parameterized Constructor"<<endl;
    }

    Parent(string name) {
        this->name = name;
        cout<<"Perameterized Constructor"<<endl;
    }
    virtual void getname() { // virtual function.
        cout<<"Parent class\n";
    }
    //till here
};

class Child : public Parent {
public:
    void getname() {
        cout<<"Child class\n";
    }
};

class Print {
public:
    // below is the example of Function overloading.
    void show(int x) {
        cout<<"int : "<<x<<endl;
    }

    void show(char y) {
        cout<<"char : "<<y<<endl;
    }
};

int main() {
    /* Here depending on the context the object is being called we can also say that object is changing its form depending on the context.
    Parent s1;
    Parent s2("Lakshya Soni"); 
    */
    /* this is the code for func overloading.
    Print p1;
    p1.show('$');
    */
    Child c;
    c.getname();
    return 0;
}