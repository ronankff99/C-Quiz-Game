//Author: Ronan O'Keeffe - R00161931
//This function takes the level and answer as a parameter and adjusts them based on difficulty level
void getClue(int level, char* answer){
    char *clue[50];
    char mixedAnswer[30];
    char temp;
    int i, pos1, pos2, random, randLevel;

    switch(level){
        case 1:
            //????
            printf("Clue: ?\n");
            break;
        case 2:
            //Number of letters
            printf("Clue: ");
            for (i = 0; i < strlen(answer); i++){
                printf("%c", '-');
            }
            printf("\n");
            break;
        case 3:
            //Random two letters
            pos1 = rand() % (strlen(answer));
            pos2 = rand() % (strlen(answer));
            for (i = 0; i < strlen(answer); i++){
                if(i == pos1 || i == pos2){
                    printf("%c", answer[i]);
                }
                else{
                    printf("-");
                }
            }
            printf("\n");
            break;
        case 4:
            //First and last letters
            if (strlen(answer) < 3){
                printf("Clue: ");
                for (i = 0; i < strlen(answer); i++){
                    printf("%c", '-');
                }
                printf("\n");
            break;
            }
            for (i = 0; i < strlen(answer); i++){
                if(i == 0 || i == strlen(answer) - 1){
                    printf("%c", answer[i]);
                }
                else{
                    printf("-");
                }
            }
            printf("\n");
            break;
        case 5:
            //Random order
            strcpy(mixedAnswer, answer);

            for (i = strlen(mixedAnswer) - 1; i > 0; i--){
                random = rand()%(i+1);
                temp = mixedAnswer[random];
                mixedAnswer[random] = mixedAnswer[i];
                mixedAnswer[i] = temp;
            }
            printf("Clue: %s\n", mixedAnswer);
            break;
        case 6:
            //Random selection of the above
            randLevel = rand() % (strlen(answer));
            getClue(randLevel, answer);
            break;
    }
}
