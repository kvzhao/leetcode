#include "utility.hpp"

using namespace std;

constexpr int numCharacters = 26;

struct TrieNode {
public:
  bool endOfWorld = false;
  TrieNode *children[numCharacters] = {};
};

class Trie {
public:
  Trie() { root = new TrieNode; }

  void insert(string word) {
    TrieNode *node = root;
    for (char c : word) {
      c = c - 'a';
      if (node->children[c] == nullptr) {
        node->children[c] = new TrieNode;
      }
      node = node->children[c];
    }

    node->endOfWorld = true;
  }

  bool search(string word) {
    auto *p = find(word);

    return p != nullptr && p->endOfWorld;
  }

  bool startsWith(string prefix) {
    auto *p = find(prefix);

    return p != nullptr;
  }

private:
  TrieNode *find(string key) {
    TrieNode *node = root;
    for (int i = 0; i < key.size() && node != nullptr; ++i) {
      char c = key[i] - 'a';
      node = node->children[c];
    }
    return node;
  }

  TrieNode *root = nullptr;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {

  Trie *t = new Trie();

  string line;

  while (getline(cin, line)) {
    auto op = line;

    getline(cin, line);
    auto item = line;

    cout << op << " " << item << endl;

    if (op == "insert") {

      t->insert(item);

    } else if (op == "search") {

      auto ret = t->search(item);
      cout << ret << endl;

    } else if (op == "startswith") {

      auto ret = t->startsWith(item);
      cout << ret << endl;
    }
  }

  return 0;
}