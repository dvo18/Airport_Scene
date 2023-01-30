// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "auxiliar.h"
#include "material.h"
#include "textura.h"

#include <algorithm>

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Malla3D
{
   public:

   // constructor
   Malla3D();
   // constructor de copia
   Malla3D( const Malla3D & malla );
   

   // función que dibuja el objeto en modo diferido (usando VBOs)
   void draw() ;


   // funcion para crear los buffers
   GLuint CrearVBO( GLuint tipo_vbo, GLuint tam, GLvoid * puntero_ram ) ;


   // función para situar las coordenadas de un polígono en el plano XZ del espacio
   /**
    * minimo: posición en el vector de coordenadas en la que enpieza a añadir cada una
    * maximo: última posción en el vector en la que añade coordenadas
   */
   void rotacionesPlanoXZ( int maximo, int numSegmentos, float r, float h, float anguloComienzo ) ;

   // funcion que establece el color según el modo de visualización
   void setColor( Tupla3f colorP, Tupla3f colorL, Tupla3f colorS ) ;
   TuplaG3<Tupla3f> getColor();

   //
   void rellenarColor( std::vector<Tupla3f> & tablaColor, Tupla3f color ) ;


   // funcion para transformar radianes a grados
   double radAGrad ( double radianes ) ;
   // funcion para transformar grados a radianes
   double gradARad ( double grados ) ;


   //
   void calcularNormales() ;
   //
   void asignarNormal( Tupla3i cara, Tupla3f normal );

   //
   void setTextura( Textura * t );

   bool tieneTextura();

   //
   void setRepetirTextura( bool repetir );

   //
   void setPolygonMode( GLenum mode );

   //
   void setMaterial( Material * m );

   //
   void setID( GLint id );

   //
   GLint getID();


   private:

   GLuint id_vbo_ver, id_vbo_tri, id_vbo_col, id_vbo_colP, id_vbo_colL, id_vbo_colS, id_vbo_nor, id_vbo_tex;
   
   Textura * textura = nullptr;

   bool repetirTextura;

   Material * material = nullptr;

   GLenum polygonMode;

   GLint id;


   protected:

   float origen = 0.0f ;

   std::vector<Tupla3f> v ; // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo

   std::vector<Tupla3f> cP ; // tabla de rgb para los colores para modo puntos
   std::vector<Tupla3f> cL ; // tabla de rgb para los colores para modo lineas
   std::vector<Tupla3f> cS ; // tabla de rgb para los colores para modo solido

   std::vector<Tupla3f> nv ;
   std::vector<Tupla2f> ct ;
} ;


#endif
