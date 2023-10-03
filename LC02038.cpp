class Solution {
public:
    bool winnerOfGame(string colors) {
        int Acount = 0;
        int Bcount = 0;
        int n = colors.size();
        int Acur = -2;
        int Bcur = -2;
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            if(colors[i] == 'A')
            {
                if(Bcur>0)
                    Bcount+= Bcur;
                Acur++;
                //flag = 0;
                Bcur = -2;
            }
            else
            {
                if(Acur>0)
                    Acount+= Acur;
                Acur = -2;
                Bcur++;
            }
        }
        if(Acur>0)
            Acount+= Acur;
        if(Bcur>0)
            Bcount+= Bcur;
        
        return Acount>Bcount;
        
    }
};