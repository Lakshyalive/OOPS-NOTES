#include<iostream>
#include<string>
using namespace std;
#pragma region Constructor
/*
whenever a object is created a constructor is called.
Constructor - special method invoked/ called automatically at the time of object creation.
            - used for initialization.
            properties - same name as class.
                       - constructor doest have a return type.
                       - only called once(automatically), at time of object creation.
                       - memory allocation happends when constructor is called.
                       - Most constructors are public.

1.) Non-parametrized constructor - containing no parameters. also called default constructor.
2.) parameterized - containing parameters. helpful as we can initialize a object in a single line by passing values.
3.) copy constructor - special constructor(default) used to copy properties of one object to another.
                     - 1.) Shallow copy - a shallow copy of an object copies all the member values from one object to another.(default copy).
                                        - leads to "dengling pointers" where if one is deleted the other will points to empty/ invalid
                                          memory location.
                     - 2.) deep copy - (Student class code for explination) a deep copy not only copies the member values but also makes
                                        copies of any dynamically allocated memory that the members point to.
                                     - we use pointers to dynamically allocate memory( in heap ) so that we can change the value of copy 
                                        changing the value of original.
                                     - ensures object independence meaning deleting one will not affect the other.

constructor overloading - since constructor has same name as class, when we need to make objects with different set of parameters/attributes 
                          we make another constructor of same name but different set/no. of attributes/parameters.
                        - type of compile time polymorphism.

this pointer - special pointer in cpp that is use to point to the current object.
             - helps in maintianing the readability of code. 
             - automatic create hone wala pointer jo calling object ko point karta hai.
             - it is basically like object.property ko hum likhte hai (*this).property and isko likhne ka tarika hai this->property. 
*/
#pragma endregion Constructor

#pragma region Destructor  
/*
~Destructor - is used to deallocate memory.
            - it is automatically called when the object goes out of scope.
            - we use delete ptr to remove / delete data from the memory address that the pointer is pointing to.
            - if we dont deallocate the memory it leads to memory leak means that hum ne bahut sari memories heap mai bana bana ke chordi 
                but program end hone per un memories per koi pointer point nahi kar raha hai. and since the pointer is stored in the stack
                which is auto emptied as the program proceeds and when program ends stack is emptied but since the only way to access the 
                memories in the heap was by those pointers now heap is filled with data without any pointers and will stay there until
                system restarts.
*/
#pragma endregion Destructor
class Teacher {
private:
    double salary;
public:
    // Non-parameterized constructor.
    Teacher() {
        subject = "OOPs"; //initialization.
    }
    //parameterized constructor.
    Teacher(string name , string dept , string subject , double salary) {
        this->name = name; /* these all are this pointer examples, left name is object property and right is constructor parameter.
                               its like this when we write in main obj.name = "lakshya soni" but here we are taking all the attribute in 
                               single line only  */
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }
    //copy constructor. this is a custom copy constructor but if we dont make it, it will be called by default when we write t2(t1).
    Teacher(const Teacher &orgObj) { //pass by reference  -------  we us const so that we dont excidently modify the org obj parameters.
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }
    //constructor overloading
    Teacher(string sub , double s) {
        subject = sub;
        salary = s;
    }
    string name;
    string dept;
    string subject = "Programming";  /*NOTE:
                                     even if initialize the attribute/ data member here the constructor initializtion will be given
                                     higher preference.and this will be overwriten.
                                     */

    void getInfo() {
        cout << name << endl;
        cout << dept << endl;
        cout << salary << endl;
    }
};

class Student {
public:
    string name;
    float* cgpaPtr; // i have created a pointer.
    Student(string name , double cgpa) {
        this->name = name;
        cgpaPtr = new float; // here i allocated memory to pointer in heap.
        *cgpaPtr = cgpa; // here i have stored the value of cgpa perameter of object to allocated memory in heap.
    }
    Student(const Student &obj) {
        this->name = obj.name;
        cgpaPtr = new float; // here i have allocated new memory to pointer of different object/ copyed object in heap.
        *cgpaPtr = *(obj.cgpaPtr); // copied the value of perameter of the orignal object.
    }
    ~Student() {
        delete cgpaPtr;
    }
    void getInfo() {
        cout << name << endl;
        cout << *cgpaPtr << endl;
        cout << "address of pointer: " << cgpaPtr << endl;
    }
};
int main() {
    /* -----Teacher class code------
    Teacher t1("lakshya soni" , "Computer Science" , "OOPS" , 100000); // parameterized constructor is called here.
    Teacher t2(t1); //copy constructor is called
    t2.getInfo();
    */
    Student s1("lakshya soni" , 8.9);
    s1.getInfo();
    Student s2(s1);
    *(s2.cgpaPtr) = 9.2;
    s2.getInfo();
    s1.getInfo();
    return 0;
}
