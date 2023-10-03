//Michael Dominguez

#include "department.hpp"

using namespace std;
  
MLDepartment::MLDepartment(vector <Profemon> profemons)
 {
    for(int g = 0; g < profemons.size(); g++)
    {
        if (profemons[g].getSpecialty() == 0)
        {
            addProfemon(profemons[g]);
        }
    }
 }
 
 bool MLDepartment::addProfemon(Profemon profemon)
 {
    if (contains(profemon.getName()) || profemon.getSpecialty() != 0)
    {
        return false;
    }

    Trainer::addProfemon(profemon);
    return true;

 }
//--------------------------------------------------------------------------------

 SoftwareDepartment::SoftwareDepartment(vector <Profemon> profemons)
 {
    for(int g = 0; g < profemons.size(); g++)
    {
        if (profemons[g].getSpecialty() == 1)
        {
            addProfemon(profemons[g]);
        }
    }
 }
 
 bool SoftwareDepartment::addProfemon(Profemon profemon)
 {
    if (contains(profemon.getName()) || profemon.getSpecialty() != 1)
    {
        return false;
    }
    
    Trainer::addProfemon(profemon);
    return true;
 }
//--------------------------------------------------------------------------------

 HardwareDepartment::HardwareDepartment(vector <Profemon> profemons)
 {
    for(int g = 0; g < profemons.size(); g++)
    {
        if (profemons[g].getSpecialty() == 2)
        {
            addProfemon(profemons[g]);
        }
    }
 }
 
 bool HardwareDepartment::addProfemon(Profemon profemon)
 {
    if (contains(profemon.getName()) || profemon.getSpecialty() != 2)
    {
        return false;
    }
    
    Trainer::addProfemon(profemon);
    return true;
 }