#include<iostream>
#include<string>
using namespace std;
#pragma region Encapsulation
/*
Encapsulation - wrapping up of data & methods/member func in a single unit called class.
              - helps in data hiding by using access modifiers(private)
data hiding - hiding of data from outside world by using private access modifier.
*/
#pragma endregion Encapsulation

class Account {
private: //data hiding. here we implimented data hiding using encapsulation 
    double balance;
    string password;
public:
    string accountID;
    string username;
    
};