
#include "c1.h"

C1::C1( float add, float MAXang, float MAXincrementoL, float largo )
{
    anadido = add;
    largoCinta = largo;

    angulo = 0;
    MAXangulo = MAXang;

    incrementoLargo = 0;
    MAXincrementoLargo = MAXincrementoL;

    cilindro = new Cilindro( 5, 10, 1, 0.5 );
    cc = new CintaCorredera( largoCinta, 1.2 );
    c2 = new C2( anadido, largo );
}

void C1::setAngulo( float nuevoAngulo )
{
    angulo = nuevoAngulo;
}

void C1::variarIncrementoLargo( float incremento )
{
    float nuevoIncremento = incrementoLargo + incremento;

    if( nuevoIncremento >= 0 and nuevoIncremento <= MAXincrementoLargo ) incrementoLargo = nuevoIncremento;
    else if( nuevoIncremento > MAXincrementoLargo ) incrementoLargo = MAXincrementoLargo;
    else incrementoLargo = 0;
}

float C1::getIncrementoLargo()
{
    return incrementoLargo;
}

bool C1::tieneTextura()
{
    return cilindro->tieneTextura() and c2->tieneTextura() and cc->tieneTextura();
}

void C1::draw()
{
    c2->setMaterial( material );
    c2->setPolygonMode( polygonMode );
    cc->setMaterial( material );
    cc->setPolygonMode( polygonMode );
    cilindro->setMaterial( material );
    cilindro->setPolygonMode( polygonMode );

    glPushMatrix();

        glPushMatrix();

            glTranslatef(-largoCinta/2,0,0);

            cc->draw();

            glPushMatrix();
                glTranslatef(-largoCinta/2,0,0.65);
                drawPiston();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-largoCinta/2,0,-0.65);
                drawPiston();
            glPopMatrix();

        glPopMatrix();

        glPushMatrix();
            glTranslatef(-incrementoLargo,0,0);
            c2->draw();
        glPopMatrix();

    glPopMatrix();
}

void C1::drawPiston()
{
    float largo = largoCinta + anadido;
    
    float L90grados = sqrt( pow(largo,2) + pow(0.85,2) );
    float L120grados = sqrt( pow(largo,2) + pow(0.85,2) - 2*largo*0.85*cos( gradARad(120) ) );


    float L120gradosCambia = sqrt( pow(largo,2) + pow(0.85,2) - 2*largo*0.85*cos( gradARad(90+angulo) ) );
    float incremento = /*L120gradosCambia - L90grados*/ ( ( L120grados - L90grados ) / MAXangulo ) * angulo;

    float L80porCiento = L90grados * 0.8;

    float angulo90 = radAGrad( acos( ( pow(largo,2) + pow(L120gradosCambia,2) - pow(0.85,2) ) / ( 2 * largo * L120gradosCambia ) ) );
    float anguloGiro = 90 - angulo90;

    //std::cout << std::endl << L20porCiento << " " << L80porCiento << " " << incremento << std::endl;

    glPushMatrix();

        glRotatef(anguloGiro,0,0,1);
        glTranslatef(0,-(L90grados+incremento),0);

        glPushMatrix();

            glTranslatef(0,(L90grados-L80porCiento)+incremento,0);

            glPushMatrix();
                glTranslatef(0,L80porCiento,0.05);
                glRotatef(-90,1,0,0);
                glScalef(0.15,0.1,0.15);
                cilindro->draw();
            glPopMatrix();

            glPushMatrix();
                glScalef(0.07,L80porCiento,0.07);
                cilindro->draw();
            glPopMatrix();

        glPopMatrix();

        glPushMatrix();
            glScalef(0.1,L80porCiento,0.1);
            cilindro->draw();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0,0,0.05);
            glRotatef(-90,1,0,0);
            glScalef(0.15,0.1,0.15);
            cilindro->draw();
        glPopMatrix();

    glPopMatrix();
}