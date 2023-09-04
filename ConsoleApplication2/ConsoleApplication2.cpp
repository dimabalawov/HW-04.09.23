
#include <iostream>

using namespace std;

struct Employee {
    char firstname[20];
    char lastname[20];
    char phonenumber[20];
    double salary;
};
unsigned int amountofemplo=0;
Employee* emplo = new Employee[amountofemplo];
void readFile(const char* path)
{
    FILE* file = fopen(path, "r");
    const int SIZE = 1000;
    char buffer[SIZE];
    while (fgets(buffer, SIZE, file) != NULL)
        cout << buffer;
    fclose(file);
}

void addEmployee(const char* path)
{
    cout << "Enter the first name of the employee: ";
    cin >> emplo[amountofemplo].firstname;
    cout << "Enter the last name of the employee: ";
    cin >> emplo[amountofemplo].lastname;
    cout << "Enter the phone number of the employee: ";
    cin >> emplo[amountofemplo].phonenumber;
    cout << "Enter the salary of the employee: ";
    cin >> emplo[amountofemplo].salary;
    FILE* file = fopen(path, "a");
    fprintf_s(file, "FIRST NAME: %s\n", emplo[amountofemplo].firstname);
    fprintf_s(file, "LAST NAME: %s\n", emplo[amountofemplo].lastname);
    fprintf_s(file, "PHONE NUMBER: %s\n", emplo[amountofemplo].phonenumber);
    fprintf_s(file, "SALARY: %f\n", emplo[amountofemplo].salary);
    amountofemplo++;
    fprintf_s(file, "---\n");
    fclose(file);
}

void deleteEmployee(const char* path, Employee* arr)
{
    Employee* newarr = new Employee;
    char firstname[20];
    char lastname[20];
    cout << "Enter the first name of the employee: ";
    cin >> firstname;
    cout << "Enter the last name of the employee: ";
    cin >> lastname;
    int index=0;
    for (int i = 0; i < amountofemplo; i++)
    {
        if (firstname == arr[i].firstname && lastname == arr[i].lastname)
        {
            index = i;
            for (size_t j = 0; j < amountofemplo; j++)
            {
                if (j != index)
                    newarr[j] = arr[j];
            }
        }
    }
    amountofemplo--;
    delete[] emplo;
    for (size_t i = 0; i < amountofemplo; i++)
    {
        emplo[i] = newarr[i];
    }
    delete[] newarr;
    
}

int main()
{
    const int SIZE = 100;
    char path[SIZE];
    unsigned short choice = 1;
    cout << "Type the path to the file: " << endl;
    cin >> path;

    addEmployee(path);
    addEmployee(path);
    readFile(path);
}