#include "../include/datastructures.hpp"

binElement::binElement(int value) : value(value), leftChild(0), rightChild(0)
{
}

void insertElement(binElement *parent, int value)
{
    binElement **child = &parent;

    while (*child != 0)
    {
        if (value >= (*child)->value)
            child = &(*child)->rightChild;
        else
            child = &(*child)->leftChild;

        if (*child == 0)
        {
            *child = new binElement(value);
            break;
        }
    }
}

void displayTree(binElement *parent)
{

    if (parent->leftChild != 0)
    {
        displayTree(parent->leftChild);
    }

    std::cout << parent->value << std::endl;

    if (parent->rightChild != 0)
    {
        displayTree(parent->rightChild);
    }
}

int a = 0;
void treeToList(int list[],binElement parent, int* acc){
    

    if (parent.leftChild != 0)
    {
        treeToList(list,*parent.leftChild,acc);
    }

    list[*acc] = parent.value;
    *acc = *acc+1;

    if (parent.rightChild != 0)
    {
        treeToList(list,*parent.rightChild,acc);
    }
}