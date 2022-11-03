#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "status.h"
#include "my_string.h"
#include "generic_vector.h"
#include "associative_array.h"

void validate(char* guess, MY_STRING used_char_s);

int main(int argc, char* argv[]) {
    GENERIC_VECTOR Vector[30] = { NULL };
    MY_STRING hString = NULL;
    FILE* fp;
    MY_STRING key = my_string_init_default();
    MY_STRING used_char;
    MY_STRING used_char_s;
    MY_STRING word;                                                                                                                                                         MY_STRING MasterWord_ListKey;                                                                                                                                           GENERIC_VECTOR MasterWord_List;                                                                                                                                         MY_STRING Selected_Word;                                                                                                                                                MY_STRING current_word_family = my_string_init_default();
    hString = my_string_init_default();                                                                                                                                         
    
    int j = 0;
    for (j = 0; j < 30; j++) {
        Vector[j] = generic_vector_init_default(my_string_assignment, my_string_destroy);
    }

    fp = fopen("dictionary.txt", "r");

    if (fp == NULL) {
        fprintf(stdout, "Did not open\n");
        exit(1);
    }

    int size = 4;
    int index = 0;
    while (my_string_extraction(hString, fp)) {
        size = my_string_get_size(hString);
        index = size;

        if (index < 0) {
            break;
        }
        generic_vector_push_back(Vector[index], hString);
    }

    int i = 0;
    int length = 0;

    while (1) {
        length = 0;
        
        printf("What length word do you want to play with? ");
        scanf("%d", &length);

        while (generic_vector_get_size(Vector[length]) <= 0 || length <= 0 || length > 29) {
            printf("\nI'm sorry there is no word with that length, try again. ");
            printf("What length word do you want to play with?\n");
            while ((getchar()) != '\n')
                scanf("%d", &length);
        }

        int num_guesses = 0;
        printf("How many guesses do you want to have?\n");
        scanf("%d", &num_guesses);

        while (num_guesses <= 0) {
            printf("Theres no guesses that are less than or equal to zero, try again\n");
            printf("How many guesses do you want to have?\n");
            while ((getchar()) != '\n');
            scanf("%d", &num_guesses);
        }

        // conditional statement to access words of said length

        // Trick the user to make it harder
        // If they enter length 3 and letter t, the, tea, top would be family 
        // of 3 while hot is 1 so pick the word family with highest word_family

        MasterWord_List = Vector[length];

        //MY_STRING MasterWord_List = (MY_STRING)List;

        used_char = my_string_init_c_string("Used letters:");
        used_char_s = my_string_init_default();
        word = my_string_init_c_string("Word: ");
        MasterWord_ListKey = my_string_init_default();

        for (i = 0; i < length; i++) {
            my_string_push_back(MasterWord_ListKey, '-');
        }

        char guess;


        /*Partition  the words in the dictionary into groups by word family. The word family is the
        “key” in the AssociativeArray, and the words(already contained in MyStrings from having
        been read into the Vector of Vectors of MyStrings initially), are added to the Vector in the
        AssociativeArray which is associated with the given “key” word family.  // Associative Array - aka Avl Tree */


        Selected_Word = my_string_init_default();  
        my_string_destroy(&Selected_Word);

        for (i = 0; i < length; i++) {
            my_string_push_back(key, '-');
        }

        

        for (i = 0; i < my_string_get_size(MasterWord_List); i++) {
            my_string_push_back(current_word_family, '-');
        }

        srand(time(NULL));
        int rand_num = rand() % generic_vector_get_size(Vector[length]);
        Selected_Word = generic_vector_at(Vector[length], rand_num);
        
        
        int count = 0;
        char* actual;
        while (num_guesses > 0) {
            for (i = 0; i < my_string_get_size(MasterWord_List); i++) {
                actual = my_string_at(MasterWord_List, i);
                char* answer = my_string_at(MasterWord_ListKey, i);
                //actual = tolower(actual);
                if (actual == answer) {
                    count++;
                    continue;
                }
                else {
                    count = 0;
                }
            }

            if (count == my_string_get_size(MasterWord_List)) {
                break;
            }
            else {
                count = 0;
            }

            printf("\nYou have %d guesses left.\n", num_guesses);
            my_string_insertion(used_char, stdout);
            my_string_insertion(used_char_s, stdout);
            printf("\n");

            my_string_insertion(word, stdout);
            my_string_insertion(MasterWord_ListKey, stdout);
            printf("\n");
            printf("Enter guess: ");

            scanf(" %c", &guess);

            while (isalpha(guess) == 0) {
                printf("It is not an alphabetical character ");
                printf("Enter guess: ");
                while ((getchar()) != '\n')
                    scanf(" %c", &guess);
            }

            validate(&guess, used_char_s);
            
            // handle for original masterword list // copy vector of said length // So if user wants to play again // Update word list

            for (i = 0; i < generic_vector_get_size(Vector[length]); i++) {
                MY_STRING string = (MY_STRING)generic_vector_at(Vector[length], i);
                avl_insert(MasterWord_List, MasterWord_ListKey, string); // Fix avl
            }


            if (get_word_key_value(current_word_family, MasterWord_ListKey, Selected_Word, guess) == SUCCESS) {
                my_string_push_back(used_char_s, ' ');
                my_string_push_back(used_char_s, guess);
                continue;
            } else {
                my_string_push_back(used_char_s, ' ');
                my_string_push_back(used_char_s, guess);
                num_guesses--;
            }

        }
        
        if (num_guesses == 0) {
            printf("\nYou lose! The word was: ");
            my_string_insertion(Selected_Word, stdout);        
        } else {
            printf("\nCongratualations! The word was: ");
            my_string_insertion(Selected_Word, stdout);
        }

        char answer;
        printf("\nPlay Again? Say 'Y' for Yes or 'N' for No: ");
        scanf(" %c", &answer);

        if (answer == 'Y' || answer == 'y') {
            my_string_destroy(&key);                                                                                                                                               my_string_destroy(&used_char);                                                                                                                                          my_string_destroy(&word);                                                                                                                                               my_string_destroy(&MasterWord_ListKey); 
            my_string_destroy(&used_char_s);

            key = my_string_init_default();
            continue;
	    } else {
            my_string_destroy(&key);
            my_string_destroy(&used_char);
            my_string_destroy(&used_char_s);
            my_string_destroy(&word);
            my_string_destroy(&MasterWord_ListKey);  
            my_string_destroy(&current_word_family);   
            for(i = 0; i < 30; i++){
                my_string_destroy(&hString); 
                break;
        }
    } 

    fclose(fp);
    return 0;
    }

    return 0;
}

void validate(char* guess, MY_STRING used_char_s) {
    int i = 0;
    for (i = 0; i < my_string_get_size(used_char_s); i++) {
        char tmp = *my_string_at(used_char_s, i);
        if (*guess == tmp) {
            while (*guess == tmp) {
                printf("You already used that character! Try Again\n");
                printf("Enter guess: ");
                scanf(" %c", guess);
                validate(guess, used_char_s);
            }
        }
    }
}