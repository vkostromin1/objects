#include <iostream>
#include <list>
#include "header.h"
#include <string>

using namespace std;

DefaultHelicopter *Create_new_helicopter(HelicopterType Type)
{
    switch(Type)
    {
        case HelicopterType::PassHeli: return new PassangerHelicopter() ;
        case HelicopterType::TaxiHeli: return new TaxiHelicopter() ;
        case HelicopterType::CargoHeli: return new CargoHelicopter();
        case HelicopterType::CombatHeli: return new CombatHelicopter();
        default : return 0 ;
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    return 0;
}

