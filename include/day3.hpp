#include "../data/dataDay2.h"
#include <iostream>
#include <fstream>

const char filename[] = "/Users/mauricebal/vs_code/adventofcode/data/dataDay3.txt";
int8_t list[128];
int lastValue = 0;


void init(){
    for(int i =0 ; i<=128; i++)
        list[i] = 255;

    for(int i ='0' ; i<='9'; i++)
        list[i] = 10;

    list['m'] = 1;
    list['u'] = 2;
    list['l'] = 3;
    list['('] = 4;
    list[','] = 5;
    list[')'] = 6;

}

int day3()
{
    init();
    lastValue = 0;

    std::string data;
    std::string tempData;
    std::vector<int> leftValue;
    std::vector<int> rightValue;
    int value;

    std::ifstream file(filename);

    if (!file) {
        std::cout << "Unable to open file";
        return 1;
    }

    char ch;
    while (file.get(ch)) {
        auto a = list[ch];
        auto b = ch;
        
        if(lastValue == 0 && list[ch] != 1)
            continue;

        if((list[ch] - lastValue) != 1 && list[ch] != 10){
            tempData = "";
            lastValue = 0;
            continue;
        }

        if(list[ch] == 6)
        {   
            lastValue = 0;
            continue;
        }

        if(list[ch] != 10)
            lastValue = list[ch];

        if(list[ch] == 10)
            value = value*10;  
        
        tempData += ch;
    }

    std::cout << tempData <<std::endl; 
}