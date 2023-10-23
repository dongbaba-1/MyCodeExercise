#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
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
        
    }

};
int main(){
    string s = "abb";
    string t = "abb";
    Solution solution;
    vector<int> vec1{4,9,5};
    vector<int> vec2{9,4,9,8,4};
    // if(solution.isAnagram(s,t))
    //     cout<<"true"<<endl;
    // else
    //     cout<<"false"<<endl;
    vector<int> result = solution.intersection_set(vec1,vec2);
    for_each(result.begin(),result.end(),my_print);
    cout<<endl;
    return 0;
}