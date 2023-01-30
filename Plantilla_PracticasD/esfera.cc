#include "objrevolucion.h"
#include "auxiliar.h"
#include "esfera.h"


Esfera::Esfera( const int num_vert_perfil, const int num_instancias_perf, const float radio, bool reverse ) {
     std::vector<Tupla3f> perfil_original;


    for( int i=0; i<num_vert_perfil; i++ )
        perfil_original.push_back( calcularCoordenadas( i, radio, 3*M_PI/2, M_PI/(num_vert_perfil-1) ) );
        

    crearMalla( perfil_original, num_instancias_perf, reverse );
}


Tupla3f Esfera::calcularCoordenadas( int i, float radio, float anguloComienzo, float segmento ) {
    float angulo = anguloComienzo + i*segmento;
    return Tupla3f( radio*(float)cos(angulo), radio*(float)sin(angulo)+radio, origen );
}