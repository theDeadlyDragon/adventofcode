#include "../data/dataDay2.h"
#include <iostream>
#include <fstream>

const char filename[] = "/Users/mauricebal/vs_code/adventofcode/data/dataDay3.txt";
int8_t list[128];

void init()
{
    for (int i = 0; i <= 128; i++)
        list[i] = 254;

    for (int i = '0'; i <= '9'; i++)
        list[i] = 10;

    list['m'] = 1;
    list['u'] = 2;
    list['l'] = 3;
    list['('] = 4;
    list[','] = 5;
    list[')'] = 6;

    list['d'] = -1;
    list['o'] = -2;
    list['n'] = -3;
    list['\''] = -4;
    list['t'] = -5;
}

int day3()
{
    init();
    int lastCharKey = 0;

    std::string data;
    std::string tempData;
    std::vector<int> leftValue;
    std::vector<int> rightValue;
    long output = 0;
    int count = 0;
    int mulValues[2] = {0, 0};

    std::ifstream file(filename);

    if (!file)
    {
        std::cout << "Unable to open file";
        return 1;
    }

    char ch;
    while (file.get(ch))
    {
        auto a = list[ch];
        auto b = ch;

        if (lastCharKey == 0 && list[ch] != 1)
            continue;

        if ((list[ch] - lastCharKey) != 1 && list[ch] != 10)
        {
            mulValues[0] = 0;
            mulValues[1] = 0;
            lastCharKey = 0;
            continue;
        }

        if (list[ch] == 6)
        {
            output += mulValues[0] * mulValues[1];

            mulValues[0] = 0;
            mulValues[1] = 0;
            count++;

            lastCharKey = 0;
            continue;
        }

        if (list[ch] != 10)
            lastCharKey = list[ch];

        // add char to value  mulValues add index 0 or 1
        if (list[ch] == 10)
        {
            mulValues[lastCharKey == list[',']] = mulValues[lastCharKey == list[',']] * 10 + (ch - '0');
        }
        tempData += ch;
    }

    std::cout << output << " : " << count << std::endl;
    // 110869077 l
    // 174103751
    // 8700803669 h
}


int day3_1()
{
    init();
    int lastCharKey = 0;

    std::string data;
    std::string tempData;
    std::vector<int> leftValue;
    std::vector<int> rightValue;
    long output = 0;
    int count = 0;
    int mulValues[2] = {0, 0};
    int doDont = 0;
    bool notAdding = false;

    std::ifstream file(filename);

    if (!file)
    {
        std::cout << "Unable to open file";
        return 1;
    }

    char ch;
    while (file.get(ch))
    {
        if (doDont != 0 && ch == '(')
        {
            lastCharKey = 5;
            continue;
        }
 
        if (lastCharKey == 0 && abs(list[ch]) != 1)
            continue;

        if (abs(list[ch] - lastCharKey) != 1 && list[ch] != 10)
        {
            mulValues[0] = 0;
            mulValues[1] = 0;
            lastCharKey = 0;
            continue;
        }

        if (list[ch] == 6)
        {
            if (!notAdding)
                output += mulValues[0] * mulValues[1];

            mulValues[0] = 0;
            mulValues[1] = 0;
            count++;

            lastCharKey = 0;

            if (doDont == 1)
                notAdding = false;
            if (doDont == 2)
                notAdding = true;

            doDont = 0;

            continue;
        }

        if (list[ch] == -2 || list[ch] == -5)
        {
            doDont = (list[ch] == -2 ? 1 : 2);
        }

        if (list[ch] != 10)
            lastCharKey = list[ch];

        // add char to value  mulValues add index 0 or 1
        if (list[ch] == 10)
        {
            mulValues[lastCharKey == list[',']] = mulValues[lastCharKey == list[',']] * 10 + (ch - '0');
        }
        tempData += ch;
    }

    std::cout << output << " : " << count << std::endl;
    // 100411201 
  
}