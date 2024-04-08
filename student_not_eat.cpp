// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

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
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int c = 0;
        for (int i = 0, j = 0; i < students.size(), j < sandwiches.size();)
        {
            if (students[i] == sandwiches[j])
            {
                i++;
                j++;
                c = 0;
            }
            else
            {
                c++;
                if (c > students.size() - i)
                {
                    c--;
                    break;
                }
                students.push_back(students[i]);
                students.erase(students.begin() + i);
            }
        }
        return c;
    }
};

int main()
{
    Solution o1;
    vector<int> students{1, 1, 1, 0, 0, 1};
    vector<int> sandwiches{1, 0, 0, 0, 1, 1};
    int result = o1.countStudents(students, sandwiches);
    cout << "Number of Students Unable to Eat Lunch : " << result << endl;
    return 0;
}