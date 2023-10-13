//Activities selection problem
#include <stdio.h>
#include <stdlib.h>


struct Activity {
    int start;
    int finish;
};


int compareActivities(const void *a, const void *b) {
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}


void selectActivities(struct Activity activities[], int n) {
    
    qsort(activities, n, sizeof(struct Activity), compareActivities);

    printf("Selected activities:\n");

    
    printf("(%d, %d) ", activities[0].start, activities[0].finish);

    int prevFinishTime = activities[0].finish;

    
    for (int i = 1; i < n; i++) {
        
        if (activities[i].start >= prevFinishTime) {
            printf("(%d, %d) ", activities[i].start, activities[i].finish);
            prevFinishTime = activities[i].finish;
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    printf("Enter start and finish times for each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    selectActivities(activities, n);

    return 0;
}