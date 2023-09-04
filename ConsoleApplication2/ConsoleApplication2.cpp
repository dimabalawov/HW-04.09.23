
#include <iostream>

using namespace std;

struct Employee {
	char* firstname;
	char* lastname;
	char* phonenumber;
	double salary;
}emplo;

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
    cin.getline(emplo.firstname, 20);
    cout << "Enter the last name of the employee: ";
    cin.ignore();
    cin.getline(emplo.lastname, 20);
    cout << "Enter the phone number of the employee: ";
    cin >> emplo.phonenumber;
    cout << "Enter the salary of the employee: ";
    cin >> emplo.salary;
    FILE* file = fopen(path, "a");
    fprintf_s(file, "FIRST NAME: %s\n", emplo.firstname);
    fprintf_s(file, "LAST NAME: %s\n", emplo.lastname);
    fprintf_s(file, "PHONE NUMBER: %s\n", emplo.phonenumber);
    fprintf_s(file, "SALARY: %f\n", emplo.salary);
    fprintf_s(file, "---\n");
    fclose(file);
}

int main()
{
    const int SIZE = 100;
    char path[SIZE];
    unsigned short choice = 1;
    cout << "Type the path to the file: " << endl;
    cin >> path;


    readFile(path);
}

