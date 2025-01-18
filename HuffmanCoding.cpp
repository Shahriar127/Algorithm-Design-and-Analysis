#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(MinHeapNode* left, MinHeapNode* right) {
        return left->freq > right->freq;
    }
};

void printHuffmanCodes(MinHeapNode* root, const string& str) {
    if (!root) return;
    if (root->data != '$') cout << root->data << ": " << str << endl;
    printHuffmanCodes(root->left, str + "0");
    printHuffmanCodes(root->right, str + "1");
}

void HuffmanCoding(const string& data) {
    unordered_map<char, int> freqMap;
    for (char ch : data) freqMap[ch]++;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (const auto& pair : freqMap) 
                minHeap.push(new MinHeapNode(pair.first, pair.second));

    while (minHeap.size() > 1) {
        MinHeapNode* left = minHeap.top(); minHeap.pop();
        MinHeapNode* right = minHeap.top(); minHeap.pop();

        MinHeapNode* top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    printHuffmanCodes(minHeap.top(), "");
}

int main() {
    string data = "this is an example for huffman encoding";
    HuffmanCoding(data);
    return 0;
}
