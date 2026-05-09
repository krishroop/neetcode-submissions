class WordDictionary {
    
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;

            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* root;

public:

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {

        TrieNode* node = root;

        for (char c : word) {

            int idx = c - 'a';

            if (!node->child[idx])
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->isEnd = true;
    }

    bool dfs(string &word, int pos, TrieNode* node) {

        if (!node)
            return false;

        if (pos == word.size())
            return node->isEnd;

        char c = word[pos];

        // wildcard
        if (c == '.') {

            for (int i = 0; i < 26; i++) {

                if (node->child[i] &&
                    dfs(word, pos + 1, node->child[i]))
                    return true;
            }

            return false;
        }

        // normal character
        int idx = c - 'a';

        return dfs(word, pos + 1, node->child[idx]);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};