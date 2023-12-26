class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count1 = 0, count2=0;
        for(int i=0; i<moves.size();i++){
            if(moves[i] == 'L'){
                count1++;
                count2++;
            }
            if(moves[i] == 'R'){
                count1--;
                count2--;
            }
            if(moves[i] == '_'){
                count1++;
                count2--;
            }
        }
        return max(abs(count1),abs(count2));
    }
};