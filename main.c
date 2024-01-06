#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
  char question[100];
  char answers[4][50];
  char correctAnswer;
} Question;

void displayIntro() {
  printf("\t\t\t\t***********************************************\n");
  printf("\t\t\t\t*  Welcome to the Awesome Quiz Game!         *\n");
  printf("\t\t\t\t*  Author: Shah Jalal Khan                   *\n");
  printf("\t\t\t\t*  Presented to: Saurov Chandra Das Sir      *\n");
  printf("\t\t\t\t***********************************************\n\n");
}

void displayOutro(int score) {
  printf("\n\n\t\t\t\t\t***********************************************\n");
  printf("\t\t\t\t\t*  Your SCORE: %-3d                            *\n", score);
  printf("\t\t\t\t\t*  Thanks for playing the Awesome Quiz Game!  *\n");
  printf("\t\t\t\t\t***********************************************\n\n");
}

int main() {
  Question questions[5] = {
    {
      "What is the capital of France?",
      {"Berlin", "London", "Paris", "Rome"},
      'C'
    },
    {
      "What is the extension of C Programming?",
      {".html", ".c", ".swift", ".cpp"},
      'B'
    },
    {
      "What is the largest planet in our solar system?",
      {"Mars", "Venus", "Jupiter", "Saturn"},
      'C'
    },
    {
      "Which language is known as the 'language of the web'?",
      {"Java", "Python", "HTML", "JavaScript"},
      'D'
    },
    {
      "What is the powerhouse of the cell?",
      {"Nucleus", "Cytoplasm", "Mitochondrion", "Ribosome"},
      'C'
    }
  };

  int numQuestions = sizeof(questions) / sizeof(questions[0]);
  int score = 0;
  char answer;

  displayIntro();

  for (int i = 0; i < numQuestions; i++) {
    printf("\t\t\t\t************ Question %d ************\n\n", i + 1);
    printf("%s\n", questions[i].question);
    for (int j = 0; j < 4; j++) {
      printf("%c) %s\n", 'A' + j, questions[i].answers[j]);
    }

    printf("\nEnter your answer: ");
    scanf(" %c", &answer);

    if (toupper(answer) == questions[i].correctAnswer) {
      score++;
      printf("\nCorrect! Your score is: %d\n\n", score);
    } else {
      printf("\nWrong answer. The correct answer is %c.\n\n", questions[i].correctAnswer);
    }
  }

  displayOutro(score);

  return 0;
}
