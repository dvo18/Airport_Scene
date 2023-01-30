#ifndef FAROSEGURIDAD_H_INCLUDED
#define FAROSEGURIDAD_H_INCLUDED

#include "objcompuesto.h"
#include "auxiliar.h"

#include "faro.h"


class FaroSeguridad : public ObjCompuesto
{
    private:

    Faro * faro = nullptr;

    public:
    FaroSeguridad();

    void draw();
};

#endif