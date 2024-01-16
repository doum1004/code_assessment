/*
xxx's network of trucks contains num_trucks number of trucks denoted by [1,2, ...num_trucks]. many of these trucks depend on packages from a shipment arriving from a separate truck, before departing to make its own shipoment. There are a total of m dependencies in the truck network which are denoted by the 2d array track_deps[], with shape mx2. Each pair {truck_deps[i][0], truck_deps[i][1]} denotes that the truck numbered truck_deps[i][0] depends on the packages in the shipment from truck_deps[i][1]. truck_deps[i][0] must depart only after truck_deps[i][1] has arrived. If a truck is delayed, all the trucks dependent on the previous truck and their corresponding dependencies are also delayed. Given a list of k initially delayed trucks and the network as described, find the list of all delyaed trucks. Return the list sorted in increasing order of truck numbers.

ex) consdier num_trucks = 4 and the number of dependencies m = 2, truck_deps = [[4,1], [32]] the number of delayed trucks k=2, and delayed=[1,3]. turck 1 is delayed. truck 4 depends on truck 1 so truck 4 is delayed. truck 3 is delyaed there are no turkcsd depedndent on truck 3. return the sorted array of delay trucks [1,3,4]

int num_trucks: number of trucks
int truck_deps[m,2]: the details of the truck dependencies
int delayed[k] trucks delayed initially
return int[] sorted list of all delayed trucks

constraints
2 <- num_trucks <= 10^5
1 <= m <min(num_trucks*(num_trucks-1)/2, 10^5)
1 <= k <= num_trucks
1 <= truck_deps[i][0,1] <=n
truck_deps[i][0] != truck[deps[i][1]
1<=delayed[i] <= num_trucks
the pair trucks_deps[i][0], trucks_deps[i][1] will only be given once in the input

*/
class Solution {
public:
    std::vector<int> countDelayedTrucks(int num_trucks, std::vector<std::vector<int>> truck_deps, std::vector<int> delayed) {
        std::vector<std::vector<int>> graph(num_trucks + 1);
        std::vector<int> is_delayed(num_trucks + 1, 0);
        std::vector<int> result;

        for (const auto& dep : truck_deps) {
            graph[dep[1]].push_back(dep[0]);
        }

        for (int i : delayed) {
            dfs(i, graph, is_delayed);
        }

        for (int i = 1; i <= num_trucks; i++) {
            if (is_delayed[i]) {
                result.push_back(i);
            }
        }

        return result;
    }

private:
    void dfs(int truck, const std::vector<std::vector<int>>& graph, std::vector<int>& is_delayed) {
        if (is_delayed[truck]) {
            return;
        }

        is_delayed[truck] = 1;

        for (int dependent_truck : graph[truck]) {
            dfs(dependent_truck, graph, is_delayed);
        }
    }
};

int main() {
    Solution solution;

    // Example test case
    int num_trucks = 4;
    std::vector<std::vector<int>> truck_deps = {{4, 1}, {3, 2}};
    std::vector<int> delayed = {1, 3};

    std::vector<int> result = solution.countDelayedTrucks(num_trucks, truck_deps, delayed);

    std::cout << "Delayed trucks: ";
    for (int truck : result) {
        std::cout << truck << " ";
    }
    std::cout << std::endl;

    return 0;
}