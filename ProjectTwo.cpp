// Joseph Wilfong 02/23/2025
// I used cin for user input but stringstream for reading CSV files since it's more efficient for parsing structured data.

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store course details
struct Course {
    string courseNumber;  // Course identifier
    string courseName;    // Full course title
    vector<string> prerequisites;  // List of prerequisite course numbers
};

// Class to manage the course catalog using a hash table
class CourseCatalog {
private:
    unordered_map<string, Course> courses;  // Hash table to store courses

public:
    // Load courses from a file into the hash table
    void LoadCourses(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error: Cannot open file " << filename << endl;
            return;
        }

        string line;
        // Read each line from the file
        while (getline(file, line)) {
            stringstream ss(line); // Im using stringstream for parsing instead of cin just to check it out
            string courseNumber, courseName, prereq;
            vector<string> prerequisites;

            // Extract course number and course name
            getline(ss, courseNumber, ',');
            getline(ss, courseName, ',');
            
            // Extract prerequisites if any
            while (getline(ss, prereq, ',')) {
                prerequisites.push_back(prereq);
            }

            // Store the course in the hash table
            courses[courseNumber] = {courseNumber, courseName, prerequisites};
        }

        file.close();
        cout << "Courses successfully loaded!" << endl;
    }

    // Print all courses sorted in alphanumeric order
    void PrintCourseList() {
        vector<Course> sortedCourses;
        
        // Copy courses from the hash table into a vector for sorting
        for (const auto& pair : courses) {
            sortedCourses.push_back(pair.second);
        }
        
        // Sort courses based on course number
        sort(sortedCourses.begin(), sortedCourses.end(), [](const Course& a, const Course& b) {
            return a.courseNumber < b.courseNumber;
        });

        // Display the sorted courses
        cout << "\nCourse List:\n";
        for (const auto& course : sortedCourses) {
            cout << course.courseNumber << ", " << course.courseName << endl;
        }
    }

    // Print details of a specific course, including prerequisites
    void PrintCourseInfo(const string& courseNumber) {
        // Check if the course exists in the hash table
        if (courses.find(courseNumber) == courses.end()) {
            cout << "Course not found." << endl;
            return;
        }
        
        Course course = courses[courseNumber];
        cout << course.courseNumber << ", " << course.courseName << endl;
        
        // Display prerequisites if any
        if (course.prerequisites.empty()) {
            cout << "No prerequisites." << endl;
        } else {
            cout << "Prerequisites: ";
            for (size_t i = 0; i < course.prerequisites.size(); ++i) {
                cout << course.prerequisites[i];
                if (i < course.prerequisites.size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }
};

// Main program
int main() {
    CourseCatalog catalog;  // Course catalog instance
    string filename = "ABCU_Advising_Program_Input.csv";  // Default input file name
    string courseNumber;
    int choice;

    cout << "Welcome to the course planner." << endl;
    
    // Main menu loop
    do {
        // Display menu options
        cout << "\n1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "What would you like to do? ";
        cin >> choice;
        
        // Handle user choices
        switch (choice) {
            case 1:
                // Load courses from file
                catalog.LoadCourses(filename);
                break;
            case 2:
                // Display all courses in alphanumeric order
                catalog.PrintCourseList();
                break;
            case 3:
                // Prompt user for course number and display details
                cout << "Enter course number: ";
                cin >> courseNumber;
                catalog.PrintCourseInfo(courseNumber);
                break;
            case 9:
                // Exit the program
                cout << "Thank you for using the course planner!" << endl;
                break;
            default:
                // Handle invalid input
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
