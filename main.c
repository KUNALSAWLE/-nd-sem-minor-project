#include <stdio.h>

typedef struct {
    char question[256];
    char options[4][50];
    char correctOption;
} Question;

char askQuestion(Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, q.options[i]);
    }
    char answer;
    printf("Enter your answer (A/B/C/D): ");
    scanf(" %c", &answer);
    return answer;
}

int main() {
    Question questions[6] = {
        {"Q1. What is the capital of USA?", {"Washington D.C.", "New York", "Los Angeles", "Chicago"}, 'A'},
        {"Q2. What is the largest planet of our solar system?", {"Earth", "Mars", "Jupiter", "Saturn"}, 'C'},
        {"Q3. What is the longest river in India?", {"Ganga", "Brahmaputra", "Yamuna", "Godavari"}, 'A'},
        {"Q4. What is the chemical symbol of gold?", {"Ag", "Au", "Pb", "Pt"},'B'},
        {"Q5. Who was the first president of India?", {"Dr. Sarvepalli Radhakrishnan", "Rajendra Prasad", "Sardar Patel", "Jawaharlal Nehru"},'D'},
        {"Q6. Which element has the highest melting point?", {"Tungsten", "Iron", "Gold", "Carbon"}, 'A'}
    };

    int score = 0;
    int marksPerQuestion = 5;
    
    for (int i = 0; i < 6; i++) {
        char answer = askQuestion(questions[i]);
        if (answer == questions[i].correctOption) {
            printf("Correct!\n");
            score += marksPerQuestion;
        } else {
            printf("Wrong. The correct answer is %c.\n", questions[i].correctOption);
        }
    }

    printf("Your total score is: %d out of 30\n", score);

    return 0;
}
