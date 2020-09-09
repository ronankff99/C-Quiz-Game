//Author: Ronan O'Keeffe - R00161931
//This function saves the quiz to a file
void saveQuiz(filepath, score, noOfQuestions, level){
    FILE* file = fopen("quiz_history.txt", "w+");
    fprintf(file, "File used: %s\n", filepath);
    fprintf(file, "Questions answered correctly: %d\n", score);
    fprintf(file, "Total number of questions: %d\n", noOfQuestions);
    fprintf(file, "Difficulty level: %d", level);
    fclose(file);
}
