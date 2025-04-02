#include "include/Todo.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

Todo::Todo() {
  todoList = {{"Bake brød", 10}, {"Spise brød", 100}, {"Gå tur", 1000}, {"Kjøre bil", 3}};
}

Todo::~Todo() {}

void Todo::add_todo_item() {
  std::string a;
  uint32_t b;
  std::cout << "### Add an item ###" << "\n\n\n" << "Write task name: ";
  std::cin >> a;
  std::cout << "Write a importance value: " << "\n";
  std::cin >> b;

  todoList.push_back({a, b});
}

void Todo::show_all_tasks() {
  std::sort(todoList.begin(), todoList.end(),
            [](const TodoItems &a, const TodoItems &b) {
              return a.importance < b.importance;
            });

  for (auto it = todoList.begin(); it != todoList.end(); it++) {
    std::cout << it->taskName << "\n" << it->importance << "\n";
  }
}

void Todo::show_winner() {
  auto mostImportant =
      std::max_element(todoList.begin(), todoList.end(),
                       [](const TodoItems &a, const TodoItems &b) {
                         return a.importance < b.importance;
                       });

  if (mostImportant != todoList.end()) {
    std::cout << mostImportant->taskName << "\n" << mostImportant->importance;
  }
}

void Todo::todo_game() {
  std::vector<TodoItems> todos = todoList;

  int z = -1, count = 0;

  while (todos.size() > 1) {
    for (size_t i = 0; i < todos.size(); i++) {
      count = i + 1;

      if (i == todos.size() - 1)
      {
        count = i - 1;
        // continue;
      }

      std::cout << "[1]" << todos[i].taskName << "\n"
                << "[2]" << todos[count].taskName << "\n";
      std::cin >> z;

      switch (z) {
      case 1:
        todos.erase(todos.begin() + count);
        for (size_t i = 0; i < todos.size(); i++) {
          std::cout << todos[i].taskName << "\n" << todos[i].importance << "\n";
        }
        break;
      case 2:
        todos.erase(todos.begin() + i);
        for (size_t i = 0; i < todos.size(); i++) {
          std::cout << todos[i].taskName << "\n" << todos[i].importance << "\n";
        }
        break;
      }
    }
  }
  std::cout << todos[0].taskName << " is the winner! :D" << "\n";
}
