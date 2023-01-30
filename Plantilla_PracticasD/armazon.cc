
#include "armazon.h"


Armazon::Armazon( float largo )
{
    angulo = 0;
    largoCinta = largo;

    MAXanguloElevacion = 30;
    MAXincrementoLargo = largoCinta/2 - 2 * ( anadido + 0.11 ) - anadido; 

    cubo = new Cubo();
    faro = new Faro();
    c1 = new C1( anadido, MAXanguloElevacion, MAXincrementoLargo, largoCinta/2 );
    cc = new CintaCorredera( largoCinta );
}

void Armazon::variarAnguloElevacion( float incremento )
{
    float nuevoAngulo = angulo + incremento;

    if( nuevoAngulo >= 0 and nuevoAngulo <= MAXanguloElevacion ) angulo = nuevoAngulo;
    else if( nuevoAngulo >= MAXanguloElevacion ) angulo = MAXanguloElevacion;
    else angulo = 0;

    c1->setAngulo( angulo );
}

float Armazon::getAnguloElevacion()
{
    return angulo;
}

void Armazon::variarIncrementoLargo( float incremento )
{
    c1->variarIncrementoLargo( incremento );
}

float Armazon::getIncrementoLargo()
{
    return c1->getIncrementoLargo();
}

float Armazon::getMAXincrementoLargo()
{
    return MAXincrementoLargo;
}

float Armazon::getMAXanguloElevacion()
{
    return MAXanguloElevacion;
}

bool Armazon::tieneTextura()
{
    return cubo->tieneTextura() and faro->tieneTextura() and c1->tieneTextura() and cc->tieneTextura();
}

void Armazon::draw()
{
    c1->setMaterial(material);
    c1->setPolygonMode(polygonMode);
    cc->setMaterial(material);
    cc->setPolygonMode(polygonMode);
    faro->setMaterial(material);
    faro->setPolygonMode(polygonMode);
    cubo->setMaterial(material);
    cubo->setPolygonMode(polygonMode);

    glPushMatrix();

        drawBase();

        glPushMatrix();
            glTranslatef(0.4,0,-0.6);
            faro->draw();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-(largoCinta/2+0.4),0.9,0);
            cc->draw();
        glPopMatrix();

        drawEstructura();

    glPopMatrix();
}

void Armazon::drawBase()
{
    glPushMatrix();

        glPushMatrix();
            glScalef(1,0.75,1);
            cubo->draw();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.125,0.75,0);
            glScalef(0.75,0.25,1);
            cubo->draw();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(0,0,0.6);
            glScalef(1,1,0.2);
            cubo->draw();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.05,0,-0.6);
            glScalef(0.9,1,0.2);
            cubo->draw();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(0.45,0,-0.55);
            glScalef(0.1,1,0.1);
            cubo->draw();
        glPopMatrix();

    glPopMatrix();
}

void Armazon::drawEstructura()
{
    float largo = largoCinta + anadido;

    glPushMatrix();

        glPushMatrix();
            glTranslatef(-((largo-0.05)/2+0.5),0,0.55);
            glScalef(largo-0.05,0.1,0.1);
            cubo->draw();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-((largo-0.05)/2+0.5),0,-0.55);
            glScalef(largo-0.05,0.1,0.1);
            cubo->draw();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(-((largo-0.1)+0.5),0,0.55);
            glScalef(0.1,0.78,0.1);
            cubo->draw();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-((largo-0.1)+0.5),0,-0.55);
            glScalef(0.1,0.78,0.1);
            cubo->draw();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(-((largo-0.2)+0.5),1,0.55);
            glRotatef(-(90+radAGrad(atan2(0.9,largo-0.2))),0,0,1);
            glTranslatef(0.05,0,0);
            glScalef(0.1,sqrt(pow(largo-0.2,2)+pow(0.9,2)),0.1);
            cubo->draw();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-((largo-0.2)+0.5),1,-0.55);
            glRotatef(-(90+radAGrad(atan2(0.9,largo-0.2))),0,0,1);
            glTranslatef(0.05,0,0);
            glScalef(0.1,sqrt(pow(largo-0.2,2)+pow(0.9,2)),0.1);
            cubo->draw();
        glPopMatrix();


        glPushMatrix();

            glTranslatef(-((largo-0.1)+0.5),0.78,0);

            glPushMatrix();
                glTranslatef(-anadido,0.11,0);
                glRotatef(-angulo,0,0,1);
                c1->draw();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,0,0.55);
                glScalef(0.43,0.22,0.1);
                cubo->draw();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,0,-0.55);
                glScalef(0.43,0.22,0.1);
                cubo->draw();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();  
}