//Michael Dominguez

#include "profemon.hpp"
using namespace std;


Profemon::Profemon() {
    name = "Undefined";
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty) {
    this->name = name;
    this->max_health = max_health;
    this->specialty = specialty;
    to_levelUp = 50;
    currentEXP = 0;
    level = 0;
}

std::string Profemon::getName() {
    return name;
}

Specialty Profemon::getSpecialty() {
    return specialty;
}

int Profemon::getLevel() {
    return level;
}

double Profemon::getMaxHealth() {
    return max_health;
}

void Profemon::setName(std::string name) {
    this->name = name;
}

void Profemon::levelUp(int exp) {
    currentEXP += exp;
    while (currentEXP >= to_levelUp) {
            currentEXP -= to_levelUp;
            level++;

            switch (specialty) { 
            case 0:
                to_levelUp += 10;
                break;
            case 1:
                to_levelUp += 15;
                break;
            case 2:
                to_levelUp += 20;
            break;
        }
        }
}

bool Profemon::learnSkill(int slot, Skill skill)
    {
        if (slot < 0 || slot > 2 || skill.getSpecialty() != specialty)
        {
            return false;
        }
        else
        {
            prof[slot] = skill;
            return true;
        }
    }


    void Profemon::printProfemon(bool print_skills)
    {
        string specialNew;
       switch (getSpecialty())
       {
           case 0:
            specialNew = "ML";
            break;
           case 1:
            specialNew = "SOFTWARE";
              break;
           case 2:
            specialNew = "HARDWARE";
            break;
       }
        cout << name << " [" << specialNew << "] | lvl " << level << " | exp " << currentEXP << "/" << to_levelUp << " | hp " << max_health << endl;
        
        if (print_skills)
        {
        for (int g = 0; g < 3; g++)
        {
           if(prof[g].getName() != "Undefined")
           {
            cout << "    " << prof[g].getName() << " [" << prof[g].getTotalUses() << "] : " << prof[g].getDescription() << endl;
            print_skills = true;
           }
        }
    }
    }
