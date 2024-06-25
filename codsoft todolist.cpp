#include <iostream>
#include <vector>
#include <string>

class Task {
private:
    std::string description;

public:
    Task(std::string desc) : description(desc) {}

    std::string getDescription() {
        return description;
    }
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(std::string description) {
        Task newTask(description);
        tasks.push_back(newTask);
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            std::cout << "To-Do List:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].getDescription() << std::endl;
            }
        }
    }

    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
        } else {
            std::cout << "Task removed: " << tasks[index - 1].getDescription() << std::endl;
            tasks.erase(tasks.begin() + index - 1);
        }
    }
};

int main() {
    ToDoList myList;
    int choice;
    std::string taskDesc;
    int taskNum;

    do {
        std::cout << "\n1. Add Task\n2. View Tasks\n3. Remove Task\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore();  
                std::getline(std::cin, taskDesc);
                myList.addTask(taskDesc);
                break;
            case 2:
                myList.viewTasks();
                break;
            case 3:
                std::cout << "Enter task number to remove: ";
                std::cin >> taskNum;
                myList.removeTask(taskNum);
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
