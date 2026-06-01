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

  first->light = true;
  Car* pos = first;

  int step = 1;
  while (true) {
    for (int i = 0; i < step; i++) {
      pos = pos->next;
      countOp++;
    }

    if (pos->light) {
      pos->light = false;
    }

    for (int i = 0; i < step; i++) {
      pos = pos->prev;
      countOp++;
    }

    if (first->light == false) {
      return step;
    }

    step++;
  }
}

int Train::getOpCount() {
  return countOp;
}
