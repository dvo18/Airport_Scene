
#ifndef OBJCOMPUESTO_H_INCLUDED
#define OBJCOMPUESTO_H_INCLUDED

#include "auxiliar.h"
#include "material.h"
#include "textura.h"

#include <algorithm>

class ObjCompuesto
{
   public:

   // constructor
   ObjCompuesto();
   // constructor de copia
   ObjCompuesto( const ObjCompuesto & objCompuesto );
   
   
   // 
   template <class TipoObjeto>
   void setDrawMode( TipoObjeto * objeto, Material * m, GLenum mode );


   // funcion para transformar radianes a grados
   double radAGrad ( double radianes ) ;
   // funcion para transformar grados a radianes
   double gradARad ( double grados ) ;

   //
   void setPolygonMode( GLenum mode );

   //
   void setMaterial( Material * m );

   //
   void setID( GLint id );

   //
   GLint getID();


   protected:

   Material * material = nullptr;

   GLenum polygonMode;

   GLint id;
} ;


#endif