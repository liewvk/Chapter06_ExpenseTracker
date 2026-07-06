#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>

struct Expense
{
    int id;
    std::string date;
    std::string category;
    std::string description;
    double amount;
};

void displayMenu()
{
    std::cout << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "          Expense Tracker" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "1. Add Expense" << std::endl;
    std::cout << "2. Display All Expenses" << std::endl;
    std::cout << "3. Search Expenses by Category" << std::endl;
    std::cout << "4. Calculate Total Expenses" << std::endl;
    std::cout << "5. Update Expense" << std::endl;
    std::cout << "6. Delete Expense" << std::endl;
    std::cout << "7. Save Expenses to File" << std::endl;
    std::cout << "8. Load Expenses from File" << std::endl;
    std::cout << "9. Export Expenses to CSV" << std::endl;
    std::cout << "10. Exit" << std::endl;
    std::cout << "Please choose an option: ";
}

int generateExpenseId(const std::vector<Expense>& expenses)
{
    int maxId = 0;

    for (const Expense& expense : expenses)
    {
        if (expense.id > maxId)
        {
            maxId = expense.id;
        }
    }

    return maxId + 1;
}

void addExpense(std::vector<Expense>& expenses)
{
    Expense newExpense;

    newExpense.id = generateExpenseId(expenses);

    std::cout << "Enter date (YYYY-MM-DD): ";
    std::getline(std::cin, newExpense.date);

    std::cout << "Enter category: ";
    std::getline(std::cin, newExpense.category);

    std::cout << "Enter description: ";
    std::getline(std::cin, newExpense.description);

    std::cout << "Enter amount: ";
    std::cin >> newExpense.amount;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    expenses.push_back(newExpense);

    std::cout << "Expense added successfully." << std::endl;
}

void displayExpense(const Expense& expense)
{
    std::cout << "Expense ID : " << expense.id << std::endl;
    std::cout << "Date       : " << expense.date << std::endl;
    std::cout << "Category   : " << expense.category << std::endl;
    std::cout << "Description: " << expense.description << std::endl;
    std::cout << "Amount     : " << std::fixed << std::setprecision(2) << expense.amount << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

void displayAllExpenses(const std::vector<Expense>& expenses)
{
    if (expenses.empty())
    {
        std::cout << "No expenses found." << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << "========== All Expenses ==========" << std::endl;

    for (const Expense& expense : expenses)
    {
        displayExpense(expense);
    }
}

void searchExpensesByCategory(const std::vector<Expense>& expenses)
{
    std::string category;
    bool found = false;

    std::cout << "Enter category to search: ";
    std::getline(std::cin, category);

    std::cout << std::endl;
    std::cout << "========== Search Results ==========" << std::endl;

    for (const Expense& expense : expenses)
    {
        if (expense.category == category)
        {
            displayExpense(expense);
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No expenses found for category: " << category << std::endl;
    }
}

double calculateTotalExpenses(const std::vector<Expense>& expenses)
{
    double total = 0.0;

    for (const Expense& expense : expenses)
    {
        total += expense.amount;
    }

    return total;
}

void displayTotalExpenses(const std::vector<Expense>& expenses)
{
    double total = calculateTotalExpenses(expenses);

    std::cout << "Total expenses: "
        << std::fixed << std::setprecision(2)
        << total << std::endl;
}

int findExpenseIndexById(const std::vector<Expense>& expenses, int id)
{
    for (int i = 0; i < static_cast<int>(expenses.size()); ++i)
    {
        if (expenses[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

void updateExpense(std::vector<Expense>& expenses)
{
    int id;

    std::cout << "Enter expense ID to update: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int index = findExpenseIndexById(expenses, id);

    if (index == -1)
    {
        std::cout << "Expense not found." << std::endl;
        return;
    }

    std::cout << "Enter new date (YYYY-MM-DD): ";
    std::getline(std::cin, expenses[index].date);

    std::cout << "Enter new category: ";
    std::getline(std::cin, expenses[index].category);

    std::cout << "Enter new description: ";
    std::getline(std::cin, expenses[index].description);

    std::cout << "Enter new amount: ";
    std::cin >> expenses[index].amount;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Expense updated successfully." << std::endl;
}

void deleteExpense(std::vector<Expense>& expenses)
{
    int id;

    std::cout << "Enter expense ID to delete: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int index = findExpenseIndexById(expenses, id);

    if (index == -1)
    {
        std::cout << "Expense not found." << std::endl;
        return;
    }

    expenses.erase(expenses.begin() + index);

    std::cout << "Expense deleted successfully." << std::endl;
}

void saveExpensesToFile(const std::vector<Expense>& expenses, const std::string& filename)
{
    std::ofstream file(filename);

    if (!file)
    {
        std::cout << "Error: Could not open file for writing." << std::endl;
        return;
    }

    for (const Expense& expense : expenses)
    {
        file << expense.id << "|"
            << expense.date << "|"
            << expense.category << "|"
            << expense.description << "|"
            << expense.amount << std::endl;
    }

    file.close();

    std::cout << "Expenses saved successfully." << std::endl;
}

void loadExpensesFromFile(std::vector<Expense>& expenses, const std::string& filename)
{
    std::ifstream file(filename);

    if (!file)
    {
        std::cout << "No existing expense file found. Starting with an empty expense list." << std::endl;
        return;
    }

    expenses.clear();

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string idText;
        std::string amountText;
        Expense expense;

        std::getline(ss, idText, '|');
        std::getline(ss, expense.date, '|');
        std::getline(ss, expense.category, '|');
        std::getline(ss, expense.description, '|');
        std::getline(ss, amountText, '|');

        expense.id = std::stoi(idText);
        expense.amount = std::stod(amountText);

        expenses.push_back(expense);
    }

    file.close();

    std::cout << "Expenses loaded successfully." << std::endl;
}

std::string formatCsvText(const std::string& text)
{
    std::string result = "\"";

    for (char ch : text)
    {
        if (ch == '"')
        {
            result += "\"\"";
        }
        else
        {
            result += ch;
        }
    }

    result += "\"";

    return result;
}

void exportExpensesToCsv(const std::vector<Expense>& expenses, const std::string& filename)
{
    std::ofstream file(filename);

    if (!file)
    {
        std::cout << "Error: Could not open CSV file for writing." << std::endl;
        return;
    }

    file << "ID,Date,Category,Description,Amount" << std::endl;

    for (const Expense& expense : expenses)
    {
        file << expense.id << ","
            << formatCsvText(expense.date) << ","
            << formatCsvText(expense.category) << ","
            << formatCsvText(expense.description) << ","
            << std::fixed << std::setprecision(2) << expense.amount
            << std::endl;
    }

    file.close();

    std::cout << "Expenses exported to CSV successfully." << std::endl;
}

int main()
{
    std::vector<Expense> expenses;
    const std::string dataFile = "expenses.txt";
    const std::string csvFile = "expenses.csv";
    int choice;

    loadExpensesFromFile(expenses, dataFile);

    while (true)
    {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            addExpense(expenses);
            break;

        case 2:
            displayAllExpenses(expenses);
            break;

        case 3:
            searchExpensesByCategory(expenses);
            break;

        case 4:
            displayTotalExpenses(expenses);
            break;

        case 5:
            updateExpense(expenses);
            break;

        case 6:
            deleteExpense(expenses);
            break;

        case 7:
            saveExpensesToFile(expenses, dataFile);
            break;

        case 8:
            loadExpensesFromFile(expenses, dataFile);
            break;

        case 9:
            exportExpensesToCsv(expenses, csvFile);
            break;

        case 10:
            saveExpensesToFile(expenses, dataFile);
            std::cout << "Thank you for using the Expense Tracker." << std::endl;
            return 0;

        default:
            std::cout << "Invalid option. Please choose again." << std::endl;
        }
    }
}
