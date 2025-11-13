#include <stdio.h>
#include <string.h>   // For using string length and related functions

// --------------------------------------------------------------
// Function: getGrade
// Purpose : Determine grade based on percentage value
// Input   : float percentage
// Output  : grade character (A, B, C, D, F)
// --------------------------------------------------------------
char getGrade(float percentage) {
    if (percentage >= 80)
        return 'A';
    else if (percentage >= 70)
        return 'B';
    else if (percentage >= 60)
        return 'C';
    else if (percentage >= 50)
        return 'D';
    else
        return 'F';
}

// --------------------------------------------------------------
// Main Function
// --------------------------------------------------------------
int main() {

    // ********** Variable Declarations **********
    char name[50];       // Stores student full name
    int subjects , i;        // Number of subjects student has

    // ********** Input Section **********
    printf("Enter Student Name: ");
    scanf("%[^\n]", name);   // Allows spaces in name

    printf("Enter number of subjects: ");
    scanf("%d", &subjects);

    // Declaring arrays after getting subjects count
    char subName[subjects][20];  // Stores subject names
    float marks[subjects];       // Stores marks of each subject

    float maxMarks = 100;        // Maximum marks per subject
    float obtainedTotal = 0;     // Sum of all obtained marks

    // ********** Loop to Input Subject Names & Marks **********
    for (i = 0; i < subjects; i++) {

        printf("\nEnter name of subject %d: ", i + 1);
        scanf("%s", subName[i]);   // Only single word names allowed

        printf("Enter marks in %s (out of 100): ", subName[i]);
        scanf("%f", &marks[i]);

        // Validating Marks (no negative or >100 allowed)
        if (marks[i] < 0 || marks[i] > 100) {
            printf("Invalid Marks! Please enter again.\n");
            i--;    // Repeat this iteration
            continue;
        }

        obtainedTotal += marks[i];  // Add to total obtained marks
    }

    // ********** Displaying Student Result Header **********
    printf("\n\n================ STUDENT RESULT ================\n");
    printf("Student Name: '%s'\n", name);
    printf("-------------------------------------------------\n");
    printf("Subject\t\tMarks\tPercentage\tGrade\n");

    // ********** Loop to Display Individual Subject Records **********
    for (i = 0; i < subjects; i++) {

        float percent = (marks[i] / maxMarks) * 100;  // subject percentage
        char grade = getGrade(percent);               // grade for subject

        // Display each subject marks detail
        printf("%-10s\t%.2f\t%.2f%%\t\t%c\n", subName[i], marks[i], percent, grade);
    }

    // ********** Overall Result Calculation **********
    float totalPossibleMarks = subjects * maxMarks;              // Total marks possible
    float overallPercent = (obtainedTotal / totalPossibleMarks) * 100; // Overall Percentage
    char overallGrade = getGrade(overallPercent);           // Overall grade

    // ********** Display Final Summary **********
    printf("-------------------------------------------------\n");
    printf("Total Obtained Marks: %.2f\n", obtainedTotal);
    printf("Total Subject marks:%.2f\n",totalPossibleMarks);
    printf("Overall Percentage: %.2f%%\n", overallPercent);
    printf("Overall Grade: '%c'\n", overallGrade);
    printf("=================================================\n");

    // ********** End Program **********
    return 0;
}
