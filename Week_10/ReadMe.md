20201105
24. 两两交换链表中的节点
    说明：给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
    实例：1234 ->2143
    解法1：递归：
    	class Solution {
	public:
    	ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
         return NULL;
         if(head->next==NULL)
         return head;
         ListNode *headSub;
         ListNode * headNew;
         headSub = head->next->next;
         head->next->next = head;
         headNew = head->next;
         head->next = swapPairs(headSub);
         return headNew;
    }
};
	解法2：双指针，一点一点向后移动
	class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
        return head;

        ListNode * first = head;
        ListNode * second = NULL;

           second = head->next;

        while(first!=NULL&&second!=NULL)
        {
            int temp;
            temp =  second->val;
            second->val = first->val;
            first->val = temp;
            first = first->next->next;
            if(second->next!=NULL)
            {
                second = second->next->next;
            }
        }
        return head;
    }
};
心得体会：
	1)递归：
	1
	1 2
	1 2 3
	1 2 3 4
	你会看到分割为重复子结构，可以用递归，然后再将视角放到当前，确认终止条件和当前功能（null，1个节点和两个节点交换）即可。难点使用特例法确认子结构。用回退某一次来理解递归可以辅助代码编写。
	2)双指针
	如何用双指针来重复循环，这个是难点，就是因为这个比较难，而采用递归规避如何通过指针判断结束，看答案后也明白了，就是所见即所得，框架先确定，再各顾个的，比如：first和second每次结束后，如何移动到下个位置，继续循环，其实记住一点：first和second都不为空时才能比较，才有意义，而null和不够两个节点时都可以return head统一。1.移动（a->next为null时就没有next->next了。但是都可以指向null.这里是难点）2.返回时机（子循环，指针移动，返回统一（自顶向下写法））
	3）看的再多，遍数再多都不如自己死磕一次，再5遍。---专注本次，下次不再犯的勇气。
