#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("encryption.txt");

    if (!fin.is_open())
    {
        cout << "Error opening file";
        return 1;
    }
    else
    {
        char ch, chn;
        string line;
        int count = 0;
        while (!fin.eof())
        {
            getline(fin, line);
            for (int i = 0; i < 8; i++)
            {
                ch = line[i];
                fout << ch;
                cout << ch;
                if (i == 7)
                {
                    fout << "\n";
                    cout << "\n";
                }
            }

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

    return 0;
}