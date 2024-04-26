#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TaskSchema
{
    string Description;
    bool Completed;
};

void addTask(vector<TaskSchema>& listOfTask){
    while (true){
        TaskSchema storeTask;
        cout << "Enter The Task Description (type 'Exit' to stop): " << flush;
        getline(cin, storeTask.Description);
        if (storeTask.Description == "Exit"){
            break;
        }
        storeTask.Completed = false;
        size_t initialSize = listOfTask.size();
        listOfTask.push_back(storeTask);
        if(listOfTask.size() > initialSize){
            cout << "\nTask Added Successfully!!!!!" << endl;
        } else {
            cout << "\nFailed To Add Task" << endl;
        }
    }
}

void viewTask(const vector<TaskSchema>& listOfTask){
    while (true)
    {
        string text;
        if (listOfTask.empty()){
            cout << "No Task To Display" << endl;
            cout << "Type (Exit) To Go Back: " << flush;
            cin >> text;
            if(text=="Exit"){
                break;
            }
        }
        cout << "Task: " << endl;
        for (size_t i = 0; i <= listOfTask.size(); ++i){
            cout << i+1 << ". ";
            cout << listOfTask[i].Description << flush;
            if (listOfTask[i].Completed)
            {
                cout << " [Y]" << endl;
                cout << "Type (Exit) To Go Back: " << flush;
                cin >> text;
                if(text=="Exit"){
                    break;
                }
            } else {
                cout << " [X]" << endl;
                cout << "Type (Exit) To Go Back: " << flush;
                cin >> text;
                if(text=="Exit"){
                    break;
                }
            }
        }
    }
}

void markTaskComplete(vector<TaskSchema>& listOfTask){
    int taskIndex;
    cout << "Enter The Index of Description Want to Mark Complete: " << flush;
    cin >> taskIndex;
    --taskIndex;
    if (taskIndex >= 0 && taskIndex < listOfTask.size()){
        listOfTask[taskIndex].Completed = true;
        cout << "Task Marked as Completed" << endl;

        viewTask(listOfTask);
    }else{
        cout << "Invalid Task Number" << endl;
    }
}

int main(){
    vector<TaskSchema> taskList;
    int choice;

    do{
        cout << "\nTask Manager Menu: " << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Task" << endl;
        cout << "3. Mark Task as Complete" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Exit" << endl;
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
        case 5:
            cout << "Exiting Task Manager........." << endl;
            break;
        default:
            cout << "Invalid Input. Please Try Again" << endl;
            break;
        }
    }while(choice >0 && choice <= 5);
    return 0;
}
