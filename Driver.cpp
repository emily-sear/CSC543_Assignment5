#include <iostream> 
#include <string.h>

using namespace std;

string longestCommonSubString(char* string1, char* string2)
{
    int len = strlen(string1);
    cout << len << endl;
    int table[len + 1][len + 1];
    int longestNum = 0;
    string longestSubString = "";


    for(int i = 0; i < (len + 1); i++)
    {
        for(int j = 0; j < (len+1); j++)
        {
            if(i == 0 || j == 0)
            {
                table[i][j] = 0; 
            }
            else if (string1[i -1] == string2[j - 1])
            {
                table[i][j] = table[i -1][j -1] + 1;
                cout << string1[i -1] << endl;
                int beforeNum = longestNum; 
                longestNum = max(longestNum, table[i][j]);
                if(longestNum > beforeNum)
                {
                    longestSubString = string1[i -1] + longestSubString;
                }
                cout << longestNum << endl;
            }
            else
            {
                table[i][j] = 0;
            }
        }
    }
    return longestSubString;
}

int main()
{
    char string1[] = "ABABC";
    char string2[] = "BABCA";

    cout << "The longest common string is: " << longestCommonSubString(string1, string2) << endl;
    return 0;
}
