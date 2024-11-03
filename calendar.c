#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define the structure for a Day
struct Day
{
    char *dayName;
    int date;
    char *activity;
};
// Function to create a day entry
void create(struct Day *day)
{
    day->dayName = (char *)malloc(sizeof(char) * 20);
    day->activity = (char *)malloc(sizeof(char) * 100);
    if (day->dayName == NULL || day->activity == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the day name: ");
    scanf("%19s", day->dayName); // Limit input to avoid buffer overflow
    printf("Enter the date: ");
    scanf("%d", &day->date);
    // Clear the input buffer to handle the newline character left by scanf
    while (getchar() != '\n')
        ;
    printf("Enter the activity for the day: ");
    // Read the rest of the line (including spaces)
    fgets(day->activity, 100, stdin);
    // Remove newline character if present
    day->activity[strcspn(day->activity, "\n")] = 0;
}
// Function to read details for each day in the calendar
void read(struct Day *calendar, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter details for Day %d:\n", i + 1);
        create(&calendar[i]);
    }
}
// Function to display the calendar
void display(const struct Day *calendar, int size)
{
    printf("\nWeek's Activity Details:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Day %d:\n", i + 1);
        printf("Day Name: %s\n", calendar[i].dayName);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n", calendar[i].activity);
        printf("\n");
    }
}
// Function to free allocated memory
void freeMemory(struct Day *calendar, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(calendar[i].dayName);
        free(calendar[i].activity);
    }
}
int main()
{
    int size;
    printf("Enter the number of days in the week: ");
    scanf("%d", &size);
    // Allocate memory for the calendar
    struct Day *calendar = (struct Day *)malloc(sizeof(struct Day) * size);
    if (calendar == NULL)
    {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }
    read(calendar, size);
    display(calendar, size);
    // Free allocated memory
    freeMemory(calendar, size);
    free(calendar);
    return 0;
}