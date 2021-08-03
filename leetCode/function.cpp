#include"function.h"

LinkNode* Solution::removeElement(LinkNode* head, int val)
{
      LinkNode *dummyNode = new LinkNode();
        dummyNode->next = head;
        LinkNode *cur = dummyNode;
        while(cur->next != nullptr){
            if(cur->next->val == val){
                LinkNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete  tmp;
            }
            else{
                cur = cur->next;
            }
        }
        head = dummyNode->next;
        delete dummyNode;

        return head;
}

LinkNode* Solution::removeNthFromEnd(LinkNode* head, int n)
{
     LinkNode* dummyHead = new LinkNode(-1);
    // ListNode dummyHead;
    dummyHead->next = head;
    LinkNode* fast = dummyHead;
    LinkNode* slow = dummyHead;
    while(n-- > 0 && fast->next != nullptr){
        fast = fast->next;
    }

    fast = fast->next;
    while(fast != nullptr){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummyHead->next;
}

LinkNode* Solution::getIntersectionNode(LinkNode *headA, LinkNode *headB)
{
    LinkNode* A = headA;
    LinkNode* B = headB;
    int lenA = 0, lenB = 0;
    while(A != nullptr){
        lenA++;
        A = A->next;
    }
    while(B != nullptr){
        lenB++;
        B = B->next;
    }
    A = headA;
    B = headB;
    if(lenB > lenA){
        swap(A, B);
        swap(lenA, lenB);
    }
    int delta = lenA - lenB;
    while(delta--){
        A = A->next;
    }
    while(A != nullptr){
        if(A == B)
            return A;
        A = A->next;
        B = B->next;
    }
    return NULL;
}

LinkNode *Solution::detectCycle(LinkNode *head)
{
     LinkNode* fast = head;
        LinkNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                LinkNode* node1 = fast;
                LinkNode* node2 = head;
                while(node1 != node2){
                    node1 = node1->next;
                    node2 = node2->next;
                }
                return node2;
            }
        }
        return NULL;
}

void Solution::Readfile()
{
    string name = "8G_In";
    string path = "C:\\Users\\minji_eimum53\\Desktop\\WavePort\\J\\tmp/";

    string type1 = ".txt";
    string filePath_In = path + name + type1;

    vector<double> X, Z, V;
    ifstream infile(filePath_In);
    if (!infile.is_open())
	{
		cout << "读取文件失败" << endl;
		return ;
	}
    while(infile){
        string line;
        double x, z, v;
        getline(infile, line);
        if(infile.fail()) break;

        stringstream sin(line);
        sin >> x >> z >> v;
        if(z > 0.02) continue;
        X.push_back(x);
        Z.push_back(z);
        V.push_back(v);

    }
    infile.close();

    string type2 = "_Current.txt";
    string filePath_Out = path + name + type2;
    ofstream outfile(filePath_Out);
    for(int i = 0; i < X.size(); ++i){
        outfile << X[i] << "\t" << Z[i] << "\t" << V[i] << endl;
    }
    outfile.close();
}

int Solution::fib(int N)
{
    if(N < 2)
        return N;
    
    /* 递归 时间复杂度O(2^n)*/
    // return fib(N-1) + fib(N-2);


    // std::vector<int> dp(N+1);
    // dp[0] = 0;
    // dp[1] = 1;
    // for(int i = 2; i <= N; ++i){
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }
    // return dp[N];

    int dp[2];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= N; ++i){
        int sum = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = sum;
    }
    return dp[1];
}

int Solution::climbStairs(int n)
{
    if(n <= 3)
        return n;

    int dp[3];
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; ++i){
        int sum = dp[1] + dp[2];
        dp[1] = dp[2];
        dp[2] = sum;
    }
    return dp[2];
}

int Solution::minCostClimbingStairs(vector<int>& cost) {
    int length = cost.size();
    if(length <= 1)
        return 0;
    if(length == 2)
        return min(cost[0], cost[1]);
    
    vector<int> dp(length + 1, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2; i < length; ++i){
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    }
    return min(dp[length-1], dp[length -2]);
}

int Solution::rob(vector<int>& nums)
{
    int size = nums.size();
    if(size < 1)
        return 0;
    if(size <= 1)
        return nums[0];
    if(size <= 2)
        return max(nums[0], nums[1]);
    
    vector<int> dp(size + 1, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < size; ++i){
        dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
    }
    return max(dp[size-1], dp[size-2]);
}

int Solution::rob2(vector<int>& nums)
{
    auto func = [&](int left, int right, vector<int> &nums)->int{
        int size = right;
        vector<int> dp(nums.size(), 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);
        for(int i = left + 2; i < size; ++i){ // 1~ size -1
            dp[i] = max(dp[i-1], dp[i-2]+ nums[i]);
        }

        return max(dp[right - 1], dp[right - 2]);
    };

    int size = nums.size();
    if(size < 1)
        return 0;
    if(size == 1)
        return nums[0];
    if(size == 2)
        return max(nums[0], nums[1]);
        
    int a = func(0, size - 1, nums);
    int b = func(1, size, nums);    
    return max(a, b);
}

 int Solution::deleteAndEarn(vector<int>& nums) {
    // int size = nums.size();
    // map<int, int> sum;
    // int maxnum = -1;
    // for(auto num : nums){
    //     maxnum = max(maxnum, num);
    //     auto iter = sum.find(num);
    //     if(iter == sum.end()){
    //         sum.insert(pair<int, int>(num, 1));
    //     }else{
    //         iter->second++;
    //     }
        
    // }
    // vector<int> newVec(maxnum + 1, 0);
    // for(auto it = sum.begin(); it != sum.end(); it++){
    //     newVec[it->first] = (it->first * it->second);
    // }
    // int res = rob(newVec);

    int Max = -1;
    for(auto num : nums){
        Max = max(num, Max);
    }
    vector<int> sum(Max + 1, 0);
    for(auto num : nums){
        sum[num] += num;
    }
    int res = rob(sum);
    return res;

    return res;
}

double Solution::GaussIntegral_1D()
{

}

void Solution::TransformIntegraInterval(vector<vec3> &Line, int Xmin, int Xmax)
{
    std::vector<double> X, W;

    X.push_back(-0.9815606342467190); W.push_back(0.0471753363865118);
    X.push_back(-0.9041172563704740); W.push_back(0.1069393259953180);
    X.push_back(-0.7699026741943040); W.push_back(0.1600783285433460);
    X.push_back(-0.5873179542866170); W.push_back(0.2031674267230650);
    X.push_back(-0.3678314989981800); W.push_back(0.2334925365383540);
    X.push_back(-0.1252334085114680); W.push_back(0.2491470458134020);
    X.push_back(0.1252334085114680); W.push_back(0.2491470458134020);
    X.push_back(0.3678314989981800); W.push_back(0.2334925365383540);
    X.push_back(0.5873179542866170); W.push_back(0.2031674267230650);
    X.push_back(0.7699026741943040); W.push_back(0.1600783285433460);
    X.push_back(0.9041172563704740); W.push_back(0.1069393259953180);
    X.push_back(0.9815606342467190); W.push_back(0.0471753363865118);

    int X_size = X.size();
    
    int L_length = Xmax - Xmin;
	real common_term = L_length / 2.0;
	std::vector<real> new_x, new_w;
	new_x.resize(X_size);
	new_w.resize(X_size);

	for(int i = 0; i < X.size(); i++){
		new_x[i] = common_term * X[i] + common_term;
		new_w[i] = common_term * W[i];
	}

    std::vector<vec3> r_vec;
	for(int i = 0; i < X.size(); i++){
		vec3 r;
		faxpBy(r, new_x[i], L_vec_n, Xmin);
		r_vec.push_back(r);
	}
    
}