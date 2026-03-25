#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f);
};

struct compare {
    bool operator()(Node* l, Node* r);
};

Node* buildTree(string text);
void generateCodes(Node* root, string str, unordered_map<char, string>& huffmanCode);
string encode(string text, unordered_map<char, string>& huffmanCode);
string decode(string encoded, Node* root);

#endif