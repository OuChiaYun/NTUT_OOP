#include <iostream>

using namespace std;

int check_x(bool **grid)
{

    int x = 9;

    for (int i = 0; i < 10; i++)
    {
        int tmp = 0;
        for (int j = 0; j < 10; j++)
        {
            tmp |= grid[i][j];
        }

        x -= tmp;
    }

    return x + 1;
}

int check_y(bool **grid)
{
    int y = 0;

    for (int i = 0; i < 10; i++)
    {
        int tmp = 0;
        for (int j = 0; j < 10; j++)
        {
            tmp |= grid[j][i];
        }

        y += tmp;
    }

    return y - 1;
}

void moveTop(bool **grid)
{
    int x = check_x(grid);
    int y = check_y(grid);

    if (x - 1 >= 0)
    {
        grid[x - 1][y] = true;
    }
    else
    {
        throw(std::string("out of range"));
    }
}

void moveRight(bool **grid)
{
    int x = check_x(grid);
    int y = check_y(grid);

    if (y + 1 <= 9)
    {
        grid[x][y + 1] = true;
    }
    else
    {
        throw(std::string("out of range"));
    }
}

void printGrid(bool **grid)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int calRow(bool **grid, int r)
{

    if (r < 0 || r > 9)
    {
        throw(string("out of range"));
    }

    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        if (grid[r][i] == true)
        {
            count++;
        }
    }

    return count;
}

int calCol(bool **grid, int c)
{

    if (c < 0 || c > 9)
    {
        throw(string("out of range"));
    }

    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        if (grid[i][c] == true)
        {
            count++;
        }
    }

    return count;
}
