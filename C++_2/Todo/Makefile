CC = g++
TARGET = pp3.exe
$(TARGET): driver.o todo_ui.o todo_list.o todo_item.o
	$(CC) -o $(TARGET) driver.o todo_ui.o todo_list.o todo_item.o

driver.o: driver.cpp
	$(CC) -c driver.cpp

todoui.o: todo_ui.h todo_ui.cpp
	$(CC) -c todo_ui.cpp

todolist.o: todo_list.h todo_list.cpp
	$(CC) -c todo_list.cpp
		
todoitem.o: todo_item.h todo_item.cpp
	$(CC) -c todo_item.cpp

clean:
	del*.o

cleanall:
	del*.o$(TARGET)