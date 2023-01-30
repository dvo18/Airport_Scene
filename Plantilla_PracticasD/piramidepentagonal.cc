#include "auxiliar.h"
#include "malla.h"
#include "piramidepentagonal.h"

using namespace std;

PiramidePentagonal::PiramidePentagonal(float h, float r)
{
   // inicializar la tabla de vértices
   v.push_back( Tupla3f( origen, h, origen ) );
   rotacionesPlanoXZ( 5, 5, r, origen, M_PI/2 );


   // inicializar la tabla de caras o triángulos:
   f.push_back(Tupla3i( 1, 5, 4 ));
   f.push_back(Tupla3i( 1, 4, 2 ));
   f.push_back(Tupla3i( 2, 4, 3 ));
   f.push_back(Tupla3i( 0, 1, 2 ));
   f.push_back(Tupla3i( 0, 2, 3 ));
   f.push_back(Tupla3i( 0, 3, 4 ));
   f.push_back(Tupla3i( 0, 4, 5 ));
   f.push_back(Tupla3i( 0, 5, 1 ));

   cout << endl << "Tam: " << v.size() << endl;
   //
   setColor( Tupla3f( 1, 0, 0 ), Tupla3f( 0, 1, 0 ), Tupla3f( 0, 0, 1 ) );

   calcularNormales();
}

