#include <iostream>
using namespace std;

float total_amount_of_calories;
float amount_of_fat_contained_in_food;
const float desired_fat_percentage = 0.7;
float fat_percentage;
float coconut_calories_needed_to_stay_in_ketosis;

void inputData () {
    cout << "Amount of calories in meal?" << "\n";
    cin >> total_amount_of_calories;
    cout << "how much fat does it contain?" << "\n";
    cin >> amount_of_fat_contained_in_food;

    fat_percentage = amount_of_fat_contained_in_food / total_amount_of_calories;
    coconut_calories_needed_to_stay_in_ketosis = (amount_of_fat_contained_in_food -(desired_fat_percentage*total_amount_of_calories))/(desired_fat_percentage-1);
    cout << "fat percentage: " << fat_percentage << "\n";
    cout << "calories needed from fat to stay in ketosis: " << coconut_calories_needed_to_stay_in_ketosis << "\n\n";
};


int main () {
    inputData();
}
