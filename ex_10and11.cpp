#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

struct Course
{
    int courseId;
    string courseName;
    string instructor;
};

void createRecord()
{
    ofstream outfile("course_records.txt", ios::app);
    Course course;

    cout << "Enter Course ID: ";
    cin >> course.courseId;

    cout << "Enter Course Name: ";
    cin.ignore();
    getline(cin, course.courseName);

    cout << "Enter Instructor Name: ";
    getline(cin, course.instructor);

    cout << "Record Added Successfully" << endl;

    outfile << course.courseId << "," << course.courseName << "," << course.instructor << endl;

    outfile.close();
}

void searchRecord(int courseId)
{
    ifstream infile("course_records.txt");
    Course course;
    bool found = false;

    while (infile >> course.courseId >> ws && getline(infile, course.courseName, ',') && getline(infile, course.instructor))
    {
        if (course.courseId == courseId)
        {
            cout << "Course ID: " << course.courseId << endl;
            cout << "Course Name: " << course.courseName << endl;
            cout << "Instructor: " << course.instructor << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Course ID not found." << endl;
    }

    infile.close();
}

void editRecord(int courseId)
{
    ifstream infile("course_records.txt");
    ofstream outfile("temp_records.txt");

    Course course;
    bool found = false;

    while (infile >> course.courseId >> ws && getline(infile, course.courseName, ',') && getline(infile, course.instructor))
    {
        if (course.courseId == courseId)
        {
            cout << "Enter New Course ID: ";
            cin >> course.courseId;

            cout << "Enter New Course Name: ";
            cin.ignore();
            getline(cin, course.courseName);

            cout << "Enter New Instructor Name: ";
            getline(cin, course.instructor);

            outfile << course.courseId << "," << course.courseName << "," << course.instructor << endl;
            found = true;
        }
        else
        {
            outfile << course.courseId << "," << course.courseName << "," << course.instructor << endl;
        }
    }

    if (!found)
    {
        cout << "Course ID not found." << endl;
    }

    infile.close();
    outfile.close();

    if (remove("course_records.txt") != 0)
    {
        cout << "Error deleting file." << endl;
    }
    else if (rename("temp_records.txt", "course_records.txt") != 0)
    {
        cout << "Error renaming file." << endl;
    }
    else
    {
        cout << "Record updated successfully." << endl;
    }
}

void deleteRecord(int courseId)
{
    ifstream infile("course_records.txt");
    ofstream outfile("temp_records.txt");

    Course course;
    bool found = false;

    while (infile >> course.courseId >> ws && getline(infile, course.courseName, ',') && getline(infile, course.instructor))
    {
        if (course.courseId == courseId)
        {
            found = true;
        }
        else
        {
            outfile << course.courseId << "," << course.courseName << "," << course.instructor << endl;
        }
    }

    if (!found)
    {
        cout << "Course ID not found." << endl;
    }
    infile.close();
    outfile.close();

    if (remove("course_records.txt") != 0)
    {
        cout << "Error deleting file." << endl;
    }
    else if (rename("temp_records.txt", "course_records.txt") != 0)
    {
        cout << "Error renaming file." << endl;
    }
    else
    {
        cout << "Record deleted successfully." << endl;
    }
}

int main()
{
    int choice, courseId;

    while (true)
    {
        cout << "\n------ Course Record Management ------" << endl;
        cout << "1. Create Record" << endl;
        cout << "2. Search Record" << endl;
        cout << "3. Edit Record" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createRecord();
            break;
        case 2:
            cout << "Enter Course ID to search: ";
            cin >> courseId;
            searchRecord(courseId);
            break;
        case 3:
            cout << "Enter Course ID to edit: ";
            cin >> courseId;
            editRecord(courseId);
            break;
        case 4:
            cout << "Enter Course ID to delete: ";
            cin >> courseId;
            deleteRecord(courseId);
            break;
        case 5:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
