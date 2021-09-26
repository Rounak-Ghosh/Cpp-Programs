#include<iostream>
using namespace std;

class Employee
{
    private:            // hidden or encapsulated
        string Name;
        string Company;
        int Age;

    public:
    
    void setName(string name)   // Setter
    {
        Name = name;
    }
    string getName()  // Getter
    {
        return Name;
    }
    void setCompany(string company)     // Setter
    {
        Company = company;
    }
    string getCompany()     // Getter
    {
        return Company;
    }
    void setAge(int age)    // Setter
    {
        if(age >= 18)
            Age = age;
    }
    int getAge()    // Getter 
    {
        return Age;
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

    Employee employee2 = Employee("Saldina", "YT-CodeBeauty", 25);
    
    employee1.setAge(28);
    cout << employee1.getName() << " is " << employee1.getAge() << " years old." << endl;

    return 0;
}