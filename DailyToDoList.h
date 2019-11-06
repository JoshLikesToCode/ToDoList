#ifndef _DAILYTODOLIST_H_
#define _DAILYTODOLIST_H_
#include "ToDo.h"
#include <iostream>
#include <vector>

class DailyToDoList
{
public:
    DailyToDoList(std::string d);
    void add_to_do(ToDo add_this);
    void remove_to_do(std::string remove_this);
    void shift_to_do(int oi, int ni);
    void modify_to_do(int index);
    void set_current_date(std::string d);
    std::string get_current_date();
    bool check_bounds(int index);
    void print_to_do();
    
private:
    std::string current_date;
    std::vector <ToDo> toDoList;

};

#endif // _DAILYTODOLIST_H_
