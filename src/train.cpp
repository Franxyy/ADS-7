// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
  countOp = 0;
  first = nullptr;
}

void Train::addCar(bool light) {
  Car* c = new Car;
  c->light = light;
  c->next = nullptr;
  c->prev = nullptr;

  if (first == nullptr) {
    c->next = c;
    c->prev = c;
    first = c;
    return;
  }

  Car* last = first->prev;
  c->next = first;
  c->prev = last;
  last->next = c;
  first->prev = c;
}

int Train::getLength() {
  countOp = 0;
  
  if (first == nullptr) {
    return 0;
  }

  first->light = false;
  
  Car* cur = first;
  int len = 0;
  
  while (true) {
    cur = cur->next;
    countOp++;
    len++;
    
    if (cur->light) {
      return len;
    }
    
    cur->light = true;
  }
}

int Train::getOpCount() {
  return countOp;
}
