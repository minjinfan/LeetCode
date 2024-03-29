#include "DP.h"


// 推箱子
struct Sokoban_Node {
    int x, y, b_x, b_y, step;
    Sokoban_Node(int x, int y, int b_x, int b_y, int step) :
        x(x), y(y), b_x(b_x), b_y(b_y), step(step) {
 
    };
};
 
int n, m;
vector<string> path;
// xy bxby 推着箱子走
int visited[50][50][50][50];
// const vector<pair<int, int>> direc = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
 
bool Sokoban_valid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || path[x][y] == '#') return false;
    return true;
}
 
int DP::Sokoban_bfs(int start_x, int start_y, int box_x, int box_y)
{
    queue<Sokoban_Node> que;
    que.push(Sokoban_Node(start_x, start_y, box_x, box_y, 0));
    visited[start_x][start_y][box_x][box_y] = 1;
    while (!que.empty()) {
        Sokoban_Node node = que.front();
        que.pop();
        int bx = node.b_x;
        int by = node.b_y;
        int step = node.step;
        for (int i = 0; i < 4; ++i) {
            int x = node.x + direc[i].first;
            int y = node.y + direc[i].second;
            
            // 箱子被同方向推动的位置
            int next_x = bx + direc[i].first;
            int next_y = by + direc[i].second;
 
            if (!Sokoban_valid(x, y)) continue;

            // 走到箱子旁边
            if ((x != bx || y != by) && visited[x][y][bx][by] == 0) {
                visited[x][y][bx][by] = 1;
                que.push(Sokoban_Node(x, y, bx, by, step + 1));
                // 推箱子
            }
            else if (x == bx && y == by && Sokoban_valid(next_x, next_y) && visited[x][y][next_x][next_y] == 0) {
                visited[x][y][next_x][next_y] = 1;
                if (path[next_x][next_y] == 'E')
                    return step + 1;
                que.push(Sokoban_Node(x, y, next_x, next_y, step + 1));
            }
        }
    }
 
    return -1;
}
 
int DP::Sokoban()
{
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;
    path = vector<string>(n, string(""));
    for (int i = 0; i < n; ++i)
         cin >> path[i];
         
    int start_x, start_y, box_x, box_y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (path[i][j] == 'S') {
                start_x = i, start_y = j;
            }
            else if (path[i][j] == '0') {
                box_x = i, box_y = j;
            }
        }
    }
    cout << Sokoban_bfs(start_x, start_y, box_x, box_y) << endl;
    return 0;
}




long long C(long long n) {
    return (n-1) * n / 2;
}
int ZJ_1()
{
    int N, D; cin>> N >> D;
    long long count = 0;
    vector<int> res(N);
    for (int end = 0, begin = 0; end < N; end++) {
        cin>> res[end];
        while (end >= 2 && (res[end] - res[begin]) > D) {
            begin++;//不满足则begin往前移动
        }
        count += C(end - begin);//由于判断一次往前移动（for循环中的end++），即可以采用每次固定首位的组合。
    }
    cout << count % 99997867;
}



int DP::minPathSum(vector<vector<int> >& matrix)
{
        // write code here
    int R = matrix.size();
    int C = matrix[0].size();
    
    vector<vector<int>> dp(R, vector<int>(C,0));
    dp[0][0] = matrix[0][0];
    
    // 第一行
    for(int j = 0; j < C; ++j){
        dp[0][j] = dp[0][j-1] + matrix[0][j];
    }
    
    // 第一列
    for(int i = 1; i < R; ++i){
        dp[i][0] = dp[i-1][0] + matrix[i][0];
    }
    
    for(int i = 1; i < R; ++i){
        for(int j = 1; j < C; ++j){
            int tmp = min(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = matrix[i][j] + tmp;
        }
    }
    
    return dp[R-1][C-1];
    
}


int DP::largestRectangleArea(vector<int> &heights) 
{
    unsigned long size = heights.size();
    if (size == 1) {
        return heights[0];
    }
    int res = 0;
    stack<int> stk;
    for (int i = 0; i < size; ++i) {
        while (!stk.empty() && heights[stk.top()] > heights[i]) {
            int length = heights[stk.top()];
            stk.pop();
            int weight = i;
            if (!stk.empty()) {
                weight = i - stk.top() - 1;
            }
            res = max(res, length * weight);
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        int length = heights[stk.top()];
        stk.pop();
        int weight = size;
        if (!stk.empty()) {
            weight = size - stk.top() - 1;
        }
        res = max(res, length * weight);
    }
    return res;
}
// // 柱状图中的 最大矩形 面积 暴力解法 
// int largestRectangleArea(int[] heights) {
//     int len = heights.length;
//     // 特判
//     if (len == 0) {
//         return 0;
//     }
//     int res = 0;
//     for (int i = 0; i < len; i++) {
//         // 找左边最后 1 个大于等于 heights[i] 的下标
//         int left = i;
//         int curHeight = heights[i];
//         while (left > 0 && heights[left - 1] >= curHeight) {
//             left--;
//         }
//         // 找右边最后 1 个大于等于 heights[i] 的索引
//         int right = i;
//         while (right < len - 1 && heights[right + 1] >= curHeight) {
//             right++;
//         }
//         int width = right - left + 1;
//         res = Math.max(res, width * curHeight);
//     }
//     return res;
// }



/*
给出一颗二叉树，每个节点有一个编号和一个值，该值可能为负数，请你找出一个最优节点(除根节点外)，
使得在该节点将树分成两棵树后(原来的树移除这个节点及其子节点，新的树以该节点为根节点)，
分成的两棵树各 节点的和之间的差绝对值最大。请输出该节点编号，如有多个相同的差，输出编号最小的节点。
*/
const int N = 1e6 + 50;
vector<int> v[N], sum(N + 1);

void dfs(int x) {
    for (int &y : v[x]) {
        dfs(y);
        sum[x] += sum[y];
    }
}

int HW98_01() 
{
    // ios::sync_with_stdio(false);
    int n;
    long long tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        tot += sum[i];
    }
    for (int x, y, i = 1; i < n; i++) {
        cin >> x >> y;
        x++;
        y++;
        v[x].push_back(y);
    }

    dfs(1);
    int res = 0;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (abs(sum[i] - tot + sum[i]) > ans) {
            ans = abs(sum[i] - tot + sum[i]);

            res = i;
        }
    }

    // cout << ans;
    cout << res << endl;   // ?
}



/*打家劫舍III  二叉树
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，
聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

unordered_map <TreeNode*, int> f, g;
void dfs(TreeNode* node) {
    if (!node) {
        return;
    }
    dfs(node->left);
    dfs(node->right);
    f[node] = node->val + g[node->left] + g[node->right];
    g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
}
int rob(TreeNode* root) {
    dfs(root);
    return max(f[root], g[root]);
}

// 优化
struct SubtreeStatus {
    int selected;
    int notSelected;
};
class Solution {
public:
    SubtreeStatus dfs(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        int selected = node->val + l.notSelected + r.notSelected;
        int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
        return {selected, notSelected};
    }

    int rob(TreeNode* root) {
        auto rootStatus = dfs(root);
        return max(rootStatus.selected, rootStatus.notSelected);
    }
};
*/





int DP::calculateMinimumHP(vector<vector<int>>& dungeon) 
{

    int R = dungeon.size();
    int C = dungeon[0].size();

    vector<vector<int>> dp(R, vector<int>(C, INT_MAX));
    // dp[R-1][C-1] = max(1,1-dungeon[R-1][C-1]);
    // for(int i = R-2; i >=0; i--){ // 最后一列
    //     dp[i][C-1] = max((dp[i+1][C-1] - dungeon[i][C-1]),1);
    // }
    // for(int j = C-2; j >= 0; j--){ // 最后一行
    //     dp[R-1][j] = max(dp[R-1][j + 1] - dungeon[R-1][j], 1);
    // }
    // for(int i = R - 2 ; i >= 0; i--){
    //     for(int j = C - 2; j >= 0; j--){
    //         int a = (dp[i + 1][j] - dungeon[i][j]) > 0 ? (dp[i + 1][j] - dungeon[i][j]) : 1;
    //         int b = (dp[i][j+1] - dungeon[i][j]) > 0 ? (dp[i][j+1] - dungeon[i][j]) : 1;

    //         dp[i][j] = min(a,b);
    //     }
    // }
    // return dp[0][0];
    
    // dp[R-1][C-1] = max(1, 1-dungeon[R-1][C-1]);
    // for(int i =  R - 2; i >= 0; i--){
    //     dp[i][C-1] = max(1, dp[i+1][C-1] - dungeon[i][C-1]);
    // }
    // for(int j = C - 2; j >= 0; j--){
    //     dp[R-1][j] = max(1, dp[R-1][j+1] - dungeon[R-1][j]);
    // }
    for(int i = R-1; i >=0; i--){
        for(int j = C-1; j >=0; j--){

            if(i == R-1 && j == C-1){
                dp[i][j] = max(1, 1 - dungeon[i][j]);
            }
            else if(i == R-1){
                dp[i][j] = max(1, dp[i][j+1] - dungeon[i][j]);
            }
            else if(j == C -1){
                dp[i][j] = max(1, dp[i+1][j] - dungeon[i][j]);
            }
            else{
                int tmp = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(1,  tmp - dungeon[i][j]);
            }

        }
    }

    return dp[0][0];
}














void preorderTraversal_helper(TreeNode* root, vector<int> &res){
    if(root == nullptr){
        return ;
    }

    res.push_back(root->val);
    preorderTraversal_helper(root->left, res);
    preorderTraversal_helper(root->right, res);
}
vector<int> DP::preorderTraversal(TreeNode* root) 
{
    if(root == nullptr)
        return {};
    vector<int> res;
    preorderTraversal_helper(root, res);

    /* 非递归
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* t = stk.top();
        stk.pop();
        res.push_back(t->val);
        if(t->right != nullptr)
            stk.push(t->right);
        if(t->left != nullptr)
            stk.push(t->left);
        
    }
    */

    return res;
}


void inorderTraversal_helper(TreeNode* root, vector<int> &res){
    if(root == nullptr){
        return;
    }
    inorderTraversal_helper(root->left, res);
    res.push_back(root->val);
    inorderTraversal_helper(root->right, res);
}
vector<int> DP::inorderTraversal(TreeNode* root) 
{

    vector<int> res;

    if(root == nullptr)
        return res;

    inorderTraversal_helper(root, res);
    return res;

    /* 非递归
    stack<TreeNode *> stk;
    TreeNode* p;
    p = root;
    while(!stk.empty() || p != nullptr){
        if(p != nullptr){
            stk.push(p);
            p = p->left;
        }
        else{
            p = stk.top();
            stk.pop();

            res.push_back(p->val);
            p = p->right;
        }
    }
    return res;
    */
}