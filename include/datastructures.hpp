#include <iostream>

struct binElement;

struct binElement{
    binElement* leftChild;
    binElement* rightChild;
    int value;

    binElement(int value);
};


void insertElement(binElement* parent,int value);

void displayTree(binElement* parent);
void treeToList(int list[],binElement parent, int* acc);