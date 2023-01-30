// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Esfera.h

//
// #############################################################################

#ifndef ESFERA_H_INCLUDED
#define ESFERA_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"


class Esfera : public ObjRevolucion
{
    public :
    Esfera( const int num_vert_perfil, const int num_instancias_perf, const float radio, bool reverse = false );

    Tupla3f calcularCoordenadas( int i, float radio, float anguloComienzo, float segmento );
} ;


#endif