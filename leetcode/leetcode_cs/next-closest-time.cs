// https://leetcode.com/problems/next-closest-time/

public class Solution {
    public string NextClosestTime(string time) {
        var h = new HashSet<int>();
        foreach (var c in time) if (c != ':' && !h.Contains(c)) h.Add(c - '0');
        
        int start = Int32.Parse(time.Substring(0,2)) * 60 + Int32.Parse(time.Substring(3,2));
        int elpased = 60*24;
        while (true) {
            start = (start + 1) % (60*24);
            int[] times = {start/60/10, start/60%10, start%60/10, start%60%10};
            
            bool valid = true;
            foreach (var t in times) {
                if (!h.Contains(t)) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;
            
            break;
        }
        
        return (start/60/10).ToString() + (start/60%10).ToString() + ":" + (start%60/10).ToString() + (start%60%10).ToString();
    }
}