#include "auxiliar.h"
#include "ply_reader.h"
#include "objrevolucion.h"

#include <iomanip>


// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion( const std::string & archivo, int num_instancias, bool reverse ) {
   std::vector<Tupla3f> perfil_original;

   ply::read_vertices( archivo, perfil_original );

   crearMalla( perfil_original, num_instancias, reverse );
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion( std::vector<Tupla3f> archivo, int num_instancias, bool reverse ) {
   crearMalla( archivo, num_instancias, reverse );
}

void ObjRevolucion::crearMalla( const std::vector<Tupla3f> & perfil_original, int num_instancias_perf, bool reverse ) {
   std::vector<Tupla3f> perfil_copia(perfil_original);

   int M = perfil_copia.size();
   int N = num_instancias_perf;

   int vComienzo = 0, vFinal = 0;

   if( perfil_copia[0][1] > perfil_copia[M-1][1] ) std::reverse( perfil_copia.begin(), perfil_copia.end() );

   if( reverse ) std::reverse( perfil_copia.begin(), perfil_copia.end() );


   // Vértices
   for( int i=0; i<M; i++ )
      if( enOrigen( perfil_copia, i ) and ( i==0 or i==perfil_copia.size()-1 ) ) {
         v.push_back( Tupla3f( perfil_copia[i][0], perfil_copia[i][1], perfil_copia[i][2] ) );

         if( perfil_copia[i][1] == 0 ) vComienzo = 1;
         else vFinal = 1;
      }
      else
         rotacionesPlanoXZ( N+1, N, perfil_copia[i][0], perfil_copia[i][1], 0 );

   
   // Caras laterales
   for ( int i=vComienzo; i<v.size()-(vFinal+N+1); i++ ) {
      int a = i;
      int b = a+1;

      //if( (b-vComienzo) % N == 0 ) b -= N;

      f.push_back( Tupla3i( a, b, b+N+1 ) );
      f.push_back( Tupla3i( a, b+N+1, a+N+1 ) );
   }


   // Bases
   for( int i=0; i<N; i++) {
      if( vComienzo == 1 ) {
         int pos = i + 2;
         //if( (pos-vComienzo) % N == 0 ) pos = 1;

         f.push_back( Tupla3i( 0, pos, i+1 ) );
      }

      if( vFinal == 1 ) {
         int pos = v.size() - (vFinal+N+1);

         int fin = pos + i + 1;
         //if( (fin-vComienzo) % N == 0 ) fin = pos;

         f.push_back( Tupla3i( v.size()-1, pos+i, fin ) );
      }
   }

   setColor( Tupla3f( 1, 0, 0 ), Tupla3f( 0, 1, 0 ), Tupla3f( 0, 0, 1 ) );

   for( int i=M-1; i>=0; i-- )
      if( vComienzo == 1 and i == M-1 )
         ct.push_back( Tupla2f( 0.5, 1 ) );
      else if( vFinal == 1 and i == 0 )
         ct.push_back( Tupla2f( 0.5, 0 ) );
      else
         for( int j=0; j<N+1; j++ )
            ct.push_back( Tupla2f( float(j)/N, float(i)/(M-1) ) );

   
   calcularNormales();
   
}


bool ObjRevolucion::enOrigen( const std::vector<Tupla3f> & perfil_original, int i ) {
   return ( abs(perfil_original[i][0]) >= origen and abs(perfil_original[i][0]) < 0.01 ) and ( abs(perfil_original[i][2]) >= origen and abs(perfil_original[i][2]) < 0.01 );
}