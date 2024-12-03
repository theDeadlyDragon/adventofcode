#include "dataDay2.h"
#include <iostream>

void day2()
{
    int count = 0;
    for (int i = 0; i < 1000; i++)
    {
        bool sign;
        std::cout <<i<< ": ";
        for (int y = 1; y < 8; y++)
        {
           
            int diff = list2d[i][y - 1] - list2d[i][y];
            int temp = list2d[i][y];

            if (y == 1)
            {
                if ((abs(diff)) > 3 || diff == 0){
                    std::cout<<" \033[1;31m"<<list2d[i][y-1] <<" "<<list2d[i][y] << " \033[0m";
                    break;
                }

                sign = ((diff) >= 0);
                continue;
            }

            if ((diff >= 0) != sign || abs(diff) > 3 || diff == 0){
                std::cout << " \033[1;31m"<< list2d[i][y] << "\033[0m";
                break;
            }
            
            std::cout <<" "<<list2d[i][y];

            if (y == 7 || list2d[i][y+1] == 0)
            {
                count++; 
                break;   
            }
        }
        std::cout <<std::endl;
    }
    
    std::cout << count << std::endl;
}