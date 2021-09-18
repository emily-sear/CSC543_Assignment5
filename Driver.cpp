#include <iostream> 
#include <string.h>

using namespace std;
string longestCommonSubString(char* string1, char* string2)
{
    int len = strlen(string1);
    int table[len + 1][len + 1];
    int longestNum = 0;
    int placement1 = 0;
    int placement2 = 0; 
    string longestSubString = "";

    for(int i = 0; i < (len + 1); i++)
    {
        for(int j = 0; j < (len + 1); j++)
        {
            if(i == 0 || j == 0)
            {
                table[i][j] = 0; 
            }
            else if (string1[i - 1] == string2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                int beforeNum = longestNum;
                longestNum = max(longestNum, table[i][j]);
                if(longestNum > beforeNum)
                {
                    placement1 = i - 1;
                }
                
            }
            else
            {
                table[i][j] = 0;
            }
        }
    }

    for(int w = 0; w < longestNum; w++)
    {
        longestSubString = string1[placement1] + longestSubString;
        placement1--;
    }

    return longestSubString;
}

int main()
{
    char string1[] = "xyzhelplol";
    char string2[] = "3abchelpdd";

    cout << "The longest common string is: " << longestCommonSubString(string1, string2) << endl;
    return 0;
}
