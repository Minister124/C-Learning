#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Catagories{
    Work,
    Personal,
    Shopping,
};

struct TaskSchema{
    string description;
    bool completed;
    Catagories catagory;
};

void addTask(vector<TaskSchema>& listOfTask){
    while (true)
    {
        TaskSchema storeTask;
        cout << "\nEnter The Task Description (Type 'Exit'to Stop): " << flush;
        getline(cin, storeTask.description);
        if(storeTask.description == "Exit") break;
        cout << "\nSelect Task Catagory: " << endl;;
        cout << "\n1. Work " << endl;
        cout << "2. Personal " << endl;
        cout << "3. Shopping " << endl;
        cout << "\nEnter Your Choice: " << flush;
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice>3 && choice<0) break;
        switch (choice)
        {
        case 1:
            storeTask.catagory = Catagories::Work;
            break;
        case 2:
            storeTask.catagory = Catagories::Personal;
            break;
        case 3:
            storeTask.catagory = Catagories::Shopping;
            break;
        default:
            cout << "Invalid choice. Selecting Personal By default." << endl;
            storeTask.catagory = Catagories::Personal;
            break;
        }
        storeTask.completed = false;
        size_t initialSize = listOfTask.size();
        listOfTask.push_back(storeTask);
        if (listOfTask.size() > initialSize)
        {
            cout << "\nTask Added Successfully!!!!" << endl;
        }else{
            cout << "\nFailed To Add Task!!" << endl;
        }
    };
}

void viewTask(const vector<TaskSchema>& listOfTask, Catagories catagory){
    while (true)
    {
        string text;
        if(listOfTask.empty()){
            cout << "No Task To Display!!!" << endl;
            cout << "\nType 'Exit' to Stop the Operation: " << flush;
            cin >> text;
            if(text == "Exit") break;
        }else{
            cout << "\nTasks in Catagories: ";
            switch (catagory){
                case Catagories::Work:
                    cout << "Work" << endl;
                    break;
                case Catagories::Personal:
                    cout << "Personal" << endl;
                    break;
                case Catagories::Shopping:
                    cout << "Shopping" << endl;
                    break;
                default:
                    break;
            }
            bool success = false;
            cout << "\nTask List: " << endl;
            for(const TaskSchema& task:listOfTask){
                if (task.catagory == catagory){
                    success = true;
                    cout << "\nDescription: " << task.description << flush;
                    if (task.completed){ 
                        cout << " [Y]" << endl;
                    } else {
                        cout << " [X]" << endl;
                    }
                    cout << endl;
                }
            }
            if (!success)
            {
                cout << "No Task To In This Catagory!!!" << endl;
            }  
        }
        cout << "\nType 'Exit' to Stop the Operation: " << flush;
        cin >> text;
        if (text == "Exit")
        {
            break;
        }
    }
}

void markTaskComplete(vector<TaskSchema>& listOfTask){
    while (true)
    {
        int taskIndex;

        cout << "\nEnter The Number of Task Description you want to Mark as Complete (Type '0' to Exit): " << flush;
        cin >> taskIndex;
        if(taskIndex == 0){
            break;
        }
        --taskIndex;
        if(taskIndex>=0 && taskIndex<listOfTask.size()){
            listOfTask[taskIndex].completed = true;
            cout << "\nTask Marked as Completed!!!" << endl;
        }else{
            cout << "\nInvalid Task Number!!!!" << endl;
            break;
        }
        cout << "\nType 0 to Exit: " << flush;
        cin >> taskIndex;
        if (taskIndex == 0) 
        {
            break;
        } 
    }
}

void markTaskIncomplete(vector<TaskSchema>& listOfTask){
    while (true)
    {
        int taskIndex;
        cout << "\nEnter the Task Number you want to mark as Incomplete (Type 0 to Stop): " << flush;
        cin >> taskIndex;
        if(taskIndex == 0) break;
        --taskIndex;
        if (taskIndex >= 0 && taskIndex < listOfTask.size())
        {
            listOfTask[taskIndex].completed = false;
            cout << "\nTask Marked as Incomplete!!!!" << endl;
        }else{
            cout << "\nInvalid Task Number" << endl;
            break;
        }
        cout << "Type 0 to Exit: " << flush;
        cin >> taskIndex;
        if (taskIndex == 0) 
        {
            break;
        }
    }
}

void deleteTask(vector<TaskSchema>& listOfTask){
    while (true)
    {
        int taskIndex;
        cout << "\nEnter The task Number You Want to Delete(Type 0 to Stop): " << flush;
        cin >> taskIndex;
        if (taskIndex == 0)
        {
            break;
        }
        --taskIndex;
        if (taskIndex >= 0 && taskIndex < listOfTask.size())
        {
            listOfTask.erase(listOfTask.begin()+taskIndex);
            cout << "Task Deleted Successfully!!!!" << endl;
        }else{
            cout << "Invalid Task Number!!!" << endl;
        }
        cout << "\nType 0 to Exit: " << flush;
        cin >> taskIndex;
        if (taskIndex == 0) 
        {
            break;
        }
    }
}


int main(){
    vector<TaskSchema> taskList;
    int choice;
    do
    {
        cout << "\nTask Manager Menu: " << endl;
        cout << "\n1. Add Task" << endl;
        cout << "2. View Task By Catagories" << endl;
        cout << "3. Mark Task Complete" << endl;
        cout << "4. Mark Task Incomplete" << endl;
        cout << "5. Delete Task" << endl;
        cout << "0. Exit" << endl;
        cout << "\nEnter Your Choice: " << flush;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case 0:
                cout << "Exit Task Manager Console" << endl;
                break;
            case 1:
                addTask(taskList);
                break;
            case 2:
                cout << "\nCatagories" << endl;
                cout << "1. Work " << endl;
                cout << "2. Personal " << endl;
                cout << "3. Shopping " << endl;
                cout << "\nEnter Your Choice: " << flush;
                int catagoryChoice;
                cin >> catagoryChoice;
                cin.ignore();
                switch (catagoryChoice)
                {
                case 1:
                    viewTask(taskList, Catagories::Work);
                    break;
                case 2:
                    viewTask(taskList, Catagories::Personal);
                    break;
                case 3:
                    viewTask(taskList, Catagories::Shopping);
                    break;
                default:
                    cout << "Invalid Choice!!!" << endl;
                    break;
                }
                break;
            case 3:
                markTaskComplete(taskList);
                break;
            case 4:
                markTaskIncomplete(taskList);
                break;
            case 5:
                deleteTask(taskList);
                break;
        }
    } while (choice>=0&&choice<=5);
    return 0;
}