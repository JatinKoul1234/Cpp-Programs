#include<iostream>
#include<string>
using namespace std;
class course
{
    public:
    string name;
    int duration;
};
class UGcourse : public course
{
    public: 
    string type = "Undergraduate";
};
class PGcourse : public course
{
    public:
    string type = "Post Graduate";
};
class Diplomacourse : public course
{
    public:
    string type = "Diploma";
};
int main()
{
    UGcourse ug;
    ug.name = "B.E";
    ug.duration = 12;

    PGcourse pg;
    pg.name = "M.Tech";
    pg.duration = 46;

    Diplomacourse dc;
    dc.name = "Diploma in Web Development";
    dc.duration = 23;
    cout<<"Details of Undergraduate course:"<<endl;
    cout<<"Course name:"<<ug.name<<endl;
    cout<<"Duration:"<<ug.duration<<endl;
    cout<<"Course type:"<<ug.type<<endl;
    cout<<endl;
    cout<<"Details of Post graduate course:"<<endl;
    cout<<"Course name:"<<pg.name<<endl;
    cout<<"Duratiion:"<<pg.duration<<endl;
    cout<<"Course type:"<<pg.type<<endl;
    cout<<endl;
    cout<<"Details of Diploma course class:"<<endl;
    cout<<"Course name:"<<dc.name<<endl;
    cout<<"Duration:"<<dc.duration<<endl;
    cout<<"Course type:"<<dc.type<<endl;
    cout<<endl;
    return 0;
}

// (b)
#include <iostream>
#include<string>
using namespace std;

// Base class or parent class
class Course {
public:
  virtual void display() {
    cout << "Course Details:\n";
  }
};

// Derived class 1
class UGCourse : public Course {
public:
  void display() override {
    cout << "UG Course Details:\n";
    cout << "Course Name: Bachelor of Engineering\n";
    cout << "Duration: 4 years\n";
  }
};

// Derived class 2
class PGCourse : public Course {
public:
  void display() override {
    cout << "PG Course Details:\n";
    cout << "Course Name: Master of Science\n";
    cout << "Duration: 2 years\n";
  }
};

// Derived class 3
class DiplomaCourse : public Course {
public:
  void display() override {
    cout << "Diploma Course Details:\n";
    cout << "Course Name: Diploma in Computer Applications\n";
    cout << "Duration: 1 year\n";
  }
};

// Main function
int main() {
  Course* course;

  // Creating objects of each derived class and storing their addresses in base class pointer
  course = new UGCourse();
  course->display();

  course = new PGCourse();
  course->display();

  course = new DiplomaCourse();
  course->display();

  return 0;
}
