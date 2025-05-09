#ifndef NODE_H
#define NODE_H

#include "vehicle.h"

struct Node {
    Vehicle data;
    Node* next;
    Node* prev;

    Node(const Vehicle& v) : data(v), next(nullptr), prev(nullptr) {}
};

#endif
