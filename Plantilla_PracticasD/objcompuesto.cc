
#include "objcompuesto.h"


ObjCompuesto::ObjCompuesto() {
    material = nullptr;
    polygonMode = GL_NONE;
}

ObjCompuesto::ObjCompuesto( const ObjCompuesto & objCompuesto ) {
    material = objCompuesto.material;
    polygonMode = objCompuesto.polygonMode;
}


template <class TipoObjeto>
void ObjCompuesto::setDrawMode( TipoObjeto * objeto, Material * m, GLenum mode ) {
    objeto->setMaterial( m );
    objeto->setPolygonMode( mode );
}

double ObjCompuesto::radAGrad( double rad )
{
   return rad * 180 / M_PI;
}

double ObjCompuesto::gradARad( double grados )
{
   return grados * M_PI / 180;
}


void ObjCompuesto::setPolygonMode( GLenum mode )
{
   polygonMode = mode;
}

void ObjCompuesto::setMaterial( Material * m )
{
   material = m;
}

void ObjCompuesto::setID( GLint i )
{
   id = i;
}

GLint ObjCompuesto::getID()
{
   return id;
}