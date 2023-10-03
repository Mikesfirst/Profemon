//MICHAEL DOMINGUEZ

#ifndef TRAINER_HPP
#define TRAINER_HPP
#include "profemon.hpp"
#include <iostream>
#include <string>
#include <vector>

class Trainer
{
    private:
         std::vector <Profemon> profedéx; 
         Profemon team[3];
         Profemon* currProf; 

    public: 
         Trainer();
         Trainer(std::vector <Profemon> profemons);
         bool contains(std::string name);
         bool addProfemon(Profemon profemon);
         bool removeProfemon(std::string name);
         void setTeamMember(int slot, std::string name);
         bool chooseProfemon(int slot);
         Profemon getCurrent();
         void printProfedex();
         void printTeam();
};








#endif