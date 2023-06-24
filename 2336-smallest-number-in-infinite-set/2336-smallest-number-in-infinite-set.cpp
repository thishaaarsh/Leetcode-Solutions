class SmallestInfiniteSet {
public:
   set<int>ss;
    SmallestInfiniteSet() {
        ss.insert(1);
    }
    
    int popSmallest() {
        int temp = *ss.begin();
        ss.erase(temp);
        if(ss.empty() == true)
            ss.insert(temp+1);
        return temp;
    }
    
    void addBack(int num) {
        if(num < *ss.rbegin())
            ss.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */