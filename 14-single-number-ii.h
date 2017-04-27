#include<iostream>
using namespace std;

class Solution {
public:
    //÷±Ω”≤Â»Î≈≈–Ú
    void Sort(int A[], int n)
    {
        for(int i = 1; i<n; ++i)
        {
            int tmp = A[i];
            int j = i;
            for(; j>0; j--)
            {
                if(A[j-1] > tmp)
                    A[j] = A[j-1];
                else
                    break;
            }
            A[j] = tmp;
        }
    }
    
    int singleNumber(int A[], int n) {
        if(n <= 0 || A == NULL)
            return 0;
        
		Sort(A,n);
        for(size_t i = 0; i<n-1; i+=3)
        {
            if(A[i] != A[i+2])
            {
                if(A[i] == A[i+1])
                    return A[i+2];
                else
                    return A[i];
            }
        }
        return A[n-1];
    }
};