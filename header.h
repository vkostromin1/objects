#ifndef HELICOPTERS_H
#define HELICOPTERS_H
#include <string>
#include <vector>
#include "decorators.h"

using namespace std;

enum class HelicopterColor : int
{
    Grey = 0,
    White = 1,
    Black = 2,
    Yellow = 3,
    Unknown = -1
};

enum class HelicopterType : int
{
    PassHeli,
    TaxiHeli,
    CargoHeli,
    CombatHeli,
    Unknown = -1
};

enum class HelicopterSpeed : int
{
    Fast,
    Medium,
    Slow,
    Unknown = -1
};


class DefaultHelicopter
{
protected:
    int EnginePower = 0;
    HelicopterColor Color;
    HelicopterSpeed Speed;
    int ShassisCount = 0;
    int YearsMileage = 0;
    HelicopterType Type;
    int PassengerCount = 0;

public:
    DefaultHelicopter(){};
    HelicopterType GetType () const { return Type; }
    HelicopterColor GetColor() const { return Color; }
    HelicopterSpeed GetSpeed () const { return Speed; }
    void AddEnginePower(int HowManyEnginePower)
    {
        EnginePower = EnginePower + HowManyEnginePower;
    };
    void AddShassis(int HowManyShassis)
    {
        ShassisCount = ShassisCount + HowManyShassis;
    };
    void ChangeYearsMileage(int HowManyYearsMileage)
    {
        YearsMileage = YearsMileage + HowManyYearsMileage;
    };
    void AddPassengers (int HowManyPassengers)
    {
        PassengerCount = HowManyPassengers + PassengerCount;
    };
    virtual void Fly() const = 0;
};

typedef DefaultHelicopter *HeliPtr;

class PassangerHelicopter : public DefaultHelicopter
{
public:
    PassangerHelicopter() : DefaultHelicopter() { HelicopterColor Color = HelicopterColor::White; HelicopterType Type = HelicopterType::PassHeli; HelicopterSpeed Speed = HelicopterSpeed::Medium; }
    void Fly() const override { cout << "You fly at Passanger Helicopter"; }
};

class TaxiHelicopter : public DefaultHelicopter
{
public:
    TaxiHelicopter() : DefaultHelicopter() { HelicopterColor Color = HelicopterColor::Yellow;HelicopterType Type=HelicopterType::TaxiHeli; HelicopterSpeed Speed = HelicopterSpeed::Medium;}
    void Fly() const override { cout << "You fly at Taxi Helicopter"; }
};

class CombatHelicopter : public DefaultHelicopter
{
public:
    CombatHelicopter() : DefaultHelicopter() { HelicopterColor Color = HelicopterColor::Grey;HelicopterType Type=HelicopterType::CombatHeli; HelicopterSpeed Speed = HelicopterSpeed::Fast; }
    void Fly() const override { cout << "You fly at Combat Helicopter"; }
};

class CargoHelicopter : public DefaultHelicopter
{
public:
    CargoHelicopter() : DefaultHelicopter() { HelicopterColor Color = HelicopterColor::Black;HelicopterType Type=HelicopterType::CombatHeli; HelicopterSpeed Speed = HelicopterSpeed::Slow; }
    void Fly() const override { cout << "You fly at Cargo Helicopter"; }
};

class FirstContainerIterator : public Iterator<HeliPtr>
{
private:
    const list <HeliPtr> *FirstHeliCont ;
    list <HeliPtr>::const_iterator Iterator;
public:
    void First(){Iterator = FirstHeliCont->begin();}
    void Next() {Iterator++;}
    bool IsDone() const {return Iterator == FirstHeliCont->end();}
    HeliPtr GetCurrent() const {return *Iterator ;}
    FirstContainerIterator(const list<HeliPtr> *Firsthelicont)
    {
        FirstHeliCont = Firsthelicont;
        Iterator = FirstHeliCont->begin();
    }

};

class Container
{
public:
    virtual void AddHeli (HeliPtr NewBand) = 0 ;
    virtual int GetCount() const = 0 ;
    virtual Iterator<HeliPtr> *GetIterator() = 0;
};

class FirstContainer : public Container
{
private:
    list<HeliPtr> HeliFirstCont;

public:
    void AddHeli(HeliPtr NewHeli)
    {
        HeliFirstCont.push_back(NewHeli);
    }
    int GetCount() const {return HeliFirstCont.size() ;}

    Iterator<HeliPtr> *GetIterator()
    {
        return new FirstContainerIterator(&HeliFirstCont);
    };
};

class SecondContainerIterator : public Iterator<HeliPtr>
{
private:
	const vector <HeliPtr> *SecondHeliCont;
	vector <HeliPtr>::const_iterator Iterator;

public:
	void First(){Iterator = SecondHeliCont->begin();}
	void Next() {Iterator++;}
	bool IsDone() const {return Iterator == SecondHeliCont->end();}
	HeliPtr GetCurrent() const { return *Iterator; }
    SecondContainerIterator(const vector<HeliPtr> *Secondhelicont)
    {
		SecondHeliCont = Secondhelicont;
		Iterator = SecondHeliCont->begin();
	}
};

class SecondContainer
{
private:
    vector<HeliPtr> SecondHeliCont;

public:
    void AddHeli(HeliPtr NewHelis) {SecondHeliCont.push_back(NewHelis);}
    int GetCount() const {return SecondHeliCont.size();}
    HeliPtr GetByIndex(int index) {return SecondHeliCont[index];}

   Iterator<HeliPtr> *GetIterator()
    {
        return new SecondContainerIterator(&SecondHeliCont);
    };
};

#endif
