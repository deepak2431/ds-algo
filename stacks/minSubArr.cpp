#include <bits/stdc++.h> 
using namespace std; 

// Function to return required minimum sum 
int sumSubarrayMins(int A[], int n) 
{ 
	int left[n], right[n]; 

	stack<pair<int, int> > s1, s2; 

	// getting number of element strictly larger 
	// than A[i] on Left. 
	for (int i = 0; i < n; ++i) { 
		int cnt = 1; 

		// get elements from stack until element 
		// greater than A[i] found 
		while (!s1.empty() && (s1.top().first) > A[i]) { 
			cnt += s1.top().second; 
			s1.pop(); 
		} 

		s1.push({ A[i], cnt }); 
		left[i] = cnt; 
	} 

    for(int i = 0; i < n; i++)
        cout <<  left[i] << " ";

	// getting number of element larger than A[i] on Right. 
	for (int i = n - 1; i >= 0; --i) { 
		int cnt = 1; 

		// get elements from stack until element greater 
		// or equal to A[i] found 
		while (!s2.empty() && (s2.top().first) >= A[i]) { 
			cnt += s2.top().second; 
			s2.pop(); 
		} 

		s2.push({ A[i], cnt }); 
		right[i] = cnt; 
	} 

    for(int i = 0; i < n; i++)
        cout <<  right[i] << " ";




	int result = 0; 

	// calculating required resultult 
	for (int i = 0; i < n; ++i) 
		result = (result + A[i] * left[i] * right[i]); 

	return result; 
} 

// Driver program 
int main() 
{ 
	int A[] = { 3, 1, 2, 4 }; 

	int n = sizeof(A) / sizeof(A[0]); 

	// function call to get required resultult 
	cout << sumSubarrayMins(A, n); 

	return 0; 
} 
// This code is written by Sanjit_Prasad 
