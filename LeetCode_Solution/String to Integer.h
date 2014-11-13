#include <sstream>
#include <string>

class Solution {
public:
	int atoi(const char *str) {
		std::stringstream buf(str);
		int a = 0;
		buf >> a;
		return a;
	}
};