#ifndef _TODO_H_
#define _TODO_H_

#include <iostream>

class ToDo
{
public:
    ToDo();
    ~ToDo();
    ToDo(std::string t, std::string d, std::string s);
    void set_title(std::string t);
    std::string get_title();
    void set_description(std::string d);
    std::string get_description();
    void set_status(std::string s);
    std::string get_status();
    
private:
    std::string title;
    std::string description;
    std::string status;

};

#endif // _TODO_H_
