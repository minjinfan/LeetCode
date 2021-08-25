#include"function.h"

void Solution::DisplayVec(vector<int> &Vec)
{
    for(auto v : Vec){
        cout << v << "\t";
    }
    cout << endl;
}

void Solution::BubbleSort(vector<int> &vec)
{
    for(int i = 0; i < vec.size() - 1; ++i){
        bool flag = false;
        for(int j = 0; j < vec.size() - i - 1; ++j){
            if(vec[j] > vec[j + 1]){
                swap(vec[j], vec[j + 1]);   

                flag = true;
            }
        }
        DisplayVec(vec);
        if(!flag)
            break;
    }
}

int Solution::PartSort(vector<int> &vec, int begin, int end)
{
    // int key = GetMid(vec, begin, end);
    int key = end;
    cout << "key:  " << key << endl;
    while(begin < end){
        while(vec[begin] <= vec[key] && begin < end){
            begin++;
        }

        while(vec[end] >= vec[key] && begin < end){
            end--;
        }
        if(begin < end){
            swap(vec[begin], vec[end]);
        }
    }

    swap(vec[begin], vec[key]);
    DisplayVec(vec);
    return begin;
}

void Solution::FastSort(vector<int> &vec)
{
    FastSort(vec, 0, vec.size());
}
void Solution::FastSort(vector<int> &Vec, int start, int final)
{
    if(start < final){
        int div = PartSort(Vec, start, final - 1);
        FastSort(Vec, start, div);
        FastSort(Vec, div + 1, final);
    }
}

int Solution::GetMid(vector<int> &vec, int left, int right)
{
    int mid  = ((left + right) >> 1);

    if(vec[left] < vec[right]){
        if(vec[right] < vec[mid])
            return right;
        else if(vec[left] < vec[mid])
            return mid;
        else
            return left;
    }
    else{
        if(vec[left] < vec[mid])
            return left;
        else if(vec[right] < vec[mid])
            return mid;
        else
            return right;
    }
}

void Solution::quickSort(vector<int> &vec)
{
    quickSort(vec, 0, vec.size() - 1);
}

void Solution::quickSort(vector<int> &vec, int start, int end)
{
    if(start >= end) 
        return ;

    int mid = Partition(vec, start, end);

    quickSort(vec, start, mid - 1);
    quickSort(vec, mid + 1, end);
}

int Solution::Partition(vector<int> &vec, int start, int end)
{
    int idx = GetMid(vec, start, end);
    Exchange(vec, start, idx);

    {
        int pivot = vec[start];
        int left = start + 1;
        int right = end;
        while(left < right){
            while(left < right && vec[left] <= pivot)
                left++;

            if(left != right){
                Exchange(vec, left, right);
                right--;
            }
        }
        if(left == right && vec[right] > pivot)    
            right--;

        if(left != start)
            Exchange(vec, start, right);

        return right;

    }

    // { // 双指针

    //     // 取第一个数为基数
    //     int pivot = vec[start];
    //     // 从第二个数开始分区
    //     int left = start + 1;
    //     // 右边界
    //     int right = end;
    //     while (left < right) {
    //         // 找到第一个大于基数的位置
    //         while (left < right && vec[left] <= pivot) left++;
    //         // 找到第一个小于基数的位置
    //         while (left < right && vec[right] >= pivot) right--;
    //         // 交换这两个数，使得左边分区都小于或等于基数，右边分区大于或等于基数
    //         if (left < right) {
    //             Exchange(vec, left, right);
    //             left++;
    //             right--;
    //         }
    //     }
    //     // 如果 left 和 right 相等，单独比较 arr[right] 和 pivot
    //     if (left == right && vec[right] > pivot) right--;
    //     // 将基数和轴交换
    //     Exchange(vec, start, right);
    //     return right;
    // }

}

void Solution::Exchange(vector<int> &vec, int i, int j)
{
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}

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

void Solution::ReadCurrent()
{
    string name = "0_NoGND";
    string path = "C:\\Users\\minji_eimum53\\Desktop\\WavePort\\J\\825\\";

    string type1 = ".txt";
    string filePath_In = path + name + type1;

    vector<double> X, Z, V;
    ifstream infile(filePath_In);
    if (!infile.is_open())
	{
		cout << "读取文件失败" << endl;
		return ;
	}

    double limit = 0.01;
    while(infile){
        string line;
        double x, z, v;
        getline(infile, line);
        if(infile.fail()) break;

        stringstream sin(line);
        sin >> x >> z >> v;
        if(z > limit) continue;
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
    
    std::cout << "Read Over!" << std::endl;
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

bool Solution::canJump(vector<int>& nums)
{
    int n = nums.size();
    // if(n == 0)
    //     return true;
    int Max = 0;
    for(int i = 0; i < n; ++i){
        
        if(i <= Max ){
            Max = max(Max, i + nums[i] );
            if(Max >= n - 1)
                return true;
        }
        
    }
    return false;
}

int Solution::jump(vector<int>& nums)
{
    int start = 0, end = 0;
    int num = nums.size();
    int MaxIndex = 0;
    int step = 0;

    for(int i = 0; i < num - 1; ++i){
        MaxIndex = max(MaxIndex, nums[i] + i);
        if(i == end){
            // start = end;
            end = MaxIndex;
            ++step;
        }
    }
    return step;
}

int Solution::maxSubArray(vector<int>& nums)
{
    int res = nums[0];
    int pre = nums[0];
    for(int i = 1; i < nums.size(); ++i){
        pre = max(nums[i], pre + nums[i]);
        res = max(res, pre);
    }
    return res;
}

int Solution::maxProduct(vector<int>& nums)
{
    int size = nums.size();
    vector<int> MaxVec(size, 0);
    vector<int> MinVec(size, 0);
    MaxVec[0] = nums[0];
    MinVec[0] = nums[0];
    for(int i = 1; i < size; ++i){
        MaxVec[i] = max(MaxVec[i-1] * nums[i], max(MinVec[i-1] * nums[i],  nums[i]));
        MinVec[i] = min(MaxVec[i-1] * nums[i], min(MinVec[i-1] * nums[i],  nums[i]));
    }
    for(auto m : MaxVec){
        cout << m << "\t" << endl;
    }
    return *max_element(MaxVec.begin(), MaxVec.end());
}