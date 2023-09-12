#include <bits/stdc++.h>
using namespace std;

struct node {
    node *next[26];
    int cntWord, cntPref;

    node (){
        cntWord = 0, cntPref = 0;
        for (int i = 0; i < 26; i++){
            next[i] = NULL;
        }
    }
}* root;

void trieInsert(string &s)
{
    node *cur = root;
    int n = s.size(), x;
    for (int i = 0; i < n; i++){
        x = s[i]-'a';

        if (cur->next[x] == NULL){
            cur->next[x] = new node ();
        }

        cur = cur->next[x];
        cur->cntPref++;
    }

    cur->cntWord++;
}

int cntWordsEqualTo(string &s)  //Word count
{
    node *cur = root;
    int n = s.size(), x;
    for (int i = 0; i < n; i++){
        x = s[i]-'a';

        if (cur->next[x] == NULL){
            return 0;
        }

        cur = cur->next[x];
    }

    return cur->cntWord;
}

int cntWordsStartingWith(string &s) //Prefix count
{
    node *cur = root;
    int n = s.size(), x;
    for (int i = 0; i < n; i++){
        x = s[i]-'a';

        if (cur->next[x] == NULL){
            return 0;
        }

        cur = cur->next[x];
    }

    return cur->cntPref;
}

void wordDel(string &s)
{
    node *cur = root;
    int n = s.size(), x;
    for (int i = 0; i < n; i++){
        x = s[i]-'a';

        if (cur->next[x] == NULL){
            return;
        }

        cur = cur->next[x];
        cur->cntPref--;
    }

    cur->cntWord--;
}

void trieDel(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            trieDel(cur->next[i]);

    delete(cur);
}

void solve()
{
    int q, operation;
    cin>>q;
    string word;
    while (q--){
        cin>>operation>>word;

        if (operation == 1)
            trieInsert(word);
        else if (operation == 2)
            cout<<cntWordsStartingWith(word)<<"\n";
        else if (operation == 3)
            cout<<cntWordsEqualTo(word)<<"\n";
        else {    //operation == 4
            wordDel(word);
        }
    }
}

int main()
{
    int tc;
    cin>>tc;

    while (tc--){
        root = new node();
        solve();
        trieDel(root);
    }  

    return 0;
}