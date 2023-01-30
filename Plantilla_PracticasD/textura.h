
#ifndef TEXTURA_H_INCLUDED
#define TEXTURA_H_INCLUDED

#include "auxiliar.h"
#include "jpg_imagen.hpp"


class Textura {
    private:

    unsigned char * texels = nullptr;

    //std::vector<unsigned char> texels;

    GLuint textura_id = 0;

    int ancho, alto;


    public:
    
    Textura( std::string archivo );

    void activar( bool repetir = false );
}; 


#endif