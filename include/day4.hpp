namespace day4
{
    const char filenameDay4[] = "/Users/mauricebal/vs_code/adventofcode/data/day4.txt";
    const int fileSize = 19740;
    char content[fileSize];

    int pattern[4][5][3] = {
        {{-2, -2, 2}, {-1, -1, 1}, {0, 0, 0}, {1, 1, 1}, {2, 2, 2}},
        {{2, -2, 2}, {1, -1, 1}, {0, 0, 0}, {-1, 1, 1}, {-2, 2, 2}},
        {{0, -2, 2}, {0, -1, 1}, {0, 0, 0}, {0, 1, 1}, {0, 2, 2}},
        {{-2, 0, 2}, {-1, 0, 1}, {0, 0, 0}, {1, 0, 1}, {2, 0, 2}}};

    const int rowLenght = 141;
    const char search[] = "XMAS";

    int8_t list[128];

    int totalWordCount = 0;

    void get(int index)
    {
        int wordCount = 0;
        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                int newIndex = index + pattern[x][y][1] * rowLenght + pattern[x][y][0];

                if (newIndex < 0 || newIndex >= fileSize)
                    break;

                char test = content[newIndex];

                if (search[3 - y] != content[newIndex])
                    break;
                if (content[newIndex] == 'X')
                {
                    totalWordCount++;
                    wordCount++;
                }
            }

            for (int y = 0; y < 4; y++)
            {
                int newIndex = index + pattern[x][4 - y][1] * rowLenght + pattern[x][4 - y][0];

                if (newIndex < 0 || newIndex >= fileSize)
                    break;

                char test = content[newIndex];
                if (search[3 - y] != content[newIndex])
                    break;

                if (content[newIndex] == 'X')
                {
                    totalWordCount++;
                    wordCount++;
                }
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;

        if (wordCount > 0)
            content[index] = '0' + wordCount;
    }

    void get2(int index)
    {
        int wordCount = 0;
        if (index < rowLenght)
            return;

        for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                int newIndex = index + pattern[x][1 + y][1] * rowLenght + pattern[x][1 + y][0];

                if (newIndex < 0 || newIndex >= fileSize)
                    break;

                char test = content[newIndex];

                if (search[3 - y] != content[newIndex])
                    break;
                if (content[newIndex] == 'M')
                {
                    wordCount++;
                }
            }
            for (int y = 0; y < 3; y++)
            {
                int newIndex = index + pattern[x][3 - y][1] * rowLenght + pattern[x][3 - y][0];

                if (newIndex < 0 || newIndex >= fileSize)
                    break;

                char test = content[newIndex];
                if (search[3 - y] != content[newIndex])
                    break;
                if (content[newIndex] == 'M')
                {
                    wordCount++;
                }
            }
            std::cout << std::endl;
        }

        if (wordCount == 2)
            totalWordCount++;
    }

    int day4()
    {
        FILE *fp = fopen(filenameDay4, "rb");
        size_t nbytes = 0;
        int index = 0;

        if (!fp)
        { /* validate file open for reading */
            perror("file open failed");
            return 1;
        }

        nbytes = fread(content, 1, 20000, fp);

        while (content[index] != '\0')
        {
            if (content[index] == 'M')
                get(index);

            index++;
        }

        index = 0;
        while (content[index] != '\0')
        {
            std::cout << content[index];

            index++;
        }

        std::cout << std::endl
                  << totalWordCount << std::endl;
    }

    int day4_2()
    {
        FILE *fp = fopen(filenameDay4, "rb");
        size_t nbytes = 0;
        int index = 0;

        if (!fp)
        { /* validate file open for reading */
            perror("file open failed");
            return 1;
        }

        nbytes = fread(content, 1, 20000, fp);

        while (content[index] != '\0')
        {
            if (content[index] == 'A')
                get2(index);

            index++;
        }

        index = 0;

        std::cout << std::endl
                  << totalWordCount << std::endl;
    }

}