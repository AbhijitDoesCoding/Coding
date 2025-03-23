int highestFrequency(const vector<int>& arr) {
    unordered_map<int, int> freqMap;

    // Count frequencies of elements in the array
    for (int num : arr) {
        freqMap[num]++;
    }

    // Find the element with the highest frequency
    int maxFreq = 0;
    int maxFreqElement = arr[0]; // Default to the first element
    for (const auto& pair : freqMap) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            maxFreqElement = pair.first;
        }
    }

    return maxFreqElement;
}
