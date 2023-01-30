
#include "faroseguridad.h"

FaroSeguridad::FaroSeguridad()
{
    faro = new Faro();
}

void FaroSeguridad::draw()
{
    faro->setMaterial( material );
    faro->setPolygonMode( polygonMode );

    glPushMatrix();

        faro->draw();

        

    glPopMatrix();
}