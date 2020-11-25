#include <iostream>
#include <string>
#include "word.hpp"

using namespace std;

bool is_in_list(word *head, string test_word );

int main() {
  
 //read in the list from file, they will be in reverse order
  word *head = nullptr; 
  while (cin.eof() == false) {
    string t_word;
    cin >> t_word;
    //check if word is already in list
    if (!is_in_list(head, t_word)){
      word *new_word = new word();
      new_word->assign(t_word);
      new_word->next = head;
      head = new_word;
    }
   
  }
  // invert the list
  word *prev = nullptr;
  word *current = head;
  word *next = nullptr;
  while (current != nullptr){
    // Before changing next of current, store next object
    next = current->next;
    // Now change next of current 
    current->next = prev;
    // Move prev and curr one step forward 
    prev = current; 
    current = next;
  }
  head = prev;

  // Print out all the words in the linked list
  word *w = head;
  while (w != nullptr) {  
    cout << "\"" << *w << "\" " << w->counter << endl;
    w = w->next;
  }

  // Delete all the objects in the linked list
  w = head;
  while (w != nullptr) {
   
    word *t = w->next;
    delete w;
    w = t;
  }

}

bool is_in_list(word *head, string test_word ){
  word *curr = head;
  while (curr != nullptr) {
  
    //test if word being tested is assinged to current stringlink 
    // if it is return true
    if (*curr == test_word) {
      curr->counter ++;
      return true;
    }
    curr = curr->next;
  }
  return false;
}
