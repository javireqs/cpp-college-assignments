/* 
Javier Hernandez Requena
July 29, 2022
CS 110 B - C++ Programming Fundamentals
Assignement 6 - Secret Message
This program includes a class of private data for one Exoplanet with specified data types
*/

#include <iostream>
#include <string>

using namespace std;

class Exoplanet
{
    private:
        string name;
        double lightyearsAway;
        double planetMass;
        double stellarMag;
        int discoveryDate;

    public:
        Exoplanet(string name, double lightyearsAway, double planetMass, double stellarMag, int discoveryDate)
        {
            this->name = name;
            this->lightyearsAway = lightyearsAway;
            this->planetMass = planetMass;
            this->stellarMag = stellarMag;
            this->discoveryDate = discoveryDate;
        }
    // Accessors
        string getName();
        double getLightyearsAway();
        double getPlanetMass();
        double getStellarMag();
        int getDiscoveryDate();
    // Mutators
        void setName(string);
        void setLightyearsAway(double);
        void setPlanetMass(double);
        void setStellarMag(double);
        void setDiscoveryDate(int);
};

// get methods (accessors)
string Exoplanet::getName()
{
    return name;
}
double Exoplanet::getLightyearsAway()
{
    return lightyearsAway;
}
double Exoplanet::getPlanetMass()
{
    return planetMass;
}
double Exoplanet::getStellarMag()
{
    return stellarMag;
}
int Exoplanet::getDiscoveryDate()
{
    return discoveryDate;
}

// set methods (mutators)
void Exoplanet::setName(string newName)
{
    name = newName;
}
void Exoplanet::setLightyearsAway(double newLightyear)
{
    lightyearsAway = newLightyear;
}
void Exoplanet::setPlanetMass(double newMass)
{
    planetMass = newMass;
}
void Exoplanet::setStellarMag(double newStellar)
{
    stellarMag = newStellar;
}
void Exoplanet::setDiscoveryDate(int newDate)
{
    discoveryDate = newDate;
}

int main()
{
    Exoplanet Comae("11 Comae Berenices b", 304, 19.4, 4.72307, 2007);
    Exoplanet Ursae("11 Ursae Minoris b", 409, 14.74, 5.013, 2009);
    Exoplanet Andromedae("14 Andromedae b", 246, 4.8, 5.23133, 2008);
    Exoplanet Herculis("14 Herculis b", 58, 4.66, 6.61935, 2002);
    Exoplanet Cygni("16 Cygni B b", 69, 1.78, 6.215, 1996);

    vector<Exoplanet> planet;
    vector<Exoplanet>::iterator iter;
    planet.push_back(Comae);
    planet.push_back(Ursae);
    planet.push_back(Andromedae);
    planet.push_back(Herculis);
    planet.push_back(Cygni);

    for (iter = planet.begin(); iter != planet.end(); iter++)
    {
        Exoplanet& exo = *iter;
        exo.getName();
        exo.getLightyearsAway();
        exo.getPlanetMass();
        exo.getStellarMag();
        exo.getDiscoveryDate();
    }

    planet.pop_back();

    for(iter = planet.begin(); iter != planet.end(); iter++)
    {
        Exoplanet& exo = *iter;
        exo.getName();
        exo.getLightyearsAway();
        exo.getPlanetMass();
        exo.getStellarMag();
        exo.getDiscoveryDate();
    }
    
    return 0;
}