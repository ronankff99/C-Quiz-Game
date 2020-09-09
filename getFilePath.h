//Author: Ronan O'Keeffe - R00161931
//This function takes the filepath for the quiz file from the user and returns it to the main program
char getFilePath(){
    char filepath[30];
    printf("What is the name of the file you are drawing questions from? (E.G: quiz.txt)\n");
    scanf("%s", filepath);
    return filepath;
}
