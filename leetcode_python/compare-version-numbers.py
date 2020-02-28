class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        if version1 == version2: return 0
        def getVersion(version: str) -> List:
            v = []
            n = 0
            for c in version:
                if c.isdigit():
                    n = n*10+(ord(c) - ord('0'))
                else:  
                    v.append(n)
                    n = 0
            v.append(n)
            return v
        v1 = getVersion(version1)
        v2 = getVersion(version2)
        
        for i in range(max(len(v1), len(v2))):
            n1 = v1[i] if (i<len(v1)) else 0
            n2 = v2[i] if (i<len(v2)) else 0
            if n1 > n2: return 1
            elif n1 < n2: return -1
            
        return 0
            
                    