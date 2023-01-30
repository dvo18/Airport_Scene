
#include "faro.h"

Faro::Faro() {
    std::vector<Tupla3f> perfil_original;

    float angulo = gradARad(90/6);

    perfil_original.push_back( Tupla3f( origen, origen, origen ) );
    perfil_original.push_back( Tupla3f( 0.1,    origen, origen ) );
    perfil_original.push_back( Tupla3f( 0.1,    1+0.35,   origen ) );
    perfil_original.push_back( Tupla3f( 0.04,   1+0.5,    origen ) );
    perfil_original.push_back( Tupla3f( 0.04,   1+1,      origen ) );
    perfil_original.push_back( Tupla3f( 0.085,  1+1.1,    origen ) );
    perfil_original.push_back( Tupla3f( 0.085,  1+1.15,   origen ) );
    perfil_original.push_back( Tupla3f( 0.085*cos(angulo),      1+1.15+(0.085*sin(angulo)),     origen ) );
    perfil_original.push_back( Tupla3f( 0.085*cos(2*angulo),    1+1.15+(0.085*sin(2*angulo)),   origen ) );
    perfil_original.push_back( Tupla3f( 0.085*cos(3*angulo),    1+1.15+(0.085*sin(3*angulo)),   origen ) );
    perfil_original.push_back( Tupla3f( 0.085*cos(4*angulo),    1+1.15+(0.085*sin(4*angulo)),   origen ) );
    perfil_original.push_back( Tupla3f( 0.085*cos(5*angulo),    1+1.15+(0.085*sin(5*angulo)),   origen ) );
    perfil_original.push_back( Tupla3f( origen,                 1+1.15+0.085,                   origen ) );

    crearMalla( perfil_original, 15 );
}