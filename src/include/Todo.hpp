#pragma once
#include <cstdint>
#include <string>
#include <vector>

class TodoItems
{
public:
  std::string taskName;
  uint32_t importance;
};


class Todo
{
private:
  std::vector<TodoItems> todoList;
  
public:
  Todo();
  ~Todo();

  void add_todo_item();
  void show_all_tasks();
  void show_winner();
  void todo_game();
};
