/*
 * @Description:
 5
ATATGGATGGTGTTTGGCTCTG
TCTCCGGTTGATT
ATATCTTGCGCTCTTGATTCGCATATTCT
GCGTTTCGTTGCAA
TTAACGCACAACCTAGACTT
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-12 15:17:53
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-12 15:26:59
 */
#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n; cin.get(); // 读走换行符
    for (int i=0; i < n; i++) {
        char gen[256]; int j = 0;
        cin.getline(gen, 256);
        while (gen[j] != '\0') {
            char s = gen[j];
            if (s == '\n') break;
            else if (s == 'A') cout << 'T';
            else if (s == 'T') cout << 'A';
            else if (s == 'G') cout << 'C';
            else if (s == 'C') cout << 'G';
            j++;
        }
        cout << endl;
    }
    return 0;
}