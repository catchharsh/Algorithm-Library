#include <bits/stdc++.h>
using namespace std;
 
vector<int> psa(string pattern)
{
	int m = pattern.length();
	vector<int> arr(m);
	int i = 0;
	int j = 1;
	while (j < m)
	{
		if (pattern[j] == pattern[i])
		{
			arr[j++] = ++i;
		}
		else
		{
			while (i)
			{
				i = arr[i - 1];
				if (pattern[i] == pattern[j])
					break;
			}
			if (pattern[j] == pattern[i])
			{
				arr[j++] = ++i;
			}
			else
			{
				arr[j++] = 0;
			}
		}
	}
 
	return arr;
}
int main()
{
	string text, pattern;
	cin >> text >> pattern;
	int n = text.length();
	int m = pattern.length();
	vector<int> arr = psa(pattern);
	int i = 0, j = 0;
	int count = 0;
	while (i < n)
	{
		if (j == m)
		{
			count++;
			j = arr[j - 1];
			continue;
		}
		if (text[i] == pattern[j])
		{
			i++, j++;
		}
		else
		{
			if (j)
				j = arr[j - 1];
			else
				i++;
		}
	}
	if (j == m)
	{
		count++;
		j = arr[j - 1];
	}
	cout << count;
}