// https://leetcode.com/problems/logger-rate-limiter/

public class Logger {
    private Dictionary<string,int> h { get; set; } = new Dictionary<string,int>();
    /** Initialize your data structure here. */
    public Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    public bool ShouldPrintMessage(int timestamp, string message) {
        if (!h.ContainsKey(message)) h.Add(message, 0);
        if (timestamp < h[message]) return false;
        h[message] = timestamp+10;
        return true;
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.ShouldPrintMessage(timestamp,message);
 */