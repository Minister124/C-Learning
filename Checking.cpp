#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Categories {
    Work,
    Personal,
    Shopping,
    Cooking,
};

struct TaskSchema{
    string description;
    bool isCompleted;
    Categories category;
};

void addTask(vector<TaskSchema>& tasks){
    while (true)
    {
        TaskSchema newTask;
        cout << "Enter task description (Type 'Exit' To Stop): ";
        getline(cin, newTask.description);
        if (newTask.description == "Exit") break;
        cout << "Choose Category From The Category List: ";
        cout << "1. Work" << endl;
        cout << "2. Personal" << endl;
        cout << "3. Shopping" << endl;
        cout << "4. Cooking" << endl;
        int category;
        cin >> category;
        cin.ignore();
        switch (category)
        {
        case 1:
            newTask.category = Categories::Work;
            break;
        case 2:
            newTask.category = Categories::Personal;
            break;
        case 3:
            newTask.category = Categories::Shopping;
            break;
        case 4:
            newTask.category = Categories::Cooking;
            break;
        default:
            cout << "Invalid category!!!. Selecting Personal By Default" << endl;
            newTask.category = Categories::Personal;
            break;
        }
        newTask.isCompleted = false;
        size_t initialSize = tasks.size();
        tasks.push_back(newTask);
        if(tasks.size() > initialSize){
            cout << "Task Added Successfully!!!" << endl;
        }else{
            cout << "Failed To Add Task!!!" << endl;
        }
        cout << endl;
    }
}

void viewTask(const vector<TaskSchema>& tasks, Categories category){
    cout << endl;
    for (size_t i = 0; i < tasks.size(); i++)
    {
        if(tasks[i].category == category){
            cout << i+1 << ". " << tasks[i].description << endl;
        }
    }
    cout << endl;
}

int main(){
    vector<TaskSchema> tasks;
    return 0;
    int choice;
    do{
        cout << "Task Manager Menu: " << endl;
        cout << "\n1. Add Task" << endl;
        cout << "2. View Task" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice){
            case 1:
                addTask(tasks);
                break;
            case 2:
                cout << "Select Catagories" << endl;
                cout << "1. Work" << endl;
                cout << "2. Personal" << endl;
                cout << "3. Shopping" << endl;
                cout << "4. Cooking" << endl;
                int category;
                cin >> category;
                cin.ignore();
                switch (category)
                {
                    case 1:
                        viewTask(tasks, Categories::Work);
                        break;
                    case 2:
                        viewTask(tasks, Categories::Personal);
                        break;
                    case 3:
                        viewTask(tasks, Categories::Shopping);
                        break;
                    case 4:
                        viewTask(tasks, Categories::Cooking);
                        break;
                    default:
                        cout << "Invalid Input!!. Selecting Personal By Default" << endl;
                        viewTask(tasks, Categories::Personal);
                        break;
                }
            case 3:
                cout << "Exiting Task Manager!!!!!!!!......" << endl;
                break;
            default:
                cout << "Invalid Input!!!" << endl;
                break;
        }
    }while (choice >= 0 && choice <= 3);
    return 0;
}