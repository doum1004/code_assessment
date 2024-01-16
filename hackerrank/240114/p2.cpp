/*
in this task, a bsic message delivery service is to be implemented that has a rate-limiting algorithm that drops any message that has already arrived in the last k seconds. if a message has arrived but isn't delivered due to rate limiting, it still counts as having arrived at the delivery service
given the integer k, a list of messages as an array of n strings, messages and a sorted integer array timestamps representing the time at which the message arrived, for each message report the string true if the message is dewlivered and false otherwise
ex)
n=6, timestamps=[1,4,7,10,11,14] messages["hello", "bye", "bye", "hello", "bye", "hello"] and k = 5
return ["true", "true", "false", "true", "false", "false"]

messages(lowercase english letters only)
vector<string> getMessageStatus(vector<int> timestamps, vector<string> messages, int k) {}



*/

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::string> getMessageStatus(const std::vector<int>& timestamps, const std::vector<std::string>& messages, int k) {
    std::unordered_map<std::string, int> lastTimestamp;
    std::vector<std::string> results;

    for (int i = 0; i < timestamps.size(); ++i) {
        int curTime = timestamps[i];
        const auto& curMessage = messages[i];

        if (lastTimestamp.count(curMessage) && curTime - lastTimestamp[curMessage] < k) {
            results.push_back("false");
        } else {
            results.push_back("true");
        }
        lastTimestamp[curMessage] = curTime;
    }

    return results;
}

int main() {
    std::vector<int> timestamps = {1, 4, 7, 10, 11, 14};
    std::vector<std::string> messages = {"hello", "bye", "bye", "hello", "bye", "hello"};
    int k = 5;

    std::vector<std::string> results = getMessageStatus(timestamps, messages, k);

    // Print the results
    for (const auto& result : results) {
        std::cout << result << " ";
    }

    return 0;
}