#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

struct Node
{
    Node *links[26];
    int count = 0;

    /**
     * Check if the given character is a key in the links array.
     *
     * @param ch the character to check
     *
     * @return true if the character is a key, false otherwise
     */
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    /**
     * Sets the key for a given character in the trie.
     *
     * @param ch The character to set the key for.
     * @param node The node to associate with the character.
     *
     * @throws None.
     */
    void putKey(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    /**
     * Retrieves the Node associated with the given character.
     *
     * @param ch the character to search for
     *
     * @return the Node associated with the character
     *
     * @throws None
     */
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};

class Trie
{
public:
    Node *root;
    
    Trie()
    {
        root = new Node();
    }

    /**
     * Inserts a word into the data structure.
     *
     * @param word the word to be inserted
     *
     * @throws None
     */
    void insert(string word)
    {
        Node *node = root;
        // if(search(word)) return;
        bool in = false;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                Node *n = new Node();
                node->putKey(word[i], n);
            }
            node = node->get(word[i]);
        }
        node->count += 1;
        // at the end add a Node increase count , which will mark as the end of word and also store count of the word
    }

    /**
     * Searches for a word in the data structure.
     *
     * @param word the word to search for
     *
     * @return true if the word is found, false otherwise
     */
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->count > 0;
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
    /**
     * Counts the number of words in the Trie data structure that start with the given word.
     *
     * @param word the word to search for in the Trie
     *
     * @return the number of words in the Trie that start with the given word
     *
     * @throws None
     */
    int countWordsStartsWith(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++){
            if (!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return countWord(node);
    }
    /**
     * Counts the number of words in the given tree.
     *
     * @param node pointer to the root of the tree
     *
     * @return the total number of words in the tree
     *
     * @throws None
     */
    int countWord(Node *node)
    {
        int total = 0;
        bool f = false;
        for (int i = 0; i < 26; i++)
        {
            if(node->links[i] != NULL){
                f = true;
                total += countWord(node->links[i]);
            }
        }
        if(!f) return node->count; // if this node marks the end of the 
        return total; //
    }
};

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    Trie trie;
    trie.insert("samsung");
    trie.insert("samsung");
    trie.insert("apple");
    trie.insert("asus");
    trie.insert("google");
    cout << trie.countWordsStartsWith("samsung");
    cout << trie.countWordsStartsWith("a");
    cout << trie.countWordsStartsWith("go");
    cout << trie.search("go");
    cout << trie.search("google");
    cout << trie.startsWith("s");
    return 0;
}