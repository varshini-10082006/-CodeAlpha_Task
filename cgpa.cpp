#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    int numCourses;
    double grade, creditHours;
    double totalGradePoints = 0.0;
    double totalCredits = 0.0;
    cout << ".............CGPA Calculator ..........." << endl;
    //Input the no.of courses
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 1; i <= numCourses; i++) {
        cout << "\nCourse " << i << ":" << endl;
        //input the grade
        cout << "Enter grade of course "<<i<<": " ;  
        cin >> grade;
        //input the credit houts

        cout << "Enter credit hours: ";
        cin >> creditHours;
        //credit points calculation
        totalGradePoints += (grade * creditHours);
        totalCredits += creditHours;
    }

    //final CGPA calculation
    double cgpa = totalGradePoints / totalCredits;
    //CGPA = Total Grade Points / Total Credit Hours

    // Display final result 
    cout << fixed << setprecision(2);
    cout << "\n..........Final Result ........." << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    
    cout << "Final CGPA: " << cgpa << endl;

    return 0;
}
