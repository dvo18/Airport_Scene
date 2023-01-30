
#include "objrevolucion.h"
#include "auxiliar.h"
#include "flecha.h"


Flecha::Flecha( const float hPunta, const float hAstil, const int nRev ) // he cambiado el float por un entero para las revoluciones
{
    std::vector<Tupla3f> perfil_original;

    int num_vert_perfil = 5;

    int radio_cono = hPunta / 3;
    int radio_cilindro = radio_cono / 4;


    // generacion de los vertices del perfil para el cilindro

    perfil_original.push_back( Tupla3f( origen, origen, origen ) );

    for( int i=0; i<num_vert_perfil-2; i++ )
        perfil_original.push_back( Tupla3f( radio_cilindro, (hAstil/(num_vert_perfil-3))*i, origen ) );
    
    //perfil_original.push_back( Tupla3f( origen, hAstil, origen ) );


    // generacion de los vertices del perfil para el cono
    //perfil_original.push_back( Tupla3f( origen, origen, origen ) );

    for( int i=0; i<num_vert_perfil-2; i++ )
        perfil_original.push_back( Tupla3f( radio_cono-((radio_cono/(num_vert_perfil-2)))*i, hAstil+((hPunta/(num_vert_perfil-2))*i), origen ) );
        
    perfil_original.push_back( Tupla3f( origen, hAstil+hPunta, origen ) );


    // generar la malla de vértices para la firgura
    crearMalla( perfil_original, nRev );
}