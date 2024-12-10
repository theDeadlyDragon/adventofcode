
namespace day4
{
    const char filenameDay4[] = "/Users/mauricebal/vs_code/adventofcode/data/day4.txt";
    const int fileSize = 19740;
    bool color[fileSize];
    char content[fileSize];
 
    int pattern[15][3] = {
        {-2,2,2},{0,2,2},{2,2,2},
        {-1,1,1},{0,1,1},{1,1,1},
        {-1,0,1},{0,0,0},{1,0,1},
        {-1,-1,1},{0,-1,1},{1,-1,1},
        {-2,-2,2},{0,-2,2},{2,-2,2},
    };

    const int rowLenght = 141;
    const char search[] = "XMAS";

    int8_t list[128];

    int totalWordCount = 0;

    void init()
    {
        for (int i = 0; i <= 128; i++)
            list[i] = 0;

        list['X'] = 1;
        list['M'] = 0;
        list['A'] = 1;
        list['S'] = 2;
    }

    void get(int index)
    {
        int wordIndexes[16];
        int wordCount = 0;
        int mull = -2;

       

        for (int i = 0; i < 5 * 5; i++)
        {
            int y = -2 + (i % 5);
            int x = (i / 5) - 2;

            if((x != 0 && y!=0) && abs(x) != abs(y))
                continue;

            

            if (i % 5 == 0 && i != 0)
            {
                mull++;
                std::cout << std::endl;
            }

            int newInd = index + rowLenght * x + y;

            std::cout << x << ":" << y  << "\t" << newInd<< std::endl;

            if (newInd > 0 && newInd < fileSize)
            {
                std::cout << content[newInd];
                int listValue = (abs(x) > abs(y) ? abs(x) : abs(y));

                char test = content[newInd];
                if (list[content[newInd]] == listValue)
                {
                    subfield[i] = list[content[newInd]];
                }

                if (list[content[newInd]] == 2)
                    wordIndexes[wordCount++] = i;
            }
        }
        std::cout << std::endl;

        for(int x = 0; x<5; x++){
            for(int y = 0; y< 5; y++)
            {
                std::cout << subfield[x*5+y];
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;

        // std::cout << std::endl;
        int wordCountFunc = 0;
        for (int i = 0; i < wordCount; i++)
        {
            int x = -2 + (wordIndexes[i] % 5);
            int y = (wordIndexes[i] / 5) - 2;

            int tempX = x;
            int tempY = y;
            for (int b = 3; b >= 0; b--)
            {
                 

                int newIndex = index + tempY * rowLenght + tempX;

                if (newIndex < 0 && newIndex >= fileSize)
                    continue;

                if (x != 0)
                    tempX -= x / (x * -1);
                if (y != 0)
                    tempY -= y / (y * -1);

                char display = content[newIndex];
                if (content[newIndex] != search[b])
                    break;

                // std::cout << content[newIndex] << ":" << newIndex << std::endl;
                if (content[newIndex] == 'X')
                {
                    for (int z = 0; z < 4; z++)
                    {
                        if (x != 0)
                            tempX += x / (x * -1);
                        if (y != 0)
                            tempY += y / (y * -1);
                         newIndex = index + tempY * rowLenght + tempX;
                        color[index] = true;
                        
                    }
                    totalWordCount++;
                    wordCountFunc++;
                    break;
                }

                
            }
        }
        if(wordCountFunc<0)
content[index] = '0' +wordCountFunc;
        // std::cout << std::endl;
    }

    int day4()
    {
        FILE *fp = fopen(filenameDay4, "rb");
        size_t nbytes = 0;

        if (!fp)
        { /* validate file open for reading */
            perror("file open failed");
            return 1;
        }

        nbytes = fread(content, 1, 20000, fp);

        char ch;
        int test[8];

        init();

        // content = new std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

        int index = 0;
//541
        while (content[index] != '\0')
        {
            // std::cout << content[index];

            if (content[index] == 'M')
                get(index);

            // if (color[index])
            //     std::cout << content[index];
            // else
            //     std::cout << "\033[1;31m" << content[index] << "\033[0m";

            // if(content[index] == '\n')
            // std::cout << index << std::endl ;
            index++;
        }

        index = 0;
        while (content[index] != '\0')
        {
            if (!color[index])
                std::cout << content[index];
            else
                std::cout << "\033[1;31m" << content[index] << "\033[0m";
            index++;
        }

        std::cout << std::endl
                  << totalWordCount << std::endl;
    }
    // 2118L
}