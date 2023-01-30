#ifndef _ESCENA_H
#define _ESCENA_H

#include "malla.h"
#include "objply.h"

#include "ejes.h"

#include "camara.h"
#include "luz.h"
#include "luzdireccional.h"
#include "luzposicional.h"

#include "c1.h"
#include "c2.h"
#include "armazon.h"
#include "cintacorredera.h"
#include "cintamaletas.h"
#include "cubo.h"
#include "piramidepentagonal.h"
#include "cilindro.h"
#include "esfera.h"
#include "cono.h"
#include "flecha.h"
#include "ejesflechas.h"
#include "plano.h"
#include "cartelpublicidad.h"


using namespace std ;

typedef enum {P1, P2, P3} practicas;

typedef enum { T, E, RO, C, N } transformaciones;
typedef enum { NADA, SELOBJETO, SELVISUALIZACION, SELAUTOMATICO, SELMANUAL, SELCAMARA } menu;
typedef enum { VACIO, CUBO, PIRAMIDE } figuras;
typedef enum { CARTEL, AVION, RAMPA, TORRE } objSelecionable;

class Escena
{
    private:

    float trayecto = 0;
    bool avanzando = true;


    bool ilu;
    bool animacionLuzPuntual = false;
    bool selAutomatico = false;

    int gradoLibertadMJ = 0;

    menu modoMenu = NADA;
    figuras figura = CUBO;
    practicas debug = P2;

    Ejes ejes;

    bool botonDerchPulsado = false;
    int camaraActiva;
    Camara * camaras[4];

    GLfloat model_matrix[16];

    vector<Tupla3f> pos_objetos; // posición de los objetos en el orden en el que se dibujan

    TuplaG3< Tupla3f > coloresCopia[4]; // vector que guarda los valores de los colores para reponerlos después de hacer pick pixel

    float x1 = 0, y1 = 0;

    int numObjSeleccionables = 4;

    int objSeleccionado = 0;

    bool hayObjSeleccionado = false;

    LuzPosicional * foco0 = nullptr;
    LuzPosicional * foco1 = nullptr;
    LuzPosicional * foco2 = nullptr;
    LuzPosicional * foco3 = nullptr;
    LuzPosicional * foco4 = nullptr;
    LuzPosicional * foco5 = nullptr;
    LuzPosicional * foco6 = nullptr;
    LuzDireccional * foco7 = nullptr;

    /////////////////////   cinta maletas
    /*C2 * c2PRUEBA = nullptr;
    Armazon * armazonPRUEBA = nullptr;
    CintaCorredera * cintaPRUEBA = nullptr;
    Faro * faroPRUEBA = nullptr;*/
    CintaMaletas * cintaMaletas = nullptr;
    /////////////////////

    Cubo * cubo = nullptr;
    Cono * cono = nullptr;
    Esfera * esfera = nullptr;
    Cilindro * cilindro = nullptr;
    PiramidePentagonal * piramide = nullptr;

    Plano * sueloPavimento = nullptr;
    Plano * sueloCesped = nullptr;
    Esfera * esferaCielo = nullptr;

    Flecha * flecha = nullptr;
    EjesFlecha * ejesFlecha = nullptr;

    ObjPLY * beethoven = nullptr;
    ObjPLY * avion = nullptr;
    ObjPLY * vaca = nullptr;

    ObjRevolucion * peon = nullptr;
    ObjRevolucion * lata_pcue = nullptr;
    ObjRevolucion * peon_blanco=nullptr, * peon_negro = nullptr;
    ObjRevolucion * torre = nullptr;

    CartelPublicidad * cartelPublicidad = nullptr;
    

    Material * mColor = nullptr;
    Material * mDifuso = nullptr;
    Material * mAmbiente = nullptr;
    Material * mEspecular = nullptr;
    
    Material * mTexturaBlanco = nullptr;
    Material * mTexturaNegro = nullptr;
    Material * mMapamundi = nullptr;
    Material * mCesped = nullptr;
    Material * mCielo = nullptr;
    Material * mGris = nullptr;
    Material * mMetalico = nullptr;
    Material * mMetalOxidado = nullptr;

    Textura * tPublicidad = nullptr;
    Textura * tMapaMundi = nullptr;
    Textura * tPavimento = nullptr;
    Textura * tCuadro = nullptr;
    Textura * tCielo = nullptr;
    Textura * tCesped = nullptr;
    
    //
    float velocidadAnimacion;
    const float MAXvelocidadAnimacion = 20;
    const float MINvelocidadAnimacion = 2;

    //
    float elevacionAnimacion;
    const float MAXelevacionAnimacion = 0.1;
    const float MINelevacionAnimacion = -0.1;
    //
    float extensionAnimacion;
    const float MAXextensionAnimacion = 0.001;
    const float MINextensionAnimacion = -0.001;
    //
    float giroAnimacion;
    const float MAXgiroAnimacion = 0.1;
    const float MINgiroAnimacion = -0.1;

    Tupla3f colorAnimacion = Tupla3f(1,0,0);
    int momentoColorAnimacion = 0;
    float incrementoColorAnimacion = 0.05;

    int espera = 0;


    // 
    bool fondoNegro;
    //
    //bool maletas = true;
    bool elegirMovimientoCintaMaletas = false;
    //
    vector<bool> visualizacionActiva;
    vector<bool> lucesActivas;
    vector<bool> activadaAntes;
    vector<bool> activaCintaMaletas;



    // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)
       
    // variables que definen la posicion de la camara en coordenadas polares
    GLfloat Observer_distance;
    GLfloat Observer_angle_x;
    GLfloat Observer_angle_y;

    // variables que controlan la ventana y la transformacion de perspectiva
    GLfloat Width, Height, Front_plane, Back_plane;


    // Transformación de cámara
    void change_projection( /*const float ratio_xy*/ );
    void change_observer();


    // resetear la pantalla sin cambiar la posición de la camara
    void clear_window();
    //
    void iniVisualizaciones();
    //
    void iniMaterialesTexturas();

    //
    template <class TipoObjeto>
    void dibujarObjeto( TipoObjeto * objeto );

    // establecer modo visualización
    template <class TipoObjeto>
    void setDrawMode( TipoObjeto * objeto, int mVisu );

    //
    template <class TipoObjeto>
    void transformar( TipoObjeto * objeto, const std::vector<pair<transformaciones,Tupla4f>> & transf );

    //
    void encenderLuces();
    //
    Luz obtenerLuz( int i );

    //
    void variarVelocidadAnimacion( float incremento );

    void dibujarSeleccion( float x, float y );


    public:

    Escena();
    void inicializar( int UI_window_width, int UI_window_height );
    void redimensionar( int newWidth, int newHeight ) ;

    // Dibujar
    void dibujar() ;

    // Interacción con la escena
    bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
    void teclaEspecial( int Tecla1, int x, int y );

    //
    void animacionesColoresLucesMateriales();
    void animarModeloJerarquico();
    void animacionesVarias();


    //
    void mostrarInformacion();


    void ratonMovido( int x, int y );
    void clickRaton( int boton, int estado, int x, int y );

};
#endif
