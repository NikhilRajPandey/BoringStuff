// Reference Link For Hangman Game https://en.wikipedia.org/wiki/Hangman_(game)
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <string>

#define number_of_lines 1314// Number of lines/words in wordlist
#define file_location "wordlist.txt"
#define exit_char '!'
// I have kept the excutable in temp so the wordlist file is also there

void conv_to_lower(char *param_string,int size_){
    for (int i = 0; i < size_; i++){param_string[i] = tolower(param_string[i]);}
}

void fill(char *param_string,int size_,char word){
    for (int i = 0; i < size_; i++){param_string[i] = word;}
    param_string[size_] = '\0';
}

int main(){
    // setting a random seed for generating a random word
    srand (time(NULL));
    int word_index = rand() % number_of_lines-1;
    int word_size;
    char word_[16];

    // Opening the word-list files
    std::ifstream word_list;
    word_list.open(file_location);

    int curr_word_index = 0; /* Getting the word from file */
    while (curr_word_index <= word_index){
        word_list>>word_;
        curr_word_index++;
    }

    /* Declaring all the variables */
    word_size = strlen(word_);
    conv_to_lower(word_,word_size);

    char matched_words[word_size]; // Words that are matched by input
    fill(matched_words,word_size,'_');

    std::string missed_words;
    char input_letter;
    bool is_word_missed = true;
    int input_number = 0;

    system("clear");
    std::cout<<"Write "<<exit_char<<"For Exit\n"<<std::endl;

    while (input_number < word_size){
        // Printing this type of structure ___a__n__
        std::cout<<"Word: "<<matched_words<<"\n";

        // Taking input from the user
        std::cout<<"Guess: ";
        std::cin>>input_letter;
        conv_to_lower(&input_letter,1);

        // Now Checking exit condition
        if(input_letter == exit_char){
            std::cout<<"\nGame Over"<<std::endl;
            break;
        }
        
        // checking the is Word Entered is in the word or not and if yes then replacing it
        for (int i = 0; i < word_size; i++){
            if(word_[i] == input_letter and matched_words[i] == '_'){matched_words[i] = input_letter;is_word_missed=false;}
        }
        // Adding the word in missed if they are and input_number is the no of times this loop is runned
        if(is_word_missed){missed_words.push_back(input_letter);}
        else{input_number--;}

        // Now printing Misses
        std::cout<<"Misses: ";
        for (int i = 0; i < missed_words.size(); i++){std::cout<<missed_words[i]<<" ";}
        
        if(strcmp(matched_words,word_) == 0){break;} // Means Player is won

        std::cout<<"\n\n";
        input_number++;
        is_word_missed = true;
    }
    std::cout<<"\nThe word is "<<word_<<std::endl;
    if(strcmp(matched_words,word_) == 0){
        std::cout<<"\nYou Win"<<std::endl;
    }
    else{
        std::cout<<"\nYou Loose"<<std::endl;
    }
    word_list.close();
    return 0;
}