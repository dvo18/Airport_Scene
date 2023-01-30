
#ifndef EJESFLECHA_H_INCLUDED
#define EJESFLECHA_H_INCLUDED

#include "objcompuesto.h"
#include "auxiliar.h"

#include "flecha.h"


class EjesFlecha : public ObjCompuesto
{
    private:
    Flecha * flecha;
    Material *rojo, *verde, *azul;

    public:
    EjesFlecha();

    void draw();
} ;


#endif