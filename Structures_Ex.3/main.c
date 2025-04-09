#include <stdio.h>
#include <stdlib.h>
struct Student{
    char name[50];
    float grade;
};

struct Class{
    struct Student students[30];
    int num_students;
};

struct Graduation{
    struct Class classes[5];
    int num_classes;
};

float calculate_class_average(struct Class *class){
    float total = 0;
    for (int i = 0; i < class->num_students; i++) {
        total += class->students[i].grade;
    }
    return total / class->num_students;
}

float calculate_graduation_average(struct Graduation *graduation) {
    float total = 0;
    int total_students = 0;
    for (int i = 0; i < graduation->num_classes; i++) {
        total += calculate_class_average(&graduation->classes[i]) * graduation->classes[i].num_students;
        total_students += graduation->classes[i].num_students;
    }
    return total / total_students;
}


int main() {
    struct Graduation graduation;
    printf("Enter the number of classes in the graduation: ");
    scanf("%d", &graduation.num_classes);

    for (int i = 0; i < graduation.num_classes; i++) {
        printf("\nEnter the number of students in class %d: ", i + 1);
        scanf("%d", &graduation.classes[i].num_students);

        for (int j = 0; j < graduation.classes[i].num_students; j++) {
            printf("Enter name of student %d: ", j + 1);
            getchar();  // To consume any remaining newline character
            fgets(graduation.classes[i].students[j].name, 50, stdin);

            printf("Enter grade for student %d: ", j + 1);
            scanf("%f", &graduation.classes[i].students[j].grade);
        }
    }

    for (int i = 0; i < graduation.num_classes; i++) {
        printf("\nClass %d average grade: %.2f\n", i + 1, calculate_class_average(&graduation.classes[i]));
    }

    printf("\nOverall graduation average grade: %.2f\n", calculate_graduation_average(&graduation));

    return 0;
}
