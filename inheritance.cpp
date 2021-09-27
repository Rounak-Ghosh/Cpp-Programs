#include<iostream>
using namespace std;

class Employee
{
    protected:            // hidden but not for sub class
        string Name;
        string Company;
        int Age;

    public:

    Employee(string name, string company, int age)      // parameterised constructor
    {
        Name = name;
        Company = company;
        Age = age;
    }

    void AskForPromotion()
    {
        if(Age>=30)
            cout << Name << " got promoted!" << endl;
        else
            cout << Name << ", sorry. No promotion for you!" << endl;
    }
};

class Developer:public Employee        // sub class of Employee (super class)
{
    public:
        string FavProgrammingLanguage;
    
    Developer(string name, string company, int age, string favProgrammingLanguage)    // as parent class has constructor we need to have the same in child class also
        :Employee(name,company,age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    
    void FixBug()
    {
        cout << Name << " is fixing bug using " << FavProgrammingLanguage << endl;   // can't use Name if access modifier: private, we can use protected instead
    }
};

int main()
{    
    Developer d = Developer("Urvi", "Google", 21, "C++");
    d.FixBug();
    d.AskForPromotion();
    return 0;
}