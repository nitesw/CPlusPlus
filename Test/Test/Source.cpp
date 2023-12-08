#include <iostream>
#include <vector>
using namespace std;

class World {
public:
    World() {
        // Initialize the world with some default values
        width_ = 100;
        height_ = 100;
        temperature_ = 72.0;
        time_of_day_ = "morning";
    }

    void UpdateWeather() {
        int r = rand() % 100;
        if (r < 20) {
            temperature_ -= 1;
        }
        else if (r < 40) {
            temperature_ += 1;
        }
        if (temperature_ < 32) {
            cout << "It's freezing!" << endl;
        }
        else if (temperature_ > 90) {
            cout << "It's hot!" << endl;
        }
        else {
            cout << "The weather is mild." << endl;
        }
    }

    void UpdateTime() {
        int r = rand() % 24;
        if (r < 6) {
            time_of_day_ = "morning";
        }
        else if (r < 12) {
            time_of_day_ = "afternoon";
        }
        else if (r < 18) {
            time_of_day_ = "evening";
        }
        else {
            time_of_day_ = "night";
        }
    }

    void PrintInfo() {
        cout << "The world is " << width_ << " units wide and " << height_ << " units tall." << endl;
        cout << "The current temperature is " << temperature_ << " degrees Fahrenheit." << endl;
        cout << "It is currently " << time_of_day_ << "." << endl;
    }

private:
    int width_;
    int height_;
    double temperature_;
    string time_of_day_;
};

int main() {
    srand(time(0));
    World world;
    world.PrintInfo();
    world.UpdateWeather();
    world.UpdateTime();
    world.PrintInfo();
    return 0;
}
