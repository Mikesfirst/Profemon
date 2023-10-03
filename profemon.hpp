//MICHAEL DOMINGUEZ

#ifndef PROFEMON_HPP
#define PROFEMON_HPP
#include "skill.hpp"
#include <iostream>
#include <string>
#include <vector>



enum Specialty {ML, SOFTWARE, HARDWARE};

class Profemon {
    private: 
        std::string name;
        int level;
        int to_levelUp;
        int currentEXP;
        double max_health;
        Specialty specialty;
        Skill prof[3];
        //int learned = 0;

    public:
        Profemon();
        Profemon(std::string name, double max_health, Specialty specialty);
        std::string getName();
        Specialty getSpecialty();
        int getLevel();
        double getMaxHealth();
        void setName(std::string name);
        void levelUp(int exp);
        bool learnSkill(int slot, Skill skill);
        void printProfemon(bool print_skills);
};

#endif