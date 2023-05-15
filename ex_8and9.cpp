#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student
{
    int rollNumber;
    string name;
    string grade;
};

void writeRecord(const Student &student)
{
    ofstream outFile("students.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << student.rollNumber << " "
                << student.name << " "
                << student.grade << endl;
        outFile.close();

        cout << "Record added successfully." << endl;
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
}

void displayRecords()
{
    ifstream inFile("students.txt");
    if (inFile.is_open())
    {
        cout << "Student Records:" << endl;
        cout << "----------------" << endl;

        int rollNumber;
        string name, grade;
        while (inFile >> rollNumber >> name >> grade)
        {
            cout << "Roll Number: " << rollNumber << endl;
            cout << "Name: " << name << endl;
            cout << "Grade: " << grade << endl;
            cout << "----------------" << endl;
        }
        inFile.close();
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
}

bool searchRecord(int rollNumber, Student &student)
{
    ifstream inFile("students.txt");
    if (inFile.is_open())
    {
        int roll;
        string name, grade;
        while (inFile >> roll >> name >> grade)
        {
            if (roll == rollNumber)
            {
                student.rollNumber = roll;
                student.name = name;
                student.grade = grade;
                inFile.close();
                return true;
            }
        }
        inFile.close();
    }
    return false;
}

void editRecord(int rollNumber)
{
    Student student;
    if (searchRecord(rollNumber, student))
    {
        string name, grade;
        cout << "Enter the new name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the new grade: ";
        getline(cin, grade);

        fstream file("students.txt", ios::in | ios::out);
        if (file.is_open())
        {
            string line;
            size_t pos;
            while (getline(file, line))
            {
                pos = line.find(to_string(rollNumber));
                if (pos != string::npos)
                {
                    file.seekp(static_cast<long>(file.tellg()) - static_cast<long>(line.length()), ios::beg);
                    file << rollNumber << " " << name << " " << grade;
                    file.seekp(static_cast<long>(file.tellg()) + 1, ios::beg); // Move file pointer to the next character
                    break;
                }
            }
            file.close();
            cout << "Record updated successfully." << endl;
        }
        else
        {
            cout << "Unable to open the file." << endl;
        }
    }
    else
    {
        cout << "Record not found." << endl;
    }
}

void deleteRecord(int rollNumber)
{
    Student student;
    if (searchRecord(rollNumber, student))
    {
        ifstream inFile("students.txt");
        if (inFile.is_open())
        {
            ofstream outFile("temp.txt");
            if (outFile.is_open())
            {
                int roll;
                string name, grade;
                while (inFile >> roll >> name >> grade)
                {
                    if (roll != rollNumber)
                    {
                        outFile << roll << " " << name << " " << grade << endl;
                    }
                }
                inFile.close();
                outFile.close();
                remove("students.txt");
                rename("temp.txt", "students.txt");
                cout << "Record deleted successfully." << endl;
            }
            else
            {
                cout << "Unable to create temporary file." << endl;
            }
        }
        else
        {
            cout << "Unable to open the file." << endl;
        }
    }
    else
    {
        cout << "Record not found." << endl;
    }
}

int main()
{
    int choice;
    int rollNumber;
    Student student;
    do
    {
        cout << "1. Add Record" << endl;
        cout << "2. Display Records" << endl;
        cout << "3. Search Record" << endl;
        cout << "4. Edit Record" << endl;
        cout << "5. Delete Record" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Roll Number: ";
            cin >> student.rollNumber;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, student.name);
            cout << "Enter Grade: ";
            getline(cin, student.grade);
            writeRecord(student);
            break;
        case 2:
            displayRecords();
            break;
        case 3:
            cout << "Enter Roll Number to search: ";
            cin >> rollNumber;
            if (searchRecord(rollNumber, student))
            {
                cout << "Record found:" << endl;
                cout << "Roll Number: " << student.rollNumber << endl;
                cout << "Name: " << student.name << endl;
                cout << "Grade: " << student.grade << endl;
            }
            else
            {
                cout << "Record not found." << endl;
            }
            break;
        case 4:
            cout << "Enter Roll Number to edit: ";
            cin >> rollNumber;
            editRecord(rollNumber);
            break;
        case 5:
            cout << "Enter Roll Number to delete: ";
            cin >> rollNumber;
            deleteRecord(rollNumber);
            break;
        case 6:
            cout << "Quitting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }

        cout << endl;

    } while (choice != 6);

    return 0;
}
