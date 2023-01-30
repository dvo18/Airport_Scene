#ifndef C2_H_INCLUDED
#define C2_H_INCLUDED

#include "objcompuesto.h"
#include "auxiliar.h"

#include "cubo.h"
//#include "cilindro.h"
#include "cintacorredera.h"


class C2 : public ObjCompuesto
{
    private:
    float anadido;
    float largoCinta;
    
    Cubo * cubo = nullptr;
    CintaCorredera * cc = nullptr;


    public:
    C2( float add, float largo = 1.25 );

    bool tieneTextura();

    void draw();
};

#endif