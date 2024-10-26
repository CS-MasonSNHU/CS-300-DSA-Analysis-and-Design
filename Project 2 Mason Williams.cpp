// Project 2 Mason Williams.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// Course class to store course information: number, title, and prerequisites
class Course {
public:
    string number;          // Course number (e.g., "CS101")
    string title;           // Course title (e.g., "Intro to Programming")
    vector<string> prerequisites; // List of prerequisite course numbers

    // Default constructor
    Course() {}

    // Constructor that initializes a course with a given number and title
    Course(string num, string tit) : number(num), title(tit) {}
};

// Function to load course data from a file into the hash table (unordered_map)
void LoadDataFromFile(const string& fileName, unordered_map<string, Course>& courses) {
    ifstream file(fileName);  // Open the input file
    // Check if the file could not be opened
    if (!file.is_open()) {
        cout << "Error: File could not be opened." << endl;
        return;
    }

    string line;
    // Read the file line by line
    while (getline(file, line)) {
        stringstream ss(line);         // Create a stringstream for the current line
        string courseNumber, courseTitle, prerequisite;
        vector<string> prerequisites;  // Vector to hold any prerequisites

        // Extract the course number and title from the current line
        getline(ss, courseNumber, ',');
        getline(ss, courseTitle, ',');

        // Extract all prerequisites (if they exist) and add them to the vector
        while (getline(ss, prerequisite, ',')) {
            prerequisites.push_back(prerequisite);
        }

        // Create a Course object with the course number and title
        Course course(courseNumber, courseTitle);
        // Assign the prerequisites to the course
        course.prerequisites = prerequisites;

        // Insert the course into the hash table using the course number as the key
        courses[courseNumber] = course;
    }

    file.close();  // Close the file after reading
    cout << "Data loaded successfully." << endl;
}

// Function to print all courses in alphanumeric order
void PrintAllCourses(const unordered_map<string, Course>& courses) {
    vector<string> courseNumbers;  // Vector to hold all course numbers

    // Loop through the hash table and collect all course numbers
    for (const auto& pair : courses) {
        courseNumbers.push_back(pair.first);
    }

    // Sort the course numbers in alphanumeric order
    sort(courseNumbers.begin(), courseNumbers.end());

    // Print each course in sorted order
    for (const string& courseNumber : courseNumbers) {
        // Print the course number and title
        cout << courseNumber << ", " << courses.at(courseNumber).title << endl;
    }
}

// Function to search for a specific course and display its details
void SearchCourse(const unordered_map<string, Course>& courses, const string& courseNumber) {
    auto it = courses.find(courseNumber);  // Search for the course in the hash table
    // Check if the course is found
    if (it != courses.end()) {
        // Print the course number and title
        cout << "Course Number: " << it->second.number << endl;
        cout << "Course Title: " << it->second.title << endl;

        // Check if the course has prerequisites
        if (!it->second.prerequisites.empty()) {
            cout << "Prerequisites: ";
            // Print all prerequisites for the course
            for (const string& prereq : it->second.prerequisites) {
                cout << prereq << " ";
            }
            cout << endl;
        }
        else {
            cout << "No prerequisites" << endl;  // If no prerequisites, indicate that
        }
    }
    else {
        cout << "Course not found." << endl;  // Course not found in the hash table
    }
}

// Function to display the main menu for the program
void Menu() {
    unordered_map<string, Course> courses;  // Hash table to store all courses
    bool isDataLoaded = false;              // Flag to track if data has been loaded

    int choice = 0;  // Variable to store the user's menu choice
    string fileName = "CS 300 ABCU_Advising_Program_Input.csv";  // Default file name to load data from

    // Main menu loop; exits when choice == 9
    while (choice != 9) {
        // Display the menu options to the user
        cout << "1. Load the file data into the data structure" << endl;
        cout << "2. Print an alphanumeric list of all the courses" << endl;
        cout << "3. Print the course title and prerequisites for a specific course" << endl;
        cout << "9. Exit the program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;  // Get the user's choice

        switch (choice) {
        case 1:
            // Load the file data into the hash table
            LoadDataFromFile(fileName, courses);
            isDataLoaded = true;  // Mark that data has been loaded
            break;
        case 2:
            // Print all courses if data has been loaded, otherwise prompt the user
            if (isDataLoaded) {
                PrintAllCourses(courses);
            }
            else {
                cout << "Please load the data first using option 1." << endl;
            }
            break;
        case 3:
            // Search for a specific course if data has been loaded, otherwise prompt the user
            if (isDataLoaded) {
                cout << "Enter course number to search: ";
                string courseNumber;
                cin >> courseNumber;  // Get the course number to search for
                SearchCourse(courses, courseNumber);  // Search and display course info
            }
            else {
                cout << "Please load the data first using option 1." << endl;
            }
            break;
        case 9:
            cout << "Exiting the program." << endl;  // Exit the program
            break;
        default:
            cout << "Invalid option. Please choose a valid option." << endl;  // Invalid input
        }
    }
}

// Main function where program execution starts
int main() {
    Menu();  // Start the menu function
    return 0;  // End of program
}

