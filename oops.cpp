#include<iostream>
using namespace std;

class Employee
{
    public:
        string Name;
        string Company;
        int Age;

    void Intro()
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }

    Employee(string name, string company, int age)      // parameterised constructor
    {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    Employee employee1 = Employee("Rounak", "Apple", 20);
    /*employee1.Name = "Rounak";
    employee1.Company = "Apple";
    employee1.Age = 20;*/
    employee1.Intro();

    Employee employee2 = Employee("Saldina", "YT-CodeBeauty", 25);
    /*employee2.Name = "Saldina";
    employee2.Company = "YT-CodeBeauty";
    employee2.Age = 25;*/
    employee2.Intro();
    return 0;
}