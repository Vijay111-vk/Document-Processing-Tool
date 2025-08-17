// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Dict {
private:
    // You can add attributes/helper functions here
    struct wrd
    {
        string wrdname;
        int count=0;
        /* data */
    };
    vector<vector<wrd>> hashtbl;

    int hashfn(string str){   
        int hash=0;
        for(char c : str){
            hash = (hash*5)+c;
            hash=hash%1000000; 
        }
        return hash;
    }

    bool doesExist(string id) {
        // IMPLEMENT YOUR CODE HERE
        int h=hashfn(id);
        if(hashtbl[h].size()!=0){
        for(int i=0; i<hashtbl[h].size(); i++){
            if(id==hashtbl[h][i].wrdname){
                return true;
            }
        }
        }
        return false; // Placeholder return value
    }
public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};