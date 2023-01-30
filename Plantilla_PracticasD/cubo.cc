#include "auxiliar.h"
#include "malla.h"
#include "cubo.h"

Cubo::Cubo(float lado)
{
   float l = lado / 2;

   v.push_back( Tupla3f( l, 0, l ) );
   v.push_back( Tupla3f( l, 0, -l ) );
   v.push_back( Tupla3f( -l, 0, -l ) );
   v.push_back( Tupla3f( -l, 0, l ) );
   v.push_back( Tupla3f( l, lado, l ) );
   v.push_back( Tupla3f( l, lado, -l ) );
   v.push_back( Tupla3f( -l, lado, -l ) );
   v.push_back( Tupla3f( -l, lado, l ) );


   // inicializar la tabla de caras o triángulos:
   f.push_back(Tupla3i( 0, 5, 4 ));
   f.push_back(Tupla3i( 0, 1, 5 ));
   f.push_back(Tupla3i( 0, 4, 7 ));
   f.push_back(Tupla3i( 0, 7, 3 ));
   f.push_back(Tupla3i( 3, 7, 6 ));
   f.push_back(Tupla3i( 3, 6, 2 ));
   f.push_back(Tupla3i( 2, 6, 5 ));
   f.push_back(Tupla3i( 2, 5, 1 ));
   f.push_back(Tupla3i( 0, 3, 2 ));
   f.push_back(Tupla3i( 0, 2, 1 ));
   f.push_back(Tupla3i( 7, 4, 5 ));
   f.push_back(Tupla3i( 7, 5, 6 ));


   //
   setColor( Tupla3f( 1, 0, 0 ), Tupla3f( 0, 1, 0 ), Tupla3f( 0, 0, 1 ) );

   /*rellenarColor( cP, Tupla3f( 1, 0, 0 ) );
   rellenarColor( cL, Tupla3f( 0, 1, 0 ) );

   cS.resize( v.size() );

   cS[0] = Tupla3f( 0, 1, 0 );
   cS[1] = Tupla3f( 0, 0, 0 );
   cS[2] = Tupla3f( 1, 0, 0 );
   cS[3] = Tupla3f( 1, 1, 0 );
   cS[4] = Tupla3f( 0, 1, 1 );
   cS[5] = Tupla3f( 0, 0, 1 );
   cS[6] = Tupla3f( 1, 0, 0 );
   cS[7] = Tupla3f( 1, 1, 1 );*/

   
   calcularNormales();
}
