
#include "ejesflechas.h"


EjesFlecha::EjesFlecha()
{
    flecha = new Flecha(20, 40, 20);

    rojo = new Material( Tupla4f(1,0,0,1), Tupla4f(1,1,1,1), Tupla4f(0,0,0,1), 128 );
    verde = new Material( Tupla4f(0,1,0,1), Tupla4f(1,1,1,1), Tupla4f(0,0,0,1), 128 );
    azul = new Material( Tupla4f(0,0,1,1), Tupla4f(1,1,1,1), Tupla4f(0,0,0,1), 128 );
}


void EjesFlecha::draw()
{
    glPushMatrix();
        glPushMatrix();
            flecha->setPolygonMode( polygonMode );
            flecha->setMaterial( verde );
            flecha->draw();
        glPopMatrix();

        glPushMatrix();
            glRotatef( 90, 1, 0, 0 );
            flecha->setPolygonMode( polygonMode );
            flecha->setMaterial( azul );
            flecha->draw();
        glPopMatrix();

        glPushMatrix();
            glRotatef( -90, 0, 0, 1 );
            flecha->setPolygonMode( polygonMode );
            flecha->setMaterial( rojo );
            flecha->draw();
        glPopMatrix();
    glPopMatrix();
}