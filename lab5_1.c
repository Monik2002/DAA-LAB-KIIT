#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct person
struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

// Function to read data of 'n' students from file and store in a dynamic array
struct person *readData(int *n)
{
    printf("Enter the number of students: ");
    scanf("%d", n);

    // Allocate memory for an array of struct person
    struct person *students = (struct person *)malloc((*n) * sizeof(struct person));

    if (students == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Read student data from the user
    for (int i = 0; i < *n; i++)
    {
        students[i].name = (char *)malloc(100 * sizeof(char)); // Allocate memory for the name

        printf("Enter data for student %d:\n", i);
        printf("Id: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("Height: ");
        scanf("%d", &students[i].height);

        printf("Weight(pound): ");
        scanf("%d", &students[i].weight);
    }

    return students;
}

void displayStudentData(struct person *students, int n)
{
    printf("Id\tName\tAge\tHeight\tWeight(pound)\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\t%d\t%d\n", students[i].id, students[i].name, students[i].age, students[i].height, students[i].weight);
    }
}

// Function to free the dynamically allocated memory for students
void freeStudents(struct person *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(students[i].name);
    }
    free(students);
}

// Function to heapify a min-heap based on age
void minHeapifyAge(struct person *students, int n, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && students[left].age < students[smallest].age)
        smallest = left;

    if (right < n && students[right].age < students[smallest].age)
        smallest = right;

    if (smallest != index)
    {
        struct person temp = students[index];
        students[index] = students[smallest];
        students[smallest] = temp;

        minHeapifyAge(students, n, smallest);
    }
}

// Function to build a min-heap based on age
void buildMinHeapAge(struct person *students, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapifyAge(students, n, i);
    }
}

void maxHeapifyWeight(struct person *students, int n, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && students[left].weight > students[largest].weight)
        largest = left;

    if (right < n && students[right].weight > students[largest].weight)
        largest = right;

    if (largest != index)
    {
        struct person temp = students[index];
        students[index] = students[largest];
        students[largest] = temp;

        maxHeapifyWeight(students, n, largest);
    }
}

// Function to build a max-heap based on weight
void buildMaxHeapWeight(struct person *students, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapifyWeight(students, n, i);
    }
}

// Function to insert a new person into the Min-heap based on age
struct person *insertPerson(struct person *students, int *n, struct person newPerson)
{
    (*n)++;
    struct person *newStudents = (struct person *)realloc(students, (*n) * sizeof(struct person));

    if (newStudents == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int i = (*n) - 1;
    while (i > 0 && newPerson.age < newStudents[(i - 1) / 2].age)
    {
        newStudents[i] = newStudents[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    newStudents[i] = newPerson;

    return newStudents;
}

// Function to delete the oldest person from the Min-heap based on age
struct person *deleteOldestPerson(struct person *students, int *n)
{
    if (*n <= 0)
    {
        printf("No students available.\n");
        return students;
    }

    students[0] = students[(*n) - 1];
    (*n)--;
    struct person *newStudents = (struct person *)realloc(students, (*n) * sizeof(struct person));

    if (newStudents == NULL && *n > 0)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int i = 0;
    while (1)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < *n && newStudents[left].age < newStudents[smallest].age)
            smallest = left;

        if (right < *n && newStudents[right].age < newStudents[smallest].age)
            smallest = right;

        if (smallest != i)
        {
            struct person temp = newStudents[i];
            newStudents[i] = newStudents[smallest];
            newStudents[smallest] = temp;
            i = smallest;
        }
        else
        {
            break;
        }
    }

    return newStudents;
}

int main()
{
    int option, n;
    struct person *students = NULL;

    while (1)
    {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("8. Display Student Data\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            if (students != NULL)
            {
                freeStudents(students, n); // Free previous data if any
            }
            students = readData(&n);
            break;

        case 2:
            if (students == NULL)
            {
                printf("No student data. Please read data first.\n");
            }
            else
            {
                buildMinHeapAge(students, n);
                printf("Min-heap based on age created.\n");
            }
            break;

        case 3:
            if (students == NULL)
            {
                printf("No student data. Please read data first.\n");
            }
            else
            {
                buildMaxHeapWeight(students, n);
                printf("Max-heap based on weight created.\n");
            }
            break;

        case 4:
            if (students == NULL)
            {
                printf("No student data. Please read data first.\n");
            }
            else
            {
                if (n > 0)
                {
                    printf("Weight of youngest student: %.2f kg\n", students[0].weight * 0.453592);
                }
                else
                {
                    printf("No students available.\n");
                }
            }
            break;

        case 5:
            if (students == NULL)
            {
                printf("No student data. Please read data first.\n");
            }
            else
            {
                struct person newPerson;
                printf("Enter new person's data (Id Name Age Height Weight): ");
                scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
                students = insertPerson(students, &n, newPerson);
                printf("New person inserted into the Min-heap based on age.\n");
            }
            break;

        case 6:
            if (students == NULL)
            {
                printf("No student data. Please read data first.\n");
            }
            else
            {
                students = deleteOldestPerson(students, &n);
                printf("Oldest person deleted from the Min-heap based on age.\n");
            }
            break;

        case 7:
            if (students != NULL)
            {
                freeStudents(students, n);
            }
            printf("Exiting program.\n");
            return 0;

        case 8:
            if (students == NULL)
            {
                printf("No student data. Please read data first.\n");
            }
            else
            {
                displayStudentData(students, n);
            }
            break;

        default:
            printf("Invalid option. Please enter a valid option.\n");
        }
    }

    return 0;
}
