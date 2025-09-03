#include <iostream>
#include "../src/cookie.h"
using namespace std;

void **delGrid(bool **grid)
{
    for (int i = 0; i < 10; i++)
    {
        delete[] grid[i];
    }
    delete grid;
}

bool **createGrid()
{
    bool **arr = new bool *[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = new bool[10];
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = false;
        }
    }

    arr[9][0] = true;

    return arr;
}

TEST(COOKIE, tryit)
{

    bool **grid = createGrid();
    printGrid(grid);

    moveTop(grid);
    moveRight(grid);
    moveTop(grid);
    moveRight(grid);

    printGrid(grid);

    // cout << calCol(grid,0)<<endl;
    // cout << calRow(grid,9);

    ASSERT_EQ(calCol(grid, 0), 2);
    ASSERT_EQ(calRow(grid, 9), 1);
    ASSERT_THROW(calCol(grid, 10), string);
    ASSERT_THROW(calRow(grid, 10), string);

    delGrid(grid);
};

TEST(COOKIE, try2)
{
    bool **grid = createGrid();

    moveTop(grid);
    moveTop(grid);
    moveTop(grid);
    moveTop(grid);
    moveTop(grid);

    moveTop(grid);
    moveTop(grid);
    moveTop(grid);
    moveTop(grid);

    ASSERT_THROW(moveTop(grid),string);

    moveRight(grid);
    moveRight(grid);
    moveRight(grid);
    moveRight(grid);
    moveRight(grid);

    moveRight(grid);
    moveRight(grid);
    moveRight(grid);
    moveRight(grid);

    ASSERT_THROW(moveRight(grid),string);

    delGrid(grid);

}