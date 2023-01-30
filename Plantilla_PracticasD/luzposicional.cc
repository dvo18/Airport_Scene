
#include "auxiliar.h"
#include "luz.h"
#include "luzposicional.h"


LuzPosicional::LuzPosicional( GLenum idLuzOpenGL )
{
    id = idLuzOpenGL;

    defecto = true;
}

LuzPosicional::LuzPosicional( Tupla3f posicion, GLenum idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso )
{
    id = idLuzOpenGL;

    this->posicion[0] = posicion[0];
    this->posicion[1] = posicion[1];
    this->posicion[2] = posicion[2];
    this->posicion[3] = 1;
    
    setColor( colorAmbiente, colorEspecular, colorDifuso );
}