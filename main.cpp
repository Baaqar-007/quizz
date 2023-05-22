#include <iostream>
#include <vector>
using namespace std;

struct Question {
    string question;
    vector<string> options;
    int correctOption;
};

void askQuestion(const Question& question) {
    cout << question.question << endl;
    for (size_t i = 0; i < question.options.size(); ++i) {
        cout << i + 1 << ". " << question.options[i] << endl;
    }
}

int getAnswer() {
    int answer;
    cout << "Enter your answer: ";
    cin >> answer;
    return answer;
}

int calculateScore(const vector<Question>& questions, const vector<int>& answers) {
    int score = 0;
    for (size_t i = 0; i < questions.size(); ++i) {
        if (answers[i] == questions[i].correctOption) {
            score++;
        }
    }
    return score;
}

int main() {
    vector<Question> questions = {
        {"What is the capital of France?",
         {"Paris", "London", "Berlin", "Rome"},
         0},
        {"Which planet is known as the Red Planet?",
         {"Mars", "Jupiter", "Venus", "Saturn"},
         0},
        {"Who painted the Mona Lisa?",
         {"Leonardo da Vinci", "Pablo Picasso", "Vincent van Gogh", "Michelangelo"},
         0},
    };

    vector<int> answers;

    for (const auto& question : questions) {
        askQuestion(question);
        int answer = getAnswer();
        answers.push_back(answer - 1);
    }

    int score = calculateScore(questions, answers);
    :cout << "Your score: " << score << "/" << questions.size() << :endl;

    return 0;
}
