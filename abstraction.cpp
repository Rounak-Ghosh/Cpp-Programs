#include<iostream>
using namespace std;

class AbstractEmployee      // abstract class
{
    virtual void AskForPromotion() = 0;     // obligatory - pure virtual function
};

class Employee:AbstractEmployee
{
    private:            
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

    void AskForPromotion()
    {
        if(Age>=30)
            cout << Name << " got promoted!" << endl;
        else
            cout << Name << ", sorry. No promotion for you!" << endl;
    }
};

int main()
{
    Employee employee1 = Employee("Rounak", "Apple", 20);
    Employee employee2 = Employee("Saldina", "YT-CodeBeauty", 35);

    employee1.AskForPromotion();
    employee2.AskForPromotion();

    return 0;
}