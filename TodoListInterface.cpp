#include "TodoListInterface.h"
#include <bits/stdc++.h>
#include <sstream>
#include <iterator>

TodoListInterface::TodoListInterface(string f) : filename(f)
{
    curr_todo_id = 0;

    filein.open(filename);
    if (!filein.is_open()) {
        cout << "bad file in" << endl;
    }

    getTodoListFromFile();
}

void TodoListInterface::getTodoListFromFile() {
    string line;
    while (getline(filein, line)) {
        string substr;
        stringstream ss(line);
        vector<string> split_line;
        
        while (ss.good()) {
            getline(ss, substr, ',');
            split_line.push_back(substr);
        }
        todo_list.push_back(split_line);
    }
}

void TodoListInterface::TodoToFile() {
    fileout.open(filename, ofstream::trunc);

    if (!fileout.is_open()) {
         cout << "bad file out" << endl;       
    }

    for ( vector<string> line : todo_list ) {
        ostringstream oss;
        copy(line.begin(), line.end(), ostream_iterator<string>(oss, ","));
        string line_str(oss.str());
        line_str.pop_back();
        fileout << line_str << endl;
    }
}

void TodoListInterface::add(string _duedate, string _task)
{
    vector<string> line;
    line.push_back(_duedate);
    line.push_back(_task);
    todo_list.push_back(line);
}

int TodoListInterface::remove(string _task)
{
    for (int i = 0; i < todo_list.size(); i++) {
        if (todo_list[i][1] == _task) {
            todo_list.erase(todo_list.begin() + i);
            return 1;
        }
    }
    return 0;
}

void TodoListInterface::printTodoList()
{
    for ( vector<string> line : todo_list ) {
        for ( string i : line ) {
            cout << i << " ";
        }
        cout << endl;
    }
}

void TodoListInterface::printDaysTasks(string _date)
{
    for ( vector<string> line : todo_list ) {
        if (line[0] == _date) {
            for ( string i : line ) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}

TodoListInterface::~TodoListInterface()
{
    if (fileout.is_open()) {
        fileout.close();
    }

    if (filein.is_open()) {
        filein.close();
    }
}
    
