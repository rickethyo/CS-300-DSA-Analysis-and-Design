/**
 * Project Two: ABCU Advising Assistance Program
 *
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
        // Replace course if course number already exists
		else {
			addNode(node->left, course);
		}
	}
	// Add course to right subtree if course number is greater than current node's course number
	else if (course.courseNumber > node->course.courseNumber) {
		if (node->right == nullptr) {
			node->right = new Node(course);
		}
        // Replace course if course number already exists
		else {
			addNode(node->right, course);
		}
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
		cout << node->course.courseNumber << ", " << node->course.courseTitle << endl;
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
 * Validate that all prerequisite course numbers exist
 */
bool ValidatePrerequisites(const vector<Course>& courses) {
    // FIXME (7): Check every prerequisite against loaded courses

    return false;
}


/**
 * Load courses from a user-specified file
 */
bool LoadCourses(string fileName, BinarySearchTree& courseTree) {

    vector<Course> courses;

    // FIXME (8): Open the file

    // FIXME (9): Read each line

    // FIXME (10): Split each line at commas

    // FIXME (11): Create Course objects

    // FIXME (12): Validate prerequisite course numbers

    // FIXME (13): Insert validated courses into the BST

    return false;
}


/**
 * Print information for an individual course
 */
void PrintCourseInformation(BinarySearchTree& courseTree,
    string courseNumber) {

    // FIXME (14): Search for course

    // FIXME (15): Print course number and title

    // FIXME (16): Search for and print prerequisite numbers and titles
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
        cin >> choice;

        switch (choice) {

        case 1:
        {
            string fileName;

            cout << "Enter the course data file name: ";
            cin >> fileName;

            // FIXME (17): Clear previous data and load selected file

            break;
        }

        case 2:
            // FIXME (18): Verify data has been loaded
            // Print course list using BST in-order traversal

            break;

        case 3:
        {
            // FIXME (19): Verify data has been loaded

            string courseNumber;

            cout << "What course do you want to know about? ";
            cin >> courseNumber;

            courseNumber = ToUpper(courseNumber);

            // FIXME (20): Print requested course information

            break;
        }

        case 9:
            cout << "Thank you for using the course planner." << endl;
            break;

        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    return 0;
}