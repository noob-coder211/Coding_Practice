class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int r= 9;
        int c = 9;
        //row check

        unordered_set<char> rmap;
        unordered_set<char> cmap;

        
        for(int i=0;i<9;i++)
        {
            rmap.clear();
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.')
                    continue;
                if(rmap.count(board[i][j]) == 1)
                {
                    cout<<i<<" "<<j<<endl; 
                    return false;
                }
                rmap.insert(board[i][j]);
            }
        }
        cout<<"row"<<endl;
        for(int i=0;i<9;i++)
        {
            cmap.clear();
            for(int j=0;j<9;j++)
            {
                if(board[j][i] == '.')
                    continue;
                if(cmap.count(board[j][i]) == 1)
                    return false;
                cmap.insert(board[j][i]);
            }
        }
        cout<<"col"<<endl;
        unordered_set<char> gmap;
        for(int i=0; i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                gmap.clear();
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        if(board[3*i+k][3*j+l] == '.')
                            continue;

                        if(gmap.count(board[3*i+k][3*j+l]) == 1)
                            return false;
                        gmap.insert(board[3*i+k][3*j+l]);
                    }
                }

            }
        }
        cout<<"grid"<<endl;
        return true;
        
    }
};