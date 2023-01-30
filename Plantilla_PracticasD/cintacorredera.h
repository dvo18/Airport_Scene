
#ifndef CINTACORREDERA_H_INCLUDED
#define CINTACORREDERA_H_INCLUDED

#include "objcompuesto.h"
#include "auxiliar.h"

#include "cubo.h"
#include "cilindro.h"


class CintaCorredera : public ObjCompuesto
{
    private:
    float largoCinta;
    float largoCilindro;

    Cubo * cubo = nullptr;
    Cilindro * cilindro = nullptr;
    

    public:
    CintaCorredera( float lCinta = 1, float lCilindro = 1 );

    bool tieneTextura();

    void draw();
};

#endif