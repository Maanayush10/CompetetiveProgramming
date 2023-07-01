
//strivers problem set matrix zeroes
//better solution
void setZeroes(vector<vector<int>>& matrix) {
        int colSize= matrix[0].size();
        int rowSize= matrix.size();

       vector<bool> row(rowSize, false);
        vector<bool> col(colSize, false);

        for(int i=0; i<rowSize; i++)
        {
            for(int j=0; j<colSize; j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=true;
                    col[j]=true;
                }
            }
        }
        for(int i=0; i<rowSize; i++)
        {
            for(int j=0; j<colSize; j++)
            {
                if(row[i]|| col[j])
                {
                    matrix[i][j]=0;
                }
            }
        }

        
    }
