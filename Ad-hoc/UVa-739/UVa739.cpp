//You're reading zeeshan_amjad's code

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio (0), cin.tie (0)
#define MOD 1e9 + 7
#define ll long long
#define ld long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define rFOR(i, a, b) for(int i = a; i > b; i--)
#define PAIR pair <int, int>
#define PQ priority_queue <ld>
#define MAP map <char, char>
#define pb push_back

using namespace std;

string check = "AEIOUYWH";
MAP code;

char *solve (char *s, int l);

int main () {
    FASTIO;
    code['B'] = code['P'] = code['F'] = code['V'] = '1';
    code['C'] = code['S'] = code['K'] = code['G'] = code['J'] = code['Q'] = code['X'] = code['Z'] = '2';
    code['D'] = code['T'] = '3';
    code['L'] = '4';
    code['M'] = code['N'] = '5';
    code['R'] = '6';
    printf ("         NAME                     SOUNDEX CODE\n");
    char s[25], soundex[6];
    while ((scanf ("%s", s)) != EOF) {
        int len = 1;
        soundex[0] = s[0];
        FOR(i, 1, strlen (s)) {
            if (len == 4)
                break;
            if (check.find (s[i]) > 7 && code[s[i]] != code[s[i - 1]])
                soundex[len++] = code[s[i]];
        }
        while (len <= 4)
           soundex[len++] = '0';
        soundex[4] = '\0';
        printf ("         %-25s%s\n", s, soundex);
    }
    printf ("                   END OF OUTPUT\n");
    return 0;
}
