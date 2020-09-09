//Author: Ronan O'Keeffe - R00161931
//This function checks to see if the user's answer is correct. It will update their score if they correctly answer the question
int checkAnswer(char* myGuess, char* answer, int score){

    if(strcmp(strlwr(myGuess), strlwr(answer)) == 0){
        printf("Correct!\n");
        score++;
        printf("Your score is now %d\n", score);
        }
    else{
        printf("Incorrect!\n");
        printf("Answer was \"%s\" but you said \"%s\"\n", answer, myGuess);
    }
    return score;
}
