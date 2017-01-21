/* 思路
* 矩阵是有序的，从左下角来看，向上数字递减，向右数字递增，
* 因此从左下角开始查找，当要查找数字比左下角数字大时。右移
* 要查找数字比左下角数字小时，上移
*/
class Solution{
public:
    bool Find(int target,vector<vector<int>> array)
    {
        int rowCount = array.size();
        int colCount = array[0].size();
        int i=rowCount-1,j=0;
        while(i>=0 && j<colCount)
        {
            if(target == array[i][j])
                return true;
            else if(target > array[i][j])           
                j++;           
            else if(target < array[i][j])           
                i--;            
        }
        return false;
    }
};