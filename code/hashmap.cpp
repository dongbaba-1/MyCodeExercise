#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
遇到hash问题，可以用的数据结构有array、set和map
*/

void my_print(int value){
    cout<<value<<" ";
}
class Solution{
public:
    //242.有效的字母异位词，判断s和t是否是字母异位词
    //使用数组记录26个字母出现的次数，
    bool isAnagram(string s,string t){
        if(s.size() != t.size())
            return false;
        vector<int> vec(26);//初始化26个默认值为0的元素vector<int> vec(26,1)初始化26个默认值为1的元素
        for(int i = 0;i<s.size();++i){
            vec[s[i] - 'a']++;
            vec[t[i] - 'a']--;
        }
        // for(int i = 0;i<t.size();++i){
        //     vec[t[i] - 'a']--;
        // }
        for(int i =0;i<vec.size();++i){
            if(vec[i] != 0)
                return false;
        }

        return true;
    }

    //349.两个数组的交集，给定两个数组，返回他们的交集
    //输出结果的每个元素是唯一的
    //数组长度小于1000，元素数值0~1000
    //法1：使用数组做哈希映射
    vector<int> intersection_array(vector<int> &vec1,vector<int> &vec2){
        vector<int> hash(1000);
        vector<int> result;
        for(int i = 0;i<vec1.size();++i){
            hash[vec1[i]]++;
        }
        for(int i = 0;i<vec2.size();++i){
            if(hash[vec2[i]]){
                result.push_back(vec2[i]);
                hash[vec2[i]] = 0;
            }

        }
        
        return result;
    }
    
    //法2：使用set做哈希映射
    vector<int> intersection_set(vector<int> &vec1,vector<int> &vec2){
        set<int> set_int;
        vector<int> result;
        for(int i = 0;i<vec1.size();++i){
            set_int.insert(vec1[i]);
        }
        for(int i = 0;i<vec2.size();++i){
            if(set_int.count(vec2[i])){
                result.push_back(vec2[i]);
                set_int.erase(vec2[i]);
            }
                
        }
        return result;

    }

    //202.快乐树
    /*编写一个算法来判断一个数 n 是不是快乐数。
   「快乐数」 定义为：
    对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
    然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
    如果这个过程 结果为 1，那么这个数就是快乐数。
    如果 n 是 快乐数 就返回 true ；不是，则返回 false 。*/
    bool isHappy(int n) {
        vector<int> vec;
        unordered_set<int> uset;
        int temp = n;
        while (temp != 1)
        {
            uset.insert(temp);
            while (temp)//先把每一位数推进数组
            {
                int num = temp%10;
                vec.push_back(num);
                temp = temp / 10;
            }
            for(int i = 0;i<vec.size();++i){
                temp += vec[i] * vec[i];
            }
            vec.clear();
            if(uset.count(temp))
                return false;
            
        }
        return true;
    }

    //1.两数之和
    /*
    给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
    你可以按任意顺序返回答案。*/
    //最早使用的是双层循环遍历查找  
    //这次使用哈希表解决
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> unmap;
        vector<int> result;
        for(int i =0;i<nums.size();++i){
            if(unmap.find(target - nums[i]) == unmap.end()){//若不存在于map中
                unmap.insert(unordered_map<int,int>::value_type(nums[i],i));//插入数值 — 下标的键值对
                //unmap.insert(pair<int,int>(nums[i],i));
            }
            else{
                result.push_back(i);
                result.push_back(unmap[target - nums[i]]);
                // unordered_map<int,int>::iterator it = unmap.find(nums[i]);
                // result.push_back(it->second);
            }
                
        }
        return result;
    }

    /*454. 四数相加 II
    给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
    0 <= i, j, k, l < n
    nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
    */
    int fourSum_2(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
    }

    /*15. 三数之和
    给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
    请你返回所有和为 0 且不重复的三元组。*/
    vector<vector<int>> threeSum(vector<int>& nums) {
        
    }

    /*383. 赎金信
    给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
    如果可以，返回 true ；否则返回 false 。magazine 中的每个字符只能在 ransomNote 中使用一次。*/
    bool canConstruct(string ransomNote, string magazine) {
        multiset<char> mset;
        for(int i = 0;i<magazine.size();++i){
            mset.insert(magazine[i]);
        }
        for(int i = 0;i<ransomNote.size();++i){
            auto it = mset.find(ransomNote[i]);
            if(it!= mset.end()){//如果存在
                mset.erase(it);
            }
            else
                return false;
        }
        return true;
    }

    /*18. 四数之和
    给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
    请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
    0 <= a, b, c, d < n
    a、b、c 和 d 互不相同
    nums[a] + nums[b] + nums[c] + nums[d] == target
    你可以按 任意顺序 返回答案 。*/
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    }    

};
int main(){
    // string s = "abb";
    // string t = "abb";
    Solution solution;
    // vector<int> vec1{4,9,5};
    // vector<int> vec2{9,4,9,8,4};
    // if(solution.isAnagram(s,t))
    //     cout<<"true"<<endl;
    // else
    //     cout<<"false"<<endl;
    //vector<int> result = solution.intersection_set(vec1,vec2);
    //for_each(result.begin(),result.end(),my_print);
    if(solution.isHappy(2))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    cout<<endl;
    return 0;
}
