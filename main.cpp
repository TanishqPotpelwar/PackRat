#include "huffman.h"

string readFile(string filename) {
    ifstream in(filename);
    return string((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
}

void writeFile(string filename, string data) {
    ofstream out(filename);
    out << data;
}

int main() {
    string inputFile = "../data/input.txt";
    string compressedFile = "../data/compressed.txt";
    string outputFile = "../data/output.txt";

    string text = readFile(inputFile);

    if (text.empty()) {
        cout << "Input file is empty!\n";
        return 0;
    }

    Node* root = buildTree(text);

    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }

    string encoded = encode(text, huffmanCode);

    writeFile(compressedFile, encoded);

    string decoded = decode(encoded, root);
    writeFile(outputFile, decoded);

    cout << "\nCompression Successful!\n";

    return 0;
}