#include <iostream>

using namespace std;
/* Selects the minimum of the row , and finds the number of col and save it in jmin*/
int rMinSelect(int c, int rN, int **a, int &jmin);
/* Selects the maximum of the col that was found by rMinSelect*/
int cMaxSelect(int rN, int c, int **a, int &imax);

int main()
{
    int **arry;
    int r, c, s = 0, i;
    int lR, lC;
    int rowMin, colMax;

    cin >> r;
    cin >> c;

    arry = new int*[c];
    if (arry == NULL)
    {
        cout << "--no space left--" << endl;
    }
    for (i = 0; i < r; i++)
    {
        arry[i] = new int[c];
        if (arry[i] == NULL)
        {
            cout << "--no space left--" << endl;
        }
    }

    for (i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
             cin >> arry[i][j];
        }
    }

    for (i = 0; i < r; i++)
    {
        rowMin = rMinSelect(c, i, arry, lC);
        colMax = cMaxSelect(r, lC, arry, lR);
        if (rowMin == colMax)
        {
            ++s;
            cout << lR << " " << lC <<" "<< rowMin << endl;
        }
    }
    if (s <= 0)
    {
        cout << "Not found!" << endl;
    }

    for (i = 0; i < r; i++)
    {
        delete [] arry[i];
    }
    delete [] arry;

    return 0;
}

int rMinSelect(int cN, int r, int **a, int &jmin)
{
    int j;
    int rowMin = a[r][0];
    jmin = 0;
    for (j = 1; j < cN; j++)
    {
        if (rowMin > a[r][j])
        {
            rowMin = a[r][j];
            jmin = j;
        }
    }
    return rowMin;
}
int cMaxSelect(int rN, int c, int **a, int &imin)
{
    int colMax = a[0][c];
    int i;
    imin = 0;
    for (i = 1; i < rN; i++)
    {
        if (colMax < a[i][c])
        {
            colMax = a[i][c];
            imin = i;
        }
    }
    return colMax;
}

