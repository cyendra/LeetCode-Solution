#include <iostream>
#include <vector>
#include "Reverse Words in a String.h"

using namespace std;

Solution ss;

int main()
{
	string s;
	getline(cin, s);
	ss.reverseWords(s);
	cout << s << endl;
	cin >> s;
	return 0;
}