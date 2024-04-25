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
    TaskSchema storeTask;
    cout << "Enter The Task Description: " << flush;
    getline(cin, storeTask.Description);
    storeTask.Completed = false;
    size_t initialSize = listOfTask.size();
    listOfTask.push_back(storeTask);
    if(listOfTask.size() > initialSize){
        cout << "Task Added Successfully!!!!!" << endl;
    } else {
        cout << "Failed To Add Task" << endl;
    }
}

void viewTask(const vector<TaskSchema>& listOfTask){
    if (listOfTask.empty()){
        cout << "No Task To Display" << endl;
    }
    cout << "Task: " << endl;
    for (size_t i = 0; i <= listOfTask.size(); ++i){
        cout << i+1 << ". ";
        cout << listOfTask[i].Description << flush;
        if (listOfTask[i].Completed)
        {
            cout << " [Y]" << endl;
        } else {
            cout << " [X]" << endl;
        }
        
    }
}

int main(){
    vector<TaskSchema> Task;
    addTask(Task);
    viewTask(Task);
    return 0;
}
