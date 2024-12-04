#include <stdio.h>
#include "SimpleCar.h"
#include "SimpleCar.C"

int main() {

   int inputDistance;

   inputDistance = 0;

    SimpleCar testDrive;

    testDrive = InitCar();

   scanf("%d", &inputDistance);

    testDrive = Drive(inputDistance, testDrive);

    HonkHorn(testDrive);

    Report(testDrive);

    scanf("%d", &inputDistance);

    testDrive = Reverse(inputDistance, testDrive);

    HonkHorn(testDrive);

    Report(testDrive);

   return 0;
}