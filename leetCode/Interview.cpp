#include"Interview.h"


int Interview::input5()
{
    int lows;
    cin >> lows;
    while(lows--){
        int num;
        int sum = 0;
        cin >> num;
        while(num--){
            int a;
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
    }

    return 0;
}

int Interview::input6()
{
    string str;
    int num;
    while(cin >> num){
        int sum = 0;
        int a;
        while(cin.get() != '\n'){
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
        
    }
    return 0;
}

int Interview::input7()
{
    string str;
    int num;
    int sum = 0;
    while(cin >> num){
        sum += num;
        
        if(cin.get() == '\n'){
            cout << sum << endl;
            sum = 0;
        }

    }
    return 0;
}

int Interview::input10()
{
    string s;
    while(getline(cin, s)){
        stringstream ss(s);
        vector<string> vec;
        while(getline(ss, s, ',')){
            vec.push_back(s);
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < vec.size() - 1; ++i){
            cout << vec[i] << ",";
        }
        cout << vec[vec.size() - 1] << endl;;
    }
    return 0;
}

vector<string> Interview::split(const string& str,const string& delim) { //将分割后的子字符串存储在vector中
	vector<string> res;
	if("" == str) return  res;
	
	string strs = str + delim; //*****扩展字符串以方便检索最后一个分隔出的字符串
	size_t pos;
	size_t size = strs.size();
 
	for (int i = 0; i < size; ++i) {
		pos = strs.find(delim, i); //pos为分隔符第一次出现的位置，从i到pos之前的字符串是分隔出来的字符串
		if( pos < size) { //如果查找到，如果没有查找到分隔符，pos为string::npos
			string s = strs.substr(i, pos - i);//*****从i开始长度为pos-i的子字符串
			res.push_back(s);//两个连续空格之间切割出的字符串为空字符串，这里没有判断s是否为空，所以最后的结果中有空字符的输出，
			i = pos + delim.size() - 1;
		}
		
	}
	return res;	
}

char Interview::StringLengthCalculationAndInterception(string str)
{
    // 难点在于 12点 为 am

    string ss = str;

    // string ss = "aaa<2>bbbbb</>abcd";
    vector<string> v1 = split(ss, "<");
    vector<string> v2 = split(ss, ">");

    string ss2 = "<3>11</>aaa<2>bbbbb</>cccc<3>221</>";
    vector<string> v3 = split(ss2, "<");
    vector<string> v4 = split(ss2, ">");


    vector<string> str1 = v1;
    vector<string> str2 = v4;
    int ans = 0;
    int pre;
    int flag = 100;
    char ress;
    for(int i = 0; i < str1.size(); i++){
        if(str1[i].empty())
            continue;
        if(str1[i][0] == '/'){
            pre = ans;
            ans += 16 * (str1[i].length() - 2);
            if(ans >= flag){
                int a = (flag - pre) / 16;
                ress = str1[i][a+1];
            }
            // cout << "///    " << 16 <<  "\t" << str1[i].length() - 2  << "\t\t";
        }
        else if(str1[i][1] == '>'){
            vector<string> sub_strVec = split(str1[i], ">");
            if(sub_strVec.empty())
                continue;
            string sub_str = sub_strVec[0];
            std::stringstream sss;
            int num;
            sss << sub_str;
            sss >> num;
            
            pre = ans;
            ans += (str1[i].length() - 2) * num;
            if(ans >= flag){
                int a = (flag - pre) / num;
                ress = str1[i][a+1];
            }
            // cout << "<><><>    " << num << "\t" << str1[i].length() - 2 << "\t\t";
        }
        else{
            pre = ans;
            ans += str1[i].length() * 16;
            if(ans >= flag){
                int a = (flag - pre) / 16;
                ress = str1[i][a-1];
            }
        }
        cout << endl;     
    }
    cout << ans << endl;
    cout << ress << endl;

    return ress;
}


int Interview::BuyTicket()
{   
    int low;
    cin >> low;
    while(low--){
        int nums;
        cin >> nums;
        vector<int> A(nums, -1);
        vector<int> B(nums, -1);
        vector<int> dp(nums, 0);
        for(int i = 0; i < nums; ++i){
            cin >> A[i];
        }
        if(nums == 0){
            cout << "08:00:00 am" << endl;
            continue;
        }
        else if(nums <= 1){
            dp[0] = A[0];
        }else{
            int b;
            for(int i = 1; i < nums; ++i){
                cin >> B[i];
            }
            // vector<int> dp(nums, 0);
            dp[0] = A[0];
            dp[1] = min(dp[0] + A[1], B[1]);
            for(int i = 2; i < nums; ++i){
                dp[i] = min(dp[i-1] + A[i], dp[i-2] + B[i]);
            }
        }

        int allTime = dp[nums - 1];
        int sec = allTime % 60;
        int min = allTime / 60;
        int hour = 0;

        if(min >= 60){
            hour = min / 60;
            min = min % 60;
        }
        hour += 8;
        if(hour <= 12){
            string h = to_string(hour);
            if(hour < 10){
                h = '0' + h;
            }
            string m = to_string(min);
            if(min < 10){
                m = '0' + m;
            }
            string s = to_string(sec);
            if(sec < 10){
                s = '0' + s;
            }
            cout << h + ":" + m + ":" + s + " am" << endl;
        }else{
            string h = to_string(hour);
 
            if(hour > 12){
                h = to_string(hour - 12);
                if(hour - 12 < 10){
                    h = '0' + h;
                }
            }
            string m = to_string(min);
            if(min < 10){
                m = '0' + m;
            }
            string s = to_string(sec);
            if(sec < 10){
                s = '0' + s;
            }
            cout << h + ":" + m + ":" + s + " pm" << endl;
        }
    }
    
    return 0;
}

struct pos_remain           //自己定义一个   也可以用tuple
{
    int r, c;
    int remain_step;
    pos_remain(int x, int y, int z) : r(x), c(y), remain_step(z) {}
};

int Interview::shortestPath(vector<vector<int>>& grid, int k) {
   int R = grid.size(),    C = grid[0].size();
    if(R == 1 && C ==1)
        return 0;
    if (k >= R + C - 2)                                                             //贴着边走就行了，障碍全清楚
        return R + C - 2;
    k = std::min(k, R + C - 2);
    int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    bool visited[R][C][k + 1];      memset(visited, false, sizeof(visited));        //比vector好用太多！！！！！！！！！！！！！！！！！！
    queue<pos_remain> Q;                                                            //元素类型自己定义一个 多练练手   也可以用tuple  tuple就是取数据，解压的时候麻烦一点点  可以tie  也可以 get<0,1,2>(it)
    Q.emplace(0, 0, k);     visited[0][0][k] = true;                                //emplace很好用
    int level = 1;
    while(!Q.empty())                                                //记忆化BFS 波纹法！！！！！！标准框架
    {
        int cur_len = Q.size();
        for (int ee = 0; ee < cur_len; ee ++)                          //波纹法
        {
            pos_remain cur = Q.front();     Q.pop();
            int cur_r = cur.r,   cur_c = cur.c,   cur_remain_step = cur.remain_step;
            for (int d=0; d<4; d++)
            {
                int dr = dirs[d][0],    dc = dirs[d][1];
                int nr = cur_r + dr,    nc = cur_c + dc;
                if (0<=nr && nr<R && 0<=nc && nc<C)
                {
                    if (grid[nr][nc] == 0 && visited[nr][nc][cur_remain_step]==false)   //没有障碍  直接上
                    {
                        if (nr == R-1 && nc == C-1)                                     //走到右下角终点了
                            return level;
                        Q.emplace(nr, nc, cur_remain_step);                             //普通情况
                        visited[nr][nc][cur_remain_step] = true;
                    }
                    else if (grid[nr][nc]==1 && cur_remain_step > 0 && visited[nr][nc][cur_remain_step - 1] == false )  //有障碍的时候
                    {
                        visited[nr][nc][cur_remain_step - 1] = true;
                        Q.emplace(nr, nc, cur_remain_step - 1);
                    }
                }
            }
        }
        level += 1;
    }
    return -1;
}


bool Interview::Track(int &mainA, int &mainB, int &mainC, monster &m)
{
    int harm = mainA - m.B;
                
    if(harm < 0 && m.A > 0){
        return false;
    }
        
    if(harm >= m.C){
        mainC += harm - m.C;
        m.C -= harm;
    }else{
        m.C -= harm;
    }

    return true;
}

bool Interview::defende(int &mainA, int &mainB, int &mainC, monster &m, int &add)
{
    int harm = m.A - mainB;
                
    if(harm < 0){
        return true;
    }

    if(harm >= 0){
        mainC -= harm;
        if(mainC <= 0){
            add += 1 - mainC;
            mainC = 1;
        }
        // cout << "defende: " << mainC << endl;
    }   

    return true;
}


int Interview::FightMonsters()
{
    int T, nums;
    cin >> T;
    
    int add = 0;
    int mainA , mainB, mainC = 0;
    vector<int> res(T);
    // while(T--){
    for(int i = 0; i < T; ++i){
        add = 0;
        cin >> nums;
        cin >> mainA ;
        cin >> mainB;
        vector<monster> mon(nums);
        int a, b, c;
        for(int i = 0; i < nums; ++i){
            cin >> a ;
            cin >> b ;
            cin >> c;
            mon[i] = monster(a,b,c);
        }
        
        sort(mon.begin(), mon.end(), monster_cmp);
        for(monster &m : mon){

            bool Islive = true;
            while(1){
                Islive = Track(mainA, mainB, mainC, m);
                if(!Islive){
                    add = -1;
                    break;
                }
                   
                if(m.C <= 0)
                    break;
                defende(mainA, mainB, mainC, m, add);

            }
            if(!Islive){
                add = -1;
                break;
            }

        }
        // cout << endl;
        // cout << mainC << endl;
        // cout << add << endl;
        res[i] = add;
    }

    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << endl;
    }
    
    return 0;
}
bool Interview::EscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
    
    // int next[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int start_x = source[0];   int start_y = source[1];
    int end_x = target[0];     int end_y = target[1];

    int limit = 1e6;
    unordered_map<long long, bool> visited;
    for(int i = 0; i < blocked.size(); ++i){
        visited[(long long )blocked[i][0] * limit + blocked[i][1]] = true;
    }

    queue<pair<int, int>> Q;
    Q.push({start_x, start_y});
    while(!Q.empty()){
        int size = Q.size();
        if(size > blocked.size())
            return true;
        while(size--){
            pair<int,int> tmp = Q.front();
            Q.pop();

            int curX = tmp.first;   int curY = tmp.second;

            for(int i = 0; i < 4; ++i){
                int newX = curX + next[i][0];
                int newY = curY + next[i][1];

                if(newX >=0 && newX < 1e6 && newY >= 0 && newY < 1e6 && !visited[(long long)newX * limit + newY]){
                    if(newX == end_x && newY == end_y)
                        return true;
                    Q.push({newX, newY});
                    visited[(long long)newX * limit + newY] = true;
                }
            }


        }

    }
    
    return false;
}


bool Interview::isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target){
    if(blocked.empty())
        return true;
    
    bool res2 = EscapePossible(blocked, target, source);
    bool res1 = EscapePossible(blocked, source, target);
    return res1 && res2;
}


void Interview::NumberEscapePossible_DFS(vector<vector<bool>> &visited, coor &start)
{
    if(start == EscapePossible_end){
        NumEP++;
        for(int i = 0; i < EscapePossible_R; ++i){
            for(int j = 0; j < EscapePossible_C; ++j){
                // if( i == EscapePossible_R-1 && j == EscapePossible_C-1){
                //     cout << "(" << pathEP[i][j].first << ", " << pathEP[i][j].second << ")" ;
                // }
                // else 
                if(pathEP[i][j].first != -1){
                    cout << "(" << pathEP[i][j].first << ", " << pathEP[i][j].second << ")" << " -->";
                }
            }
        }
        cout << "(" << EscapePossible_end.x << ", " << EscapePossible_end.y << ")" << endl;
        return ;
    }

    int curX = start.x;
    int curY = start.y;
    if(visited[curX][curY] && blocked[curX][curY])
        return ;

    for(int i = 0; i < 2; ++i){
        int newX = curX + next2[i][0];
        int newY = curY + next2[i][1];

        if(newX < 0 || newX > EscapePossible_R - 1 || newY < 0 || newY > EscapePossible_C - 1)
            continue;
        // if(!visited[newX][newY] && !blocked[newX][newY]){
            coor tmp = coor(newX, newY);

            visited[newX][newY] = true;
            pathEP[newX][newY] = pair<int, int>(curX, curY);
            NumberEscapePossible_DFS(visited, tmp);
            visited[newX][newY] = false;
            pathEP[newX][newY] = pair<int, int>(-1, -1);
        // }

    }
    
}
void Interview::NumberEscapePossible()
{
    // Possible_a 
    EscapePossible_R = Possible_a.size();
    EscapePossible_C = Possible_a[0].size();
    EscapePossible_start = coor(0,0);
    EscapePossible_end = coor(EscapePossible_R - 1,EscapePossible_C - 1);

    pathEP.resize(EscapePossible_R);//n行
    for (int i = 0; i < EscapePossible_R; ++i){
        pathEP[i].resize(EscapePossible_C, pair<int, int>(-1, -1));//每行为m列
    }
    
    vector<vector<bool>> visited(EscapePossible_R, vector<bool>(EscapePossible_C, false));
    vector<vector<bool>> blocked(EscapePossible_R, vector<bool>(EscapePossible_C, false));
    for(int i = 0; i < EscapePossible_R; ++i){
        for(int j = 0; j < EscapePossible_C; ++j){
            if(Possible_a[i][j] == 1){
                blocked[i][j] = true;
            }
        }
    }
    visited[0][0] = true;
    this->blocked = blocked;
    NumberEscapePossible_DFS(visited, EscapePossible_start);
    cout << NumEP << endl;

    // for(int i = 0; i < EscapePossible_R; ++i){
    //     for(int j = 0; j < EscapePossible_C; ++j){
    //         if( i == EscapePossible_R-1 && j == EscapePossible_C-1){
    //             cout << pathEP[i][j].first << ", " << pathEP[i][j].second ;
    //         }
    //         else if(pathEP[i][j].first != -1){
    //             cout << "(" << pathEP[i][j].first << ", " << pathEP[i][j].second << ")" << " -->";
    //         }
    //     }
    // }

}


void Interview::transfrom(char &c, int i, long long int &res){
    switch(c){
        case 'A':
            res += 10 * pow(16, i); break;
        case 'B':
            res += 11 * pow(16,i); break;
        case 'C':
            res += 12 * pow(16,i); break;
        case 'D':
            res += 13 * pow(16,i); break;
        case 'E':
            res += 14 * pow(16,i); break;
        case 'F':
            res += 15 * pow(16,i); break;
        default:
           int a = c - '0';
           res += a * pow(16, i);
    }
}
void Interview::BaseConversion_HtoD()
{
    string str;
    while(cin >> str){
        string ox = str.substr(2,str.length() - 2);
        int size = ox.length();
        long long int res = 0;
        for(int i = size - 1, j = 0; i >= 0; --i, ++j){
            transfrom(ox[i], j, res);
        } 
        str = to_string(res);
        cout << str << endl;
    }
}



bool Interview::Sudoku_check(vector<vector<int>> &vec, int x, int y, int val)
{
    for(int i = 1; i < 9; ++i){
        if(vec[x][i] == val || vec[i][y] == val){
            return false;
        }
    }
    int cube_x = x / 3 * 3;
    int cube_y = y / 3 *3;
    for(int i = cube_x; i < cube_x + 3; ++i){
        for(int j = cube_y; j < cube_y + 3; ++j){
           if(vec[i][j] == val)
                return false;
        }
    }
    return true;
}
bool Interview::Sudoku_DFS(vector<vector<int>> &vec, int n)
{
    int x = n / 9;
    int y = n % 9;
    if(n > 80){
        return true;
    }
    if(vec[x][y] != 0){
        return Sudoku_DFS(vec, n + 1);
    }
    else{
        for(int i = 1; i <= 9; ++i){
            if(Sudoku_check(vec, x, y, i)){
                vec[x][y] = i;
                if(Sudoku_DFS(vec, n + 1) )
                    return true;
                vec[x][y] = 0;
            }
        }
     
    }

    return false;

}
void Interview::Sudoku()
{
    // int vec[9][9];
    vector<vector<int>> V(9,vector<int>(9));
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            V[i][j] = Sudoku_a[i][j];
        }
    }

    Sudoku_DFS(V, 0);

    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 8; ++j){
            cout << V[i][j] << " ";
        }
        cout << V[i][8] << endl;
    }
}


int Interview::ChefCooking()
{
    vector<int> a = {2,2,5,6,4,2,4,6,5,2,3,3,3,3,4,6,1,5,1,1,7};
    int t;

    //vector<int> vec;
    queue<int> Q;
    // while(cin >> t){
    //     Q.push(t);
    // }
    for(auto t : a){
        if(t == 0) continue;
        if(t == 7) break;
        Q.push(t);
    }
    int sum = 0;

    multiset<int> Kitchen;
    queue<int> used;
    // map<int, int> Kitchen;
    while(!Q.empty()){

        int f = Q.front();
        Q.pop();

        if(Kitchen.size() < 3){
        
            Kitchen.insert(f);
            // Kitchen.insert(pair<int, int>(food, 1));
            sum += 16;

            used.push(f);
        }
        else if (!Kitchen.count(f)){

            int old = used.front();
            used.pop();
            set<int>::iterator it = Kitchen.find(old);
            Kitchen.erase(it);
            sum += 6;

            Kitchen.insert(f);
            used.push(f);
            sum += 15;
        }
        else{
 
            queue<int> tmp; 
            while(!used.empty()){
                int use = used.front();
                used.pop();
                if(use = f)
                    continue;
                tmp.push(use);
            }
            while(!tmp.empty()){
                int t = tmp.front();
                tmp.pop();
                used.push(t);
            }
            
            used.push(f);
            sum += 15;

        }
    }

    cout << sum << endl;
    
    return 0;
}

struct record{
    string filename;
    int col;
    int cnt;
};
bool cmp(record r1,record r2)
{
    return r1.cnt>r2.cnt;
}

int Interview::Errorlog()
{
    string file;
    int column;
    record r[100];
    int count=0,i=0;
    while(cin>>file>>column)
    {
        string f=file.substr(file.rfind('\\')+1);
        //recor里面还未记录的文件名
        int flag=0;
        for(int j = 0;j<count;j++)
        {
            if(r[j].filename==f && r[j].col==column)
            {
                r[j].cnt++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            r[count].filename=f;
            r[count].col=column;
            r[count].cnt=1;
            count++;
        }
         
    }
    sort(&r[0],&r[count],cmp);
    if(count>8)count=8;
     
    for(int j=i;j<count;j++){
            string f=r[j].filename;
            if(f.size()>16)f=f.substr(f.size()-16,f.size());
            cout << f << ' ' << r[j].col << ' ' << r[j].cnt << endl;
     }
    return 0;
}


int Interview::DeleteNum()
{
    int n;
    while(cin>>n)
    {
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            q.push(i);
        }
        int count=0;
        while(q.size()!=1)
        {
            if(count<2)
            {
                int b=q.front();
                q.pop();
                q.push(b);
                count++;
            }
            else
            {
                q.pop();
                count=0;
            }
        }
        int c=q.front();
        cout<<c<<endl;
    }
    return 0;
}


vector<int> PokerGame_helper(string s){ 
    vector<int> v; 
    for(int i=0;i<s.size();i++){ 
        if(s[i]=='1'){ 
            v.push_back(10); 
            i++; 
        }
        else if(s[i]=='j'&&i+1<s.size()&&s[i+1]=='o')
        {
            v.push_back(16);
            i += 4;
        }
        else if(s[i]=='J'&&i+1<s.size()&&s[i+1]=='O')
        {
            v.push_back(17);
            i += 4;
        }
        else if(s[i]=='J') v.push_back(11); 
        else if(s[i]=='Q') v.push_back(12); 
        else if(s[i]=='K') v.push_back(13); 
        else if(s[i]=='A') v.push_back(14); 
        else if(s[i]=='2') v.push_back(15);
        else if(s[i]==' ') continue; 
        else if(s[i]>='3' && s[i] <= '9')v.push_back(s[i]-'0'); 
    } 
    return v; 
} 
  
int Interview::PokerGame()
{
    string str;
      
    while(getline(cin,str)){
        int pos = str.rfind('-');
        string s1 = str.substr(0,pos);
        string s2 = str.substr(pos+1);
          
        if(s1 == "joker JOKER" || s2 == "joker JOKER"){
            cout<<"joker JOKER"<<endl;
            return 0;
        }
          
        vector<int> v1 = PokerGame_helper(s1);
        vector<int> v2 = PokerGame_helper(s2);
          
        if( v1.size() == 4 && v2.size()==4){
            if(v1[0]<v2[0])cout<<s2<<endl;
            else cout<<s1<<endl;
            return 0;
        }
          
        if(v1.size()==4) cout<<s1<<endl; 
        else if(v2.size()==4) cout<<s2<<endl; 
        else if(v1.size()!=v2.size()) cout<<"ERROR"<<endl; 
        else if(v1[0]<v2[0]) cout<<s2<<endl; 
        else if(v1[0]>v2[0]) cout<<s1<<endl; 
        else{ 
            cout<<"ERROR"<<endl; 
        } 
    }
    return 0;
}


void Interview::numIslands_DFS(vector<vector<string>>& grid, int x, int y)
{
    // leetCode 上是 char 类型

    int R = grid.size();
    int C = grid[0].size();

    grid[x][y] = "0";
    
    // if(x-1 >= 0 && grid[x-1][y] == '1') numIslands_DFS(grid, x-1, y);
    // if(x+1 < R && grid[x+1][y] == '1') numIslands_DFS(grid, x+1, y);
    // if(y-1 >= 0 && grid[x][y-1] == '1') numIslands_DFS(grid, x, y-1);
    // if(y+1 < C && grid[x][y+1] == '1') numIslands_DFS(grid, x, y+1);

    for(int i = 0; i < 4; ++i){
        int newX = x + next[i][0];
        int newY = y + next[i][1];

        if(newX >= 0 && newX < R && newY >=0 && newY < C && grid[newX][newY] == "1"){
            numIslands_DFS(grid, newX, newY);
        }
    }


}

int Interview::numIslands() {
    // vector<vector<char>>& grid  
    // leetCode 上是 char 类型

    int R = numIslands_a.size();
    if(!R)
        return 0;
    int C = numIslands_a[0].size();


    int Count = 0;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if(numIslands_a[i][j] == "1"){
                Count++;
                numIslands_DFS(numIslands_a, i, j);
            }
        }
    }

    return Count;
}


int Interview::PasswordInterception()
{
    string s;
    // while(scanf("%s\n",s) !=EOF)
    while(cin>>s)
    {
        const int len = s.size();
        if(len <= 1) return -1;
        int maxLen = 0;
        for(int i = 1; i < len; i++){
            //寻找以i-1,i为中点偶数长度的回文
            int low = i-1, high = i;
            while(low >= 0 && high < len && s[low] == s[high]){
                 low--; high++;
            }
            if(high - low - 1 > maxLen)
               maxLen = high - low -1;
            //寻找以i为中心的奇数长度的回文
            low = i- 1; high = i + 1;
            while(low >= 0 && high < len && s[low] == s[high]){
                low--; high++;
            }
            if(high - low - 1 > maxLen)
               maxLen = high - low -1;
        }
        cout<<maxLen<<endl;
    }
    return 0;
}


int Interview::maxValue(vector<vector<int>>& grid) {
    int R = grid.size();
    int C = grid[0].size();
 
    int dp[R][C];
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if(i == 0 && j ==0)
                dp[i][j] = grid[0][0];
            else if(i == 0)
                dp[i][j] = dp[i][j-1] + grid[i][j];
            else if(j == 0)
                dp[i][j] = dp[i-1][j] + grid[i][j];
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
    }
    return dp[R-1][C-1];
}


int Interview::leastInterval(vector<char>& tasks, int n)
{
    unordered_map<char, int> freq;
    for (char ch: tasks) {
        ++freq[ch];
    }
    
    // 任务总数
    int m = freq.size();
    vector<int> nextValid, rest;
    for (auto [_, v]: freq) {
        nextValid.push_back(1);
        rest.push_back(v);
    }

    int time = 0;
    for (int i = 0; i < tasks.size(); ++i) {
        ++time;
        int minNextValid = INT_MAX;
        for (int j = 0; j < m; ++j) {
            if (rest[j]) {
                minNextValid = min(minNextValid, nextValid[j]);
            }
        }
        time = max(time, minNextValid);
        int best = -1;
        for (int j = 0; j < m; ++j) {
            if (rest[j] && nextValid[j] <= time) {
                if (best == -1 || rest[j] > rest[best]) {
                    best = j;
                }
            }
        }
        nextValid[best] = time + n + 1;
        --rest[best];
    }

    return time;
}



bool Interview::hasPath_dfs(vector<vector<char>> &matrix, int x, int y, int idx, vector<vector<bool>> &visited)
{
    
    if(matrix[x][y] != hasPath_target[idx])
        return false;
    
    if(idx == hasPath_target.length() - 1)
        return true;
    
    
    int R = matrix.size();
    int C = matrix[0].size();
    
    visited[x][y] = true;
    for(int i = 0; i < 4; ++i){
        int newX = x + next[i][0];
        int newY = y + next[i][1];
        
        if(newX >= 0 && newX < R && newY >= 0 &&  newY < C && !visited[newX][newY]){
            
            if(hasPath_dfs(matrix, newX, newY, idx+1, visited))
                return true;
            
        }
    }
    visited[x][y] = false;
    return false;
}
bool Interview::hasPath(vector<vector<char> >& matrix, string word) 
{
    // write code here
    
    if(matrix.empty() || matrix[0].empty()){
        return false;
    }
    if(word.empty())    return true;
    
    hasPath_target = word;
    
    int R = matrix.size();
    int C = matrix[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if(hasPath_dfs(matrix, i, j, 0, visited))
                return true;
        }
    }
    return false;
}



vector<vector<int> > Interview::FindContinuousSequence(int sum) {
    // vector<vector<int>> res;
    // for(int i = 1; i <= sum / 2; ++i){
        
    //     for(int j = i + 1; j < sum; ++j){
            
    //         int tmp = 0;
    //         for(int k = i; k <= j; ++k){
    //             tmp += k;
    //         }
    //         if(tmp == sum){
    //             vector<int> tmp;
    //             for(int m = i; m <= j;++m){
    //                 tmp.push_back(m);
    //             }
    //             res.push_back(tmp);
    //         }
    //         else if(tmp > sum){ // i需要向右增大
    //             break;
    //         }
    //     }
    // }
    // return res;

    // 前缀和
    // vector<vector<int>> ret;
    // int tmp = 0;
    // for (int i=1; i<=sum/2; ++i) {
    //     for (int j=i; j<sum; ++j) {
    //         tmp += j;
    //         if (sum == tmp) {
    //             vector<int> ans;
    //             for (int k=i; k<=j; ++k) ans.push_back(k);
    //             ret.push_back(ans);
    //         }
    //         else if (tmp > sum) {
    //             // 提前剪枝
    //             tmp = 0;
    //             break;
    //         }
    //     }
    // }
    // return ret;

    // 滑动窗口
    vector<vector<int>> ret;
    int l = 1, r = 1;
    int tmp = 0;
    while (l <= sum / 2) {
        if (tmp < sum) {
            tmp += r;
            ++r;
        }
        else if (tmp > sum) {
            tmp -= l;
            ++l;
        }
        else {
            vector<int> ans;
            for (int k=l; k<r; ++k)
                ans.push_back(k);
            ret.push_back(ans);
            tmp -= l;
            ++l;
        }
    }
    return ret;
}



int Interview::rectCover(int number) {
    if(number <= 2) return number;
    
    int dp[2];
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 3; i <= number; ++i){
        int tmp = dp[1];
        dp[1] = dp[0] + dp[1];
        dp[0] = tmp;
    }
    return dp[1];
}


string Interview::longestCommonPrefix(vector<string>& strs) {
    // write code here
    if(strs.empty())
        return "";
    int row = strs.size();
    int col = strs[0].size();
    
    for(int c = 0; c <= col; ++c){
        int first = strs[0][c];
        for(int r = 1; r < row; ++r){
            if(strs[r][c] != first || strs[r].length() == c){
                return strs[0].substr(0, c);
            }
        }
    }
    
    return strs[0];
}


int Interview::InitialEnergy()
{
    
    int n;
    while(cin >> n){
        
        vector<int> vec(n);
        for(int i = 0; i < n; ++i){
            cin >> vec[i];
        }
        
        int dp[n+1];
        dp[n] = 0;
        for(int i = n-1; i >= 0; --i){
            dp[i] = (vec[i] + dp[i + 1]) / 2.0 + 0.5;
        }
        cout << dp[0] << endl;
    }
    return 0;
}



int Interview::CoinDivision()
{
    #define mod (int)(1E9+7);
	int n;
	cin >> n;
// 	vector<int> count(n + 1, 1);//只用1就只能有1种方法
// 	for (int i = 2; i <= n; ++i)//可以有几个2，方法就加几
// 	{
// 		count[i] = (count[i] + count[i - 2]) % mod;
// 	}
// 	for (int i = 5; i <= n; ++i)//可以有几个5，方法就加几
// 	{
// 		count[i] = (count[i] + count[i - 5]) % mod;
// 	}
// 	for (int i = 10; i <= n; ++i)//可以有几个10，方法就加几
// 	{
// 		count[i] = (count[i] + count[i - 10]) % mod;
// 	}
// 	cout << count[n] << endl;
    
    int a[5]={0,1,2,5,10};
    vector<int> dp(n + 1, 1);//只用1就只能有1种方法
    for(int i = 2; i < 5; i++)
    {
        for(int j = a[i]; j<= n; j++)
        { 
            dp[j] = ( dp[j] + dp[j-a[i]] ) % mod;
           
        }
    }
    cout << dp[n] << endl;;
    
    return 0;
}

vector<int> HJRout_fun(vector<int> pre, int forward, int cache)
{
    int sent1 = min(forward, pre[0]);

    int redis = pre[0] > forward ? pre[0] - forward : 0;
    redis = min(redis, cache);

    int sent2 = min(pre[1] + redis, forward);

    return {sent1, sent2};
}

int Interview::HJRout()
{
   
    // int k= 2;
    // string str = "50,60 30,25";
    // int n = 120;      // 包的个数

    int k= 5;
    string str = "50,50 20,20 40,10 30,5 10,5";
    int n = 100;      // 包的个数

    // int k= 1;
    // string str = "30,30";
    // int n = 100; 

    if(k == 0)
        return  n;

    int forward[k+1];  // 转发量
    int cache[k+1];    // 缓存量
    forward[0] = n;
    cache[0] = 0;

    stringstream ss(str);
    string single;
    int idx = 1;
    while(getline(ss, single, ' ')){
        stringstream sin(single);
        int a, b; 
        char space;
        sin >> a >> space >> b;
        forward[idx]  = a;
        cache[idx] = b;
        idx++;
    }

    // int dp[n+1][2];  // dp[i][0] : 第i个节点第一次发送的数量，   dp[i][1] : 第i个节点第二次发送的数量
    vector<vector<int>> dp(n+1, vector<int>(2));  // // dp[i][0] : 第i个节点第一次发送的数量，   dp[i][1] : 第i个节点第二次发送的数量
    dp[0][0] = n;
    dp[0][1] = 0;  // 输入

    dp[1] = HJRout_fun(dp[0], forward[1], cache[1]);

    for(int i = 2; i <= k; ++i){
        vector<int> res1 = HJRout_fun(dp[i-1], forward[i], cache[i]);
        vector<int> res2 = HJRout_fun(dp[i-2], forward[i], cache[i]);

        dp[i] = (res1[0]+res1[1]) < (res2[0] + res2[1]) ? res1 : res2;
    }

    int res = (dp[k-1][0] + dp[k-1][1]) < (dp[k][0] + dp[k][1]) ? (dp[k-1][0] + dp[k-1][1]) : (dp[k][0] + dp[k][1]);

    cout << res << endl;

    // cout << "Hello Word \n";
    return 0;
}

int Interview::HJRout2()
{
   
    // int k= 2;
    // string str = "50,60 30,25";
    // int n = 120;      // 包的个数

    int k= 5;
    string str = "50,50 20,20 40,10 30,5 10,5";
    int n = 100;      // 包的个数

    // int k= 1;
    // string str = "30,30";
    // int n = 100; 

    if(k == 0)
        return  n;

    int forward[k+1];  // 转发量
    int cache[k+1];    // 缓存量
    forward[0] = n;
    cache[0] = 0;

    stringstream ss(str);
    string single;
    int idx = 1;
    while(getline(ss, single, ' ')){
        stringstream sin(single);
        int a, b; 
        char space;
        sin >> a >> space >> b;
        forward[idx]  = a;
        cache[idx] = b;
        idx++;
    }

    // int dp[n+1][2];  // dp[i][0] : 第i个节点第一次发送的数量，   dp[i][1] : 第i个节点第二次发送的数量
    vector<vector<int>> dp(n+1, vector<int>(2));  // // dp[i][0] : 第i个节点第一次发送的数量，   dp[i][1] : 第i个节点第二次发送的数量
    dp[0][0] = n;
    dp[0][1] = 0;  // 输入

    dp[1] = HJRout_fun(dp[0], forward[1], cache[1]);
    if(k == 1){
        cout << dp[1][0] + dp[1][1] << endl;
        return dp[1][0] + dp[1][1];
    }
    if(k == 2){
        vector<int> res1 = HJRout_fun(dp[k-1], forward[k], cache[k]);
        vector<int> res2 = HJRout_fun(dp[k-2], forward[k], cache[k]);

        dp[k] = (res1[0]+res1[1]) < (res2[0] + res2[1]) ? res1 : res2;
        int res = (dp[k-1][0] + dp[k-1][1]) < (dp[k][0] + dp[k][1]) ? (dp[k-1][0] + dp[k-1][1]) : (dp[k][0] + dp[k][1]);
         
        cout << res << endl;
        return res;
    }
    auto func = [&](int left, int right, vector<vector<int>> &dp){ // 0 ~ n-1     1 ~ n   左闭右开
       int size = right;
       dp[left] = dp[left];
       dp[left + 1] = HJRout_fun(dp[left], forward[left + 1], cache[left + 1]);
       for(int i = left + 2; i < size; ++i){
           vector<int> res1 = HJRout_fun(dp[i-1], forward[i], cache[i]);
           vector<int> res2 = HJRout_fun(dp[i-2], forward[i], cache[i]);

           dp[i] = (res1[0] + res1[1]) < (res2[0] + res2[1]) ? res1 : res2;
       }
       return (dp[right - 1][0] + dp[right - 1][1]) < (dp[right-2][0] + dp[right-2][1]) ? (dp[right-1][0] + dp[right-1][1]) : (dp[right - 2][0] + dp[right - 2][1]);
       
   };

    int res1 = func(0, k - 1, dp);
    int res2 = func(1, k, dp);

    int res = min(res1, res2);
    cout << res << endl;

    // cout << "Hello Word \n";
    return 0;
}




// // 最长公共前缀
// String longestCommonPrefix (String[] strs) {
//     // 横向扫描
//     if(strs.length==0 || strs==null){
//         return "";
//     }
//     //以第一个字符开始
//     String prefix = strs[0];
//     for(int i=1;i<strs.length;i++){
//         prefix = GetCommonPrefix(prefix,strs[i]);
//         //表示最长公共前缀就是""
//         if(prefix.length()==0){
//             return "";
//         }
//     }
//     return prefix;
// }
// //返回两子串公共前缀函数
// public String GetCommonPrefix(String s1,String s2){
//     int len= Math.min(s1.length(),s2.length());
//     int flag=0;
//     while(flag<len && s1.charAt(flag)==s2.charAt(flag)){
//         flag++;
//     }
//     return s1.substring(0,flag);
// }



// 构造二叉树
// TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
//     if (preorder_left > preorder_right) {
//         return nullptr;
//     }
    
//     // 前序遍历中的第一个节点就是根节点
//     int preorder_root = preorder_left;
//     // 在中序遍历中定位根节点
//     int inorder_root = index[preorder[preorder_root]];
    
//     // 先把根节点建立出来
//     TreeNode* root = new TreeNode(preorder[preorder_root]);
//     // 得到左子树中的节点数目
//     int size_left_subtree = inorder_root - inorder_left;
//     // 递归地构造左子树，并连接到根节点
//     // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
//     root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
//     // 递归地构造右子树，并连接到根节点
//     // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
//     root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
//     return root;
// }
// TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//     int n = preorder.size();
//     // 构造哈希映射，帮助我们快速定位根节点
//     for (int i = 0; i < n; ++i) {
//         index[inorder[i]] = i;
//     }
//     return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
// }


// 二分法 山脉数组中查找目标值
// int binary_search(MountainArray &mountain, int target, int l, int r, int key(int)) {
//     target = key(target);
//     while (l <= r) {
//         int mid = (l + r) / 2;
//         int cur = key(mountain.get(mid));
//         if (cur == target) {
//             return mid;
//         } else if (cur < target) {
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }
//     return -1;
// }
// int findInMountainArray(int target, MountainArray &mountainArr) {
//     int l = 0, r = mountainArr.length() - 1;
//     while (l < r) {
//         int mid = (l + r) / 2;
//         if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
//             l = mid + 1;
//         } else {
//             r = mid;
//         }
//     }
//     int peak = l;
//     int index = binary_search(mountainArr, target, 0, peak, [](int x) -> int{return x;});
//     if (index != -1) {
//         return index;
//     }
//     return binary_search(mountainArr, target, peak + 1, mountainArr.length() - 1, [](int x) -> int{return -x;});
// }


// 最长回文子串
string Interview::longestPalindrome(string s) {
    int n = s.size();
    if (n < 2) {
        return s;
    }

    int maxLen = 1;
    int begin = 0;
    // dp[i][j] 表示 s[i..j] 是否是回文串
    vector<vector<int>> dp(n, vector<int>(n));
    // 初始化：所有长度为 1 的子串都是回文串
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    // 递推开始
    // 先枚举子串长度
    for (int L = 2; L <= n; L++) {
        // 枚举左边界，左边界的上限设置可以宽松一些
        for (int i = 0; i < n; i++) {
            // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
            int j = L + i - 1;
            // 如果右边界越界，就可以退出当前循环
            if (j >= n) {
                break;
            }

            if (s[i] != s[j]) {
                dp[i][j] = false;
            } else {
                if (j - i < 3) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }

            // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
            if (dp[i][j] && j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                begin = i;
            }
        }
    }
    return s.substr(begin, maxLen);
}
// // 中心扩展算法
// pair<int, int> expandAroundCenter(const string& s, int left, int right) {
//     while (left >= 0 && right < s.size() && s[left] == s[right]) {
//         --left;
//         ++right;
//     }
//     return {left + 1, right - 1};
// }
// string longestPalindrome(string s) {
//     int start = 0, end = 0;
//     for (int i = 0; i < s.size(); ++i) {
//         auto [left1, right1] = expandAroundCenter(s, i, i);
//         auto [left2, right2] = expandAroundCenter(s, i, i + 1);
//         if (right1 - left1 > end - start) {
//             start = left1;
//             end = right1;
//         }
//         if (right2 - left2 > end - start) {
//             start = left2;
//             end = right2;
//         }
//     }
//     return s.substr(start, end - start + 1);
// }



int Interview::StringEncryption()
{

    string key, str;
    key = "nihao";
    str = "ni";
    // while(cin >> key >> str){

        // 构造密钥
        vector<char> miyao;
        for(int i = 0; i < key.size(); ++i){
            if('a' <= key[i] && key[i] <= 'z')
                key[i] = key[i] - 32;
            
            vector<char>::iterator iter = find(miyao.begin(), miyao.end(), key[i]);
            if(iter == miyao.end())  // 没找到 才压进去
                miyao.push_back(key[i]);
        }

        for(char i = 'A'; i <= 'Z'; ++i){
            auto iter = find(miyao.begin(), miyao.end(), i);
            if(iter == miyao.end())  // 没找到 才压进去
                miyao.push_back(i);
        }

        char res;
        for(int i = 0; i < str.length(); ++i){
            if('a' <= str[i] && str[i] <= 'z')
                res = miyao[str[i] - 'a'] + 32;
            else{
                res = miyao[str[i] - 'A'];
            }
            cout << res;
        }
        cout << endl;
    // }

    return 0;
}



bool MT1_judge(vector<int> vec, int start, int m){
    start++;  // 
    if(start == vec.size())  return false;
    if(start < vec.size() && vec[start] == m)   // ?  while
        return false;
    return true;
}
int Interview::MT1(){
    int n, x, y;
    cin >> n >> x >> y;

    if(n < 2*x || n > 2 * y){
        cout << -1 << endl;
        return 0;
    }
        
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
     
    sort(nums.begin(), nums.end());
    int cnt_out = 0;
    int cnt_in = n;  // in = n - 1?  先 cnt_in-- 的
    for(int i = 0; i < n; ++i){
        int m = nums[i];
        cnt_out++;
        cnt_in--;
        if(x <= cnt_out && cnt_out <= y && x <= cnt_in && cnt_in <= y){

            if(MT1_judge(nums, i, m)){
                cout << nums[i] << endl;
                return 0;
            }

        }
    }
    cout << -1 << endl;
    return 0;
}



int Interview::ZJ_userhobby()
{
    int n;
    while(cin >> n){
        vector<int> user(n);
        for(int i = 0; i < n; ++i){
            cin >> user[i];
        }
        int q;
        cin >> q;
        vector<int> L(q) , R(q), K(q);
        for(int i = 0; i < q; ++i){
            cin >> L[i] >> R[i] >> K[i];
        }
        map<int, vector<int>> mp;  //  喜好值 、 用户编号
        for(int i = 0; i < n; ++i){
            mp[user[i]].push_back(i+1);
        }
        vector<int> res(q, 0);
        for(int i = 0; i < q; ++i){
            vector<int> vec = mp[K[i]];
            
            auto left = lower_bound(vec.begin(), vec.end(), L[i]);  // >=
            
            auto right = upper_bound(vec.begin(), vec.end(), R[i]); // >
            
            res[i] = right - left;      // 迭代器相减
        }
        for(int i = 0; i < q; ++i){
            cout << res[i] << endl;
        }
        
    }
    
    return 0;
}


int Interview::subarraySum(vector<int>& nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0, pre = 0;
    for (auto& x:nums) {
        pre += x;
        if (mp.find(pre - k) != mp.end()) {
            count += mp[pre - k];
        }
        mp[pre]++;
    }
    return count;
}


int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> record = {{0, 1}};
    int sum = 0, ans = 0;
    for (int elem: nums) {
        sum += elem;
        // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
        int modulus = (sum % k + k) % k;
        if (record.count(modulus)) {
            ans += record[modulus];
        }
        ++record[modulus];
    }
    return ans;
}

int shortestSubarray(vector<int>& A, int K) 
{
    
    int n = A.size();
    vector<int> sum(n+1, 0);
    
    for(int i = 0; i < n; i++) //准备工作
        sum[i+1] = sum[i] + A[i];
    
    deque<int> de;
    int j = 0;
    int res = n+1;
    
    while(j<=n){
        
        while(!de.empty() && sum[j] <= sum[de.back()]){ //我们确定我们前面没有高个，有就踢他
            de.pop_back();
        }
        while(!de.empty() && sum[j] - sum[de.front()] >= K){ //从最前面第一位同学开始，进行比较
            res = min( res, j - de.front());
            de.pop_front();
        }
        de.push_back(j); //最后才坐下去
        j++;
    }
    if(res == n+1)
        return -1;
    else
        return res;
}



// ListNode* Interview::mergeTwoList(ListNode* a, ListNode* b)
// {
//     if(!a || !b)
//         return a ? a : b; 
    
//     ListNode dummy(-1);
//     ListNode* head = &dummy;
//     ListNode *pa = a, *pb = b;
//     while(pa != nullptr && pb != nullptr){
//         if(pa->val < pb->val){
//             head->next = pa;
//             pa = pa->next;
//             // head = head->next;
//         }else{

//             head->next = pb;
//             pb = pb->next;
//             // head = head->next;
//         }
//         head = head->next;
//     }
//     if(pa != nullptr){
//         head->next = pa;
//     }
//     if(pb != nullptr){
//         head->next = pb;
//     }
//     return dummy.next;
// }
// ListNode* Interview::mergeKLists(vector<ListNode*>& lists)
// {
//     ListNode *dummy = nullptr;
//     for(int i = 0; i < lists.size(); ++i){
//         dummy = mergeTwoList(dummy, lists[i]);
//     }
//     return dummy;
// }




vector<vector<int>> res;
vector<int> path;
vector<vector<int>> Interview::permuteUnique(vector<int>& nums)
{

    vector<bool> visited(nums.size(), false);

    sort(nums.begin(), nums.end());

    permuteUnique_dfs(nums, 0,0, visited);

    return res;
}
void Interview::permuteUnique_dfs(vector<int> &nums, int idx, int cnt, vector<bool> &visited)
{
    if(cnt == nums.size()){
            res.push_back(path);
            return ;
    }

    for(int i = 0; i < nums.size(); ++i){
        if(visited[i])
            continue;
        
        if(i > 0 && !visited[i-1] && nums[i] == nums[i-1])
            continue;

        visited[i] = true;
        path.push_back(nums[i]);

        permuteUnique_dfs(nums, i + 1, cnt + 1, visited);

        visited[i] = false;
        path.pop_back();
    }
}