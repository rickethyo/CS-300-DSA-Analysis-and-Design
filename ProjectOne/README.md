# Project One: Data Structure Analysis

## Overview

Project One analyzes three data structures for storing and managing course information in the ABCU advising program:

* Vector
* Hash table
* Binary search tree

The project includes pseudocode for each implementation, runtime analysis, and an evaluation of the advantages and disadvantages of each structure. The goal was to determine which data structure would best support course lookup and the requirement to display courses in alphanumeric order.

## Data Structures Evaluated

### Vector

The vector implementation stores course objects sequentially and provides straightforward iteration through the course list. Searching for an individual course may require examining every element, and the vector must be sorted before displaying the complete course list in alphanumeric order.

### Hash Table

The hash table provides efficient average-case lookup when course numbers are used as keys. However, it does not naturally maintain course order, so the courses must be collected and sorted before displaying the complete course list.

### Binary Search Tree

The binary search tree stores courses according to course number. When reasonably balanced, search and insertion operations perform efficiently, while an in-order traversal naturally displays the courses from lowest to highest course number without requiring a separate sorting operation.

## Recommendation

Based on the requirements of the ABCU advising program, I recommended using a **binary search tree**.

The BST provides a good balance between individual course lookup and ordered course display. Its in-order traversal directly supports the requirement to display courses in alphanumeric order, while search performance is approximately O(log n) when the tree remains reasonably balanced.

This recommendation was used as the basis for the implementation completed in Project Two.

## Project Contents

Project One includes:

* Pseudocode for vector, hash table, and binary search tree implementations
* File loading and prerequisite-validation logic
* Menu pseudocode
* Runtime analysis for each data structure
* Advantages and disadvantages of each structure
* Memory considerations
* Final data structure recommendation

## Project Files

* `Project 1.docx` - Complete Project One analysis, including pseudocode, evaluations, runtime analysis, and the final data structure recommendation
* `RuntimeAnalysis.xlsx` - Spreadsheet containing the supporting runtime-analysis calculations and comparisons
* `README.md` - Overview and documentation for Project One

## Author

Ricky G. Buchanan Jr.
CS-300 Data Structures and Algorithms
Southern New Hampshire University
