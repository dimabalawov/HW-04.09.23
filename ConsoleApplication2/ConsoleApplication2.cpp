
#include <iostream>
#include <string>
#include <conio.h>>


using namespace std;

struct Employee {
    char firstname[20];
    char lastname[20];
    char phonenumber[20];
    double salary;
};
const short stringlen = 30;
int amountofemplo=0;

void readFile(const char* path)
{
    FILE* file = fopen(path, "r");
    const int SIZE = 1000;
    char buffer[SIZE];
    while (fgets(buffer, SIZE, file) != NULL)
        cout << buffer;
    if (!amountofemplo)
        cout << "No employees added" << endl;
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
    cout << "Employee has been added" << endl;
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
void clearFile(const char* path, Employee*& arr)
{
    FILE* file = fopen(path, "w");
    Employee* newarr = new Employee[amountofemplo = 0];
    delete[] arr;
    arr = newarr;
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
            cout << "Employee has been deleted" << endl;
            rewriteFile(path, arr);
        }
        else if(i== amountofemplo-1)
            cout << "No such employee has found" << endl;

    }
}

void showEmployee(Employee emplo)
{
    cout << "FIRST NAME: " << emplo.firstname << endl;
    cout << "LAST NAME: " << emplo.lastname << endl;
    cout << "PHONE NUMBER: " << emplo.phonenumber << endl;
    cout << "SALARY: " << emplo.salary<< endl;
    cout << "---" << endl;
}

void searchLastname(Employee* arr)
{
    char lastname[stringlen]{};
    cout << "Enter the last name to find the employee: ";
    cin.ignore();
    cin.getline(lastname, stringlen);
    for (size_t i = 0; i < amountofemplo; i++)
    {
        if (!(strcmp(lastname, arr[i].lastname)))
        {
            showEmployee(arr[i]);
        }
        else if (i == amountofemplo - 1)
        {
            cout << "No employees found" << endl;
        }
    }
}

void searchSalary(Employee* arr)
{
    double min;
    double max;
    cout << "Enter the minimal salary: ";
    cin >> min;
    cout << "Enter the maximum salary: ";
    cin >> max;
    for (size_t i = 0; i < amountofemplo; i++)
    {
        if (arr[i].salary >= min && arr[i].salary <= max)
        {
            showEmployee(arr[i]);
        }
        else if(i==amountofemplo-1)
            cout << "No employees found" << endl;
    }
}

void spaceInput()
{
    char key;
    do
    {
        cout << "Press SPACE to continue" << endl;
        key = _getch();
        if (key == 32)
            break;
    } while (key != ' ');
}
void showMenu(const char* path, Employee*& arr)
{
    short option;
    cout << "Choose the option: " << endl;
    cout << "1 - Add the employee" << endl;
    cout << "2 - Delete the employee" << endl;
    cout << "3 - Show all the employees" << endl;
    cout << "4 - Search by the last name" << endl;
    cout << "5 - Search by the salary" << endl;
    cout << "6 - Clear the file" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        addEmployee(path, arr);
        spaceInput();
        break;
    case 2:
        deleteEmployee(path, arr);
        spaceInput();
        break;
    case 3:
        readFile(path);
        spaceInput();
        break;
    case 4:
        searchLastname(arr);
        spaceInput();
        break;
    case 5:
        searchSalary(arr);
        spaceInput();
        break;
    case 6:
    {
        short clear = 0;
        while (clear != 1 && clear != 2)
        {
            cout << "Confirim the file clearing" << endl;
            cout << "1 - Confirm" << endl;
            cout << "2 - Decline" << endl;
            cin >> clear;
            if (clear == 1)
            {
                clearFile(path, arr);
                cout << "The file has been cleared" << endl;
                spaceInput();
            }
            else if (clear == 2)
            {
                break;
                spaceInput();
            }
            else
                cout << "There is no such option" << endl;
        }
        break;
    }
    default:
        cout << "There is no such option";
        break;
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
    while (1)
    {
        showMenu(path, emplo);
    }
}