
#include "camara.h"

using namespace std;

Camara::Camara( Tupla3f _eye, Tupla3f _at, Tupla3f _up, int _tipo, float width, float high, float _near, float _far )
{
    // posición de la cámara
    setEye( _eye );

    // objetivo a donde apunta la cámara
    setAt( _at );

    // vector ascendente / apunta hacia arriba / unidad 1
    if( eye[0]==0 and eye[2]==0 and at[0]==0 and at[2]==0 ) _up = Tupla3f(0,0,-1);
    setUp ( _up.normalized() );

    //calculosVectores();
    // direccion de la cámara (para mí: apunta en sentido contrario al que está el objeto) / eje Z
    Vdir = ( eye - at ).normalized();

    // eje derecho / eje u / eje X (positivo) 
    Vx = ( up.cross(Vdir) ).normalized();

    // eje ascendente / eje v / eje Y (ascendente)
    Vy = Vdir.cross(Vx);


    calcularAngulos( eye );


    setTipo( _tipo );

    setNear_Far( _near, _far );

    setWidth_High( width, high );

    setDimensiones( width/2, high/2 );

    fovY = 2 * atan2(topBottom,near) * 180/M_PI;
}



void Camara::calculosVectores()
{
    // direccion de la cámara (para mí: apunta en sentido contrario al que está el objeto) / eje Z
    Vdir = ( eye - at ).normalized();

    // eje derecho / eje u / eje X (positivo) 
    Vx = ( up.cross(Vdir) ).normalized();

    // eje ascendente / eje v / eje Y (ascendente)
    Vy = Vdir.cross(Vx);
}
  
void Camara::setObserver()
{
    if( objSeleccionado ) {
        setAt( posObjSelec );
        setEye( posObjSelec + Vdir );
    }
    else setAt( eye -Vdir );

    gluLookAt( eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2] );
}

void Camara::setProyeccion()
{
    if( tipo == ORTOGONAL ) glOrtho( -leftRight, leftRight, -topBottom, topBottom, near, far );
    else gluPerspective( fovY, aspect, near, far );
}



void Camara::setObjSeleccionado( Tupla3f pos )
{
    cout << pos;
    posObjSelec = pos;
    objSeleccionado = true;
}

void Camara::unSetObjSelec()
{
    objSeleccionado = false;
}


void Camara::setDimensiones( float leftRight, float topBottom )
{
    this->leftRight = leftRight;
    this->topBottom = topBottom;
}

void Camara::setWidth_High( float width, float high )
{
    setAspect( width / high );
}

void Camara::setNear_Far( float near, float far )
{
    this->near = near;
    this->far = far;
}

void Camara::setAspect( float aspect )
{
    this->aspect = aspect;
}

void Camara::setTipo( int _tipo )
{
    tipo = vistaCamara(_tipo);
}


void Camara::setEye( Tupla3f eye )
{
    this->eye = eye;
}

void Camara::setAt( Tupla3f at )
{
    this->at = at;
}

void Camara::setUp( Tupla3f up )
{
    this->up = up;
}




void Camara::zoom( float factor )
{
    if( tipo == ORTOGONAL and ( ( leftRight-factor >= 1 and leftRight-factor <= 5000  ) and ( topBottom-factor >= 1 and topBottom-factor <= 5000 ) ) ) {
        leftRight -= factor * 10; 
        topBottom -= factor * 10; 
    }
    else if( tipo == PERSPECTIVA and ( fovY-factor >= 1 and fovY-factor<= 160 )  ) fovY -= factor;
}

/*void Camara::mover( float x, float y, float z )
{
    setEye( Tupla3f( x, y, z ) );
}*/

void Camara::moverAccion( acciones accion, float V )
{
    switch ( accion ) {
        case AVANZAR:
            setEye( eye - Vdir *  V );
            break;
        
        case RETROCEDER:
            setEye( eye + Vdir * V );
            break;

        case DERECHA:
            setEye( eye + (up.cross(Vdir)).normalized() * V );
            break;

        case IZQUIERDA:
            setEye( eye + (Vdir.cross(up)).normalized() * V );
            break;
    }
}




void Camara::rotarXExaminar( float angle )
{
    //recalcular( EXAMINAR, EJEX, angle );
    rotar( EXAMINAR, EJEY, angle );
}

void Camara::rotarYExaminar( float angle )
{
    //recalcular( EXAMINAR, EJEY, angle );
}



void Camara::rotarXFirstPerson( float angle )
{
    //recalcular( FIRSTPERSON, EJEX, angle );
    //rotar( EXAMINAR, EJEY, angle );

    if( angGiroSobreY + angle >= 2*M_PI ) angGiroSobreY = 0;
    else angGiroSobreY += angle;

    Vdir[0] = cos( angGiroSobreY );
    Vdir[2] = -sin( angGiroSobreY );

    Vdir = Vdir.normalized();
}

void Camara::rotarYFirstPerson( float angle )
{
    //recalcular( FIRSTPERSON, EJEY, angle );

    if( angGiroSobreX + angle >= 2*M_PI ) angGiroSobreX = 0;
    else angGiroSobreX -= angle;

    Vdir[0] = cos( angGiroSobreY ) * cos( angGiroSobreX );
    Vdir[1] = sin( angGiroSobreX );
    Vdir[2] = -sin( angGiroSobreY ) * cos( angGiroSobreX );

    Vdir = Vdir.normalized();
}



void Camara::rotar( modo modo, eje eje, float angle )
{
    float radio = 0;
    Tupla3f copia_eye = eye;

    switch ( eje ) {
        case EJEX:
            break;
        
        case EJEY:
            angGiroSobreY += angle;
            radio = sqrt( pow( copia_eye[0], 2 ) + pow( copia_eye[2], 2 ) );
            eye[0] = cos( angGiroSobreY /*angle + calcularAngulo( copia_eye[0], copia_eye[2] )*/ ) * radio;
            eye[2] = - sin( angGiroSobreY /*angle + calcularAngulo( copia_eye[0], copia_eye[2] )*/ ) * radio;
            break;
    }
}



/*      eje2            circunferencia goniométrica
     _ _ | _ _
    /    |    \
   /     |     \
  |      |      |
---------|---------- + eje1
  |      |      |
   \     |     /
    \ _ _|_ _ /
         |
    +(rotando Y)
*/

void Camara::calcularAngulos( Tupla3f punto )
{
    float sumaAnguloY = 0;

    if( punto[0] != 0 ) sumaAnguloY += atan2( abs(punto[2]), abs(punto[0]) );
    else
        if( punto[2] < 0 ) sumaAnguloY += M_PI_2;
        else if( punto[2] > 0 ) sumaAnguloY += 3 * M_PI_2;


    if( punto[0] < 0 )
        if( punto[2] < 0) sumaAnguloY += M_PI_2;
        else sumaAnguloY += M_PI;
    
    else if( punto[0] > 0 and punto[2] > 0 ) sumaAnguloY += 3 * M_PI_2;

    angGiroSobreY += sumaAnguloY;



    float sumaAnguloXZ = 0;

    float XZ = sqrt( pow(punto[0],2) + pow(punto[2],2) );
    if( punto[0] < 0 ) XZ *= -1;

    if( XZ != 0 ) sumaAnguloXZ = atan2( abs(punto[1]), abs(XZ) );
    else
        if( punto[1] > 0 ) sumaAnguloXZ += M_PI_2;
        else if( punto[1] < 0 ) sumaAnguloXZ += 3 * M_PI_2;


    if( XZ < 0 )
        if( punto[1] >= 0 ) sumaAnguloXZ += M_PI_2;
        else sumaAnguloXZ += M_PI;

    else if( XZ > 0 and punto[1] < 0 ) sumaAnguloXZ += 3 * M_PI_2;

    angGiroSobreX += sumaAnguloXZ;
}
