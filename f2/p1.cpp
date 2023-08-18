#include<bits/stdc++.h>
//#include<iostream>
using namespace std;


int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
    int t;
    cin >> t;
    
    while (t--)
    {
        long long int n, m;
        string str;
        cin >> n;
        cin >> m;
        cin >> str;
        string s; s=str;
		
        for (long long int i = 0; i < m; i++)
        {
            for (int j = 0; j < n ; j++)
            {
                if (s[j] == '0')
                {
                    if (str[j + 1] == '1' && str[j - 1] != '1')
                    {
                        s[j] = '1';
                    }
                    else if (str[j + 1] != '1' && str[j - 1] == '1')
                    {
                        s[j] = '1';
                    }
                }
            }
			if(str==s) break;
            str=s ;
        }
        cout << str << endl;
    }

    return 0;
}
