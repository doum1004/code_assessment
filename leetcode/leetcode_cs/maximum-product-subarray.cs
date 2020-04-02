// https://leetcode.com/problems/maximum-product-subarray/

public class Solution {
    public int MaxProduct(int[] nums) {
        int preA,preB,res;
        preA = preB = res = nums[0];
        for (int i=1; i<nums.Length; ++i) {
            var n = nums[i];
            var a = n*preA;
            var b = n*preB;
            preA = Math.Min(n,Math.Min(a,b));
            preB = Math.Max(n,Math.Max(a,b));
            res = Math.Max(res,Math.Max(preA,preB));
        }
        return res;
    }
}