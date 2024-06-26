#include <iostream>
#include <vector>
#include <mutex>
#include <chrono>
#include <thread>

std::mutex m;

void turnGreen(int* position) {
    if (*position == 1) {
        *position = 2;
    } else {
        *position = 1;
    }
}

void carArrived(int carId, int roadId, int direction, int* position) {
    std::lock_guard<std::mutex> s(m);
    const char* road;
    if (roadId == 1) {
        road = "A";
    } else {
        road = "B";
    }
    std::cout << "Car " << carId << " has passed road " << road << " in direction " << direction << "\n"; 
}

int main() {
    std::vector<int> cars = {1, 3, 5, 2, 4};
    std::vector<int> directions = {2, 1, 2, 4, 3};
    std::vector<int> arrivalTimes = {10, 20, 30, 40, 50};

    int position = 1;
    for (size_t i = 0; i < cars.size(); ++i) {
        if (directions[i] <= 2 && position != 1) {
            position = 1;
        } else if (directions[i] > 2 && position != 2) {
            position = 2;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(arrivalTimes[i]));
        
        carArrived(cars[i], position, directions[i], &position);
        
        if (position == 1 && i + 1 < cars.size() && directions[i + 1] > 2) {
            std::cout << "Traffic light on road B is Green\n"; 
        } else if (position == 2 && i + 1 < cars.size() && directions[i + 1] <= 2) {
            std::cout << "Traffic light on road A is Green\n";
        }
    }

    return 0;
}
