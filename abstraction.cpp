#include<iostream>
#include<string>
using namespace std;
#pragma region Abstraction
/*
Abstraction - Hinding all unnecesary/sensitive details & showing only the important parts.
            - easist way to implement abstraction is by using access modifiers(private, public, protected).
            -difference between data hiding and abstraction is that former only hides the data but latter boths hides and shows imp parts.
            -another way to implement abstraction is by using abstract classes.

Abstract class - if a class contains a pure virtual function then it automatically becomes a abstract class.
               - it is a class which never creates an object.
               - acts as a blueprint for other classes. only for inheritance. provides a base class from which other classes can be derived.
               -typically used to define an interface for derived classes.

Static Keyword - Static Variable - variable which is declared as static is created and initialised once for the lifetime of the program.
                                 - helps in keeping the value even after the function is ended and removed from the stack as static variables
                                   are stored outside the stack and in the global/static block.
                                 - and when a static variable is declared inside a class it is shared with all its objects.
*/
#pragma endregion Abstraction
class shape { // abstract class.
public:
    virtual void draw() = 0; // pure virtual function.
};

class Circle {
public:
    //below is static variable code
    static int x;
    //ends here
    void draw(){
        cout<<"circle"<<endl;
    }
};

void func() {
    static int x = 0; //static variable.
    cout<<x<<endl;
    x++;
}
int Circle::x=0; //

int main(){
    Circle c;
    Circle c1;
    c.x = 2;
    cout<<c1.x;
    return 0;
}