// https://leetcode.com/problems/evaluate-division/

public class Solution {
    private double DFS(ref Dictionary<string, Dictionary<string, double>> g, string cur, string tar, ref HashSet<string> visited, double factor) {
        if (cur == tar) return factor;
        if (visited.Contains(cur)) return -1;
        visited.Add(cur);
        foreach (var n in g[cur]) {
            var result = DFS(ref g, n.Key, tar, ref visited, factor * n.Value);
            if (result != -1) return result;
        }
        return -1;
    }
    
    public double[] CalcEquation(IList<IList<string>> equations, double[] values, IList<IList<string>> queries) {
        // build graph
        var g = new Dictionary<string, Dictionary<string, double>>();
        for (int i=0; i<equations.Count; ++i) {
            var e = equations[i];
            var v = values[i];
            if (!g.ContainsKey(e[0])) g.Add(e[0], new Dictionary<string, double>());
            if (!g.ContainsKey(e[1])) g.Add(e[1], new Dictionary<string, double>());
            g[e[0]].Add(e[1], v);
            g[e[1]].Add(e[0], 1/v);
        }
        
        double[] res = new double[queries.Count];
        for (int i=0; i<queries.Count; ++i) {
            var q = queries[i];
            double n = -1.0;
            if (g.ContainsKey(q[0]) && g.ContainsKey(q[1])) {
                if (g.ContainsKey(q[0]) && g[q[0]].ContainsKey(q[1])) {
                    n = g[q[0]][q[1]];
                }
                else {
                    var visited = new HashSet<string>();
                    n = DFS(ref g, q[0], q[1], ref visited, 1);
                }
            }
            res[i] = n;
        }
        return res;
    }
}