#include <iostream>
#include <vector>

using namespace std;

class LandUnit
{
public:
    virtual void move(int provinceID) = 0;
    virtual void detachSiege() = 0;
};

class Infantry : public LandUnit
{
public:
    int techLevel;
    void move(int provinceID) override
    {
        cout << "Infantry moving to province " << provinceID << "\n";
    }
    void detachSiege() override
    {
        cout << "Cannot detach single infantry unit.\n";
    }
};

class Cavalry : public LandUnit
{
public:
    int techLevel;
    void move(int provinceID) override
    {
        cout << "Cavalry moving to province " << provinceID << "\n";
    }
    void detachSiege() override
    {
        cout << "Cannot detach single cavalry unit.\n";
    }
};

class Artillery : public LandUnit
{
public:
    int techLevel;
    void move(int provinceID) override
    {
        cout << "Artillery moving to province " << provinceID << "\n";
    }
    void detachSiege() override
    {
        cout << "Cannot detach single artillery unit.\n";
    }
};

class Army : public LandUnit
{
public:
    vector<LandUnit *> units;
    void move(int provinceID) override
    {
        cout << "Army moving to " << provinceID << "\n";
        for (auto & unit : units)
        {
            unit->move(provinceID);
        }
        cout << "Army moved\n";
    }
    void detachSiege() override
    {

        if (units.size() > 3)
        {
            cout << "Detached army to siege\n";
        }
        else
        {
            cout << "Army can't be detached\n";
        }
    }
};

int main()
{
    Army main_army;
    LandUnit *i1 = new Infantry();
    LandUnit *i2 = new Infantry();
    LandUnit *c1 = new Cavalry();
    LandUnit *a1 = new Artillery();

    main_army.units.push_back(i1);
    main_army.units.push_back(i2);
    main_army.units.push_back(c1);
    main_army.units.push_back(a1);

    main_army.move(35);
    main_army.detachSiege();

    return 0;
}
