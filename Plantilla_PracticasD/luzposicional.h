
#ifndef LUZPOSICIONAL_H_INCLUDED
#define LUZPOSICIONAL_H_INCLUDED

#include "auxiliar.h"


class LuzPosicional : public Luz
{
    public :

    LuzPosicional ( GLenum idLuzOpenGL ) ;

    LuzPosicional ( Tupla3f posicion, GLenum idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso ) ;
};


#endif
