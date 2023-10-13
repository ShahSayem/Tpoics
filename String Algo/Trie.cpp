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
    node *curr = root;
    int n = s.size(), x;
    for (int i = 0; i < n; i++){
        x = s[i]-'a';

        if (curr->next[x] == NULL){
            curr->next[x] = new node ();
        }

        curr = curr->next[x];
        curr->cntPref++;
    }

    curr->cntWord++;
}

int cntWordsEqualTo(string &s)  //Word count
{
    node *curr = root;
    int n = s.size(), x;
    for (int i = 0; i < n; i++){
        x = s[i]-'a';

        if (curr->next[x] == NULL){
            return 0;
        }

        curr = curr->next[x];
    }

    return curr->cntWord;
}

int cntWordsStartingWith(string &s) //Prefix count
{
    node *curr = root;
    int n = s.size(), x;
    for (int i = 0; i < n; i++){
        x = s[i]-'a';

        if (curr->next[x] == NULL){
            return 0;
        }

        curr = curr->next[x];
    }

    return curr->cntPref;
}

void wordDel(string &s)
{
    node *curr = root;
    int n = s.size(), x;
    for (int i = 0; i < n; i++){
        x = s[i]-'a';

        if (curr->next[x] == NULL){
            return;
        }

        curr = curr->next[x];
        curr->cntPref--;
    }

    curr->cntWord--;
}

void trieDel(node* curr)
{
    for (int i = 0; i < 26; i++)
        if (curr->next[i])
            trieDel(curr->next[i]);

    delete(curr);
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