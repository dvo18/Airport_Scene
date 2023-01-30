
#ifndef LUZDIRECCIONAL_H_INCLUDED
#define LUZDIRECCIONAL_H_INCLUDED

#include "auxiliar.h"


class LuzDireccional : public Luz
{
    protected :

    float alpha ;
    float beta ;


    public :

    LuzDireccional ( GLenum idLuzOpenGL ) ;
    
    // inicializar la fuente de luz
    LuzDireccional ( Tupla2f direccion, GLenum idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso ) ;

    // Cambiar ángulo:
    void variarAnguloAlpha ( float incremento ) ;
    void variarAnguloBeta ( float incremento ) ;

    float getAnguloAlpha();
    float getAnguloBeta();

    //
    void resetAngulos() ;

    //
    void calcularPosicion() ;
};


#endif
