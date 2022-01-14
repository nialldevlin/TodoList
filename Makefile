
TODO: todo
	g++ -o todo.o TodoListInterface.o

todo.o: todo.cpp
	g++ -c todo.cpp

TodoListInterface.o: TodoListInterface.cpp TodoListInterface.h
	g++ -c TodoListInterface.cpp

