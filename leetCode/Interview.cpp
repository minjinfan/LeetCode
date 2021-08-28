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
        
        sort(mon.begin(), mon.end(), cmp);
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