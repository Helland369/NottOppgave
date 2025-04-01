#include "include/Todo.hpp"
#include <cstdlib>
#include <iostream>


int main(int argc, char* argv[])
{
  Todo t;
  int x;

  std::system("clear");
  for (;;)
  {
    std::cout << "\n[1] Add todo item\n" << "[2] Show all task\n" << "[3] Show winner\n" << "[0] Exit\n";
    std::cin >> x;
    switch (x) {
    case 0:
      std::exit(0);
      break;
    case 1:
      t.add_todo_item();
      std::system("clear");
      break;
    case 2:
      std::system("clear");
      t.show_all_tasks();
      break;
    case 3:
      std::system("clear");
      t.show_winner();
      break;
    case 4:
      t.todo_game();
      break;
    }
  }
  return 0;
}    
