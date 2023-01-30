
#include "auxiliar.h"
#include "luz.h"
#include "luzdireccional.h"


LuzDireccional::LuzDireccional( GLenum idLuzOpenGL )
{
    id = idLuzOpenGL;

    defecto = true;
}

LuzDireccional::LuzDireccional( Tupla2f direccion, GLenum idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso )
{
    id = idLuzOpenGL;

    alpha = direccion[0];
    beta = direccion[1];

    calcularPosicion();

    setColor( colorAmbiente, colorEspecular, colorDifuso );
}

void LuzDireccional::variarAnguloAlpha( float incremento )
{
    alpha += incremento;
    calcularPosicion();

}

void LuzDireccional::variarAnguloBeta( float incremento )
{
    beta += incremento;
    calcularPosicion();
}

void LuzDireccional::resetAngulos()
{
    alpha = 0;
    beta = 0;

    calcularPosicion();
}

void LuzDireccional::calcularPosicion()
{
    setPosicion( Tupla4f( sin(alpha)*cos(beta), sin(alpha)*sin(beta), cos( alpha ), 0 ) );
}

float LuzDireccional::getAnguloAlpha()
{
    return alpha;
}

float LuzDireccional::getAnguloBeta()
{
    return beta;
}