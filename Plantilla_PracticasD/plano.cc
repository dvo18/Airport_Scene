
#include "plano.h"

/*
    tamLado: tamaño del lado del cuadrado (centrado en el origen) que representa el plano
    giroVertical: será el ángulo en grados que girará el "plano virtual" respecto el eje X
    giroHorizontal: será el ángulo en grados que girará el "plano virtual" repecto el eje Y
*/
Plano::Plano( float tamLado, bool repetirTextura )
{
    float tam = tamLado / 2;

    /*
        V2-----V3
        |      |
        |      |
        V0-----V1
    */
    v.push_back( Tupla3f(   -tam,   -tam,    0) );
    v.push_back( Tupla3f(   tam,    -tam,    0) );
    v.push_back( Tupla3f(   -tam,    tam,   0) );
    v.push_back( Tupla3f(   tam,   tam,   0) );

    f.push_back( Tupla3i( 0, 3, 2 ) );
    f.push_back( Tupla3i( 0, 1, 3 ) );

    setColor( Tupla3f( 1, 0, 0 ), Tupla3f( 0, 1, 0 ), Tupla3f( 0, 0, 1 ) );

    calcularNormales();

    ct.resize( v.size() );

    if( repetirTextura ) {
        ct[0] = Tupla2f( 0, tamLado/300 );
        ct[1] = Tupla2f( tamLado/300, tamLado/300 );
        ct[2] = Tupla2f( 0, 0 );
        ct[3] = Tupla2f( tamLado/300, 0 );
    }
    else {
        ct[0] = Tupla2f( 0, 1 );
        ct[1] = Tupla2f( 1, 1 );
        ct[2] = Tupla2f( 0, 0 );
        ct[3] = Tupla2f( 1, 0 );
    }
}