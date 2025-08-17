#include "search.h"

SearchEngine::SearchEngine() {

    // Initialize your data structures here
    // For example, create the root node of the trie
    // You can add any additional data structures if needed

}

SearchEngine::~SearchEngine() {
    // Implement destructor, free up any memory used
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence) {
    // Pre-process the sentence (if needed)
    // You can perform any required preprocessing here, e.g., removing punctuation and converting to lowercase
    // Then, insert the pre-processed sentence into the trie data structure
    for(int i=0; i<sentence.size(); i++){
        sentence[i]=tolower(sentence[i]);
    }
    strct s(book_code, page, paragraph, sentence_no, sentence);
    gv.push_back(s);

}

Node* SearchEngine::search(string pattern, int& n_matches) {
    // Pre-process the pattern (if needed)
    // You can perform any required preprocessing here, e.g., removing punctuation and converting to lowercase
    Node* root;
    Node* r=root;
    for(int i=0; i<pattern.size(); i++){
        pattern[i]=tolower(pattern[i]);
    }
    for(int i=0; i<gv.size(); i++){
        string str;
        int offset;
        str=gv[i].sentence;
        int n=str.size();
        int p=pattern.size();
        // bool superflag = false;
        // for(int j=0; j<n-p+1; j++){
        //     bool flag=true;
        //     for(int k=j; k<p+j; k++){
        //         if(str[k]!=pattern[k-j]){
        //             flag=false;
        //             break;
        //         }
        //     }
        //     if(flag) {
        //     offset = j;
        //     superflag=true;
        //     break;
        //     }

        // }
        offset=kmp(str, pattern);
        if(offset!=-1){
            Node* n;
            n=new Node(gv[i].book_code, gv[i].page, gv[i].paragraph, gv[i].sentence_no, offset);
            root->right=n;
            n->left=root;
            root=n;
            n_matches++;
        }
    }
    return r->right;
}
