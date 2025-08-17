// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

class SearchEngine {
private:
    // You can add attributes/helper functions here
    struct  strct
    {
        int book_code;
        int page;
        int paragraph;
        int sentence_no;
        string sentence;
        public:
        strct(int book_code, int page, int paragraph, int sentence_no, string sentence){
            this->book_code=book_code;
            this->page=page;
            this->paragraph=paragraph;
            this->sentence=sentence;
            this->sentence_no=sentence_no;
        }
    };
    vector<strct> gv;
    void pitable(string &pat, vector<int> &lps){
        int i=1;
        int l=0; 
        lps[0]=0; 
        while (i<pat.length()) {
            if (pat[i]==pat[l]) {
                l++;
                lps[i]=l;
                i++;
            } 
            else {
                if (l!=0) {
                    l=lps[l-1];
                } 
                else {
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    int kmp(string &txt, string &pat){
        int n=txt.length();
        int m=pat.length();
        vector<int> lps(m);
        pitable(pat,lps);
        int i=0,j=0; 
        while (i<n) {
            if (pat[j]==txt[i]) {
                i++;
                j++;
            }
            if (j==m) {
                return i-j; 
            } 
            else if (i<n&&pat[j]!=txt[i]) {
                if (j==0){
                    i=i+1;
                }
                else{
                    j=lps[j-1];
                }
            }
        }
        return -1; 
}
public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node* search(string pattern, int& n_matches);

    /* -----------------------------------------*/
};