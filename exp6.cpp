#include <iostream>
#include <string>
using namespace std;
class course
{
public:
    string course_name, course_faculty;
    int course_id;

    void input_details()
    {
        cout << "Enter the name of the course: ";
        cin >> course_name;
        cout << "Enter the faculty of the course: ";
        cin >> course_faculty;
        cout << "Enter the id of the course: ";
        cin >> course_id;
        cout << endl;
    }

    void display_details()
    {
        cout << "Course_name: " << course_name << endl;
        cout << "Course_faculty: " << course_faculty << endl;
        cout << "Course_id: " << course_id << endl;
        cout << endl;
    }

    void delete_details()
    {
        int choice;
        cout << "Press 1 to delete course name: "<< endl;
        cout << "Press 2 to delete course faculty: "<< endl;
        cout << "Press 3 to delete course id: "<< endl;
        cout << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            course_name = "";
            break;
        case 2:
            course_faculty = "";
            break;
        case 3:
            course_id = 0;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
};
int main()
{
    course c;
    cout << "Before deleting course details:" << endl;
    c.input_details();
    c.display_details();
    c.delete_details();
    cout << "After deleting course details:" << endl;
    c.display_details();
    return 0;
}
