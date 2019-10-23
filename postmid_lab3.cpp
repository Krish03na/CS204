#include <bits/stdc++.h> 
using namespace std; 
  

int COUNT; 
  

bool Valid(int A, int B, int Key, int **I, int **U, int N, int M) 
{ 
    if (A < N && B < M && A >= 0 && B >= 0) { 
        if (U[A][B] == false && I[A][B] == Key) 
            return true; 
        else
            return false; 
    } 
    else
        return false; 
} 
  

void BFS(int x, int y, int i, int j, int **in,int **r, int** v,int n, int m) 
{ 
    
    if (x != y) 
        return; 
  
    v[i][j] = 1; 
    COUNT++; 
    int x_move[] = { 0, 0, 1, -1 }; 
    int y_move[] = { 1, -1, 0, 0 }; 
  
     
    for (int u = 0; u < 4; u++) 
        if (Valid(i + y_move[u], j + x_move[u], x, in,v,n,m)) 
            BFS(x, y, i + y_move[u], j + x_move[u], in,r,v,n,m); 
} 
  

void RESETV(int n, int m, int **v) 
{ 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            v[i][j] = 0; 
} 
   
void RESETR(int key, int **in, int **r, int **v, int n, int m) 
{   
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            if (v[i][j] && in[i][j] == key) 
                r[i][j] = v[i][j]; 
            else
                r[i][j] = 0; 
        } 
    } 
} 

int compute(int **in,int n, int m) 
{ 
    int current_max = INT_MIN; 
    int **r=new int*[n];
    for(int i=0;i<n;i++)
    r[i]=new int[m];
    int **v=new int*[n];
    for(int i=0;i<n;i++)
    v[i]=new int[m];
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            RESETV(n,m,v); 
            COUNT = 0; 
  
            if (j + 1 < m) 
                BFS(in[i][j], in[i][j + 1], i, j, in,r,v,n,m); 
  
    
            if (COUNT >= current_max) { 
                current_max = COUNT; 
                RESETR(in[i][j], in, r,v,n,m); 
            } 
            RESETV(n,m,v); 
            COUNT = 0; 
  
           
            if (i + 1 < n) 
                BFS(in[i][j], in[i + 1][j], i, j, in,r,v,n,m); 
  
      
            if (COUNT >= current_max) { 
                current_max = COUNT; 
                RESETR(in[i][j], in,r,v,n,m); 
            } 
        } 
    } 
    for(int i=0;i<n;i++)
        delete [] r[i],v[i];
    delete [] r, v;
    return current_max;
} 

int main() 
{ 
   int n,m,k;
   cin>>n>>m>>k;
   int **INPUT=new int*[n];
   for(int i=0;i<n;i++)
    INPUT[i]=new int[m];
   
   for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin>>INPUT[i][j];

    cout<<compute(INPUT,n,m)<<endl; 
    for(int i=0;i<n;i++)
        delete [] INPUT[i];
    delete [] INPUT;
    return 0; 
} 
