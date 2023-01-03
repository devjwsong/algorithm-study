#include <iostream>

using namespace std;


class ParkingSystem {
public:
    int numBigs = 0, numMediums = 0, numSmalls = 0;
    int maxBigs = 0, maxMediums = 0, maxSmalls = 0;

    ParkingSystem(int big, int medium, int small) {
        maxBigs = big;
        maxMediums = medium;
        maxSmalls = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1) {
            if  (numBigs < maxBigs) {
                ++numBigs;
                return true;
            }
            return false;
        } else if (carType == 2) {
            if (numMediums < maxMediums) {
                ++numMediums;
                return true;
            }
            return false;
        } else {
            if (numSmalls < maxSmalls) {
                ++numSmalls;
                return true;
            }
            return false;
        }
        return false;
    }
};
