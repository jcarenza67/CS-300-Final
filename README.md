# CS 300 Portfolio Submission

## Project Overview
This repository contains key portions of my work from **CS 300 - Data Structures & Algorithms**. The submissions demonstrate my understanding of data structures, algorithm efficiency, and best practices in software development.

### Included Files
- **Project One Analysis**: Runtime and memory analysis of different data structures.
- **Project Two Code**: Implementation of sorting and printing a list of Computer Science courses in alphanumeric order.

## Reflection

### **What was the problem you were solving in the projects for this course?**
The primary problem involved designing an efficient system for storing and retrieving Computer Science course information. The system needed to:
- Read and parse a CSV file containing course details.
- Store the data in an appropriate data structure.
- Allow users to search for courses and display prerequisites.
- Sort and print all courses in **alphanumeric order** efficiently.

### **How did you approach the problem?**
Understanding **data structures** was crucial to designing an optimal solution. I evaluated three different structures—**vector, hash table, and binary search tree (BST)**—by analyzing their runtime complexity for insertion, searching, and sorting. Based on the analysis, I selected a **hash table** for efficient lookup operations while implementing sorting separately when required.

### **How did you overcome any roadblocks you encountered?**
Throughout the project, I encountered several challenges, including:
- **Parsing CSV data efficiently:** I initially considered using `cin`, but I explored `stringstream`, which provided a cleaner approach.
- **Sorting data stored in a hash table:** Since hash tables do not maintain order, I extracted the keys, sorted them separately, and printed the results.
- **Understanding C++ best practices:** I refined my approach by improving code readability, using proper commenting, and handling user input validation.

### **How has your work on this project expanded your approach to designing software and developing programs?**
This project reinforced the importance of **choosing the right data structures** based on the problem at hand. I gained a deeper understanding of **algorithmic efficiency** and how to optimize code for **performance and readability**. Additionally, implementing a menu-driven system improved my approach to user interaction and program flow.

### **How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?**
I now prioritize **clean code, modular functions, and inline documentation**. By structuring my program in a way that separates logic (e.g., data storage, sorting, and searching), I made it easier to maintain and adapt in the future. Using **consistent naming conventions, meaningful comments, and structured input handling** ensures that my code remains readable for others (and for myself in the future).

---
**Author:** Joseph Wilfong  
**Date:** 02/24/2025
