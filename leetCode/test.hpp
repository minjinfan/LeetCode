#ifndef TEST_H_
#define TEST_H_
#include<iostream>

#include <string.h>
#include <vector>

using namespace std;

class test{
	public:
	test(){};
	~test(){};
	void show();
};
// class LeetCode28 {
// public:
// 	LeetCode28() {};
// 	~LeetCode28() {};
// 	void getNext(int* next, const string& s)
// 	{
// 		int j = -1;
// 		next[0] = j;
// 		for (int i = 1; i < s.size(); ++i) {
// 			while (j >= 0 && s[i] != s[j + 1]) {
// 				j = next[j];
// 			}
// 			if (s[i] == s[j + 1]) {
// 				++j;
// 			}
// 			next[i] = j;
// 		}
// 	}

// 	int strStr(string &haystack, string &needle)
// 	{
// 		if (needle.size() == 0)
// 			return 0;

// 		int next[needle.size()];
// 		getNext(next, needle);

// 	}
	
// };

#endif