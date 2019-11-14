#include<bits/stdc++.h>

using namespace std;

struct NODE {

    struct NODE* next[53];

}*NIL;


bool flag;

//check if the string is palindrome or not
bool Pal(string s){

    int n = s.length();
    for(int i = 0, j = n-1; i < j; ++i, --j) {
        if(s[i] != s[j]) return false;
    }
    return true;
}


class Trie {
    NODE *root, *NIL;


    NODE* createNode() {
        NODE* new_node = new NODE;
        for(int i = 0; i < 53; ++i) {
            new_node->next[i] = NULL;
        }
        return new_node;
    }
public:
    Trie() {

        root = createNode();
        root->next[52] = NIL;
        NIL = createNode();
    }

    void insert(string s) {

        int n = s.length();

        NODE *temp = root;

        for(int i = 0; i < n; ++i) {

            if(islower(s[i])) {

                if(temp->next[s[i]-'a']) {
                    temp = temp->next[s[i]-'a'];
                } 
                else 
                {
                    temp->next[s[i]-'a'] = createNode();
                    temp = temp->next[s[i]-'a'];
                }
            } 
            else 
            {
                char c = s[i] + 32;
                if(temp->next[c-'a' + 26]) {
                    temp = temp->next[c-'a' + 26];
                } 
                else 
                {
                    temp->next[c-'a'+26] = createNode();
                    temp = temp->next[c-'a'+26];
                }
            }
        }
        temp->next[52] = NIL;
    }

    bool search(string s) {
        int n = s.length();
        NODE *temp = root;
        for(int i = 0; i < n; ++i) {
            if(islower(s[i])) {
                if(temp->next[s[i]-'a']) {
                    temp = temp->next[s[i]-'a'];
                } else {
                    return false;
                }
            } else 
            {
                char c = tolower(s[i]);
                if(temp->next[c-'a' + 26]) {
                    temp = temp->next[c-'a' + 26];
                } 
                else 
                {
                    return false;
                }
            }
        }
        return temp->next[52] == NIL;
    }
};

int main() {

    Trie t;
    int n;
    cin >> n;
    string s[n];
    vector<string> NP;
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
        if(!Pal(s[i])) {
            t.insert(s[i]);
            string r = s[i];
            reverse(r.begin(), r.end());
            NP.push_back(r);
        }
    }
    
    for(int i = 0; i < NP.size(); ++i) {
        if(t.search(NP[i])) {
            printf("YES\n");        
            break;
        }
    }
    if(!flag) printf("NO\n");
    return 0;
}
