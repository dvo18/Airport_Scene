
#include "cartelpublicidad.h"

CartelPublicidad::CartelPublicidad( float alto, float ancho )
{
    this->altoGeneral = alto;
    this->ancho = ancho;

    altoCartel = ancho/caterlProporcion;

    alpha = 0;
    
    plano = new Plano( 1 );
    esfera = new Esfera( 100, 60, 0.5 );
    cilindro = new Cilindro( 20, 5, 1, 0.5 );

    tMetal = new Textura( "jpgs/metal.jpeg" );
    tMapaMundi = new Textura( "jpgs/mapa-mundi.jpg" );
    tMetalOxidado = new Textura( "jpgs/metal-oxidado.jpg" );
    tCartelAirline = new Textura( "jpgs/airline.jpg" );
}

void CartelPublicidad::setAngulo( float angulo )
{
    alpha = angulo;
}

float CartelPublicidad::getAngulo()
{
    return alpha;
}

void CartelPublicidad::setColor( Tupla3f colorP, Tupla3f colorL, Tupla3f colorS )
{
    plano->setColor( colorP, colorL, colorS );
    esfera->setColor( colorP, colorL, colorS );
    cilindro->setColor( colorP, colorL, colorS );
}

TuplaG3<Tupla3f> CartelPublicidad::getColor()
{
    return plano->getColor();
}

bool CartelPublicidad::tieneTextura()
{
    return /*plano->tieneTextura() and esfera->tieneTextura() and cilindro->tieneTextura()*/ true;
}

void CartelPublicidad::draw()
{
    plano->setMaterial( material );
    plano->setPolygonMode( polygonMode );

    esfera->setMaterial( material );
    esfera->setPolygonMode( polygonMode );

    cilindro->setMaterial( material );
    cilindro->setPolygonMode( polygonMode );

    plano->setTextura( tCartelAirline );
    esfera->setTextura( tMapaMundi );
    cilindro->setTextura( tMetal );

    glPushMatrix();

        glPushMatrix();
            glTranslatef( -(ancho/2-ancho*0.1), 0, 0 );
            glScalef( 3, altoGeneral, 3 );
            cilindro->draw();
        glPopMatrix();

        glPushMatrix();
            glTranslatef( ancho/2-ancho*0.1, 0, 0 );
            glScalef( 3, altoGeneral, 3 );
            cilindro->draw();
        glPopMatrix();

        glPushMatrix();

            glTranslatef( 0, altoGeneral-altoCartel/2, 1.75 );

            glPushMatrix();
                glScalef( ancho, altoCartel, 0 );
                glTranslatef( 0, 0.5, 0 );
                plano->draw();

                glPushMatrix();
                    plano->setTextura( tMetalOxidado );
                    glTranslatef( 0, 0, -0.01 );
                    glRotatef( 180, 0, 1, 0 );
                    plano->draw();
                glPopMatrix();

            glPopMatrix();

            glPushMatrix();
                glTranslatef( ancho/2, (altoCartel-altoCartel*0.7)/2+0.5, 0 );
                glScalef( altoCartel*0.7, altoCartel*0.7, altoCartel*0.7 );
                glTranslatef( 0, 0.5, 0 );
                glRotatef( -23.45, 0, 0, 1 );
                glRotatef( alpha, 0, 1, 0 );
                glTranslatef( 0, -0.5, 0 );
                esfera->draw();         // cuando se dibuja, no sé por qué pero se oculta la línea roja de los ejes
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}