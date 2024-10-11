#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    // Constructor to initialize the task
    Task(std::string desc) : description(desc), completed(false) {}
};

// Function declarations
void addTask(std::vector<Task>& tasks);
void viewTasks(const std::vector<Task>& tasks);
void markTaskCompleted(std::vector<Task>& tasks);
void removeTask(std::vector<Task>& tasks);

int main() {
    std::vector<Task> tasks;  // Vector to store tasks
    int choice;

    do {
        // Display menu
        std::cout << "\n--- TO-DO LIST MANAGER ---\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  // Ignore newline character left in the buffer

        // Handle user's choice
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting the program...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to add a task to the list
void addTask(std::vector<Task>& tasks) {
    std::string taskDescription;
    std::cout << "Enter the task description: ";
    std::getline(std::cin, taskDescription);
    tasks.push_back(Task(taskDescription));  // Add task to the vector
    std::cout << "Task added successfully!\n";
}

// Function to view all tasks with their status
void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
        return;
    }

    std::cout << "\n--- YOUR TASKS ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description
                  << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

// Function to mark a task as completed
void markTaskCompleted(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to mark as completed.\n";
        return;
    }

    int taskNumber;
    viewTasks(tasks);  // Show current tasks

    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed!\n";
    } else {
        std::cout << "Invalid task number!\n";
    }
}

// Function to remove a task from the list
void removeTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to remove.\n";
        return;
    }

    int taskNumber;
    viewTasks(tasks);  // Show current tasks

    std::cout << "Enter the task number to remove: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + (taskNumber - 1));  // Remove task from the vector
        std::cout << "Task removed successfully!\n";
    } else {
        std::cout << "Invalid task number!\n";
    }
}

