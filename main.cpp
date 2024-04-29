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
    wstring PrintHelicopterColor (const HelicopterColor Color)
{
    switch(Color)
    {
        case HelicopterColor::Grey : return L"Серый" ;
        case HelicopterColor::White : return L"Белый" ;
        case HelicopterColor::Black : return L"Чёрный" ;
        case HelicopterColor::Yellow : return L"Жёлтый" ;
        default : return L"Неизвестно" ;
    }
}

wstring PrintHelicopterType ( const HelicopterType Type)
{
    switch(Type)
    {
        case HelicopterType::PassHeli: return L"Пассажирский вертолёт";
        case HelicopterType::TaxiHeli: return L"Вертолёт-таски";
        case HelicopterType::CargoHeli: return L"Грузовой вертолёт";
        case HelicopterType::CombatHeli: return L"Военный вертолёт";
        default: return L"Неизвестно" ;
    }
}

wstring PrintHelicopterSpeed (const HelicopterSpeed Speed)
{
    switch(Speed)
    {
        case HelicopterSpeed::Fast : return L"Быстрая скорость" ;
        case HelicopterSpeed::Medium : return L"Средняя скорость" ;
        case HelicopterSpeed::Slow : return L"Медленная скорость" ;
        default : return L"Неизвестно" ;
    }
}

void task1 (Iterator<HeliPtr> *Iterator) // Увеличить мощность пассажирских вертолётов
{
    for (Iterator->First(); !Iterator->IsDone() ; Iterator->Next())
    {
        int HowManyEnginePower = rand()%(40-20+1)+20;
        const HeliPtr CurrentHeli = Iterator -> GetCurrent();
        CurrentHeli -> AddEnginePower(HowManyEnginePower);
        wcout<< L"Мощность вертолёта типа : " << PrintHelicopterType(CurrentHeli -> GetType()) << L" увеличилась на "  << HowManyEnginePower << endl;
        HowManyEnginePower = 0;
    }
}

int main(){
    setlocale(LC_ALL, "Russian");

    FirstContainer FirstCont ;
    SecondContainer SecondCont ;

    for (int i=0; i < rand()%100+1000; i++)
    {
        FirstCont.AddHeli(Create_new_helicopter(static_cast<HelicopterType>(rand()%(3)+1)));
    }
    wcout << L"В первом контейнере: " << FirstCont.GetCount() << L" элемента/элементов" << endl ;
    for (int i=0; i < rand()%100+1000; i++)
    {
        SecondCont.AddHeli(Create_new_helicopter(static_cast<HelicopterType>(rand()%(3)+1));
    }
    wcout << L"Во втором контейнере: " << SecondCont.GetCount() << L" элемента/элементов" << endl;
    return 0;
    Iterator<HeliPtr> *Iterator = new HelicopterTypeDecorator (SecondCont.GetIterator(), HelicopterType::PassHeli);
    task1(Iterator);
}
}

