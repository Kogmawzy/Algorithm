
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix)
  {
      if(matrix.empty())
          return vector<int>();
   int m=matrix.size(),n=matrix[0].size();
  int up = 0,down = m-1,left = 0,right = n-1;
  vector<int> res;
  while(1)
  {
      for(int i=left;i<=right;i++)
        res.push_back(matrix[up][i]);
      if(++up > down) break;
 
      for(int j=up;j<=down;j++)
        res.push_back(matrix[j][right]);
      if(--right<left) break;
 
      for(int i=right;i>=left;i--)
        res.push_back(matrix[down][i]);
      if(--down<up) break;
 
      for(int j=down;j>=up;j--)
        res.push_back(matrix[j][left]);
      if(++left > right) break;
  }
  return res;
    }
};