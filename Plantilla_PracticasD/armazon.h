
#ifndef ARMAZON_H_INCLUDED
#define ARMAZON_H_INCLUDED

#include "objcompuesto.h"
#include "auxiliar.h"

#include "c1.h"
#include "cubo.h"
#include "faro.h"
#include "cintacorredera.h"


class Armazon : public ObjCompuesto
{
    private:
    const float anadido = 0.1075;         // 0.1075 es para que el final de la cinta caiga justo a la derecha de la "placa" (cubo)
    float largoCinta;
    float angulo;

    float MAXanguloElevacion;
    float MAXincrementoLargo;

    C1 * c1 = nullptr;
    Cubo * cubo = nullptr;
    Faro * faro = nullptr;
    CintaCorredera * cc = nullptr;

    void drawBase();
    void drawEstructura();


    public:
    Armazon( float largo = 2.5 );

    void variarAnguloElevacion( float incremento );
    float getAnguloElevacion();

    void variarIncrementoLargo( float incremento );
    float getIncrementoLargo();

    float getMAXincrementoLargo();
    float getMAXanguloElevacion();

    bool tieneTextura();

    void draw();
};

#endif