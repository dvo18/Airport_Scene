
#ifndef C1_H_INCLUDED
#define C1_H_INCLUDED

#include "objcompuesto.h"
#include "auxiliar.h"

#include "c2.h"
#include "cilindro.h"
#include "cintacorredera.h"


class C1 : public ObjCompuesto
{
    private:
    float anadido;
    float largoCinta;

    float angulo;
    float MAXangulo;

    float incrementoLargo;
    float MAXincrementoLargo;
    
    C2 * c2 = nullptr;
    Cilindro * cilindro = nullptr;
    CintaCorredera * cc = nullptr;

    void drawPiston();


    public:
    C1( float add, float MAXang, float MAXincrementoL, float largo = 1.25 );

    void setAngulo( float nuevoAngulo );

    void variarIncrementoLargo( float incremento );
    float getIncrementoLargo();

    bool tieneTextura();

    void draw();
};

#endif