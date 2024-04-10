#include <iostream>
using namespace std;

float totalAmountOfCalories;
float weight;
float gramsOfCarbohydratePer100g;
float gramsOfProteinPer100g;
float gramsOfFatPer100g;

float amountOfCaloriesIn1gCarbohydrate = 4;
float amountOfCaloriesIn1gProtein = 4;
float amountOfCaloriesIn1gFat = 9;

const float desiredFatPercentage = 0.7;

float fatPercentage;
float coconutCaloriesNeededToStayInKetosis;

void inputData () {
    cout << "Amount of calories in meal?" << "\n";
    cin >> totalAmountOfCalories;
    
    cout << "how much does the food weigh?" << "\n";
    cin >> weight;
    cout << "how many grams of carbohydrates does it contain per 100g?" << "\n";
    cin >> gramsOfCarbohydratePer100g;
    cout << "how many grams of protein does it contain per 100g?" << "\n";
    cin >> gramsOfProteinPer100g;
    cout << "how many grams of fat does it contain per 100g?" << "\n";
    cin >> gramsOfFatPer100g;

    float amountOfCaloriesInCarbohydratesPer1g = (gramsOfCarbohydratePer100g * amountOfCaloriesIn1gCarbohydrate) / 100;
    float amountOfCaloriesInProteinPer1g = (gramsOfProteinPer100g * amountOfCaloriesIn1gProtein) / 100;
    float amountOfCaloriesInFatPer1g = (gramsOfFatPer100g * amountOfCaloriesIn1gFat) / 100;

    float totalAmountOfCaloriesPer1g = (amountOfCaloriesInCarbohydratesPer1g + amountOfCaloriesInProteinPer1g + amountOfCaloriesInFatPer1g);
    float totalAmountOfCaloriesInThisMeal = weight * totalAmountOfCaloriesPer1g;
    float totalAmountofCaloriesInThisMealFromFat = amountOfCaloriesInFatPer1g * gramsOfFatPer100g / 100 * weight;

    cout << "totalAmountOfCaloriesInThisMeal: " << totalAmountOfCaloriesInThisMeal << "\n";

    cout << "totalAmountofCaloriesInThisMealFromFat: " << totalAmountofCaloriesInThisMealFromFat << "\n";

    fatPercentage = amountOfCaloriesInFatPer1g / totalAmountOfCalories;
    coconutCaloriesNeededToStayInKetosis = (amountOfCaloriesInFatPer1g -(desiredFatPercentage*totalAmountOfCalories))/(desiredFatPercentage-1);
    cout << "fat percentage: " << fatPercentage << "\n";
    cout << "calories needed from fat to stay in ketosis: " << coconutCaloriesNeededToStayInKetosis << "\n\n";
};


int main () {
    inputData();
}
