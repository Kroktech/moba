#include <iostream>
#include <vector>

void display(std::string msg)
{
    std::cout << msg << std::endl;
}

class IFightingStyle
{
public:
    virtual ~IFightingStyle() = default;
    virtual void fight() = 0; 
};

class FightWithSword : public IFightingStyle
{
public:
    void fight() override
    {
        display("Fight with Sword");
    }
};

class FightWithStick : public IFightingStyle
{
public:
    void fight() override
    {
        display("Fight with Stick");
    }
};

class Hero
{
public:
    virtual ~Hero()
    {
        display("Destruction Hero");
        delete m_fightingStyle;
        m_fightingStyle = nullptr;
    }

    void fight() 
    {
        m_fightingStyle->fight();
    }

protected:
    IFightingStyle* m_fightingStyle;
};

class Barbarian : public Hero
{
public:
    Barbarian()
    {
        m_fightingStyle = new FightWithSword();
    }
};

class Wizard : public Hero
{
public:
    Wizard()
    {
        m_fightingStyle = new FightWithStick();
    }
};

void armyFight(std::vector<Hero*>& heroes)
{
    for (auto i = 0; i < heroes.size(); ++i)
        heroes[i]->fight();
}

int main()
{
    // Hero* barbarian = new Barbarian();
    // Hero* wizard = new Wizard();
    std::vector<Hero*> heroes;
    heroes.push_back(new Barbarian);
    heroes.push_back(new Wizard);

    armyFight(heroes);

    for (auto i = 0; i < heroes.size(); ++i)
    {
        delete heroes[i];
        heroes[i] = nullptr;
    }

    heroes.clear();

    return 0;
}
