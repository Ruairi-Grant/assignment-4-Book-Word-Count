#include <iostream>
#include <string>
#include "stringlink.hpp"

using namespace std;

bool is_in_list(stringlink *head, string word );

int main() {
 
  stringlink* head = nullptr; 
  // Read each word from the file and store each one in the linked list...
  // They will be in last-in-first-out order, but so what.
  while (cin.eof() == false) {
    string t_word;
    cin >> t_word;
    //if statement to check history
    if (!is_in_list(head, t_word)){
      stringlink *new_word = new stringlink();
      new_word->assign(t_word);
      new_word->next = head;
      head = new_word;
    }
   
  }

  // Print out all the words in the linked list...
  
  stringlink* w = head;
  while (w != nullptr) {
    // the *w below means dereference the stringlink pointer to
    // get to the stringlink object it points to and use that
    cout << "\"" << *w << "\" " << w->counter << endl;
    w = w->next;
  }

  // Delete all the objects in the linked list...
  w = head;
  while (w != nullptr) {
    // Get a copy of the pointer to the rest of the list
    // before you delete the object.
    // Otherwise, you would lose the pointer to the
    // rest of the list.
    stringlink* t = w->next;
    delete w;
    w = t;
  }

  cout << "Finished" << endl;
}

bool is_in_list(stringlink *head, string word ){
  stringlink* curr = head;
  while (curr != nullptr) {
  
    //test if word beint tested is assinged to current stringlink 
    // if it is return true
    if (*curr == word) {
      curr->counter ++;
      return true;
    }
    curr = curr->next;
  }
  return false;
}
