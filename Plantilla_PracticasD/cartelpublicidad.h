
#ifndef CARTELPUBLICIDAD_H_INCLUDED
#define CARTELPUBLICIDAD_H_INCLUDED

#include "objcompuesto.h"
#include "auxiliar.h"

#include "cubo.h"
#include "plano.h"
#include "esfera.h"
#include "cilindro.h"


class CartelPublicidad : public ObjCompuesto
{
    private:
    Plano * plano = nullptr;
    Esfera * esfera = nullptr;
    Cilindro * cilindro = nullptr;

    Textura * tMetal = nullptr;
    Textura * tMapaMundi = nullptr;
    Textura * tMetalOxidado = nullptr;
    Textura * tCartelAirline = nullptr;

    const float caterlProporcion = 848/314;

    float altoGeneral, ancho, altoCartel;
    float alpha;

    public:
    CartelPublicidad( float alto, float ancho );

    void setAngulo( float angulo );
    float getAngulo();

    void draw();

    bool tieneTextura();

    void setColor( Tupla3f colorP, Tupla3f colorL, Tupla3f colorS );
    TuplaG3<Tupla3f> getColor();
};

#endif