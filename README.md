# Chapter06_ExpenseTracker

An expense tracking application written in C++.

## 📋 Overview

This is an expense tracker application developed in C++ as part of Chapter 6 learning exercises. The project demonstrates financial data management, reporting, and analysis concepts through a practical personal expense tracking system.

## 🛠️ Technology Stack

- **Language**: C++
- **Build System**: CMake (recommended)

## 🚀 Getting Started

### Prerequisites

- C++ compiler (C++11 or later)
- CMake 3.10 or higher (optional, but recommended)

### Building the Project

#### Using CMake (Recommended)

```bash
# Clone the repository
git clone https://github.com/liewvk/Chapter06_ExpenseTracker.git
cd Chapter06_ExpenseTracker

# Create a build directory
mkdir build
cd build

# Generate build files and compile
cmake ..
make
```

#### Using Direct Compilation

```bash
# Navigate to the project directory
cd Chapter06_ExpenseTracker

# Compile all source files
g++ -std=c++11 -o ExpenseTracker src/*.cpp
```

### Running the Application

```bash
./ExpenseTracker
```

## 📁 Project Structure

The project is organized as follows:

```
Chapter06_ExpenseTracker/
├── CMakeLists.txt          # CMake configuration file
├── src/                    # Source implementation files (.cpp)
├── include/                # Header files (.h)
├── data/                   # Data files (if applicable)
└── README.md               # This file
```

## ✨ Features

- **Expense Recording**: Add and track daily expenses
- **Category Management**: Organize expenses by categories
- **Budget Tracking**: Set and monitor budget limits
- **Expense Reports**: Generate detailed expense summaries
- **Date Filtering**: View expenses by date range
- **Data Persistence**: Save and load expense records from files
- **Statistical Analysis**: Calculate totals, averages, and trends
- **Currency Support**: Track expenses in different currencies

## 📝 Usage

### Basic Operations

The application supports the following operations:

1. **Add Expense**: Record a new expense with amount, category, and date
2. **View Expenses**: Display all or filtered expenses
3. **List Categories**: View all expense categories
4. **Generate Reports**: Create expense summaries and statistics
5. **Budget Management**: Set and update budget limits
6. **Search Expenses**: Find expenses by category or date range
7. **Delete Expense**: Remove expense records
8. **Save/Load**: Persist expense data to and from files

## 📚 Key Concepts Demonstrated

- Classes and Objects
- File I/O Operations
- Dynamic Memory Management
- Data Structures (Vectors, Maps)
- String Manipulation
- Input Validation
- Decimal Number Handling
- Date and Time Management
- Data Analysis and Aggregation

## 🎯 Learning Objectives

By working through this project, you will learn:

- How to design and implement a financial tracking system
- Techniques for organizing data by categories
- Methods for generating reports and statistics
- How to handle currency and decimal values accurately
- File I/O for data persistence
- User input validation for financial data

## 💡 Example Workflow

```
1. Start the application
2. Add expense: "Lunch - $15.50 - Food"
3. Add expense: "Gas - $45.00 - Transportation"
4. View all expenses
5. Generate monthly report
6. Set budget for each category
7. Check if over budget
8. Save data
```

## 📝 License

This project is currently unlicensed. Please refer to the repository for any licensing information.

## 👤 Author

[liewvk](https://github.com/liewvk)

## 🤝 Contributing

Contributions are welcome! Feel free to fork this repository and submit pull requests with improvements or additional features.

---

**Last Updated**: July 6, 2026
