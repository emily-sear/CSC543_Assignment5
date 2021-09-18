#include <iostream> 
#include <string.h>

using namespace std;
string longestCommonSubString(char* string1, char* string2)
{
    int len = strlen(string1);
    int table[len + 1][len + 1];
    int longestNum = 0;
    string longestSubString = "";

    cout<< "String 1: " << endl;
    for (int h = 0; h < len; h++)
    {
        cout << string1[h];
    }
    cout << endl;
    cout<< "String 2: " << endl;
    for(int g = 0; g < len; g++)
    {
        cout << string2[g];
    }
    cout << endl;
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
                    longestSubString = longestSubString + string2[j -1];
                }
                
            }
            else
            {
                table[i][j] = 0;
            }
        }
    }

    cout << "The Table" << endl;
    for(int k = 0; k < (len + 1); k++)
    {
        for(int m = 0; m < (len + 1); m++)
        {
            cout << table[k][m] << " ";
        }
        cout << endl;
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
