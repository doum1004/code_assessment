'''
https://leetcode.com/problems/substring-with-concatenation-of-all-words

Solution1. sliding window with hash map
time: o(L*N) s.size() * N(all words)
space: o(n)
https://leetcode.com/problems/substring-with-concatenation-of-all-words/solutions/969070/approach-using-hashmap-and-sliding-window-concepts-in-c-easy-understandable-code/?envType=study-plan-v2&envId=top-interview-150
'''
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n1 = len(words)
        n2 = len(words[0])
        total = n1*n2
        n3 = len(s)
        if n1 == 0 or n2 == 0 or n3 == 0: return []

        wordMap, tempMap = defaultdict(int), defaultdict(int)
        for word in words: wordMap[word] += 1
        
        res = []
        for i in range(n3 - total + 1):
            for j in range(i, i+total, n2):
                subs = s[j:j+n2]
                if subs in wordMap: tempMap[subs] += 1
                else: break
            if wordMap == tempMap: res.append(i)
            tempMap.clear()
        return res
        