#include "../data/dataDay2.h"
#include <iostream>

void day2()
{
    int count = 0;
    for (int i = 0; i < 1000; i++)
    {
        bool sign;

        for (int y = 1; y < 8; y++)
        {
            int diff = list2d[i][y - 1] - list2d[i][y];
            int temp = list2d[i][y];

            if (y == 1)
            {
                if ((abs(diff)) > 3 || diff == 0)
                {
                    std::cout << " " << list2d[i][y - 1] << " \033[1;31m" << list2d[i][y] << " \033[0m";
                    break;
                }

                sign = ((diff) >= 0);
                continue;
            }

            if ((diff >= 0) != sign || abs(diff) > 3 || diff == 0)
            {
                std::cout << " \033[1;31m" << list2d[i][y] << "\033[0m";
                break;
            }

            std::cout << " " << list2d[i][y];

            if (y == 7 || list2d[i][y + 1] == 0)
            {
                count++;
                break;
            }
        }
        std::cout << std::endl;
    }

    std::cout << count << std::endl;
}

void day2_2()
{
    int count = 0;
    for (int i = 0; i < 1000; i++)
    {
        int sign[2] = {0, 0}; // {deces,ascending}
        int accDiff = 0;
        int foul = 0;
        int last = list2d[i][0];
        int diff = last - list2d[i][1];
        int foulReg[8] ={0,0,0,0,0,0,0,0};
        std::string numList = std::to_string(list2d[i][0]) + " ";
        // std::cout << last;
        for (int y = 1; y < 8; y++)
        {
            // diffList += std::to_string(diff) + " ";
            if (list2d[i][y] == 0)
                break;
            if(i==144)
                int i= 0;

            if (foul > 1)
                continue;

            diff = last - list2d[i][y];

            foulReg[y] = diff / abs(diff);

            //if(sign[diff >= 0] == 1)

            //adds 
            sign[diff < 0] += diff != 0;

            last = list2d[i][y];

            if(accDiff<0 && abs(accDiff +diff) <=3)
                accDiff =0;

            //checks for duplicates and diff bigger then 3
            int errorDec = (diff == 0) || (abs(diff) > 3) || accDiff !=0;
            foul += errorDec;

            if((abs(diff) > 3))
                accDiff = diff;

            foulReg[y] += (foulReg[y]*errorDec);

            numList += std::to_string(list2d[i][y]) + " ";
        }
        int temp = foul;

        if(sign[0] >= sign[1])
            foul += sign[1];
        else if(sign[0] < sign[1])
            foul += sign[0];

        if(foul == 2 && temp ==1){
            for(int x=0; x<8; x++)
            {
                if((sign[0] >= sign[1] && foulReg[x] ==-1) ||(sign[0] < sign[1] && foulReg[x] ==1) )
                    break;;
                if(sign[0] < sign[1] && foulReg[x] <-1)
                    foul = 1;
                if(sign[0] >= sign[1] && foulReg[x] >1)
                    foul = 1;
            }
        }

        if (foul <= 1)
        {
            count++;
            if (temp >=1)
                std::cout << i << ": " << sign[0]<<":" <<sign[1] <<" " << numList << std::endl;
        }
        else if(foul == 2 && temp<2)
        {
           // std::cout << i << ": \033[1;31m" << numList << "\033[0m \t\t\t" << foul << std::endl;
        }
        
    }

    std::cout << count << std::endl;
    // 432 low
    // 492, 574 high
    // 469, ----488
}
void day2_2()
{
    int count = 0;
    for (int i = 0; i < 1000; i++)
    {
        int sign[2] = {0, 0}; // {deces,ascending}
        int accDiff = 0;
        int foul = 0;
        int last = list2d[i][0];
        int diff = last - list2d[i][1];
        int foulReg[8] ={0,0,0,0,0,0,0,0};
        std::string numList = std::to_string(list2d[i][0]) + " ";
        // std::cout << last;
        for (int y = 1; y < 8; y++)
        {
            // diffList += std::to_string(diff) + " ";
            if (list2d[i][y] == 0)
                break;
            if(i==144)
                int i= 0;

            if (foul > 1)
                continue;

            diff = last - list2d[i][y];

            foulReg[y] = diff / abs(diff);

            //if(sign[diff >= 0] == 1)

            //adds 
            sign[diff < 0] += diff != 0;

            last = list2d[i][y];

            if(accDiff<0 && abs(accDiff +diff) <=3)
                accDiff =0;

            //checks for duplicates and diff bigger then 3
            int errorDec = (diff == 0) || (abs(diff) > 3) || accDiff !=0;
            foul += errorDec;

            if((abs(diff) > 3))
                accDiff = diff;

            foulReg[y] += (foulReg[y]*errorDec);

            numList += std::to_string(list2d[i][y]) + " ";
        }
        int temp = foul;

        if(sign[0] >= sign[1])
            foul += sign[1];
        else if(sign[0] < sign[1])
            foul += sign[0];

        if(foul == 2 && temp ==1){
            for(int x=0; x<8; x++)
            {
                if((sign[0] >= sign[1] && foulReg[x] ==-1) ||(sign[0] < sign[1] && foulReg[x] ==1) )
                    break;;
                if(sign[0] < sign[1] && foulReg[x] <-1)
                    foul = 1;
                if(sign[0] >= sign[1] && foulReg[x] >1)
                    foul = 1;
            }
        }

        if (foul <= 1)
        {
            count++;
            if (temp >=1)
                std::cout << i << ": " << sign[0]<<":" <<sign[1] <<" " << numList << std::endl;
        }
        else if(foul == 2 && temp<2)
        {
           // std::cout << i << ": \033[1;31m" << numList << "\033[0m \t\t\t" << foul << std::endl;
        }
        
    }

    std::cout << count << std::endl;
    // 432 low
    // 492, 574 high
    // 469, ----488
}