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

  Car* cur = first;
  int step = 1;
  
  while (true) {
    for (int i = 0; i < step; i++) {
      cur = cur->next;
      countOp++;
    }
    
    cur->light = !cur->light;
    
    for (int i = 0; i < step; i++) {
      cur = cur->prev;
      countOp++;
    }
    
    if (cur->light != first->light) {
      return step;
    }
    
    step++;
  }
}

int Train::getOpCount() {
  return countOp;
}
