#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

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
void ULListStr::push_back(const std::string& val){
  
  if(head_==NULL){
    push_front(val);
  }else if(tail_->last != 10){
    tail_->val[tail_->last]=val;
    tail_->last += 1;
    size_++;
  }else{
    Item* newItem = new Item();
    tail_->next=newItem;
    newItem->prev = tail_;
    newItem->next = NULL;
    newItem->first = 0;
    newItem->last = 1;
    newItem->val[0] = val;
    tail_=newItem;
    size_++;
  }

}


void ULListStr::push_front(const std::string& val){
  if(head_==NULL){
    Item* newItem = new Item();
    newItem->prev = NULL;
    newItem->next = NULL;
    newItem->first = 4;
    newItem->last = 5;
    newItem->val[4] = val;
    head_=newItem;
    tail_=newItem;
    size_++;
  }else if(head_->first != 0){
    head_->val[head_->first-1]=val;
    head_->first-=1;
    size_++;
  }else{
    Item* newItem = new Item();
    newItem->prev = NULL;
    newItem->next = head_;
    head_->prev = newItem;
    head_=newItem;
    newItem->first=9;
    newItem->last=10;
    newItem->val[9] = val;
    size_++;

  }
}


void ULListStr::pop_front(){
  if(head_==NULL){
    return;
  }else{
    head_->val[head_->first]="";
    size_--;
    head_->first+=1;
    if(head_->first == head_->last){
      if(head_==tail_){
        tail_=NULL;
      }
      Item *temp = head_->next;
      delete head_;
      head_ = temp;
    }
  }
}

void ULListStr::pop_back(){
  if(tail_==NULL){
    return;
  }else{
    tail_->val[tail_->last-1]="";
    size_--;
    tail_->last-=1;
    if(tail_->first == tail_->last){
      if(tail_==head_){
        head_=NULL;
      }
      Item *temp = tail_->prev;
      delete tail_;
      tail_ = temp;
    }
  }
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}


std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* temp = head_;
  size_t currIdx = temp->first;
  for(size_t i = 0; i <size_; i++){
    if(currIdx == 10){
      temp = temp->next;
      currIdx=temp->first;
    }
    if(i==loc){
      return &temp->val[currIdx];
    }
    currIdx++;
  }
  return NULL;
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

//END OF MY CODE

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
