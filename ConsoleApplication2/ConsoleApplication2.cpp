
#include <iostream>
#include <string>

using namespace std;

struct Employee {
    char firstname[20];
    char lastname[20];
    char phonenumber[20];
    double salary;
};
int amountofemplo=0;
void readFile(const char* path)
{
    FILE* file = fopen(path, "r");
    const int SIZE = 1000;
    char buffer[SIZE];
    while (fgets(buffer, SIZE, file) != NULL)
        cout << buffer;
    fclose(file);
}

void addEmployee(const char* path,Employee* &arr)
{
    Employee* newarr = new Employee[amountofemplo+1];
    for (size_t i = 0; i < amountofemplo; i++)
    {
        newarr[i] = arr[i];
    }
    cout << "Enter the first name of the employee: ";
    cin >> newarr[amountofemplo].firstname;
    cout << "Enter the last name of the employee: ";
    cin >> newarr[amountofemplo].lastname;
    cout << "Enter the phone number of the employee: ";
    cin >> newarr[amountofemplo].phonenumber;
    cout << "Enter the salary of the employee: ";
    cin >> newarr[amountofemplo].salary;
    FILE* file = fopen(path, "a");
    fprintf_s(file, "FIRST NAME: %s\n", newarr[amountofemplo].firstname);
    fprintf_s(file, "LAST NAME: %s\n", newarr[amountofemplo].lastname);
    fprintf_s(file, "PHONE NUMBER: %s\n", newarr[amountofemplo].phonenumber);
    fprintf_s(file, "SALARY: %f\n", newarr[amountofemplo].salary);
    fprintf_s(file, "---\n");
    fclose(file);
    amountofemplo++;
    delete[] arr;
    arr = newarr;
}

void rewriteFile(const char* path, Employee*& arr)
{
    FILE* file = fopen(path, "w");
    for (size_t i = 0; i < amountofemplo; i++)
    {
        fprintf_s(file, "FIRST NAME: %s\n", arr[i].firstname);
        fprintf_s(file, "LAST NAME: %s\n", arr[i].lastname);
        fprintf_s(file, "PHONE NUMBER: %s\n", arr[i].phonenumber);
        fprintf_s(file, "SALARY: %f\n", arr[i].salary);
        fprintf_s(file, "---\n");
    }
    fclose(file);
}
void deleteEmployee(const char* path, Employee* &arr)
{
    Employee* newarr = new Employee[amountofemplo-1];
    char firstname[20];
    char lastname[20];
    cout << "Enter the first name of the employee: ";
    cin >> firstname;
    cout << "Enter the last name of the employee: ";
    cin >> lastname;
    int index=0;
    for (int i = 0; i < amountofemplo; i++)
    {
        if (!(strcmp(firstname,arr[i].firstname)) && !(strcmp(lastname, arr[i].lastname)))
        {
            index = i;
            for (size_t j = 0; j < amountofemplo; j++)
            {
                if (j != index)
                    newarr[j] = arr[j];
            }
            amountofemplo--;
            delete[] arr;
            arr = newarr;
            rewriteFile(path, arr);
        }
        else if(i== amountofemplo-1)
            cout << "No such employee has found" << endl;

    }
}

int main()
{
    Employee* emplo = new Employee[amountofemplo];
    const int SIZE = 100;
    char path[SIZE];
    unsigned short choice = 1;
    cout << "Type the path to the file: " << endl;
    cin >> path;
    addEmployee(path, emplo);
    addEmployee(path, emplo);
    readFile(path);
    deleteEmployee(path, emplo);
    readFile(path);
}