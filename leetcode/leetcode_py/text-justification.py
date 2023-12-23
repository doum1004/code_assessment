'''
https://leetcode.com/problems/text-justification

Solution1. Iterate word and give right space using modulo
time: o(n)
space: o(n)

ex) "example" "of" "text" maxWidth = 18 (total 13)
for i; i<5(leftspace); ++i
  idx = i % cursize-1
- 'example ' 'of' 'text' (i = 0, idx = 0) 14
- 'example ' 'of ' 'text' (i = 1, idx = 1) 15
- 'example  ' 'of ' 'text' (i = 2, idx = 0) 16
- 'example  ' 'of  ' 'text' (i = 2, idx = 0) 17
- 'example   ' 'of  ' 'text' (i = 2, idx = 0) 18
-> 'example   of  text'
'''
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res, cur, nbWords = [], [], 0
        
        for word in words:
            if len(word) + len(cur) + nbWords > maxWidth:
                for i in range(maxWidth - nbWords):
                    idx = 0 if len(cur) == 1 else i % (len(cur) - 1)
                    cur[idx] += ' '
                res.append(''.join(cur))
                cur.clear()
                nbWords = 0
            cur.append(word)
            nbWords += len(word)
                
        # last word
        lastWords = ' '.join(cur)
        while len(lastWords) < maxWidth:
            lastWords += ' '
        res.append(lastWords)

        return res
        