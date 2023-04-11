#include <bits/stdc++.h>
using namespace std;

struct node {
    node *next[27];
    bool completeWord;

    node (){
        completeWord = false;
        for (int i = 0; i < 26; i++){
            next[i] = NULL;
        }
        
    }
}* root;

void trieInsert(string s)
{
    node *n = root;
    for (int i = 0; i < s.size(); i++){
        int x = s[i]-'a';

        if (n->next[x] == NULL){
            n->next[x] = new node ();
        }

        n = n->next[x];
    }
    n->completeWord = true;
}

bool trieSearch(string s)
{
    node *n = root;
    for (int i = 0; i < s.size(); i++){
        int x = s[i]-'a';

        if (n->next[x] == NULL){
            return false;
        }

        n = n->next[x];
    }

    return n->completeWord;
}

void trieDel(node* n)
{
    for (int i = 0; i < 26; i++)
        if (n->next[i])
            trieDel(n->next[i]);

    delete(n);
}

void solve()
{
    int n;
    cin>>n;
    string word;
    while (n--){
        cin>>word;

        trieInsert(word);
    }
    
    int q;
    cin>>q;
    while (q--){
        cin>>word;

        if (trieSearch(word))
            cout<<"YES\n";
        else 
            cout<<"NO\n";
    }
}

int main()
{
    int t;
    cin>>t;

    while (t--){
        root = new node();
        solve();

        trieDel(root);
    }  
}