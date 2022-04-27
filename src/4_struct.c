#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char *name;
    char *surname;
    int grade;
    struct student *next;
} student;

char *get_string();
student *create_node();
void print_list(student *stud);
void add_in_the_end(student **stud);


char *get_string() {
    char c;
    char *tmp = NULL;
    int len = 0;
    tmp = (char*)malloc(sizeof(char));
    while (scanf("%c", &c) == 1 && c != '\n') {
        tmp = (char*)realloc(tmp, (len + 1) * sizeof(char));
        tmp[len] = c;
        len++;
    }
    return tmp;
}

student *create_node() {
    student *node = (student *)malloc(sizeof(student));

    printf("Name: ");
    node -> name = get_string();

    printf("Surname: ");
    node -> surname =  get_string();

    printf("Grade: ");
    int gr;
    while (!(scanf("%d", &gr) == 1 && 2 <= gr && gr <= 5)) {
        printf("Wrong input, try again\n");
    }
    node -> grade = gr;

    node -> next = NULL;

    return node;
}

void print_list(student *stud) {
    while (stud -> next != NULL) {
        printf("\nName: ");
        puts(stud -> name);
        printf("\nSurname: ");
        puts(stud -> surname);
        printf("\nGrade: %d\n\n", stud -> grade);
        // stud = stud -> next;
    }
}

void add_in_the_end(student **stud) {
    student *new_student = create_node();
    *stud= new_student;
}

int main() {
    struct student *stud = create_node();
    print_list(stud);
    // while (1) {
        // char ans[4], yes[] = "yes";
        // printf("Do you want to add information about one more student? (yes/no)\n");
        // scanf("%s", ans);
        // if (strcmp(ans, yes))
            add_in_the_end(&stud);
    //     else
    //         break;
    // }
    print_list(stud);
    return 0;
}