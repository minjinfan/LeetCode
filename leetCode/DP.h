#ifndef _DP_H_
#define _DP_H_

#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <sstream>
#include <utility>


using namespace std;

class DP
{
    public:
    const vector<pair<int, int>> direc = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };

    // 推箱子游戏
    int Sokoban();
    int Sokoban_bfs(int start_x, int start_y, int box_x, int box_y);

    // 给定一个 n * m 的矩阵 a，从左上角开始每次只能 <<< ***向右或者向下走 ***>>> ，最后到达右下角的位置，路径上所有的数字累加起来就是路径和，输出所有的路径中最小的路径和。
    int minPathSum(vector<vector<int> >& matrix);

};

#endif  // _DP_H_