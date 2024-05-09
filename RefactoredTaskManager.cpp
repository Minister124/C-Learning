#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Enum for task categories
enum class Categories {
    Work,
    Personal,
    Shopping,
};

// Task class
class Task {
public:
    string description;
    bool completed;
    Categories category;

    // Constructor
    Task(const string& desc, Categories cat) : description(desc), category(cat), completed(false) {}
};

// TaskManager class
class TaskManager {
protected:
    vector<Task> taskList;

public:
    // Method to add a task
    void addTask(const Task& task) {
        taskList.push_back(task);
        cout << "\nTask Added Successfully!!!!" << endl;
    }

    // Method to view tasks by category
    void viewTasksByCategory(Categories category) {
        cout << "\nTasks in Category: ";
        switch (category) {
            case Categories::Work:
                cout << "Work" << endl;
                break;
            case Categories::Personal:
                cout << "Personal" << endl;
                break;
            case Categories::Shopping:
                cout << "Shopping" << endl;
                break;
        }

        bool found = false;
        for (const auto& task : taskList) {
            if (task.category == category) {
                found = true;
                cout << "Description: " << task.description << " ";
                if (task.completed)
                    cout << "[Y]" << endl;
                else
                    cout << "[X]" << endl;
            }
        }

        if (!found)
            cout << "No tasks in this category." << endl;
    }

    // Method to mark a task as complete
    virtual void markTaskComplete() = 0;

    // Method to mark a task as incomplete
    virtual void markTaskIncomplete() = 0;

    // Method to delete a task
    void deleteTask(int index) {
        if (index >= 0 && index < taskList.size()) {
            taskList.erase(taskList.begin() + index);
            cout << "Task Deleted Successfully!!!!" << endl;
        } else {
            cout << "Invalid Task Number!!!" << endl;
        }
    }
};

// Derived class for interaction with task completion
class InteractiveTaskManager : public TaskManager {
public:
    // Method to mark a task as complete with interaction
    void markTaskComplete() override {
        int index;
        cout << "\nEnter the number of the task you want to mark as complete (Type '0' to Exit): ";
        cin >> index;

        if (index == 0) return;
        index--;

        if (index >= 0 && index < taskList.size()) {
            Categories category = taskList[index].category;
            viewTasksByCategory(category);

            cout << "\nEnter the number of the task to mark as complete (Type '0' to go back): ";
            cin >> index;
            if (index == 0) return;
            index--;

            if (index >= 0 && index < taskList.size() && taskList[index].category == category) {
                taskList[index].completed = true;
                cout << "Task Marked as Completed!!!" << endl;
            } else {
                cout << "Invalid Task Number or Category!!!" << endl;
            }
        } else {
            cout << "Invalid Task Number!!!" << endl;
        }
    }

    // Method to mark a task as incomplete with interaction
    void markTaskIncomplete() override {
        int index;
        cout << "\nEnter the number of the task you want to mark as incomplete (Type '0' to Exit): ";
        cin >> index;

        if (index == 0) return;
        index--;

        if (index >= 0 && index < taskList.size()) {
            Categories category = taskList[index].category;
            viewTasksByCategory(category);

            cout << "\nEnter the number of the task to mark as incomplete (Type '0' to go back): ";
            cin >> index;
            if (index == 0) return;
            index--;

            if (index >= 0 && index < taskList.size() && taskList[index].category == category) {
                taskList[index].completed = false;
                cout << "Task Marked as Incomplete!!!" << endl;
            } else {
                cout << "Invalid Task Number or Category!!!" << endl;
            }
        } else {
            cout << "Invalid Task Number!!!" << endl;
        }
    }
};

int main() {
    InteractiveTaskManager taskManager;

    int choice;
    do {
        cout << "\nTask Manager Menu: " << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Task By Category" << endl;
        cout << "3. Mark Task Complete" << endl;
        cout << "4. Mark Task Incomplete" << endl;
        cout << "5. Delete Task" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 0:
                cout << "Exiting Task Manager Console" << endl;
                break;
            case 1: {
                string description;
                int categoryChoice;
                cout << "Enter The Task Description: ";
                getline(cin, description);
                cout << "Select Task Category: " << endl;
                cout << "1. Work" << endl;
                cout << "2. Personal" << endl;
                cout << "3. Shopping" << endl;
                cout << "Enter Your Choice: ";
                cin >> categoryChoice;
                cin.ignore();
                if (categoryChoice >= 1 && categoryChoice <= 3) {
                    taskManager.addTask(Task(description, static_cast<Categories>(categoryChoice - 1)));
                } else {
                    cout << "Invalid Choice!!!" << endl;
                }
                break;
            }
            case 2: {
                int categoryChoice;
                cout << "Select Category: " << endl;
                cout << "1. Work" << endl;
                cout << "2. Personal" << endl;
                cout << "3. Shopping" << endl;
                cout << "Enter Your Choice: ";
                cin >> categoryChoice;
                cin.ignore();
                if (categoryChoice >= 1 && categoryChoice <= 3) {
                    taskManager.viewTasksByCategory(static_cast<Categories>(categoryChoice - 1));
                } else {
                    cout << "Invalid Choice!!!" << endl;
                }
                break;
            }
            case 3:
                taskManager.markTaskComplete();
                break;
            case 4:
                taskManager.markTaskIncomplete();
                break;
            case 5: {
                int taskIndex;
                cout << "Enter The Task Number You Want to Delete: ";
                cin >> taskIndex;
                cin.ignore();
                taskManager.deleteTask(taskIndex - 1);
                break;
            }
            default:
                cout << "Invalid Choice!!!" << endl;
        }
    } while (choice != 0);

    return 0;
}
