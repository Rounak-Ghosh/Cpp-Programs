#include<iostream>
using namespace std;

class Employee
{
    protected:             
        string Name;
        string Company;
        int Age;

    public:

    Employee(string name, string company, int age)      
    {
        Name = name;
        Company = company;
        Age = age;
    }

    virtual void Work()     // checks if this function exists in derived class as well, if yes, execute that instead
    {
        cout << Name << " is cheking task back logs, emails, performing tasks ..." << endl;
    }
};

class Developer:public Employee       
{
    public:
        string FavProgrammingLanguage;
    
    Developer(string name, string company, int age, string favProgrammingLanguage)    
        :Employee(name,company,age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }

    void Work()
    {
        cout << Name << " is writing code in " << FavProgrammingLanguage << endl;
    }
};

int main()
{    
    Developer d = Developer("Urvi", "Google", 21, "C++");
    d.Work();

    Employee *e1 = &d;      // base class pointer to a derived class
    e1->Work();             

    return 0;
}