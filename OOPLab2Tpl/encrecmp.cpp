#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    char s[8][9], ch;
    char so[8][9];
    unsigned short sh_dat[64], sd2[64], r, w;
    char st[9];
    ifstream ifs("input.txt");
    if (!ifs)
    {
        cout << "File is not open" << endl;
        return -1;
    }
    ofstream ofs("encryption.txt");
    ofstream ofsb("encryption.txt", ios::out | ios::binary);
    unsigned short i, j, l, b, k, t;
    for (i = 0; i < 8; i++)
    {
        ifs.get(s[i], 9, '\0');
        ifs.get(ch);
    }
    j = 0;
    for (i = 0; i < 8; i++)
        for (l = 0; l < 8; l++)
        {
            r = i; // 0000 0000 0000 0___ <- i
            w = l << 3;
            r |= w; // 0000 0000 00__ _000 <- l
            b = 0;
            t = 1;
            for (k = 0; k < 6; k++) // обчислення біта парності
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
            w = 1 << 6;
            if (b)
                r |= w; // 0000 0000 0_000 0000 <- b
            w = s[i][l];
            w <<= 7;
            r |= w;
            if (r & 0x4000)
                r |= 0x8000;
            sh_dat[j] = r;
            j++;
            ofs << hex << r << ' ';
            cout << hex << r << endl;
        }
    ofsb.write((char *)sh_dat, 64 * sizeof(unsigned short));
    ofsb.close();
    ifs.close();
    // for (i = 0;i < 64;i++) sh_dat[i] = 0;
    ifs.open("outb.dat", ios::in | ios::binary);
    ifs.read((char *)sd2, 64 * sizeof(unsigned short));
    short indi, indj;
    for (i = 0; i < 64; i++)
    {
        r = sd2[i];
        indj = r & 0x0038;
        indj >>= 3;        // 0000 0000 0011 1000 = 0x0038
        indi = r & 0x0007; // 0000 0000 0000 0111 = 0x0007
        w = r & 0x7f80;    // 0111 1111 1000 0000 = 0x7f80
        w >>= 7;
        ch = w;
        so[indi][indj] = ch;
    }
    for (i = 0; i < 8; i++)
    {
        for (l = 0; l < 8; l++)
            cout << so[i][l];
        cout << endl;
    }
    return 0;
}