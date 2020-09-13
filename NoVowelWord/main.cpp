#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#define file_location "wordlist.txt"
// The wordlist in temp but that is not complete wordlist

bool is_vowel_in_it(std::string param_word){
    // Give true when it founds no vowel else false

    if(param_word.length() <= 2){return false;}

    char vowels[6] = "aeiou";
    for (int i = 0; i < param_word.length(); i++){
        for (int j = 0; j < 6; j++){ // Running loop 6 because len(vowels) = 6
            if(vowels[j] == tolower(param_word[i])){return false;} // If matched then false
        }
    }
    return true; // OtherWise true
    
}

std::vector<std::string> word_without_vowel(){
    std::vector<std::string> result; // Result will contain all the words that have no vowels
    std::string current_word;

    std::ifstream file_; // Opening the file
    file_.open(file_location);

    while (!file_.eof()){
        if(is_vowel_in_it(current_word)){result.push_back(current_word);}
        file_>>current_word;
    }
    return result;

}
int main(){
    std::vector<std::string> all_words = word_without_vowel();
    // std::vector<std::string> all_words = *(word_without_vowel());
    // std::cout<<*(all_words.at(0))<<std::endl;
    std::string biggest_word = all_words.at(0);
    for(int i = 0;i<all_words.size();i++){
        std::cout<<all_words.at(i)<<std::endl;

        // Finding the maximum letter word from the result
        if(all_words.at(i).size() > biggest_word.size()){biggest_word = all_words.at(i);}
    }
    std::cout<<"The Biggest Word Founded is "<<biggest_word<<std::endl;
}