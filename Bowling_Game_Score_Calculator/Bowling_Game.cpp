//Bowling Game

#include <iostream>
#include <vector>

int calculateScore(const std::vector<int> vecRolls) {
    int totalScore = 0;
    int rollIndex = 0;

    for (int frame = 0; frame < 10; ++frame) {
        
        int frameScore = 0;
        if (vecRolls[rollIndex] == 10) {
            //calculating framescore for strike
            frameScore = 10 + vecRolls[rollIndex + 1] + vecRolls[rollIndex + 2]; 
            rollIndex =rollIndex + 1;
        }
        else if (vecRolls[rollIndex] + vecRolls[rollIndex + 1] == 10) {
            //calculating framescore for spare
            frameScore = 10 + vecRolls[rollIndex + 2];
            rollIndex =rollIndex + 2;
        }
        // OPEN FRAME
        else {
            //calculating framescore
            frameScore = vecRolls[rollIndex] + vecRolls[rollIndex + 1];
            rollIndex = rollIndex + 2;
        }
        totalScore =totalScore+frameScore;  //adding frame score in total score
    }

    return totalScore;
}

int main() {
    std::vector<int> rolls = { 1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6};  //input 
    std::cout<<"Bowling frames - 1,4 | 4,5 | 6,4 | 5,5 | 10 | 0,1 | 7,3 | 6,4 | 10 | 2,8,6 "<<std::endl;
    std::cout << "Total Score: " << calculateScore(rolls) <<std::endl;
    return 0;
}

