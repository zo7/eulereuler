#include <iostream>
#include <sstream>


int main(void)
{
    // Our triangle of numbers

    std::istringstream ss( "75 "
                           "95 64 "
                           "17 47 82 "
                           "18 35 87 10 "
                           "20 04 82 47 65 "
                           "19 01 23 75 03 34 "
                           "88 02 77 73 07 63 67 "
                           "99 65 04 28 06 16 70 92 "
                           "41 41 26 56 83 40 80 70 33 "
                           "41 48 72 33 47 32 37 16 94 29 "
                           "53 71 44 65 25 43 91 52 97 51 14 "
                           "70 11 33 28 77 73 17 78 39 68 17 57 "
                           "91 71 52 38 17 14 91 43 58 50 27 29 48 "
                           "63 66 04 68 89 53 67 30 73 16 69 87 40 31 "
                           "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23" );

    int level = 1;
    long *last_level, *current_level;

    // Get the first level from the tree
    last_level = new long[level];
    ss >> last_level[0];

    // Scan through the stream
    while (!ss.eof())
    {
        level++;

        current_level = new long[level];

        for (int i = 0; i < level; i++)
        {
            // Get the number
            ss >> current_level[i];

            // Add the greatest value above our current value and store it in its place.
            // This will make our array the list of greatest possible sums for each elements.

            if (i == 0)
                current_level[i] += last_level[i];
            else if (i == level-1)
                current_level[i] += last_level[i-1];
            else
                current_level[i] += std::max(last_level[i-1], last_level[i]);                
        }

        delete last_level;
        last_level = current_level;
    }

    // Find the largest sum in that last level

    long answer = 0;

    for (int i = 0; i < level; i++)
        if (current_level[i] > answer)
            answer = current_level[i];

    std::cout << answer << std::endl;

    delete current_level;

    return 0;
}