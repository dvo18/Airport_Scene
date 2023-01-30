
#include "c2.h"

C2::C2( float add, float largo )
{
    anadido = add;
    largoCinta = largo;

    cubo = new Cubo();
    cc = new CintaCorredera( largoCinta, 1 );
}

bool C2::tieneTextura()
{
    return cubo->tieneTextura() and cc->tieneTextura();
}

void C2::draw()
{
    cc->setMaterial( material );
    cc->setPolygonMode( polygonMode );
    cubo->setMaterial( material );
    cubo->setPolygonMode( polygonMode );

    glPushMatrix();

        glTranslatef(-(2*anadido+anadido/2+0.01),0,0);

        glPushMatrix();
            glTranslatef(-largoCinta/2,-2*anadido,0);
            cc->draw();
        glPopMatrix();

        glPushMatrix();

            glTranslatef(0,0,-0.55);

            glPushMatrix();
                glTranslatef(0,-0.055,0.1);
                glScalef(0.11,0.11,0.1);
                cubo->draw();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.11,-anadido,0);
                glRotatef(-90,0,0,1);
                glScalef(0.43,0.22,0.1);
                cubo->draw();
            glPopMatrix();
        
        glPopMatrix();

        glPushMatrix();

            glTranslatef(0,0,0.55);

            glPushMatrix();
                glTranslatef(0,-0.055,-0.1);
                glScalef(0.11,0.11,0.1);
                cubo->draw();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.11,-anadido,0);
                glRotatef(-90,0,0,1);
                glScalef(0.43,0.22,0.1);
                cubo->draw();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}