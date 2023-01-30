
#include "auxiliar.h"
#include "luz.h"


Luz::Luz() 
{
    defecto = false;
};

void Luz::activar()
{
    definir();
    
    glEnable( id );
}

void Luz::definir()
{
    if( !defecto ) {
        glLightfv( id, GL_SPECULAR, colorEspecular );
        glLightfv( id, GL_AMBIENT, colorAmbiente );
        glLightfv( id, GL_DIFFUSE, colorDifuso );
        glLightfv( id, GL_POSITION ,posicion );
    }
}

void Luz::desactivar()
{
    glDisable( id );
}

GLenum Luz::getId()
{
    return id;
}

void Luz::setColor( Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso )
{
    if( defecto ) defecto = true;

    this->colorEspecular = colorEspecular;
    this->colorAmbiente = colorAmbiente;
    this->colorDifuso = colorDifuso;

    definir();
}

void Luz::setPosicion( Tupla4f nPosicion )
{
    posicion = nPosicion;

    definir();
}