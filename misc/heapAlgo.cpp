#include <bits/stdc++.h> 
using namespace std; 
  
//Prints the array 
void printArr(int a[],int n) 
{ 
    for (int i=0; i<n; i++) 
        cout << a[i] << " "; 
    printf("\n"); 
} 

void printStr(string s, int n) {

    for(int i = 0; i < n; i++)
        cout << s[i] << " ";
    cout << endl;

}
  
// Generating permutation using Heap Algorithm 
void heapPermutationArr(int a[], int size, int n) 
{ 
    // if size becomes 1 then prints the obtained 
    // permutation 
    if (size == 1) 
    { 
        printArr(a, n); 
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heapPermutationArr(a,size-1,n); 
  
        // if size is odd, swap first and last 
        // element 
        if (size%2==1) 
            swap(a[0], a[size-1]); 
  
        // If size is even, swap ith and last 
        // element 
        else
            swap(a[i], a[size-1]); 
    } 
} 

void heapPermStr(string s, int size_, int n) {

    if(size_ == 1) {
        printStr(s, n);
        return;
    }
    for(int i = 0; i < size_; i++) {

        heapPermStr(s, size_-1, n);
         if (size_%2==1) 
            swap(s[0], s[size_-1]); 
  
        // If size is even, swap ith and last 
        // element 
        else
            swap(s[i], s[size_-1]); 

    }
}
  
// Driver code 
int main() 
{ 
    int a[] = {1, 2, 3}; 
    int n = sizeof a/sizeof a[0]; 
    heapPermutationArr(a, n, n); 
    heapPermStr("ABC", 3, 3);
    return 0; 
} 