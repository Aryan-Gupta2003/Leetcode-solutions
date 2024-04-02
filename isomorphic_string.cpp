#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool isIsomorphic(string s, string t)
    {
        vector<int> a(256, 0);
        vector<int> b(256, 0);

        int len = s.length();

        if (len != t.length())
        {
            return false;
        }

        for (int i = 0; i < len; i++)
        {
            if (a[s[i]] != b[t[i]])
            {
                return false;
            }

            a[s[i]] = i + 1;
            b[t[i]] = i + 1;
        }
        return true;
    }
};

int main()
{
    Solution o1;
    string s = "egg";
    string t = "add";
    bool result = o1.isIsomorphic(s, t);
    cout << "Isomorphic String : " << (result == 1 ? "True" : "False") << endl;
    return 0;
}