/*
    Author: Ronan O'Keeffe
    SNo: R00161931
    Class: SDH2-B
    Lecturer: Victor Cionca
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //This is for checking if the file exists
#include "getClue.h"
#include "getDifficulty.h"
#include "checkAnswer.h"
#include "saveQuiz.h"
//List object
struct list {
    char *question;
    char *answer;
    struct list *next;
};

//Alias for datatype LIST
typedef struct list LIST;


int main(void) {
    //Check if file exists, if not, end the program and let the user fix it
    char filepath[30];

    printf("What is the name of the file you are drawing questions from?\n");
    scanf("%s", filepath);

    if(access(filepath, F_OK) == -1){
        printf("File does not exist, please check your installation directory\n");
        exit(1);
    }

    //Build the list if the file exists
    FILE *file;
    char line[128];
    LIST *current, *head;
    int noOfQuestions = 0;
    head = current = NULL;
    file = fopen(filepath, "r");

    char myGuess[30];
    int score = 0;
    int counter = 1;

    while(fgets(line, sizeof(line), file)){
        LIST *a = malloc(sizeof(LIST));

        if (!malloc){
            prinf("MALLOC ERROR! AGHHH!");
            exit(1);
        }

        //This separates the question and the answer from a line of text using strtok
        a->question = strdup(line);
        a->question = strtok(a->question, "?");
        a->answer = strtok(NULL, " \n");

        a->next = NULL;
        if(head == NULL){
            current = head = a;
        } else {
            current = current->next = a;
        }
        noOfQuestions++;
    }
    fclose(file);

    //Game starts here
    printf("Welcome to the CIT AutoQuiz - There are %d questions in this quiz\n", noOfQuestions);
    //Get the difficulty
    int level = getDifficulty();


    //For each node, ask it's question, check its answer and then move on
    for(current = head; current; current = current->next){
        printf("\nQ%d of %d: %s\n", counter, noOfQuestions, current->question);
        getClue(level, current->answer);
        scanf("%s", myGuess);
        score = checkAnswer(myGuess, current->answer, score);
        counter++;
    }

    //Save game details
    printf("\n\nThank you for participating, your score was %d/%d\n", score, noOfQuestions);
    saveQuiz(filepath, score, noOfQuestions, level);
    printf("Saved details to quiz_history.txt\n");
    return 0;
}
