#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    unsigned short t, b, i, j, l, k, r, w;

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
        char ch[8], chn, cha[8];
        string line;
        int count = 0;

        // fout << "Our encrypted code is: " << endl;

        while (!fin.eof())
        {
            fin.getline(ch, 8);
            count = 0;
            cout << "\n";
            for (i = 0; i < 7; i++)
            {
                if (ch[i] == '\0' || ch[i] == '')
                {
                    ch[i] = ' ';
                    ch[i + 1] = ' ';
                    fout << ch[i];
                    count++;
                }

                fout << ch[i];
                ch[i] == cha[i];

                // if (ch[i] == '\0' || ch[i] == '\n')
                // {
                // count++;
                // }
                // cout << count;
            }
            fout << endl;
            //     getline(fin, line);
            //     for (int i = 0; i < 8; i++)
            //     {
            //         ch = line[i];
            //         fout << ch;
            //         cout << ch;
            //         if (i == 7)
            //         {
            //             fout << "\n";
            //             cout << "\n";
            //         }
            //     }

            // fin.get(ch);
            // if (ch == '\0' || ch == '\n')
            // {
            //     fout << ' ';
            //     cout << '0';
            // }
            // else
            // {
            //     fout << ch;
            // }
            // count++;
            // if (count == 8)
            // {
            //     fout << endl;
            //     count = 0;
            // }
        }

        fout << "\n";
        fout << "\n";
        fout << "Encrypted message: ";
        fout << "\n";
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                fout << "00" << j + 1 << int(cha[i]) << "\n";
            }
        }
    }
    fin.close();
    fout.close();

    // if (!fout.is_open())
    // {
    //     cout << "Error opening file" << endl;
    //     return 1;
    // }
    // else
    // {
    //     fout << "Our encrypted code is: " << endl;
    // }

    // fout.close();
    // cin.get();
    return 0;
}