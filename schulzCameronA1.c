/************************schulzCameronA1.c**************
Student Name: Cameron Schulz        Email Id: cschul03
Due Date: 2022/10/07        Course Name: CIS 1300

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:

1) I have read and understood the University policy on academic integrity. 2) I
have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.
********************************************************/

/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall

compiling:
gcc -std=c99 -Wall schulzCameronA1.c

Running: ./a.out

OR

gcc -std=c99 -Wall schulzCameronA1.c -o a1
Running the Program: ./a1
*********************************************************/

#include <stdio.h>

int main()
{
    // Determine variable names
    int count, moss1, moss2, moss3;
    char student, surveyLab;

    float lab1, lab2, lab3, lab4, lab5;
    float assignment1, assignment2, assignment3;
    float quiz1, quiz2, quiz3, quiz4;
    float labExam, finalExam, finalExam1, finalExam2, examWeight;

    float labTotal, assignmentTotal, quizTotal, quizExam;

    float finalGrade;
    char letterGrade;


    // Intro
    printf("Welcome to ALT1300 admin page\n");



    // Loop repeats based on number of students user wants to calculate
    count = 1;
    student = 'y';
    while (student != 'n'){
        printf("For student # %d\n", count);



        // For Lab marks
        printf("Enter 5 lab marks, each separated by a space: ");
        scanf("%f%f%f%f%f", &lab1, &lab2, &lab3, &lab4, &lab5);

        // Adds all labs, divides by number of values, and multiplies by how much it is weighed - labTotal = weighted %
        labTotal = (lab1 + lab2 + lab3 + lab4 + lab5) / 5 * 0.2;

        printf("Overall lab grade (20): %.2f / 20.00\n\n", labTotal);



        // For Individual Assignments
        printf("Enter 3 assignments, each separated by a space: ");
        scanf("%f%f%f", &assignment1, &assignment2, &assignment3);

        // Gathers MOSS values for each assignment
        printf("Enter MOSS value for assignment 1: ");
        scanf("%d", &moss1);

        printf("Enter MOSS value for assignment 2: ");
        scanf("%d", &moss2);

        printf("Enter MOSS value for assignment 3: ");
        scanf("%d", &moss3);

        // Checks if student plagarised on 3 seperate occasions - gives automatic 0 and ends program if student did
        if (moss1 == 0 && moss2 == 0 && moss3 == 0){
            printf("Moss detected plagarism on 3 occasions\n");
            printf("Student #%d overall course grade: 0.00 / 100.00 \n", count);
            printf("Overall grade: F\n\n");
        }
        else {

            // Multiplies each value by how it is weighed and by the MOSS value, and adds them up - assignmentTotal = weighted %
            assignmentTotal = (assignment1*0.05*moss1 + assignment2*0.07*moss2 + assignment3*0.08*moss3);

            printf("Overall assignment grade (20): %.2f / 20.00\n\n", assignmentTotal);



            // For Quiz marks
            printf("Enter 4 quiz marks, each separated by a space: ");
            scanf("%f%f%f%f", &quiz1, &quiz2, &quiz3, &quiz4);

            // Adds all quizzes, divides by number of values, and multiplies by how much it is weighed - quizTotal = weighted %
            quizTotal = (quiz1 + quiz2 + quiz3 + quiz4) / 4 * 0.2;

            printf("Overall quiz grade (20): %.2f / 20.00\n\n", quizTotal);



            // For Lab exam
            printf("Enter the lab exam mark: ");
            scanf("%f", &labExam);

            // For student survey response - 'y' means students will transfer weight of the labExam to finalExam.
            do {

                  printf("Enter the survey response (y/n): ");
                  scanf(" %c", &surveyLab);

            } while (surveyLab != 'n' && surveyLab != 'y');

            // If 'y' is inputed, labExam will be weighed 0 and finalExam will be weighed 40.
            if (surveyLab == 'y') {
                  printf("Your lab exam is worth 0, and your final exam is worth 40\n\n");
                  labExam = 0;
                  examWeight = 40;
            }
            else {
                  printf("Your lab exam is worth 10, and your final exam is worth 30\n");
                  labExam = labExam * 0.1;
                  examWeight = 30;
                  printf("Overall lab exam mark (10): %.2f / 10.00\n\n", labExam);
            }



            // For final exam grade
            printf("Enter the final exam mark: ");
            scanf("%f", &finalExam);

            // Multiplies the final exam mark by how much it is weighted
            finalExam1 = finalExam * (examWeight / 100); // Real grade
            finalExam2 = finalExam * 0.3; // Used to show if totalQuiz + finalExam is >= 25 (further down)

            printf("Overall final exam grade (%.f): %.2f / %.f\n\n", examWeight, finalExam1, examWeight);


            // Calculates overall course grade (num)
            finalGrade = labTotal + assignmentTotal + quizTotal + labExam + finalExam1;

            // Determines letter grades
            if (finalGrade >= 80){
                  letterGrade = 'A';
            }
            else if (finalGrade >= 70){
                  letterGrade = 'B';
            }
            else if (finalGrade >= 60){
                  letterGrade = 'C';
            }
            else if (finalGrade >= 50){
                  letterGrade = 'D';
            }
            else {
                  letterGrade = 'F';
            }

            // Check if quizzes and exam >= 25
            quizExam = quizTotal + finalExam2;

            printf("Quizzes + Final Exam = %.2f + %.2f =  %.2f ", quizTotal, finalExam2, quizExam);
            if (quizExam >= 25){
                  printf("(>=25)\n\n");
            }
            else {
                  printf("(<25)\n\n");
                  letterGrade = 'F';
            }



            // Prints course marks and final grade
            printf("Overall course marks (%%)\n");
            printf("********************************\n");
            printf("Labs = %.2f\n", labTotal);
            printf("Assignments = %.2f\n", assignmentTotal);
            printf("Quizzes = %.2f\n", quizTotal);
            if (examWeight == 30){
                  printf("Lab Exam = %.2f\n", labExam);
            }

            printf("Final Exam = %.2f\n", finalExam1);
            printf("********************************\n\n");

            printf("Your overall course marks = %.2f%%\n", finalGrade);
            printf("Overall grade = %c\n\n", letterGrade);
        }


        // Asks user if they want to calculate grade of another student
        do {

            printf("Would you like to continue? (y/n): ");
            scanf(" %c", &student);
            printf("\n");

        } while (student != 'n' && student != 'y');

        count++;
    }
    printf("Goodbye\n\n");

    return 0;

}
