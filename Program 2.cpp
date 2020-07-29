#include <bits/stdc++.h> 

using namespace std; 

  
// Declaring the size of the matrix 

const int M = 3; 

const int N = 3; 

  
// Absolute Difference between the height of 
// two consecutive blocks 

int contribution_height(int current, int previous) 
{ 

    return abs(current - previous); 
} 

  
// Function To calculate the Total surfaceArea. 

int surfaceArea(int A[N][M]) 
{ 

    int ans = 0; 

  

    // Traversing the matrix. 

    for (int i = 0; i < N; i++) { 

        for (int j = 0; j < M; j++) { 

  

            /* If we are traveling the topmost row in the  

            matrix, we declare the wall above it as 0 

            as there is no wall above it. */

            int up = 0; 

  

            /* If we are traveling the leftmost column in the  

            matrix, we declare the wall left to it as 0 

            as there is no wall left it. */

            int left = 0; 

  

            // If its not the topmost row 

            if (i > 0) 

                up = A[i - 1][j]; 

  

            // If its not the leftmost column 

            if (j > 0) 

                left = A[i][j - 1]; 

  

            // Summing up the contribution of by 

            // the current block 

            ans += contribution_height(A[i][j], up)  

                    + contribution_height(A[i][j], left); 

  

            /* If its the rightmost block of the matrix 

               it will contribute area equal to its height 

               as a wall on the right of the figure */

            if (i == N - 1) 

                ans += A[i][j]; 

  

            /* If its the lowest block of the matrix it will  

               contribute area equal to its height as a wall 

               on the bottom of the figure */

            if (j == M - 1) 

                ans += A[i][j]; 

        } 

    } 

  

    // Adding the contribution by the base and top of the figure 

    ans += N * M * 2; 

    return ans; 
} 

  
// Driver program 

int main() 
{ 

    int A[N][M] = { { 1, 3, 4 }, 

                    { 2, 2, 3 }, 

                    { 1, 2, 4 } }; 

    cout << surfaceArea(A) << endl; 

    return 0; 
}
