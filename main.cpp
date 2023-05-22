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
        {"What is the largest planet in our solar system?",
         {"Jupiter", "Saturn", "Neptune", "Uranus"},
         0},
        {"Who wrote the play 'Romeo and Juliet'?",
         {"William Shakespeare", "George Bernard Shaw", "Anton Chekhov", "Oscar Wilde"},
         1},
        {"Which country is home to the kangaroo?",
         {"Australia", "Brazil", "Canada", "India"},
         0},
        {"What is the chemical symbol for the element gold?",
         {"Au", "Ag", "Fe", "Hg"},
         1},
        {"What is the capital of Japan?",
         { "Beijing", "Seoul" , "Tokyo", "Bangkok"},
         2},
        {"Who painted the famous artwork 'The Starry Night'?",
         { "Pablo Picasso", "Leonardo da Vinci", "Michelangelo","Vincent van Gogh"},
         3},
        {"Which planet is known as the 'Morning Star' or 'Evening Star'?",
         {"Mercury","Venus",  "Mars", "Jupiter"},
         1},
        {"What is the tallest mountain in the world?",
         { "K2", "Kangchenjunga","Mount Everest", "Makalu"},
         2},
        {"Who is credited with inventing the telephone?",
         {"Alexander Graham Bell", "Thomas Edison", "Nikola Tesla", "Albert Einstein"},
         0},
        {"What is the primary language spoken in Brazil?",
         { "Spanish", "French","Portuguese", "English"},
         2},
        {"Which famous scientist developed the theory of relativity?",
         { "Isaac Newton", "Galileo Galilei", "Stephen Hawking","Albert Einstein"},
         3},
        {"Who is the author of the Harry Potter book series?",
         { "George R.R. Martin","J.K. Rowling", "Dan Brown", "Stephen King"},
         1}
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
