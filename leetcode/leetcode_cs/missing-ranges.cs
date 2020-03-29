// 

public class Solution {
    public IList<string> FindMissingRanges(int[] nums, int lower, int upper) {
        var res = new List<string>();
        for (int i=0; i<=nums.Length; ++i) {
            long l = (i == 0) ? lower : (long)nums[i-1]+1;
            long r = (i == nums.Length) ? upper : (long)nums[i]-1;
            if (l<=r) {
                var s = l.ToString();
                if (l<r) s += "->" + r.ToString();
                res.Add(s);
            }
        }
        return res;
    }
}