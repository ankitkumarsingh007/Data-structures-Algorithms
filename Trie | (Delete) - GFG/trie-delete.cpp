// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream> 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define MAX 10^19
// Alphabet size (# of symbols)
 
#define ALPHABET_SIZE (26)
#define INDEX(c) ((int)c - (int)'a')
 
#define FREE(p) \
    free(p);    \
    p = NULL;
using namespace std;
 
// forward declration
typedef struct trie_node trie_node_t;
 
// trie node
struct trie_node
{
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
};
 
// trie ADT
typedef struct trie trie_t;
 
struct trie
{
    trie_node_t *root;
    int count;
};
void deleteKey(trie_node_t *root, char key[]);
trie_node_t *getNode(void)
{
    trie_node_t *pNode = NULL;
 
    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));
 
    if( pNode )
    {
        int i;
 
        pNode->value   = 0;
 
        for(i = 0; i < ALPHABET_SIZE; i++)
        {
            pNode->children[i] = NULL;
        }
    }
 
    return pNode;
}
 
void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}
 
void insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pTrie->count++;
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);
 
        if( pCrawl->children[index] )
        {
            // Skip current node
            pCrawl = pCrawl->children[index];
        }
        else
        {
            // Add new node
            pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
        }
    }
 
    // mark last node as leaf (non zero)
    pCrawl->value = pTrie->count;
}
 
int ifExsist(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pCrawl = pTrie->root;
    if( !pCrawl)
        {
            return 0;
        }
    for( level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);
 
        if( !pCrawl->children[index] )
        {
            return 0;
        }
 
        pCrawl = pCrawl->children[index];
    }
 
    if(pCrawl && pCrawl->value)
        return 1;
    else
        return 0;
}
int compare_strings(char a[], char b[]){
    if(strlen(a)!=strlen(b))
        return 1;
    for(int i=0;i<strlen(a);i++){
        if(a[i]!=b[i])
            return 1;
    }
    return 0;
}

 // } Driver Code Ends
/*Complete the function below
Node is as follows:
struct trie_node
{
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
};*/
class Solution{
  public:
    bool isempty(trie_node_t* root){
       for(int i=0;i<26;i++){
           if(root->children[i]!=NULL) return false;
       }
       return true;
    }
    trie_node_t* delkey(trie_node_t *root,char key[],int level){
       int n=strlen(key);
       if(root==NULL) return NULL;
       if(level==n){
           root->value=0;
           if(isempty(root)){
               delete(root);
               root=NULL;
           }
           return root;
       }
       int index=key[level]-'a';
       root->children[index]=delkey(root->children[index],key,level+1);
       if(isempty(root) && root->value==0){
           delete(root);
           root=NULL;
       }
       return root;
    } 
    void deleteKey(trie_node_t *root, char key[]){
       delkey(root,key,0);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char keys[MAX][MAX];
        for(int i=0;i<n;i++){
            fflush(stdin);
            cin>>keys[i];
        }
        trie_t trie;
        initialize(&trie);
        for(int i = 0; i < n; i++){
            insert(&trie, keys[i]);
        }
        char abc[MAX];
        fflush(stdin);
        cin>>abc;
        Solution obj;
        obj.deleteKey(trie.root, abc);
        if(ifExsist(&trie, abc)==false){
            int f1=0;
            for(int i=0;i<n;i++){
                if(compare_strings(keys[i],abc)){
                    if(ifExsist(&trie,keys[i])==false){
                        f1=1;
                        break;
                    }
                }
            }
            if(f1){
                cout<<"0";
            }
            else{
                cout<<"1";
            }
        }
        else
            cout<<"0";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends