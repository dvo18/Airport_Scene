
#include "cintacorredera.h"

CintaCorredera::CintaCorredera( float lCinta, float lCilindro )
{
    largoCinta = lCinta;
    largoCilindro = lCilindro;
    
    cubo = new Cubo();
    cilindro = new Cilindro( 5, 10, 1, 0.5 );    
}

bool CintaCorredera::tieneTextura()
{
    return cilindro->tieneTextura() and cubo->tieneTextura();
}

void CintaCorredera::draw()
{
    //setDrawMode( cubo, material, polygonMode );
    //setDrawMode( cilindro, material, polygonMode );

    cubo->setMaterial(material);
    cubo->setPolygonMode(polygonMode);
    cilindro->setMaterial(material);
    cilindro->setPolygonMode(polygonMode);

    glPushMatrix();

        glPushMatrix();
            glTranslatef( -largoCinta/2, 0, largoCilindro/2 );
            glRotatef( -90, 1, 0, 0 );
            glScalef( 0.2, largoCilindro, 0.2 );
            cilindro->draw();
        glPopMatrix();

        glPushMatrix();
            glTranslatef( largoCinta/2, 0, largoCilindro/2 );
            glRotatef( -90, 1, 0, 0 );
            glScalef( 0.2, largoCilindro, 0.2 );
            cilindro->draw();
        glPopMatrix();

        glPushMatrix();
            glTranslatef( 0, -0.1, 0 );
            glScalef( largoCinta, 0.2, 0.925 );
            cubo->draw();
        glPopMatrix(); 
           
    glPopMatrix();
}