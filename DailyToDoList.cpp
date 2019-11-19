#include "DailyToDoList.h"

    
DailyToDoList::DailyToDoList(std::string d)
        : current_date(d) {}
    
void DailyToDoList::add_to_do(ToDo add_this) {
    toDoList.push_back(add_this);
}

void DailyToDoList::remove_to_do(std::string remove_this) {
    if (toDoList.empty() == false) {
        for (int i = toDoList.size() - 1; i >= 0; i--)
            if (toDoList.at(i).get_title() == remove_this) {
                toDoList.erase( toDoList.begin() + i);
                }
    } else {
        std::cout << "This activity has not been found on your To Do List." << std::endl;
    }
}

bool DailyToDoList::check_bounds(int index) {
    if (index >= 0 && index < toDoList.size() ) 
        return true;
    return false;
}

void DailyToDoList::shift_to_do(int old_index, int new_index) {
    ToDo temp;
    if (check_bounds(new_index)) {
        temp = toDoList.at(new_index);
        toDoList.at(new_index) = toDoList.at(old_index);
        toDoList.at(old_index) = temp;
    } else {
        std::cout << "The index you're trying to shift to/from doesn't exist." << std::endl;
    }
}

void DailyToDoList::print_to_do() {
    for (int i{0}; i < toDoList.size(); ++i) {
        std::cout << "( " << i << " ) " << toDoList.at(i).get_title() << " - " << toDoList.at(i).get_description() << " || STATUS: " << toDoList.at(i).get_status();
        std::cout << std::endl;
    }
}

void DailyToDoList::modify_to_do(int index) {
    
    if (check_bounds(index)) {
        char user_option;
        std::string changeThis;
        std::cout << "Modify Item Menu" << std::endl;
        std::cout << "Enter a char from the following menu options for desired effect." << std::endl;
        std::cout << "a) Change title." << std::endl;
        std::cout << "b) Change description." << std::endl;
        std::cout << "c) Change Status." << std::endl;
        std::cin >> user_option;
        switch (user_option) {
            case 'A' :
                std::cout << "Change title of " << toDoList.at(index).get_title() << " to : ";
                getline(std::cin, changeThis);
                toDoList.at(index).set_title(changeThis);
                break;
            case 'a' :
                std::cout << "Change title of '" << toDoList.at(index).get_title() << "' to : ";
                std::cin.ignore();
                std::getline(std::cin, changeThis);
                toDoList.at(index).set_title(changeThis);
                break;   
            case 'B' :
                std::cout << "Change description of " << toDoList.at(index).get_title() << " to : ";
                std::cin.ignore();
                getline(std::cin, changeThis);
                toDoList.at(index).set_description(changeThis);
                break;
            case 'b' :
                std::cout << "Change description of " << toDoList.at(index).get_title() << " to : ";
                std::cin.ignore();
                getline(std::cin, changeThis);
                toDoList.at(index).set_description(changeThis);
                break;
            case 'c' :
                std::cout << "Change status of " << toDoList.at(index).get_title() << " to : ";
                std::cin.ignore();
                getline(std::cin, changeThis);
                toDoList.at(index).set_status(changeThis);
                break;
            case 'C' :
                std::cout << "Change status of " << toDoList.at(index).get_title() << " to : ";
                std::cin.ignore();
                getline(std::cin, changeThis);
                toDoList.at(index).set_status(changeThis);
                break;
            default:
                std::cout << "Invalid option choice." << std::endl;
                modify_to_do(index);
        }
    } else {
        std::cout << "Invalid index." << std::endl;
    }

}

void DailyToDoList::save_toDo() {
    std::ofstream out_file {"../ToDo.txt", std::ios::out};
    
    if (!out_file) {
        std::cerr << "Error in creating this file.." << std::endl;
        exit(0);
    }
            
    for (int i{0}; i < toDoList.size(); i++) {
        out_file << toDoList.at(i).get_title() << std::endl;
        out_file << toDoList.at(i).get_description() << std::endl;
        out_file << toDoList.at(i).get_status() << std::endl;
    }
    
    out_file.close();
}

void DailyToDoList::read_toDo() {
    std::ifstream in_file{"../ToDo.txt"};
    
    if (!in_file) {
        std::cerr << "Error in opening this file.." << std::endl;
        exit(0);
    }

    while (in_file) {
        std::string title, description, status;
        getline(in_file, title, '\n');
        getline(in_file, description, '\n');
        getline(in_file, status, '\n');
        toDoList.push_back(ToDo(title, description, status));
    }
    toDoList.pop_back();

    in_file.close();
}



void DailyToDoList::set_current_date(std::string d) {
    current_date = d;
}

std::string DailyToDoList::get_current_date() {
    return current_date;
}




