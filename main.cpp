#include "ToDo.h"
#include "DailyToDoList.h"
#include <iostream>

using namespace std;

void print_menu(DailyToDoList);
ToDo initializeToDo();

int main() {
    string current_date;
    cout << "What's todays date?" << endl;
    getline(cin, current_date);
    DailyToDoList toDoList(current_date);
    print_menu(toDoList);
    
    
    return 0;
}

ToDo initializeToDo() {
    string title, description, status;
    cout << "Enter a title for your To Do List entry." << endl;
    cin.ignore();
    getline(cin, title);
    cout << "Enter a breif description for your To Do List entry." << endl;
    getline(cin, description);
    cout << "Enter the current status of your To Do List entry." << endl;
    getline(cin, status);
    
    ToDo newToDo(title, description, status);
    return newToDo;
}

void print_menu(DailyToDoList toDoList) {
    char menuOption;
    string user_input;
    int index;
    int index2;
    bool close_menu = 1;
    
    while(close_menu) {
    cout << endl;
    cout << "======== TO DO LIST FOR ( " << toDoList.get_current_date() << " ) OPTIONS ========" << endl;
    cout << "Press one of the following keys for your desired option." << endl;
    cout << "a) Add something To Do to your list." << endl;
    cout << "b) Remove something To Do from your list." << endl;
    cout << "c) Modify something from your To Do list." << endl;
    cout << "d) Shift priority around in your To Do list." << endl;
    cout << "e) Print out your current To Do list." << endl;
    cout << "q) Exit out of your To Do list." << endl;
    cin >> menuOption;
    cout << endl;
    
    switch (menuOption) {
        case 'a':
            toDoList.add_to_do(initializeToDo());
            break;
        case 'A':
            toDoList.add_to_do(initializeToDo());
            break;
        case 'b':
            cout << "Enter the To Do List entry's current title that you want removed." << endl;
            cin.ignore();
            getline(cin, user_input);
            toDoList.remove_to_do(user_input);
            break;
        case 'B':
            cout << "Enter the To Do List entry's current title that you want removed." << endl;
            cin.ignore();
            getline(cin, user_input);
            toDoList.remove_to_do(user_input);
            break;
        case 'c':
            cout << "Enter the placement (or index) of the item you want modified." << endl;
            cin >> index;
            toDoList.modify_to_do(index);
            break;
        case 'C':
            cout << "Enter the placement (or index) of the item you want modified." << endl;
            cin >> index;
            toDoList.modify_to_do(index);
            break;
        case 'd':
            cout << "Enter the current index (or placement) of the item you want to switch." << endl;
            cin >> index;
            cout << "Enter the new index (or placement) you wish to put it in on the list." << endl;
            cin >> index2;
            toDoList.shift_to_do(index, index2);
            break;
        case 'D':
            cout << "Enter the current index (or placement) of the item you want to switch." << endl;
            cin >> index;
            cout << "Enter the new index (or placement) you wish to put it in on the list." << endl;
            cin >> index2;
            toDoList.shift_to_do(index, index2);
            break;
        case 'e':
            toDoList.print_to_do();
            break;
        case 'E':
            toDoList.print_to_do();
            break;
        case 'q':
            close_menu = 0;
        case 'Q':
            close_menu = 0;

        }
    }
}
