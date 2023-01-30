
#ifndef LUZ_H_INCLUDED
#define LUZ_H_INCLUDED

#include "auxiliar.h"

class Luz
{
    protected:

    bool defecto;

    GLenum id;

    Tupla4f posicion;
    Tupla4f colorDifuso;
    Tupla4f colorAmbiente;
    Tupla4f colorEspecular;


    public:

    Luz();
    void activar();
    void desactivar();
    GLenum getId();

    void definir();

    void setColor( Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso );
    
    void setPosicion( Tupla4f nPosicion );
};


#endif
