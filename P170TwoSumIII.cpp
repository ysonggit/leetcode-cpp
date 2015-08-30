class TwoSum {
public:
    unordered_map<int, int> nums;
	void add(int number) {
	    nums[number]++; // TLE if add an if(nums.find(number) == nums.end())
	}

	bool find(int value) {
	    for(auto iter = nums.begin(); iter!= nums.end(); ++iter){
	        int cur = iter->first;
	        int expect = value - cur;
	        // mistake must check cur != expect
	        // test case add(0) find(0)
	        if((cur == expect && nums[cur] > 1) || (cur != expect && nums.find(expect) != nums.end()) ) return true;
	    }
	    return false;
	}
};
