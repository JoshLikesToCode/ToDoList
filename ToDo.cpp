#include "ToDo.h"
#include <iostream>


ToDo::ToDo()
{
}

ToDo::~ToDo()
{
}

ToDo::ToDo(std::string t, std::string d, std::string s) 
    : title(t), description(d), status(s) {}
    
void ToDo::set_description(std::string d) {
    description = d;
}

std::string ToDo::get_description() {
    return description;
}

void ToDo::set_title(std::string t) {
    title = t;
}

std::string ToDo::get_title() {
    return title;
}

void ToDo::set_status(std::string s) {
    status = s;
}

std::string ToDo::get_status() {
    return status;
}
    
    
