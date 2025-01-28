#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  

typedef struct {
    int task_id;
    int execution_time;
    int deadline;
    int time_left;
} Task;

int compare_tasks(const void *a, const void *b) {
    Task *task1 = (Task *)a;
    Task *task2 = (Task *)b;
    return task1->deadline - task2->deadline;
}

void schedule_tasks(Task tasks[], int num_tasks) {
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);

    for (int i = 0; i < num_tasks; i++) {
        Task *task = &tasks[i];

        while (task->time_left > 0) {
            printf("Executing Task %d (Deadline: %d), Remaining Time: %d\n", 
                   task->task_id, task->deadline, task->time_left);
            sleep(1);
            task->time_left--;
        }
        printf("Task %d completed.\n", task->task_id);
    }
}

int main() {
    Task tasks[] = {
        {1, 3, 5, 3},
        {2, 2, 3, 2},
        {3, 1, 4, 1}
    };

    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);

    schedule_tasks(tasks, num_tasks);

    return 0;
}