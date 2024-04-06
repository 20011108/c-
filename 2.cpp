#include <bits/stdc++.h>
using namespace std;
string a[7000][100];
bool cmp(string s1,string s2)
{
	string s3 = s1 + s2;
	string s4 = s2 + s1;
	if (s3.compare(s4) < 0) return true;
	else return false;
	 
}
int main (){
	int size,j=0;
	int n[7000];
	cin >> size;
	for (int j = 0; j < size; j++)
	{
		cin >> n[j];
		for (int i = 0; i < n[j]; i++)
		{
			cin >> a[j][i];
		}
	}
	for (int j = 0; j < size; j++)
	{
		sort(a[j],a[j]+n[j],cmp);
		for (int i = 0; i < n[j]; i++)
			cout << a[i][j];
		cout << endl;
	}
	return 0;
}
