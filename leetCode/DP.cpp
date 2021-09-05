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
    for (int i = 0; i < n; ++i) cin >> path[i];
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





/*
打家劫舍III
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
