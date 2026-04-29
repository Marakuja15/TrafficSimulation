// TrafficSimulation.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Car.h"
#include "TrafficLight.h"
#include "Simulation.h"
int main()
{
    int numOfCars = 50;
    int numOfTrafficLights = 20;
    float startingPos = -(numOfCars * 5);

    std::vector<Car> carsVector;
    carsVector.reserve(numOfCars);
    for (int i = 0; i < numOfCars; i++) {
        Car myCar(std::to_string(i), i * startingPos, 20.0f);
        carsVector.push_back(myCar);
    }
    std::vector<TrafficLight> lightsVector;
    carsVector.reserve(numOfTrafficLights);
    for (int i = 0; i < numOfTrafficLights; i++) {
        TrafficLight myLight((i + 1) * 100.0f, LightColor::RED);
        lightsVector.push_back(myLight);
        
    }

   
  
 
    Simulation sim(carsVector, lightsVector);
    sim.run();
    

    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
