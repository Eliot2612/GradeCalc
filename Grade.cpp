#include <iostream>
#include <vector>
#include <limits> 

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

    std::cout << "University Grade Calculator" << std::endl;
    std::cout << "Enter the grade (0-100) and credits for each module." << std::endl;
    std::cout << "Enter -1 at the grade prompt to finish.\n" << std::endl;

    while (true) {
        while (true) {
            std::cout << "Module " << counter << " Grade: ";
            
            if (std::cin >> temp.grade) {
                if (temp.grade == -1 || (temp.grade >= 0 && temp.grade <= 100)) {
                    break; 
                } else {
                    std::cout << "[Error] Grade must be between 0 and 100." << std::endl;
                }
            } else {
                std::cout << "[Error] Please enter a numeric value." << std::endl;
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 
            }
        }

        if (temp.grade == -1) {
            break;
        }

        while (true) {
            std::cout << "Module " << counter << " Credits: ";
            
            if (std::cin >> temp.credits && temp.credits > 0) {
                break; 
            } else {
                std::cout << "[Error] Credits must be a positive number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        totalCredits += temp.credits;
        transcript.push_back(temp);
        counter++;
        std::cout << "--- Module Added ---\n" << std::endl;
    }

    if (totalCredits > 0) {
        for (const auto& module : transcript) {
            overallGrade += module.grade * ((float)module.credits / totalCredits);
        }
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Total Credits: " << totalCredits << std::endl;
        std::cout << "Your Overall Weighted Grade: " << overallGrade << "%" << std::endl;
        std::cout << "------------------------------------" << std::endl;
    } else {
        std::cout << "No data entered" << std::endl;
    }

    return 0;
}