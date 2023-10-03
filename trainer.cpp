//Michael Dominguez


#include "trainer.hpp"

Trainer::Trainer(){
    currProf = nullptr;
}

Trainer::Trainer(std::vector<Profemon> profemons) {
    for (int g = 0; g < profemons.size(); g++) {
        if (g < 3) {
            if (team[g].getName() == "Undefined") 
            {
                team[g] = profemons[g];
            } 
            else {
                profedéx.push_back(profemons[g]);
            }
        } 
        else 
        {
            profedéx.push_back(profemons[g]);
        }
    }
    currProf = &team[0];
}

bool Trainer::contains(std::string name){
    for (int g = 0; g < 3; g++)
    {
         if(team[g].getName() == name)
         {
            return true;
         }
    }
    
    for (int g = 0; g < profedéx.size(); g++)
    {
        if (profedéx[g].getName() == name)
        {
            return true;
        }
    }
    return false;
}

bool Trainer::addProfemon(Profemon profemon)
{
    if (contains(profemon.getName()))
    {
        return false;
    }
   
    for (int g = 0; g < 3; g++)
    {
     if (team[g].getName() == "Undefined")
        {
            team[g] = profemon;
            return true;
        }
    }

    profedéx.push_back(profemon);
    return true;
}

bool Trainer::removeProfemon(std::string name)
{
    for (int g = 0; g < 3; g++)
    {
        if (team[g].getName() == name)
        {
            Profemon undef = Profemon();
            team[g] = undef;
            return true;
        }
    }
    for (int g = 0; g < profedéx.size(); g++)
    {
        if (profedéx[g].getName() == name)
        {
            profedéx.erase(profedéx.begin() + g);
            return true;
        }
    }
    return false;
}

void Trainer::setTeamMember(int slot, std::string name)
{
    if (contains(name) && slot < 3)
    {
        for (int g = 0; g < profedéx.size(); g++)
        {
            if (profedéx[g].getName() == name)
            {
                if (team[slot].getName() == "Undefined")
                {
                    team[slot] = profedéx[g];
                    profedéx.erase(profedéx.begin() + g);
                    return;
                }
                else if (team[slot].getName() != "Undefined")
                {
                    Profemon temp =  team[slot];
                    team[slot] = profedéx[g];
                    profedéx[g] =  temp;
                    return;
                }
            }
        }
    }
}

bool Trainer::chooseProfemon(int slot)
{
    if (team[slot].getName() != "Undefined")
    {
        currProf = team + slot;
        return true;
    }
    return false;
}

Profemon Trainer::getCurrent()
{
    return *currProf; 
}

void Trainer::printProfedex()
{
    for(int g = 0; g < profedéx.size(); g++)
    {
        profedéx[g].printProfemon(false);
        std::cout << std::endl;
    }
}

void Trainer::printTeam()
{
    for(int g = 0; g < 3; g++)
    {
        if (team[g].getName() != "Undefined")
        {
             team[g].printProfemon(true);
            std::cout << std::endl;
        }
    }
}


/*void Trainer::printTeam()
{
    for(int g = 0; g < 3; g++)
    {
        team[g].printProfemon(team[g].getName() != "Undefined");
    }
}
*/


