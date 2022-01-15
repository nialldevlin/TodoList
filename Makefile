
TODO: todo.o TodoListInterface.o
	g++ todo.o TodoListInterface.o -o TODO

todo.o: todo.cpp
	g++ -c todo.cpp -o todo.o

TodoListInterface.o: TodoListInterface.cpp TodoListInterface.h
	g++ -c TodoListInterface.cpp -o TodoListInterface.o
