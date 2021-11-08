#include <iostream>

void displayMatrix(char s1[], char s2[], int s1Len, int s2Len, int** matrix)
{
    std::cout << "OUTPUT: \n";
    std::cout << "  ";
    for (int j = 0; j < s1Len; j++)
    {
        std::cout << s1[j]<< " ";
    }
    std::cout << "\n";

    for (int i = 0; i < s2Len; i++)
    {
        for (int j = 0; j < s1Len; j++)
        {
            if(j==0)
                std::cout << s2[i] << " ";
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void displayLCS(char s1[], int s1Len, int s2Len, int** matrix)
{
    int largestNum = 0;
    int largestNumI = 0;
    int largestNumJ = 0;

    for (int i = 0; i < s2Len; i++)
    {
        for (int j = 0; j < s1Len; j++)
        {
            if (matrix[i][j] > largestNum)
            {
                largestNum = matrix[i][j];
                largestNumI = i;
                largestNumJ = j;
            }
        }
    }

    //Print out LCS
    std::cout << "\nLongest Common String: ";
    for (int i = 0; i < largestNum; i++)
    {
        std::cout << s1[(largestNumJ - (largestNum - 1)) + i];
    }
    std::cout << "\n\n";
}


int main()
{
    //Input Strings and initialize matrix
    char string1[] = "ABAB";
    char string2[] = "BABA";
    int string1Len = (sizeof(string1) / sizeof(char)) -1;
    int string2Len = (sizeof(string2) / sizeof(char)) -1;

    int** matrix = new int* [string2Len];
    for (int j = 0; j < string2Len; j++)
    {
        matrix[j] = new int[string1Len];
    }

    for (int i = 0; i < string2Len; i++)
    {
        for (int j = 0; j < string1Len; j++)
        {
            matrix[i][j] = -1;
        }
    }


    //Populate the matrix using comparisons
    for (int i = 0; i < string2Len; i++)
    {
        for (int j = 0; j < string1Len; j++)
        {
            if (string2[i] == string1[j] && matrix[i][j]<0)
            {
                if (i == 0 || j == 0)
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
            else
                matrix[i][j] = 0;
        }
    }

    //Display findings
    displayMatrix(string1, string2, string1Len, string2Len, matrix);
    displayLCS(string1, string1Len, string2Len, matrix);

}
