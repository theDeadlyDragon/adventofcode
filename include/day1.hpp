
#include <iostream>
#include "datastructures.hpp"
#include "data.h"


void day1(){
    std::cout << "Hello world" << std::endl;

    binElement a(list1[0]);
    binElement b(list2[0]);

    int size = sizeof(list1)/sizeof(int);

    for(int i =1; i<size; i++){
        insertElement(&a, list1[i]);
        insertElement(&b, list2[i]);
    }
    
    int acc = 0;
    treeToList(list1,a,&acc);
    acc = 0;
    treeToList(list2,b,&acc);

    int num = 0;

    for(int i =0; i<size; i++){
        num += abs(list1[i]-list2[i]);
    }
    std::cout << "done: " << num << std::endl;
}