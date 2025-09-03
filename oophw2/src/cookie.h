#ifndef COOKIE_H
#define COOKIE_H

#include <iostream>

using namespace std;

int check_x(bool **grid)
{
    int n = 0;
    scanf("%d",&n);
    /* Return the x-coordinate of the lastest of cookie. */

    int x = 9;

    int a;

    for (int i = 0; i < 10; i++)
    {
        a = 0;
        for (int j = 0; j < 10; j++)
        {
            a |= grid[i][j];
        }
        x -= a;
    }

    // printf("\nca: %d cb: %d\n",x+1,y-1);

    return x + 1;
}

int check_y(bool **grid)
{
    /* Return the y-coordinate of the lastest of cookie. */

    int y = 0;

    for (int i = 0; i < 10; i++)
    {
        int b = 0;
        for (int j = 0; j < 10; j++)
        {
            b |= grid[j][i];
        }
        y += b;
    }

    // printf("\nca: %d cb: %d\n",x+1,y-1);

    return y - 1;
}

int print_grid(bool **grid)
{
    /* Print the grid you input. */
    /* Implement this function if necessary, it can help you to check your grid is correct or not. */

    printf("\n/ ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", i);
    }
    printf("\n");
    int dfy = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", dfy);
        dfy++;

        for (int j = 0; j < 10; j++)
        {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }

    return 1;
}

void placeTop(bool **grid)
{
    /* Get the coordinate of the cookie which place lastest from grid. */
    /* You can implement check_x(), check_y() above to get the x, y of the lastest cookie you place. */

    int x = check_x(grid);
    int y = check_y(grid);
    // throw std::string("out of range");

    if (x - 1 < 0)
    {

        throw std::string("out of range");
        return;
    }
    else
    {

        grid[x - 1][y] = true;
    }

    // print_grid(grid);

    /* Check when you place cookie, it will out of bound or not. */
    /* ... */

    /* Place cookie from the top of current cookie. */
}

void placeRight(bool **grid)
{
    /* Get the coordinate of the cookie which place lastest from grid. */
    int x = check_x(grid);
    int y = check_y(grid);

    if (y + 1 > 9)
    {

        throw std::string("out of range");
        return;
    }
    else
    {
        grid[x][y + 1] = true;
    }

    // print_grid(grid);

    /* Check when you place cookie, it will out of bound or not. */

    /* Place cookie from the right of current cookie. */
}

int calcRow(bool **grid, int row)
{
    /* Calculate the count of cookie on the specific row */

    int count = 0;

    if (row > 9 || row < 0)
    {
        return -1;
    }

    for (int i = 0; i < 10; i++)
    {
        if (grid[row][i] == true)
        {
            count++;
        }
    }

    if (count > 10)
    {
        return -1;
    }

    return count;
}

int calcColumn(bool **grid, int column)
{
    /* Calculate the count of cookie on the specific column */

    int count = 0;

    if (column > 9 || column < 0)
    {
        return -1;
    }
    for (int i = 0; i < 10; i++)
    {
        if (grid[i][column] == true)
        {
            count++;
        }
    }

    if (count > 10)
    {
        return -1;
    }

    return count;
}

#endif
