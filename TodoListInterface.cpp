#include "TodoListInterface.h"

TodoListInterface::TodoListInterface(string f) : filename(f)
{
    file.open(filename);
    if (!file.is_open()) {
         cout << "bad file";       
    }
}

void TodoListInterface::add(string _duedate, string _task)
{
    file << _duedate << "," << _task << endl;
}

TodoListInterface::~TodoListInterface()
{
    
}
    
