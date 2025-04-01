#include "include/Todo.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

Todo::Todo() {}

Todo::~Todo() {}

void Todo::add_todo_item()
{
  std::string a;
  uint32_t b;
  std::cout << "### Add an item ###" << "\n\n\n" << "Write task name: ";
  std::cin >> a;
  std::cout << "Write a importance value: " << "\n";
  std::cin >> b;

  todoList.push_back({a, b});
}

void Todo::show_all_tasks()
{
  std::sort(todoList.begin(), todoList.end(), [](const TodoItems& a, const TodoItems& b) {
    return a.importance < b.importance;
  });

  for (auto it = todoList.begin(); it != todoList.end(); it++)
  {
    std::cout << it->taskName << "\n" << it->importance << "\n";
  }
}

void Todo::show_winner()
{
 auto mostImportant = std::max_element(todoList.begin(), todoList.end(),
        [](const TodoItems& a, const TodoItems& b) {
            return a.importance < b.importance;
        });

if (mostImportant != todoList.end())
{
  std::cout << mostImportant->taskName << "\n" << mostImportant->importance;
}
}
