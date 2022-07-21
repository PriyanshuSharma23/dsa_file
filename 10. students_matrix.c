#include <stdio.h>

int main()
{
    // 5 subjects per student and total 10 students
    int students[10][5];

    // initialize the array
    // making every mark as zero by default and then we will ask user
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            students[i][j] = 0;
        }
    }

    printf("Welcome to marks manager!\n");
    printf("Index starts from 1\n");

    while (1)
    {
        printf("Please enter the student number: ");
        int student_number;
        scanf("%d", &student_number);

        // print the column for that student
        printf("Current marks of the students are: \n");
        for (int i = 0; i < 5; i++)
        {
            printf("%d ", students[student_number - 1][i]);
        }
        printf("\n");

        int choice;
        printf("\t1) Enter a new mark\n");
        printf("\t2) Go back\n");
        scanf("%d", &choice);

        // printf("Enter the subject number to update: ")
        switch (choice)
        {
        case 1:
            printf("Enter the subject number to update: ");
            int subject_number;
            scanf("%d", &subject_number);
            printf("Enter the new mark: ");
            int new_mark;
            scanf("%d", &new_mark);

            students[student_number - 1][subject_number - 1] = new_mark;
            break;
        
        default:
            continue;
            break;
        }


    }

    return 0;
}