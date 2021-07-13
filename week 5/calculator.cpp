// C++ program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

vector<int> find_sequence(int n)
{
	
	// Base Case
	if (n == 1)
		return {1, -1};

	// Recursive Call for n-1
	auto arr = find_sequence(n - 1);
	vector<int> ans = {arr[0] + 1, n - 1};

	// Check if n is divisible by 2
	if (n % 2 == 0)
	{
		vector<int> div_by_2 = find_sequence(n / 2);

		if (div_by_2[0] < ans[0])
			ans = {div_by_2[0] + 1, n / 2};
	}

	// Check if n is divisible by 3
	if (n % 3 == 0)
	{
		vector<int> div_by_3 = find_sequence(n / 3);

		if (div_by_3[0] < ans[0])
			vector<int> ans = {div_by_3[0] + 1, n / 3};
	}

	// Returns a tuple (a, b), where
	// a: Minimum steps to obtain x from 1
	// b: Previous number
	return ans;
}

// Function that find the optimal
// solution
vector<int> find_solution(int n)
{
	auto a = find_sequence(n);

	// Print the length
	cout << a[0] << endl;

	vector<int> sequence;
	sequence.push_back(n);

	//Exit condition for loop = -1
	//when n has reached 1
	while (a[1] != -1)
	{
		sequence.push_back(a[1]);
		auto arr = find_sequence(a[1]);
		a[1] = arr[1];
	}

	// Return the sequence
	// in reverse order
	reverse(sequence.begin(),
			sequence.end());

	return sequence;
}

// Driver Code
int main()
{
	int n;
cin>>n;
	 
	
	// Function call
	auto i = find_solution(n);
	
	for(int j : i)
		cout << j << " ";
}

// This code is contributed by mohit kumar 29
