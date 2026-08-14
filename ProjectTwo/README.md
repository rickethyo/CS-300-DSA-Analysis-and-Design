# ABCU Advising Assistance Program

## Overview

This project is a C++ command-line application developed for ABCU academic advisors. The program reads course information from a CSV file and stores the course data in a binary search tree. Users can display the complete course list in alphanumeric order or search for an individual course to view its title and prerequisite information.

The binary search tree was selected based on the analysis completed in Project One. It provides efficient course lookup while also allowing the complete course list to be displayed in order through an in-order traversal.

## Features

* Loads course information from a user-input CSV file
* Stores course objects in a binary search tree
* Validates prerequisite course numbers before loading data
* Displays courses in alphanumeric order
* Displays the number of prerequisites associated with each course
* Searches for individual courses by course number
* Displays prerequisite course numbers and titles
* Accepts lowercase or uppercase course-number input
* Handles missing files, malformed course data, and invalid menu input
* Removes leading and trailing whitespace from imported course data
* Prevents duplicate course numbers from creating duplicate tree nodes

## Menu Options

The application provides the following menu:

1. **Load Data Structure**
   Loads and validates course data from a CSV file.

2. **Print Course List**
   Displays all loaded courses in alphanumeric order, including count of prerequisites, if applicable. 

3. **Print Course**
   Searches for a course and displays its title and prerequisite information.

4. **Exit**
   Closes the application.

## Data Structure

Course information is stored using a binary search tree with the course number as the key. Courses with lower course numbers are stored in the left subtree, while courses with higher course numbers are stored in the right subtree.

An in-order traversal visits the left subtree, current node, and right subtree. This allows the program to display the complete course catalog in alphanumeric order without requiring a separate sorting operation.

Each course contains:

* Course number
* Course title
* A vector containing zero or more prerequisite course numbers

## Input File Format

Each course should appear on a separate line of a CSV file using the following format:

```text
CourseNumber,CourseTitle,Prerequisite1,Prerequisite2,Prerequisite3,...
```

Example:

```text
CSCI200,Data Structures,CSCI101
CSCI300,Introduction to Algorithms,CSCI200,MATH201,CSCI150
MATH201,Discrete Mathematics
```

Courses may contain zero or more prerequisites.

## Running the Program

Compile and run `ProjectTwo.cpp` in a C++ development environment.

When the program starts:

1. Select **1** to load course data.
2. Enter the name of the CSV file containing the course information.
3. Select **2** to display the complete course list.
4. Select **3** to search for an individual course.
5. Select **9** to exit the program.

The course data must be successfully loaded before Options 2 or 3 can be used. Otherwise an error message will result. 

## Project Files

* `ProjectTwo.cpp` - Complete C++ source code for the advising assistance program
* `CS 300 ABCU_Advising_Program_Input.csv` - ABCU course data provided by SNHU.
* `README.md` - This file, providing an overview of the project, features, and instructions for use.
* `Test.csv` - Test CSV file I expanded to 250 courses with random prerequisites for stress testing the program with various course data beyond the provided ABCU course data.

## Author

Ricky G. Buchanan Jr.
CS-300 Data Structures and Algorithms
Southern New Hampshire University
08-16-2026
