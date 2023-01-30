
#ifndef CAMARA_H_INCLUDED
#define CAMARA_H_INCLUDED

#include "auxiliar.h"

typedef enum { ORTOGONAL, PERSPECTIVA } vistaCamara;
typedef enum { EXAMINAR, FIRSTPERSON } modo;
typedef enum { EJEX, EJEY } eje;
typedef enum { AVANZAR, RETROCEDER, DERECHA, IZQUIERDA } acciones;

class Camara
{
    private:

    Tupla3f eye, at, up;
    Tupla3f Vdir, Vx, Vy;

    vistaCamara tipo = PERSPECTIVA;

    float leftRight, topBottom;
    float near, far, aspect, fovY;

    float angGiroSobreY, angGiroSobreX = 0;

    bool objSeleccionado = false;
    Tupla3f posObjSelec;


    public:

    Camara( Tupla3f _eye, Tupla3f _at, Tupla3f _up, int _tipo, float width, float high, float _near, float _far );

    void calculosVectores();
    
    void rotarXExaminar( float angle );
    void rotarYExaminar( float angle );
    //void rotarZExaminar( float angle );

    void rotarXFirstPerson( float angle );
    void rotarYFirstPerson( float angle );
    //void rotarZFirstPerson( float angle );

    void rotar(  modo modo, eje eje, float angle );

    void calcularAngulos( Tupla3f punto );

    //void mover( float x, float y, float z );
    void moverAccion( acciones accion, float V );     // V = velocidad

    void setObjSeleccionado( Tupla3f pos );
    void unSetObjSelec();

    void setEye( Tupla3f eye );
    void setAt( Tupla3f at );
    void setUp( Tupla3f up );

    void zoom( float factor );

    void setDimensiones( float leftRight, float topBottom );
    void setWidth_High( float width, float high );
    void setNear_Far( float near, float far );
    void setAspect( float aspect );

    void setObserver();
    void setProyeccion();

    void setTipo( int _tipo );
};


#endif