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

    

};

#endif  // _DP_H_