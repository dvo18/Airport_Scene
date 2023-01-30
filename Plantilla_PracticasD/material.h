
#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include "auxiliar.h"


class Material
{
    private:

    float brillo;

    Tupla4f difusa;
    Tupla4f especular;
    Tupla4f ambiental;


    public:

    Material();

    Material( const Material & material );

    Material( Tupla4f mdifuso, Tupla4f mespecular, Tupla4f mambiente, float mbrillo );

    void aplicar();
}; 


#endif