#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

string getLCS(string x, string y)
{
    int x_length = x.length(), y_length = y.length();

    vector<vector<int>> lcs;
    lcs.resize(x_length + 1);

    for(int i = 0; i <= x_length; i++)
        lcs[i].resize(y_length + 1);

    for(int i = x_length - 1; i >= 0; i--)
    {
        for(int j = y_length - 1; j >= 0; j--)
        {
            if(x[i] == y[j])
            {
                lcs[i][j] = lcs[i + 1][j + 1] + 1;
            }
            else
            {
                lcs[i][j] = max(lcs[i + 1][j], lcs[i][j + 1]);
            }
        }
    }

    string result;
    int i = 0, j = 0;
    while(lcs[i][j] != 0 && i < x_length && j < y_length)
    {
        if(x[i] == y[j])
        {
            result.push_back(x[i]);
            i++;
            j++;
        }
        else
        {
            if(lcs[i][j] == lcs[i + 1][j])
                i++;
            else
                j++;
        }
    }
    return result;

}

int main()
{
    string x;
    string y;
    string res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, x);
        getline(fin, y);
        fin.close();
    }

    res = getLCS(x, y);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}