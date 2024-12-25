#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 10;
struct Task {
    string description;
    int priority;
    string deadline;
    bool isCompleted;
};

void displayTasks(Task tasks[], int count) {
    cout << "=======================================" << endl;
    cout << "| No | Description       | Priority | Deadline    | Status     |" << endl;
    cout << "=======================================" << endl;
    for (int i = 0; i < count; i++) {
        cout << "| " << (i + 1) << "  | " << tasks[i].description << "    | " << tasks[i].priority 
             << "       | " << tasks[i].deadline << " | " << (tasks[i].isCompleted ? "Completed" : "Pending") << " |" << endl;
    }
    cout << "=======================================" << endl;
}

void addTask(Task tasks[], int &count) {
    if (count >= MAX_TASKS) {
        cout << "Task list is full!" << endl;
        return;
    }
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, tasks[count].description);
    cout << "Enter priority (1-5): ";
    cin >> tasks[count].priority;
    cout << "Enter deadline (DD/MM/YYYY): ";
    cin >> tasks[count].deadline;
    tasks[count].isCompleted = false;
    count++;
}

void updateTask(Task tasks[], int count) {
    int taskNo;
    cout << "Enter task number to update: ";
    cin >> taskNo;
    if (taskNo < 1 || taskNo > count)
     {
     cout << "Invalid task number!" << endl;
        return;
    }
    cout << "Enter new description: ";
    cin.ignore();
    getline(cin, tasks[taskNo - 1].description);
    cout << "Enter new priority (1-5): ";
    cin >> tasks[taskNo - 1].priority;
    cout << "Enter new deadline (DD/MM/YYYY): ";
    cin >> tasks[taskNo - 1].deadline;
    cout << "Is the task completed? (0 for no, 1 for yes): ";
    cin >> tasks[taskNo - 1].isCompleted;
}
void deleteTask(Task tasks[], int &count) 
{
    int taskNo;
    cout << "Enter task number to delete: ";
    cin >> taskNo;
    if (taskNo < 1 || taskNo > count) {
 cout << "Invalid task number!" << endl;
        return;
    }
    for (int i = taskNo - 1; i < count - 1; i++) {
    tasks[i] = tasks[i + 1];
    }
    count--;
}

int main() {
    Task tasks[MAX_TASKS];
    int count = 0;
    int choice;
    
    do {
        cout << "========================" << endl;
        cout << "| To-Do List Application |" << endl;
        cout << "========================" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Update Task" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Display Tasks" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
     case 1:
   addTask(tasks, count);
           break;
            case 2:
      updateTask(tasks, count);
     break;
            case 3:
     deleteTask(tasks, count);
                break;
            case 4:
       displayTasks(tasks, count);
   break;
            case 5:
         cout << "Exiting the application." << endl;
      break;
            default:
     cout << "Invalid choice! Please enter again." << endl;
         break;
        }
    } while (choice != 5);

    return 0;
}
