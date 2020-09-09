//Author: Ronan O'Keeffe - R00161931
//This function gets the difficulty level as an input from the user and returns it for use in the main program
int getDifficulty(){
    int level;
    printf("\nPlease enter your desired difficulty level:\n1 - No hint"
           "\n2 - Number of letters\n3 - Random two letters"
           "\n4 - First and last letters\n5 - Random order of letters"
           "\n6 - Random difficulty\n");
    scanf("%d", &level);
    return level;
}
