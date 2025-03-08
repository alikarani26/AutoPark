#include <stdlib.h>
#include <stdio.h>
typedef struct {
    char name[11];
    int sex;
    char carSign[7];
    int enteringHour;
    int enteringMinute;
} customer;

int main(void) {
    customer liste;
    starting(&liste);
    exiting(&liste);
    return 0;
}

void starting(customer *liste) {
    printf("Welcome to the Auto Park\n\n");
    printf("Enter Your Name: ");
    scanf("%s", liste->name);
    printf("Enter Your Sex [1 for Male, 2 for Female]: ");
    scanf("%d", &liste->sex);
    printf("Enter Your Car Sign: ");
    scanf("%s", liste->carSign);
    printf("Enter Your Entering Hour [HH]: ");
    scanf("%d", &liste->enteringHour);
    printf("Enter Your Entering Minutes [MM]: ");
    scanf("%d", &liste->enteringMinute);

    FILE *fp = fopen("customer.txt", "w");
    if (fp == NULL) {
        printf("\nFile Cannot Open!");
        return;
    }
    fprintf(fp, "%s\n%d\n%s\n%d\n%d",liste->name, liste->sex, liste->carSign, liste->enteringHour, liste->enteringMinute);
    fclose(fp);
}
void exiting(customer *liste) {
    FILE *fp = fopen("customer.txt", "r");
    if (fp == NULL) {
        printf("\nFile Cannot Open!");
        return;
    }
    fscanf(fp, "%s %d %s %d %d", liste->name, &liste->sex, liste->carSign, &liste->enteringHour, &liste->enteringMinute);
    fclose(fp);
    int exitingHour, exitingMinute;
    if (liste->sex == 1) {
        printf("Welcome Mr. %s\n\n", liste->name);
    } else if (liste->sex == 2) {
        printf("Welcome Mrs. %s\n\n", liste->name);
    }
    printf("Enter Your Exiting Hour [HH]: ");
    scanf("%d", &exitingHour);
    printf("Enter Your Exiting Minute [MM]: ");
    scanf("%d", &exitingMinute);
    printf("\nYour Exiting Time: %d:%d", exitingHour, exitingMinute);
    int totalMinuteEnter = (liste->enteringHour * 60) + liste->enteringMinute;
    int totalMinuteExit = (exitingHour * 60) + exitingMinute;
    int total;
    if (totalMinuteExit > totalMinuteEnter) {
        total = totalMinuteExit - totalMinuteEnter;
    } else {
        total = (totalMinuteExit + 1440) - totalMinuteEnter;
    }
    printf("\nYour Total Time: %d Minutes!", total);
    int cost;
    if (total < 30) {
        cost = 0;
    } else if (total <= 60) {
        cost = (total / 10) * 5;
    } else if (total <= 180) {
        cost = (total / 10) * 10;
    } else if (total <= 300) {
        cost = (total / 10) * 15;
    } else {
        cost = (total / 10) * 20;
    }
    printf("\nYour Cost: %d TL", cost);
}
