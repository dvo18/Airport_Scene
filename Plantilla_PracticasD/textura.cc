
#include "textura.h"


Textura::Textura( std::string archivo )
{
    // declara puntero a imagen (pimg)
    jpg::Imagen * pimg = NULL;

    // cargar la imagen
    pimg = new jpg::Imagen( archivo );

    ancho = pimg->tamX();           // num. columnas
    alto = pimg->tamY();            // num. filas
    texels = pimg->leerPixels();    // puntero texels

    glGenTextures( 1, &textura_id );
}

void Textura::activar( bool repetir )
{
    glBindTexture( GL_TEXTURE_2D, this->textura_id );

    glLightModeli( GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR );

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    if( repetir ) {
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    }

    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, ancho, alto, GL_RGB, GL_UNSIGNED_BYTE, texels );
}