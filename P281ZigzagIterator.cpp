class ZigzagIterator {
public:
    vector<int>::iterator iter1, iter2;
    int next_val;
    bool next_from_first;
    vector<int> first, second;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        first = v1;
        second = v2;
        iter1 = first.begin();
        iter2 = second.begin();
        if(iter1 != first.end()) next_from_first = true;
    }

    int next() {
        return next_val;
    }

    bool hasNext() {
        if(iter1 == first.end() && iter2 == second.end()){ 
            return false;
        }else if(iter1 == first.end()) {
            next_val = *iter2;
            iter2++;
        }else if(iter2 == second.end()){
            next_val = *iter1;
            iter1++;
        }else{
            if(next_from_first){
                next_from_first = false;
                next_val = *iter1;
                iter1++;
            }else{
                next_from_first = true;
                next_val = *iter2;
                iter2++;
            }
        }
        return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
