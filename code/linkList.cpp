#include <iostream>
using namespace std;
struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode(int value):val(value),next(nullptr){}
    ListNode(int value,ListNode* next):val(value),next(next){}
};

class Solution {
public:

    void print_list(ListNode* head){
        while(head){
            cout<<head->val<<"->";
            head = head->next;
        }
    }

    //203.移除链表元素
    //给你一个链表的头节点head和一个整数val ，请你删除链表中所有满足Node.val == val的节点，并返回新的头节点
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return nullptr;
        ListNode* pre = new ListNode(1);//设置虚拟头节点
        ListNode* result = pre;
        ListNode* cur = head;
        pre->next = head;
        while(cur){
            
            if(cur->val == val){
                pre->next = cur->next;
                cur = cur->next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return result->next;
    }

    //206.反转链表
    //给你单链表的头节点head，请你反转链表，并返回反转后的链表。
    //三指针法
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)//head为空或只有head一个节点
            return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        
        if(!cur->next){//只有两个节点
            cur->next = pre;
            pre->next = nullptr;
            return cur;
        }
        //有两个以上节点
        ListNode* post = cur->next;
        pre->next = nullptr;
        while(cur){
            cur->next = pre;
            pre =cur;
            cur = post;
            if(post)
                post = post->next;
        }
        return pre;
            
    }
    //24. 两两交换链表中的节点
    /*给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。*/
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* pre = head;
        ListNode* cur = pre->next;
        ListNode* post = cur->next;
        ListNode* result = cur;
        ListNode* pre_pre;
        while(1){
            pre_pre = pre;
            cur->next = pre;
            pre->next = post;

            pre = post;
            if(pre)
                cur = pre->next;
            else
                break;
            if(cur){
                post = cur->next;
                pre_pre->next = cur;
            }
                
            else
                break;
        }
        return result;
        
    }

    //19. 删除链表的倒数第N个结点
    //给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head||(!head->next&&n == 1))
            return nullptr;
        ListNode* virtual_head = new ListNode(0,head);
        ListNode* p = head;
        int count = 1;
        while(p->next){
            count++;
            p = p->next;
        }
        if(n > count)
            return nullptr;
        virtual_head->next = head;
        ListNode* pre = virtual_head;
        ListNode* cur = pre->next;
        int num = count - n;
        if(num == 0){
            head = head->next;
        }
        while(num){
            pre = cur;
            cur = cur->next;
            num--;
        }
        pre->next = cur->next;
        delete cur;
        return head;
    }
    //还可以使用快慢指针，快指针先走n步然后快慢指针同时移动，当快指针指空时此时慢指针指向倒数第n个节点


    //160.链表相交
    //给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
    //进阶：你能否设计一个时间复杂度 O(n) 、仅用 O(1) 内存的解决方案
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)
            return nullptr;
        int node_count_A = 0,node_count_B = 0;
        ListNode* p = headA,* q = headB;
        while(p){
            node_count_A++;
            p = p->next;
        }
        while(q){
            node_count_B++;
            q = q->next;
        }
        p = headA;
        q = headB;//返回头节点
        int num = abs(node_count_A - node_count_B);
        if(node_count_A > node_count_B){
            while(num){
                headA = headA->next;
                num--;
            }
        }
        else if(node_count_B > node_count_A){
            while(num){
                headB = headB->next;
                num--;
            }
        }
        while(headA&&headB){
            if(headA == headB)
                break;
            headA = headA->next;
            headB = headB->next;
        }
        if(!headA||!headB)
            return nullptr;
        return headA;
    }
    
    //142.环形链表II
    /*给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。*/
    //进阶：你是否可以使用 O(1) 空间解决此题？
    ListNode *detectCycle(ListNode *head) {
        
    }

};

int main(){
    ListNode *node_1 = new ListNode(4);
    ListNode *node_2 = new ListNode(2,node_1);
    ListNode *node_3 = new ListNode(1,node_2);
    ListNode *node_4 = new ListNode(9,node_3);
    ListNode *node_5 = new ListNode(0,node_4);

    ListNode *node_21 = new ListNode(4);
    ListNode *node_22 = new ListNode(2,node_21);
    ListNode *node_23 = new ListNode(3,node_22);
    Solution solution;
    //solution.print_list(solution.removeElements(node_5,7));
    // solution.print_list(node_3);
    // cout<<"翻转后"<<endl;
    // solution.print_list(solution.reverseList(node_3));
    // solution.print_list(node_2);
    // cout<<"删除倒数第2个节点后"<<endl;
    solution.print_list(solution.getIntersectionNode(node_5,node_23));
    return 0;
}

