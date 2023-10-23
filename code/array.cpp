#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    //704. 二分查找
    //给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target,写一个函数搜索 nums中的target,如果目标值存在返回下标，否则返回-1  
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = (low + high)/2;
        if(target < nums[0])
            return -1;
        if(target > nums[high])
            return -1;
        while(nums[mid] != target&&low<=high){
            if(target > nums[mid]){
                low = mid+1;
                mid = (low + high)/2;
            }
            if(target < nums[mid]){
                high = mid - 1;
                mid = (low + high)/2;
            }
                
        }
        if(low>high)
            return -1;
        return mid; 

    }
    
    //977. 有序数组的平方
    /*给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。*/
    //双指针法
    vector<int> sortedSquares(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int flag = high;
        vector<int> new_vec(nums.size());
        while(low<=high){
            if(nums[low]*nums[low] >= nums[high]*nums[high]){
                new_vec[flag] = nums[low]*nums[low];
                low++;
                
                
            }
            else if(nums[low]*nums[low] < nums[high]*nums[high]){
                new_vec[flag] = nums[high]*nums[high];
                high--;
            }
            flag--;
        }
        return new_vec;
    }

    //209.长度最小的子数组
    /*给定一个含有 n 个正整数的数组和一个正整数 target 。
    找出该数组中满足其总和大于等于 target 的长度最小的连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
    并返回其长度。如果不存在符合条件的子数组，返回 0 */
    int minSubArrayLen(int target, vector<int>& nums) {
        int p1 = 0,p2 = 0;
        int result = 0;
        int length = 0;
        int min_length = INT_MAX;
        while(p2<nums.size()){
            result = 0;
            for(int i = p1;i <= p2;i++){
                result += nums[i];
            }
            if(result < target)
                p2++;//窗口右边向右滑动
            else{
                length = p2 - p1 +1;
                if(length < min_length)
                    min_length = length;
                p1++;//窗口左边向右滑动
                if(p2<p1)
                    p2 = p1;
                
            }
        }
        return min_length<INT_MAX?min_length:0;

    }
    
    //59.螺旋矩阵II
    /*给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。*/
    vector<vector<int>> generateMatrix(int n) {
        int num = pow(n,2);
        vector<int> vec(num);
        vector<vector<int> > result_vec;
        for(int i = 1;i <= num;++i){
            
        }
    }

};

int main(){
    Solution Solution;
    vector<int> vec{-7,-3,2,3,11};
    vector<int> vec_2{1,2,3,4,5};
    //vector<int> new_vec = Solution.sortedSquares(vec);
    cout<<Solution.minSubArrayLen(11,vec_2)<<endl;
    return 0;
}