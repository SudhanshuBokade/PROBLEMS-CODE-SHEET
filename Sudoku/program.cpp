#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> toVisit;
int size_toVisit;

void checkHorizontal(vector<vector<int>>& arr ,vector<bool> &check, int row)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[row][i] != 0)
        {
            check[arr[row][i] - 1] = false;
        }
    }
}

void checkVertical(vector<vector<int>>& arr ,vector<bool> &check, int col)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][col] != 0)
        {
            check[arr[i][col] - 1] = false;
        }
    }
}

void checkSquare(vector<vector<int>>& arr ,vector<bool> &check, int row, int col)
{
    int start_row = row / 3 * 3;
    int start_col = col / 3 * 3;

    for (int i = start_row; i < start_row + 3; i++)
    {
        for (int j = start_col; j < start_col + 3; j++)
        {
            if (arr[i][j] != 0)
            {
                check[arr[i][j] - 1] = false;
            }
        }
    }
}

bool isSolve(vector<vector<int>> &arr, int index, vector<vector<vector<int>>> &ans)
{
    if (index == size_toVisit)
    {
        ans.push_back(arr);
        return true;
    }
    else
    {
        vector<bool> check(9, true);
        int i = toVisit[index].first, j = toVisit[index].second;
        checkHorizontal(arr , check, i);
        checkVertical(arr , check, j);
        checkSquare(arr , check, i, j);
        int flag = 0 ;
        for (int k = 0; k < 9; k++)
        {
            if (check[k])
            {
                arr[i][j] = k + 1;
                if (isSolve(arr , index + 1 ,ans ))
                {
                    flag = 1 ;
                }
                arr[i][j] = 0;
            }
        }
        return (flag == 1);
    }
}

int main()
{
    vector<vector<int>> arr = {
        {0, 4, 0, 0, 1, 9, 0, 0, 3},
        {0, 7, 0, 0, 0, 6, 0, 0, 0},
        {0, 0, 0, 0, 7, 0, 0, 0, 1},
        {0, 5, 1, 0, 0, 0, 0, 4, 0},
        {7, 0, 0, 0, 0, 3, 0, 9, 0},
        {0, 0, 2, 0, 8, 0, 0, 0, 0},
        {0, 0, 9, 3, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},

    };

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            if (arr[i][j] == 0)
            {
                toVisit.push_back({i, j});
            }
        }
    }
    size_toVisit = toVisit.size();
    cout << endl;
    vector<vector<vector<int>>> ans;
    if (isSolve(arr, 0, ans))
    {
        cout<<"no of possible ans are " <<ans.size()<<endl;
        // for (auto m : ans)
        // {
        //     for (int i = 0; i < 9; i++)
        //     {
        //         if (i % 3 == 0)
        //         {
        //             cout << endl;
        //         }
        //         for (int j = 0; j < 9; j++)
        //         {
        //             if (j % 3 == 0)
        //                 cout << " ";
        //             cout << m[i][j] << " ";
        //         }
        //         cout << endl;
        //     }
        // }
    }
    else
    {
        cout << "\nSudoku not solvable." << endl;
    }
    return 0;
}
