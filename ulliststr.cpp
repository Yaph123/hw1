#include <cstddef>
#include <stdexcept>
#include <string>
#include "ulliststr.h"
//#include <iostream> //Remove
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}



// WRITE YOUR CODE HERE

void ULListStr::push_back(const string& val)
{
  if (head_ == nullptr){
    Item* newItem = new Item;
    head_ = newItem;
    tail_ = newItem;

    newItem -> val[0] = val;

    newItem -> first = 0;
    newItem -> last  =  1;

    newItem->next = nullptr;
    newItem->prev = nullptr;

    size_++;
    return;
  }

  if((tail_->last) < ARRSIZE){
    tail_ -> val[tail_->last] = val;
    tail_ -> last++;
  }
  else{
    Item* newNode = new Item;
    newNode->prev = tail_;
    tail_->next = newNode;
    tail_ = newNode;
    newNode->next = nullptr;
    
    newNode -> first = 0;
    newNode -> last = 1;
    newNode -> val[0] = val;
  }

  size_ ++;
  return;

}

void ULListStr:: pop_back()
{
  if (head_ == nullptr){
    return;
  }

  //(tail_ -> val[tail_ -> last -1]).clear();
  tail_ -> last --;

  if(tail_ -> last == tail_->first){
    Item* tailPrev = tail_;
    tail_ = tail_->prev;
    if(tail_ != nullptr){
    tail_ -> next = nullptr;
    }
    else {
    head_ = nullptr;
    }
    delete tailPrev;
  }

  size_ --;

}

void ULListStr:: push_front(const string& val)
{
  if (head_ == nullptr){
    Item* newNode = new Item;

    head_ = newNode;
    tail_ = newNode;

    newNode -> val[ARRSIZE-1] = val;
    newNode->first = ARRSIZE-1;
    newNode-> last = ARRSIZE;

    newNode->next = nullptr;
    newNode->prev = nullptr;

    size_ ++;
    return;
  }

  else if(head_->first > 0){
      head_->first --;
      head_->val[ head_->first] = val;  
      size_++;  
    }

  else{

      Item* newNode = new Item;

      newNode->val[ARRSIZE-1] = val;
      newNode->first = ARRSIZE-1;
      newNode->last = ARRSIZE;

      newNode->next = head_;
      newNode->prev = nullptr;

      head_->prev = newNode;

      head_ = newNode;
      size_++;
    }
  
}

void ULListStr:: pop_front()
{
  if(head_ == nullptr){
    return;
  }

  //(head_->val[head_->first]).clear();
   
   head_->first++;

  if(head_-> first == head_->last){
    Item* temp = head_;
    head_ = head_->next;

    if(head_ != nullptr){
      head_->prev = nullptr;
    }
    else{
      tail_ = nullptr;
    }
    delete temp; 
  }

  size_ --;
  
}

string const& ULListStr::back() const
{

  return (tail_ -> val[tail_->last-1]);

}

string const& ULListStr::front() const
{

  return (head_-> val[head_->first]);

}

string* ULListStr:: getValAtLoc(size_t loc) const
{
  //cout << "@@@@@@@@" << loc << endl;
  if (loc >= size_){
    return nullptr;
  }

  Item* newNode = head_;

  while( newNode != nullptr){
    size_t range = newNode ->last - newNode->first;
    //cout << "element " << loc << " last:" << newNode ->last << " first:" << newNode->first << " range:" <<range << endl;
    
    if(loc < range ){
      //cout << "in if" << endl;
      return &(newNode->val[newNode->first +loc]);
    }
    loc -= range;
    newNode = newNode -> next;
  }
  return nullptr;

}

//////

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
