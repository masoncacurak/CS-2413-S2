// ========================================
// Assignment 1: C++ Programming
// ========================================

// In this assignment, we will implement a Student class and a University class.

// The Student class has two private member variables and five member functions (not
// counting the constructor).

// The University class has one private member variable and four member functions. 

// For all print functions, only print the value and do not add any additional character
// such as space or change line. For example, if you are asked to print the value of x,
// write "cout << x;" instead of "cout << x << endl;"

// ! Task 1: Complete the header files

#include <iostream>
using namespace std;

// ! Task 2: Design and implement all member functions of the following two classes: Student and University.

class Student {

public:
    void set_SID(int x); // It assigns x to SID.
    void prt_SID(); // It prints SID.
    void set_GPA(float y); // It assigns y to GPA.
    void prt_GPA(); // It prints GPA.
    void reset(); // It resets SID and GPA to -1.
    float get_GPA(); // It returns GPA
    float get_SID(); // It returns SID
    Student(); // Constructor. It initializes both SID and GPA to -1.

private:
    int SID; // It holds a student's ID.
    float GPA; // It holds a student's GPA.
};

class University {

public:
    void set_Stu(Student x[]); // It assigns x to Sooner.
    float GPA_Mean(); // It prints the mean GPA of the five students held by Sooner[5].
    float GPA_Max(); // It prints the max GPA of these five students.
    float GPA_Min(); // It prints the min GPA of these five students.
    University(); // Constructor. Initialize all student SID and GPA to -1.

private:
    Student Sooner[5]; // It holds the records of five students.
};

// Assigns x to SID
void Student::set_SID(int x) {
    SID = x;
}

// Prints out SID
void Student::prt_SID() {
    cout << SID;
}

// Assigns y to GPA
void Student::set_GPA(float y) {
    GPA = y;
}

// Prints GPA
void Student::prt_GPA() {
    cout << GPA;
}

// Resets SID and GPA to -1
void Student::reset() {
    SID = -1;
    GPA = -1;
}

// Returns GPA
float Student::get_GPA() {
    return GPA;
}

// Returns SID
float Student::get_SID() {
    return SID;
}

// Initializes both SID and GPA to -1
Student::Student() { 
    SID = -1;
    GPA = -1;
}

// Assigns x to Sooner
void University::set_Stu(Student x[]) { 
    for (int i = 0; i < 5; i++) {
        Sooner[i].set_SID(x[i].get_SID());
        Sooner[i].set_GPA(x[i].get_GPA());
    }
}

// Prints the mean GPA of the five students held by Sooner[5]
float University::GPA_Mean() {
    float sum = 0.0;

    for (int i = 0; i < 5; i++) {
        sum += Sooner[i].get_GPA();
    }
    float mean = sum / 5.0;
    cout << mean;
    return mean;
}

// Prints the max GPA of these five students
float University::GPA_Max() {
    float max = Sooner[0].get_GPA();

    for (int i = 1; i < 5; i++) {
        if (Sooner[i].get_GPA() > max) {
            max = Sooner[i].get_GPA();
        }
    }
    cout << max;
    return max;
}

// Prints the min GPA of these five students
float University::GPA_Min() {
    float min = Sooner[0].get_GPA();

    for (int i = 1; i < 5; i++) {
        if (Sooner[i].get_GPA() < min) {
            min = Sooner[i].get_GPA();
        }
    }
    cout << min;
    return min;
}

// Initialize all student SID and GPA to -1
University::University() { 
    for (int i = 0; i < 5; i++) {
        Sooner[i].set_SID(-1);
        Sooner[i].set_GPA(-1);
    }
}

// ! === End of Task 2 ====

int main() {

    Student x[5];
    University OU;
    int sid;
    float gpa;

// ? ======= Test 1 ======= This tests your constructor function, print function and header files.
for (int i = 0; i < 5; i++) {
    x[i].prt_SID(); cout << ' ';
    x[i].prt_GPA(); cout << endl;
}

// ! Task 3:  Write a program that takes the SID and GPA of five students as input and assignes them to x[5].
// ! Format of the inputs should be (with space) SID1 GPA1 SID2 GPA2 SID3 GPA3 SID4 GPA4 SID5 GPA5

// Takes the SID and GPA of five students as input and assignes them to x[5]
for (int i = 0; i < 5; i++) {
    cin >> sid;
    cin >> gpa;
    x[i].set_SID(sid);  
    x[i].set_GPA(gpa);
}

// ? ======= Test 2 ======= This tests your set function
for (int i = 0; i < 5; i++) {
    x[i].prt_SID(); cout << ' ';
    x[i].prt_GPA(); cout << endl;
}

// ? ======= Test 3 ======= This tests your University class.
OU.set_Stu(x);
OU.GPA_Mean(); cout << ' ';
OU.GPA_Max(); cout << ' ';
OU.GPA_Min(); cout << endl;

// ? ======= Test 4 ======= This tests your reset function.
for (int i = 0; i < 5; i++) {
    x[i].reset();
    x[i].prt_SID(); cout << ' ';
    x[i].prt_GPA(); cout << endl;
}

return 0;

}