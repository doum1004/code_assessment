'''
https://leetcode.com/problems/minimum-genetic-mutation

Solution1. BSF
time: o(n) n*8 + n
space: o(n) n(q) + n(hash)

1. store bank into hashmap with minMutation count
2. queue add startGene
3. loop queue, BSF.
4. pop from queue and mutate char on from begin to end.
5. check mutated string is bank, if it is exit loop
6. check minMutation in hashMap, if minMutation is smaller or equal exit loop
7. save new minMutation
8. if mutation is not the endGene push into queue

'''
class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        hm = {}
        for gene in bank:
            hm[gene] = 0
        if not endGene in hm:
            return -1

        q = []
        q.append(startGene)
        while q:
            gn = len(q)
            for i in range(gn):
                gene = q.pop(0)
                res = 0
                if gene in hm:
                    res = hm[gene]
                res += 1
                
                for j in range(len(gene)):
                    for c in 'ACGT':
                        mutated = gene
                        if mutated[j] == c:
                            continue
                        mutated = mutated[:j] + c + mutated[j+1:]
                        if mutated == endGene:
                            return res

                        if not mutated in hm: continue
                        if hm[mutated] != 0 and res >= hm[mutated]: continue
                        hm[mutated] = res
                        q.append(mutated)
        return -1
        