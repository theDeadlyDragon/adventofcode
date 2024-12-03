
#include <iostream>
#include "datastructures.hpp"
#include "../data/dataDay1.h"

void day1()
{
    std::cout << "Hello world" << std::endl;

    binElement a(list1[0]);
    binElement b(list2[0]);

    int size = sizeof(list1) / sizeof(int);

    for (int i = 1; i < size; i++)
    {
        insertElement(&a, list1[i]);
        insertElement(&b, list2[i]);
    }

    int acc = 0;
    treeToList(list1, a, &acc);
    acc = 0;
    treeToList(list2, b, &acc);

    int num = 0;

    for (int i = 0; i < size; i++)
    {
        std::cout << list1[i] << " , " << list2[i] << std::endl;
        num += abs(list1[i] - list2[i]);
    }
    std::cout << "done: " << num << std::endl;
}

void day1_1()
{
    binElement a(list1[0]);
    binElement b(list2[0]);

    int size = sizeof(list1) / sizeof(int);

    for (int i = 1; i < size; i++)
    {
        insertElement(&a, list1[i]);
        insertElement(&b, list2[i]);
    }

    int acc = 0;
    treeToList(list1, a, &acc);
    acc = 0;
    treeToList(list2, b, &acc);

    int indexLeft = 0;
    int indexRight = 0;
    int output = 0;
    acc = 0;

    while (indexLeft < 1000)
    {
        if (indexRight == (1000 - 1))
        {
            list1[indexLeft++] = 0;
            continue;
        }

        if (list1[indexLeft] > list2[indexRight])
        {
            acc = 0;
            indexRight++;
            continue;
        }

        if (list1[indexLeft] == list2[indexRight])
        {
            acc++;
            indexRight++;
            continue;
        }

        if (list1[indexLeft] < list2[indexRight])
        {
            output += list1[indexLeft] * acc;
            acc = 0;
            indexLeft++;
        }
    }
  
    std::cout << output << "\t 22539317" <<std::endl;
}