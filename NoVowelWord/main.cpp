#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#define file_location "wordlist.txt"
// The wordlist in temp but that is not complete wordlist

bool is_vowel_in_it(std::string param_word){
    // Give true when it founds no vowel else false

    if(param_word == ""){return false;}

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
    std::cout<<word_without_vowel()<<std::endl;
}