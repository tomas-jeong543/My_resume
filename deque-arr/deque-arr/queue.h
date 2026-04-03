#pragma once
#include<stdio.h>
#include<stdlib.h>

void initallize();
bool isEmpty(int rear, int front);
bool isFull(int rear, int front);
void enqueue(int value);
int dequeue();