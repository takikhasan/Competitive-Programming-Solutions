#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int Grundy(int x, int y)
{
    if (dp[x][y] != -1) return dp[x][y];
    if (x == 0) return 0;
    set<int> st;
    st.insert(Grundy(x - 1, y));
    for (int i = 1; i <= y; i++) {
        st.insert(Grundy(x, y - i));
    }
    int ret = 0;
    while (st.find(ret) != st.end())
        ret++;
    return dp[x][y] = ret;
}


int main()
{
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            /*
                i is first pile, j is second.
                From first pile 1 at a time, second pile is normal nim pile.
                Game ends only when first pile is empty.
            */
            cout << i << " " << j << " " << Grundy(i, j) << endl;
        }
    }

    /*
        As we can see, when first pile is 1, Grundy number is second pile + 1.
        Otherwise,
            When first pile is even, Grundy number = second pile.
            When first pile is odd, Grundy number = second pile + (second pile % 2) ? -1 : 1.
    */

    /*
        We have proven the green hackenbush solution and colon principle with i == 1.
        And we have established a pattern when i != 1 effectively solving LightOJ 1355.
    */
}
