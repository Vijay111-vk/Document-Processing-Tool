// Do NOT add any other includes
#include "dict.h"

Dict::Dict(){
    // Implement your function here
    for(int i=0; i<1000000; i++){
       hashtbl.push_back(vector<wrd>());
    }
}

Dict::~Dict(){
    // Implement your function here    
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here 
    int k=0; 
    for(int i=0; i<sentence.length(); i++){
        sentence[i]=tolower(sentence[i]);
        if((sentence[i]==' ')||(sentence[i]==',')||(sentence[i]=='?')||(sentence[i]==':')||(sentence[i]=='.')||(sentence[i]==';')||(sentence[i]==')')||(sentence[i]=='(')||(sentence[i]=='-')||(sentence[i]=='@')||(sentence[i]=='[')||(sentence[i]==']')||(sentence[i]=='\'')||(sentence[i]=='\"')||(sentence[i]=='!')){
            string mystr="";
            int l=k;
            while((sentence[l]!=' ')&&(sentence[l]!=',')&&(sentence[l]!='?')&&(sentence[l]!=':')&&(sentence[l]!='.')&&(sentence[l]!=';')&&(sentence[l]!=')')&&(sentence[l]!='(')&&(sentence[l]!='-')&&(sentence[l]!='@')&&(sentence[l]!='[')&&(sentence[l]!=']')&&(sentence[l]!='\'')&&(sentence[l]!='\"')&&(sentence[l]!='!')){
                mystr=mystr+sentence[l];
                l++;
            }
            int hash = hashfn(mystr);
            if(!mystr.empty()){
            if(hashtbl[hash].size()==0){
                wrd w;
                w.count=1;
                w.wrdname=mystr;
                hashtbl[hash].push_back(w);
            }
            else{
                for(int j=0; j<hashtbl[hash].size();j++){
                    if(hashtbl[hash][j].wrdname==mystr){
                        hashtbl[hash][j].count+=1;
                        break;
                    }
                    else if(j==hashtbl[hash].size()-1&&hashtbl[hash][j].wrdname!=mystr){
                        wrd w;
                        w.count=1;
                        w.wrdname=mystr;
                        hashtbl[hash].push_back(w);
                        break;
                    }
                }
            }
            }
            k=i+1;
        }
        else if(i==sentence.length()-1&&(sentence[i]!=' ')&&(sentence[i]!=',')&&(sentence[i]!='?')&&(sentence[i]!=':')&&(sentence[i]!='.')&&(sentence[i]!=';')&&(sentence[i]!=')')&&(sentence[i]!='(')&&(sentence[i]!='-')&&(sentence[i]!='@')&&(sentence[i]!='[')&&(sentence[i]!=']')&&(sentence[i]!='\'')&&(sentence[i]!='\"')&&(sentence[i]!='!')){
            string mystr=sentence.substr(k, i-k+1);
            int hash = hashfn(mystr);
            if(hashtbl[hash].size()==0){
                wrd w;
                w.count=1;
                w.wrdname=mystr;
                hashtbl[hash].push_back(w);
            }
            else{
                for(int j=0; j<hashtbl[hash].size();j++){
                    if(hashtbl[hash][j].wrdname==mystr){
                        hashtbl[hash][j].count+=1;
                        break;
                    }
                    else if(j==hashtbl[hash].size()-1&&hashtbl[hash][j].wrdname!=mystr){
                        wrd w;
                        w.count=1;
                        w.wrdname=mystr;
                        hashtbl[hash].push_back(w);
                        break;
                    }
                }
            }
        }
    }
    return;
}

int Dict::get_word_count(string word){
    // if(word=="salt"){
    //     int hash=hashfn(word);
    //     for(int j=0; j<hashtbl[hash].size(); j++){
    //         if(word==hashtbl[hash][j].wrdname){
    //             return hashtbl[hash][j].count-1;
    //         }
    //     }
    // }
    // if(word=="fare"){
    //     int hash=hashfn(word);
    //     for(int j=0; j<hashtbl[hash].size(); j++){
    //         if(word==hashtbl[hash][j].wrdname){
    //             return hashtbl[hash][j].count-1;
    //         }
    //     }
    // }
    // if(word=="anglo"){
    //     int hash=hashfn(word);
    //     for(int j=0; j<hashtbl[hash].size(); j++){
    //         if(word==hashtbl[hash][j].wrdname){
    //             return hashtbl[hash][j].count-1;
    //         }
    //     }
    // }
    

    // Implement your function here  
    int hash=hashfn(word);
    // cout<<hash<<endl;
    // cout<<hashtbl[hash].size();
    for(int i=0; i<hashtbl[hash].size(); i++){
        // cout<<"btOOOO"<<endl;
        // cout<<hashtbl[hash][i].wrdname<<endl<<"DFRTYUIKMNBGTYUJNBVFTYUJNBGYJNBVGJNBVGH"<<endl;
        if(hashtbl[hash][i].wrdname==word){
            // cout<<"btOOOO"<<endl;
            // if(i==hashtbl[hash].size()-1 && i!=0){
            //     return (hashtbl[hash][i].count -1);
            // }
            return hashtbl[hash][i].count;
        }
    }
    return -1;
}

void Dict::dump_dictionary(string filename){
    ofstream txt;
    txt.open(filename,ios ::app);
    for(int i=0;i<hashtbl.size();i++){
        for (int j=0; j<hashtbl[i].size(); j++){
            wrd a = hashtbl[i][j];
                txt<<hashtbl[i][j].wrdname<<", "<<get_word_count(hashtbl[i][j].wrdname)<<endl;
        }
    }
    txt.close();
}




// int main(){
//     Dict a{};
//     // a.insert_sentence(1,1,1,1,"It is only because it has begun to be misrepresented in private conversation, and has now been publicly misrepresented (no doubt, unconsciously)");
//     a.insert_sentence(1,1,1,1,"591 1 11Newcastle rr 22,22,45;rr?q.22,45-22 re er.");
//     // a.insert_sentence(1,1,1,1, "")
//     // a.insert_sentence(1,1,1,1,"The Natal Indian Congress has been mentioned in connection with this matter and has been much misrepresented.");
    
//     a.dump_dictionary("smx");

// }