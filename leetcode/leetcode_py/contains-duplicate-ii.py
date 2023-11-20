class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        m = {}
        for i, n in enumerate(nums):
            if n in m:
                if abs(m[n] - i) <= k:
                    return True
            m[n] = i
        return False
        