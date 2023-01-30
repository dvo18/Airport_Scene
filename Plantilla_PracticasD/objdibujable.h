#ifndef OBJDIBUJABLE_H_INCLUDED
#define OBJDIBUJABLE_H_INCLUDED

#include "auxiliar.h"
#include "material.h"
#include "textura.h"

#include <algorithm>

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class ObjDibujable
{
    public:

    ObjDibujable();

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
};

#endif