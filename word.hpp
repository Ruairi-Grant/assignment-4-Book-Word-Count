#pragma once
#include <string>

class word : public std::string {
  public:
  word *next; //pointer to next object in list
  int counter = 1; 
  
};
