
#include "objdibujable.h"

ObjDibujable::ObjDibujable() {}

void ObjDibujable::setPolygonMode( GLenum mode )
{
   polygonMode = mode;
}

void ObjDibujable::setMaterial( Material * m )
{
   material = m;
}

void ObjDibujable::setID( GLint i )
{
   id = i;
}

GLint ObjDibujable::getID()
{
   return id;
}