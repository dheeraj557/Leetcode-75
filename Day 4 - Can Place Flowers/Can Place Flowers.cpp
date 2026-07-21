class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)
        {
            return true;
        }
        int size = flowerbed.size();
        if(size==1)
        {
            if(flowerbed[0]==0 and (n==1 or n==0))
            {
                return true;
            }
            else if(flowerbed[0]==1 and n==0)
            {
                return true;
            }
            return false;
        }
        for(int i=0;i<flowerbed.size();i++)
        {
            if(i==0)
            {
                if(flowerbed[1]==0 and flowerbed[0]==0)
                {
                    flowerbed[i]=1;
                    n--;
                }
            }
            else if(i==(size-1))
            {
                if(flowerbed[size-1]==0 and flowerbed[size-2]==0)
                {
                    flowerbed[i]=1;
                    n--;
                }
            }
            else if(flowerbed[i]==0 and flowerbed[i+1]==0 and flowerbed[i-1]==0)
            {
                flowerbed[i]=1;
                n--;
            }
            if(n==0)
            {
                return true;
            }
        }
        return false;
    }
};