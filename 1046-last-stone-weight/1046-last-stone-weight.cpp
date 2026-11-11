class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i : stones)pq.push(i);
        while(pq.size() > 1){
            int largest = pq.top();
            pq.pop();
            int secondLargest = pq.top();
            pq.pop();
            if(largest != secondLargest)
            pq.push(abs(largest - secondLargest));
        } 
        if(pq.size() == 0)return 0;       
        return pq.top();
    }
};