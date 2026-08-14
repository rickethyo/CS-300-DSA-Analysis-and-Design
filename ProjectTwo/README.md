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

9. **Exit**
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

## Reflection

### What problem were you solving in the projects for this course?

The primary problem was determining how to efficiently store, search, and display course information for an academic advising program. Project One focused on analyzing vectors, hash tables, and binary search trees to determine which structure best supported the requirements. Project Two then used that analysis to build a working advising program that loads course data, displays the complete course list in alphanumeric order, and allows an advisor to look up an individual course and its prerequisites.

### How did you approach the problem?

I approached the problem by first considering what operations the program needed to perform most often. A vector was simple and efficient for sequential access, while a hash table provided fast average lookup performance. However, neither structure naturally produced the complete course list in alphanumeric order. I ultimately recommended a binary search tree because it provided a good balance between course lookup and ordered output. An in-order traversal of the tree naturally produces the course numbers from lowest to highest without requiring a separate sorting operation.

This project reinforced the importance of understanding data structures. Two structures may both store the same information. However, the way the information is accessed and processed can make one structure much better suited to a particular problem.

### How did you overcome roadblocks?

Several roadblocks arose during the development and testing of the program. File parsing required accounting for courses with varying numbers of prerequisites, including those with no prerequisites. An early issue occurred when empty prerequisite fields were being treated as actual course numbers, causing valid files to fail prerequisite validation. I corrected the parsing logic so that empty fields are treated properly as having zero prerequisites.

Additional testing identified issues with whitespace in input files and non-integer menu input, which caused an infinite loop. I added trimming for imported values and input-stream error handling so the program could recover rather than enter an infinite loop. I also tested the program with larger course catalogs, duplicate course records, invalid prerequisites, missing files, and malformed data. Working through these issues reinforced the value of testing individual pieces of a program as they are developed rather than waiting until the entire application is finished.

### How has this work expanded your approach to designing software and developing programs?

This project strengthened my approach of analyzing a problem before choosing an implementation. Instead of selecting a data structure simply because it was familiar or easy to use, I compared how each structure would perform against the program's actual requirements. The implementation then followed the design created in Project One.

I also became more aware of the importance of separating responsibilities within a program. File loading, prerequisite validation, tree insertion, searching, traversal, input handling, and display logic were implemented as separate functions or methods. This made the program easier to develop incrementally and to isolate problems during testing. As a result, debugging was significantly easier and faster than in my previous work.

### How has this project evolved the way you write maintainable, readable, and adaptable programs?

Throughout the project, I placed more emphasis on descriptive naming, focused functions, comments, error handling, and consistent program structure. I also built a structure first, using FIXME comments to mark sections to be completed later, rather than building features one by one as I had in the past. This allowed me to get the menu working and the code compiling before building any actual functionality.

The project also demonstrated the value of writing code that handles unexpected input rather than assuming that every user or file will behave exactly as expected. Validation for missing files, malformed course records, invalid prerequisites, whitespace, duplicate courses, and incorrect menu input made the final program more reliable without changing its primary purpose. These practices make the code easier to maintain and provide a stronger foundation for future changes.

## Project Files

* `ProjectTwo.cpp` - Complete C++ source code for the advising assistance program
* `CS 300 ABCU_Advising_Program_Input.csv` - ABCU course data provided by SNHU
* `README.md` - This file, providing an overview of the project, features, instructions for use, and portfolio reflection
* `Test.csv` - Test CSV file I expanded to 250 courses with random prerequisites for stress testing the program with various course data beyond the provided ABCU course data

## Author

Ricky G. Buchanan Jr.
CS-300 Data Structures and Algorithms
Southern New Hampshire University
08-16-2026
