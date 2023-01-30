
#ifndef CINTAMALETAS_H_INCLUDED
#define CINTAMALETAS_H_INCLUDED

#include "objcompuesto.h"
#include "auxiliar.h"

#include "cubo.h"
#include "armazon.h"
#include "cilindro.h"
#include "piramidepentagonal.h"


class CintaMaletas : public ObjCompuesto
{
    private:
    float angulo;
    float MAXanguloGiro = 60;
    float MINanguloGiro = -60;

    Cubo * cubo = nullptr;
    Armazon * armazon = nullptr;
    Cilindro * cilindro = nullptr;
    PiramidePentagonal * piramide = nullptr;


    public:
    CintaMaletas( float largo = 2.5 );

    void variarAnguloGiro( float incremento );
    float getAnguloGiro();

    void variarAnguloElevacion( float incremento );
    float getAnguloElevacion();

    void variarIncrementoLargo( float incremento );
    float getIncrementoLargo();

    float getMAXanguloGiro();
    float getMINanguloGiro();
    float getMAXincrementoLargo();
    float getMAXanguloElevacion();

    bool tieneTextura();

    void draw();
};

#endif