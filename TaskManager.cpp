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
};

void addTask(vector<TaskSchema>& listOfTask){
    while (true)
    {
        TaskSchema storeTask;
        cout << "\nEnter The Task Description (Type 'Exit'to Stop): " << flush;
        getline(cin, storeTask.description);
        if (storeTask.description == "Exit") break;
        storeTask.completed = false;
        size_t initialSize = listOfTask.size();
        listOfTask.push_back(storeTask);
        if (listOfTask.size() > initialSize)
        {
            cout << "\n Task Added Successfully!!!!" << endl;
        }else{
            cout << "\n Failed To Add Task!!" << endl;
        }
    };
}

void viewTask(const vector<TaskSchema>& listOfTask){
    while (true)
    {
        string text;
        if(listOfTask.empty()){
            cout << "No Task To Display!!!" << endl;
            cout << "\nType 'Exit' to Stop the Operation: " << flush;
            cin >> text;
            if(text == "Exit") break;
        }else{
            cout << "\nTask List: " << endl;
            for(size_t i = 0; i<listOfTask.size(); ++i){
                cout << i+1 << ". ";
                cout << listOfTask[i].description << flush;
                if (listOfTask[i].completed){
                    cout << "[Y]" << endl;
                }else{
                    cout << "[X]" << endl;
                }
            }
            cout << "\n Type 'Exit' to Stop the Operation: " << flush;
            cin >> text;
            if (text == "Exit")
            {
                break;
            }
            
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
            cout << "\n Task Marked as Completed!!!" << endl;
        }else{
            cout << "\n Invalid Task Number!!!!" << endl;
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

void breakOut(){
    while (true)
    {
        string text;
        cout << "\nType 'Enter' To Exit: ";
        cin >> text;
        if (text == "Exit"){
            break;
        }
        
    }
}

int main(){
    vector<TaskSchema> taskList;
    int choice;
    do{
        cout << "Task Manager Menu: " << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Task" << endl;
        cout << "3. Mark Task as Complete" << endl;
        cout << "4. Mark Task as Incomplete" << endl;
        cout << "5. Delete Task" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your Number Choice: " << flush;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addTask(taskList);
            break;
        case 2:
            viewTask(taskList);
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
        case 6:
            cout << "Exiting Task Manager!!!!!!!" << endl;
            break;
        default:
            cout << "Invalid Output!!, Please Try Again" << endl;
            break;
        }
    }while (choice > 0 && choice != 6);
    return 0;
}