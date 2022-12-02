#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Da
{
    unsigned short row : 3;
    unsigned short pos : 3;
    unsigned short p2 : 1; // біт парності перших двох рядків
    unsigned short pp : 1; // біт парності попереднього рядка
    unsigned short ASCII : 8;
};
int main()
{
    char s[8][9], ch;
    char so[8][9];
    unsigned char vladik;
    unsigned short t, b, i, j, l, k, r, w;
    char st[9];

    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("encryption.txt", ios::out | ios::binary);

    if (!fin.is_open())
    {
        cout << "Error opening file";
        return 1;
    }
    else
    {

        for (i = 0; i < 8; i++)
        {
            fin.get(s[i], 9, '\0');
            fin.get(ch);
        }
        for (i = 0; i < 8; i++)
        {
            for (l = 0; l < 8; l++)
            {
                if (s[i][l] == '\0')
                    s[i][l] == ' ';
                s[i][l + 1] == '\0';
            }
        }
        for (i = 0; i < 8; i++)
        {
            for (l = 0; l < 8; l++)
            {
                Da.row = 13;
                r = Da.row << Da.row; // 0000 0000 0000 0iii <- i
                vladik = s[i][l];
                r |= vladik << 5; // 0000 0000 00ll l000 <- l
                b = 0;
                t = 1;
                for (k = 0; k < 6; k++)
                {
                    if (r & t)
                    {
                        if (b == 0)
                            b = 1;
                        else
                            b = 0;
                    }
                    t <<= 1;
                }
                w = 1 << 4;
                if (b)
                {
                    r |= w;
                }

                r |= l << 1;

                t = 1;
                b = 0;
                for (k = 8; k < 13; k++)
                {
                    if (r & t)
                    {
                        if (b == 0)
                            b = 1;
                        else
                            b = 0;
                    }
                    t <<= 1;
                }
                w = 1;
                if (b)
                {
                    r |= w;
                }

                fout << r;
            }
            fout << ' ' << '\n';
        }
    }
    return 0;
}