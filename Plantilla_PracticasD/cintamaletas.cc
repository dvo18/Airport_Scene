
#include "cintamaletas.h"

CintaMaletas::CintaMaletas( float largo )
{
    cubo = new Cubo();
    armazon = new Armazon( largo );
    cilindro = new Cilindro( 5, 10, 1, 0.5 );

    angulo = 0;
}


void CintaMaletas::variarAnguloGiro( float incremento )
{
    float nuevoAngulo = angulo + incremento;

    if( nuevoAngulo >= MINanguloGiro and nuevoAngulo <= MAXanguloGiro ) angulo = nuevoAngulo;
    else if( nuevoAngulo >= MAXanguloGiro ) angulo = MAXanguloGiro;
    else angulo = MINanguloGiro;
}

float CintaMaletas::getAnguloGiro()
{
    return angulo;
}


void CintaMaletas::variarAnguloElevacion( float incremento )
{
    armazon->variarAnguloElevacion( incremento );
}

float CintaMaletas::getAnguloElevacion()
{
    return armazon->getAnguloElevacion();
}


void CintaMaletas::variarIncrementoLargo( float incremento )
{
    armazon->variarIncrementoLargo( incremento );
}

float CintaMaletas::getIncrementoLargo()
{
    return armazon->getIncrementoLargo();
}


float CintaMaletas::getMAXanguloGiro()
{
    return MAXanguloGiro;
}

float CintaMaletas::getMINanguloGiro()
{
    return MINanguloGiro;
}

float CintaMaletas::getMAXincrementoLargo()
{
    return armazon->getMAXincrementoLargo();
}

float CintaMaletas::getMAXanguloElevacion()
{
    return armazon->getMAXanguloElevacion();
}

bool CintaMaletas::tieneTextura()
{
    return false;
}


void CintaMaletas::draw()
{
    cubo->setMaterial(material);
    cubo->setPolygonMode(polygonMode);
    armazon->setMaterial(material);
    armazon->setPolygonMode(polygonMode);
    cilindro->setMaterial(material);
    cilindro->setPolygonMode(polygonMode);
    piramide->setMaterial(material);
    piramide->setPolygonMode(polygonMode);

    glPushMatrix();

        glPushMatrix();
            glScalef(2*sqrt(pow(0.7,2)+pow(0.5,2)),0.35,2*sqrt(pow(0.7,2)+pow(0.5,2)));
            cubo->draw();
        glPopMatrix();

        glPushMatrix();

            glRotatef(angulo,0,1,0);

            glPushMatrix();
                glTranslatef(0,0.35,0);
                glScalef(1,0.2,1);
                cilindro->draw();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,0.55,0);
                armazon->draw();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,2,0);
                glScalef(0.2,0.2,0.2);
                piramide->draw();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}