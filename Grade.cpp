#include <iostream>
#include <vector>

struct Module {
    int grade;
    int credits;
};

int main() {
    std::vector<Module> transcript;
    Module temp;
    int totalCredits = 0;
    int counter = 1;
    float overallGrade = 0.0;
    std::cout << "Lets Calculate your grade." << std::endl;
    std::cout << "Module by module enter the grade, and then the credits it was worth." << std::endl;
    std::cout << "When you are done entering modules, enter -1 for the overall grade." << std::endl;
    while (true){
        std::cout << "Enter Grade for Module " << counter << ": ";
        std::cin >> temp.grade;
        if (temp.grade == -1){
            break;
        }
        std::cout << "Enter Credits for Module " << counter << ": ";
        std::cin >> temp.credits;
        totalCredits += temp.credits;
        transcript.push_back(temp);
        counter ++;
    }
    for (const auto& module : transcript) {
        overallGrade += module.grade * ((float)module.credits / totalCredits);
    }
    std::cout << "Overall Grade: " << overallGrade << std::endl;
    return 0;
}

