/**
 * Project Two: ABCU Advising Assistance Program
 *
 * Module 7 Submission
 * Name: Ricky G. Buchanan Jr.
 * Course: CS-300 DSA
 * Instructor: Jayantha Muthukudage
 * Southern New Hampshire University
 * Date: 08/16/2026
 *
 * This program loads course information for ABCU and stores the
 * course data in a binary search tree. Users can display courses
 * in alphanumeric order or search for an individual course and
 * view its prerequisite information. 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <limits>

using namespace std;

/**
 * Structure to hold course information
 */
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

/**
 * Node structure for the binary search tree
 */
struct Node {
    Course course;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }

    Node(Course aCourse) {
        course = aCourse;
        left = nullptr;
        right = nullptr;
    }
};


/**
 * Binary search tree used to store courses
 */
class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Course course);
    void inOrder(Node* node);
    void destroyTree(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void Insert(Course course);
    Course Search(string courseNumber);
    void InOrder();
    void Clear();
};


/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}


/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    Clear();
}


/**
 * Insert a course into the tree
 */
void BinarySearchTree::Insert(Course course) {
    // Insert course into binary search tree
    // If tree is empty, new course becomes the root
    if (root == nullptr) {
        root = new Node(course);
    }
    else {
        addNode(root, course);
    }
}


/**
 * Recursively add a course to the correct tree location
 */
void BinarySearchTree::addNode(Node* node, Course course) {
    // Compare course numbers and insert left or right
	// Add course to left subtree if course number is less than current node's course number
	if (course.courseNumber < node->course.courseNumber) {
		if (node->left == nullptr) {
			node->left = new Node(course);
		}
        // Continue searching the left subtree
		else {
			addNode(node->left, course);
		}
	}
	// Add course to right subtree if course number is greater than current node's course number
	else if (course.courseNumber > node->course.courseNumber) {
		if (node->right == nullptr) {
			node->right = new Node(course);
		}
        // Continue searching the right subtree
		else {
			addNode(node->right, course);
		}
	}
    // Replace course if course number already exists
    else {
        node->course = course;
    }
}


/**
 * Search for a course using its course number
 */
Course BinarySearchTree::Search(string courseNumber) {
    // Search the binary search tree

	Node* current = root;

	while (current != nullptr) {
		if (courseNumber == current->course.courseNumber) {
			return current->course;
		}
		else if (courseNumber < current->course.courseNumber) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
    // Return an empty course if no match is found
    Course course;
    return course;
}


/**
 * Begin an in-order traversal
 */
void BinarySearchTree::InOrder() {
    // Call recursive in-order traversal
	inOrder(root);
}


/**
 * Print courses in alphanumeric order
 */
void BinarySearchTree::inOrder(Node* node) {
    // Traverse left, print course, traverse right
	if (node != nullptr) {
        // Visit left subtree
		inOrder(node->left);

        // Print current course
        if (!node->course.prerequisites.empty()) {
            cout << node->course.courseNumber << ", "
                 << node->course.courseTitle
                 << " (" << node->course.prerequisites.size()
                 << (node->course.prerequisites.size() == 1
                    ? " Prerequisite)"
                    : " Prerequisites)")
                 << endl;
        }
        else {
            cout << node->course.courseNumber << ", "
                << node->course.courseTitle
                << endl;
        }

        // Visit right subtree
		inOrder(node->right);
	}
}


/**
 * Remove all courses from the tree
 */
void BinarySearchTree::Clear() {
    destroyTree(root);
    root = nullptr;
}


/**
 * Recursively delete nodes
 */
void BinarySearchTree::destroyTree(Node* node) {
    // Delete left and right subtrees, then current node

	if (node != nullptr) {
        // Delete left and right subtrees first
		destroyTree(node->left);
		destroyTree(node->right);
        // Delete current node
		delete node;
	}
}


/**
 * Convert user-entered course numbers to uppercase
 */
string ToUpper(string value) {

    for (char& character : value) {
        character = toupper(character);
    }

    return value;
}

/**
 * Remove leading and trailing whitespace from a string
 */
string Trim(string value) {

    // Remove whitespace from the beginning
    while (!value.empty() &&
        isspace(static_cast<unsigned char>(value.front()))) {
        value.erase(value.begin());
    }

    // Remove whitespace from the end
    while (!value.empty() &&
        isspace(static_cast<unsigned char>(value.back()))) {
        value.pop_back();
    }

    return value;
}


/**
 * Validate that all prerequisite course numbers exist
 */
bool ValidatePrerequisites(const vector<Course>& courses) {
    // Check every prerequisite against loaded courses
    // Check each course in the vector

	for (const Course& course : courses) {
		// Check each prerequisite for the current course
		for (const string& prereq : course.prerequisites) {
			bool found = false;
			// Search through the list of courses to find the prerequisite
			for (const Course& c : courses) {
				if (c.courseNumber == prereq) {
					found = true;
					break;
				}
			}
			// If a prerequisite is not found, return false
			if (!found) {
				cout << "Error: Prerequisite " << prereq << " for course " << course.courseNumber << " does not exist." << endl;
				return false;
			}
		}
	}

    return true;
}


/**
 * Load courses from a user-specified file
 */
bool LoadCourses(string fileName, BinarySearchTree& courseTree) {

    vector<Course> courses;

    // Open the file
    ifstream file(fileName);

	if (!file.is_open()) {
		cout << "Error: Could not open file " << fileName << endl;
		return false;
	}

    string line;

    // Read each line
	while (getline(file, line)) {

		// Process each line to extract course information
		// Split the line into course number, title, and prerequisites
		stringstream ss(line);
		string courseNumber, courseTitle, prereq;
		vector<string> prerequisites;

        // Read course number and title
        if (!getline(ss, courseNumber, ',') ||
            !getline(ss, courseTitle, ',') ||
            courseNumber.empty() ||
            courseTitle.empty()) {

            cout << "Error: Invalid file format." << endl;
            file.close();
            return false;
        }

		// Remove leading and trailing whitespace from course number and title
		courseNumber = Trim(courseNumber);
		courseTitle = Trim(courseTitle);

		// Verify required fields are not empty
		if (courseNumber.empty() || courseTitle.empty()) {
			cout << "Error: Course number or title is missing." << endl;
			file.close();
			return false;
		}

		// Read prerequisites
		while (getline(ss, prereq, ',')) {
            prereq = Trim(prereq);

            if (!prereq.empty()) {
                prerequisites.push_back(ToUpper(prereq));
            }
		}

		// Create a Course object and add it to the courses vector
		Course course;
		course.courseNumber = ToUpper(courseNumber);
		course.courseTitle = courseTitle;
		course.prerequisites = prerequisites;
		courses.push_back(course);
	}

    // Verify the file contained course data
	if (courses.empty()) {
		cout << "Error: No course data found in file." << endl;
		file.close();
		return false;
	}


    // Validate prerequisite course numbers
    if (!ValidatePrerequisites(courses)) {
        file.close();
        return false;
    }

    // Insert validated courses into the BST
	for (const Course& course : courses) {
		courseTree.Insert(course);
	}
    file.close();
    return true;
}


/**
 * Print information for an individual course
 */
void PrintCourseInformation(BinarySearchTree& courseTree,
    string courseNumber) {

    // Search for course
    Course course = courseTree.Search(courseNumber);

		// Check if course was found
		if (course.courseNumber.empty()) {
			cout << "Course " << courseNumber << " not found." << endl;
			return;
		}

    // Print course number and title
	cout << "Course Number: " << course.courseNumber << endl;
	cout << "Course Title: " << course.courseTitle << endl;

    // Search for and print prerequisite numbers and titles
	if (course.prerequisites.empty()) {
		// No Prerequisites found for this course
		cout << "Prerequisites (0): None" << endl;
	}
	// Print prerequisites if they exist
	else {
		cout << "Prerequisites (" << course.prerequisites.size() << "):" << endl;
		for (const string& prereqNumber : course.prerequisites) {
			Course prereqCourse = courseTree.Search(prereqNumber);
			if (!prereqCourse.courseNumber.empty()) {
				cout << "  " << prereqCourse.courseNumber << ", " << prereqCourse.courseTitle << endl;
			}
			else {
				cout << "  " << prereqNumber << ", (Course not found)" << endl;
			}
		}
	}
}


/**
 * Main program
 */
int main() {

    BinarySearchTree courseTree;

    bool dataLoaded = false;
    int choice = 0;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {

        cout << endl;
        cout << "1. Load Data Structure" << endl;
        cout << "2. Print Course List" << endl;
        cout << "3. Print Course" << endl;
        cout << "9. Exit" << endl;
        cout << endl;

        cout << "What would you like to do? ";
		if (!(cin >> choice)) {
			cout << "Non-Integer input detected: Please enter a number from the provided list." << endl;
            // Clear the error flag
			cin.clear(); 
            // Discard invalid input
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            // Prompt the user again
			continue; 
		}

        switch (choice) {

        case 1:
        {
            string fileName;

            cout << "Enter the course data .csv file name: ";

            // Use getline to read the entire line including spaces
			getline(cin >> ws, fileName); 

            // Clear previous data and load selected file
            courseTree.Clear();

			if (LoadCourses(fileName, courseTree)) {
				dataLoaded = true;
				cout << "Course data loaded successfully." << endl;
			}
			else {
				dataLoaded = false;
				cout << "Failed to load course data." << endl;
			}

            break;
        }

        case 2:
            // Verify data has been loaded
			if (!dataLoaded) {
				cout << "Error: No course data loaded. Please load data first." << endl;
				break;
			}
            // Print course list using BST in-order traversal
			else {
				cout << "Course List:" << endl;
				courseTree.InOrder();
			}
            
            break;

        case 3:
        {
			// Verify data has been loaded and prompt user for course number for additional information
			if (!dataLoaded) {
				cout << "Error: No course data loaded. Please load data first." << endl;
				break;
			}

            string courseNumber;

            cout << "What course do you want to know about? ";
            cin >> courseNumber;

            courseNumber = ToUpper(courseNumber);

            // Print requested course information
			PrintCourseInformation(courseTree, courseNumber);

            break;
        }

        case 9:
            cout << "Thank you for using the course planner." << endl;
            break;

        default:
            cout << "Invalid option. Please select from the provided list." << endl;
            break;
        }
    }

    return 0;
}