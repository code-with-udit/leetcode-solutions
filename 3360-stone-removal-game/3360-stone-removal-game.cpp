class Solution {
public:
    bool canAliceWin(int n) {
        int tern = 0;
        int ct = 10;
        while(n >= ct){
            n -= ct;
            ct--;
            tern++;
        }
        return (tern % 2);
    }
};