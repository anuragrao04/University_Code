#include <stdio.h>

int main() {
    char name[50], srn[20];
    int marks[5], sum = 0;
    float average;

    printf("Enter student name: ");
    scanf("%s", name);

    printf("Enter student SRN: ");
    scanf("%s", srn);

    printf("Enter marks for 5 subjects:\n");

    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i+1);
        scanf("%d", &marks[i]);
        sum += marks[i];
    }

    average = sum / 5.0;

    printf("\n");

    printf("|    Name    |      SRN      |  Subject 1  |  Subject 2  |  Subject 3  |  Subject 4  |  Subject 5  |  Total  | Average |  Grade  |\n");

    printf("| %-10s | %-13s |     %-3d     |     %-3d     |     %-3d     |     %-3d     |     %-3d     |  %-5d  | %-7.2f |", name, srn, marks[0], marks[1], marks[2], marks[3], marks[4], sum, average);

    if (average >= 90) {
        printf("    S    |\n");
    } else if (average >= 80) {
        printf("    A    |\n");
    } else if (average >= 70) {
        printf("    B    |\n");
    } else if (average >= 60) {
        printf("    C    |\n");
    } else {
        printf("    F    |\n");
    }


    return 0;
}
