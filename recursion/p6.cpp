#include <bits/stdc++.h> 
using namespace std; 

/* Function to calculate length */
int len = 0;
int recLen(char* str)	 
{ 
	// if we reach at the end of the string 
	if (*str == '\0') 
		return 0; 
	else
		 {
             len++;
             recLen(str+1);
         } 
} 

/* Driver program to test above function */
int main() 
{ 
	char str[] = "GeeksforGeeks"; 
    recLen(str); 
    cout << len << endl;
	return 0; 
} 