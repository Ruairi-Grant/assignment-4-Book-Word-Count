#pragma once
#include <string>

class stringlink : public std::string {
  public:
  stringlink *next; // use this to link to the next  object in the linked list
  int counter = 1;
  bool is_in_list(stringlink *head);
};
