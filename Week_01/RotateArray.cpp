class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty())
            return ;
        int size = nums.size();
        int *temp = new int[size];
        for(int i=0;i<size;i++)
        {
            (temp[(i+k)%size]) = nums[i];
        }
        for(int i=0;i<size;i++)
        {
            nums[i] = temp[i];
        }
        delete [] temp;
        temp=NULL;

    }
};

/*
思路：关键知识点：
1.(i+k)%size:代表无论k的值与size是多少的关系，(i+k)%size就是num[i]的新位置。
2.必须引进temp，因为不引进临时内存，nums值就会被修改


*/
