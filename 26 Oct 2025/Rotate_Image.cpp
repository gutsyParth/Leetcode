#include<iostream>
using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {

            reverse(matrix.begin(),matrix.end());

            int n = matrix.size();

            for(int i=0;i<n-1;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
            
        }
    };