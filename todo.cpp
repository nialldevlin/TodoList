#include <iostream>
#include "TodoListInterface.h"

using namespace std;
  
int main(int argc, char** argv)
{
    TodoListInterface *todo_list;
    todo_list = new TodoListInterface("todo_list.txt");
  
    if (argc < 2) {
        cout << "No Arguments";
        return 1;
    }
    
    vector<string> args;
    for(int i = 0; i < argc; i++) {
        string v = argv[i];
        args.push_back(v);
    }

    if( args[1] == "add" ) {
        if (argc < 4) {
            cout << "Not enough args";
            delete todo_list;
            return 1;
        }
        todo_list->add(args[2], args[3]);
    } else if ( args[1] == "remove" ) {
        if (argc < 3) {
            cout << "Not enough args";
            delete todo_list;
            return 1;
        }
        todo_list->remove(args[2]);
    } else if ( args[1] == "printList" ) {
        todo_list->printTodoList();
    } else if ( args[1] == "printDay" ) {
        if (argc < 3) {
            cout << "Not Enough args";
        }
        todo_list->printDaysTasks(args[2]);
    }
    todo_list->TodoToFile();
    delete todo_list;
    return 0;
}
