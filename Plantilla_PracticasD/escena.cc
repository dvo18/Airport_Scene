

#include "auxiliar.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************

Escena::Escena()
{
   Front_plane       = 50.0;
   Back_plane        = 2000.0;
   Observer_distance = 4*Front_plane;
   Observer_angle_x  = 0.0 ;
   Observer_angle_y  = 0.0 ;

   // habilitar caras traseras ocultas
   glEnable( GL_CULL_FACE );

   ejes.changeAxisSize( 5000 );

   velocidadAnimacion = MAXvelocidadAnimacion / 2 + 2;

   elevacionAnimacion = MAXelevacionAnimacion;
   extensionAnimacion = MAXextensionAnimacion;
   giroAnimacion = MAXgiroAnimacion;

   fondoNegro = true;

   camaraActiva = 0;

   camaras[0] = new Camara( Tupla3f(0,500,1000), Tupla3f(0,0,0), Tupla3f(0,1,0), PERSPECTIVA, 50, 50, 25, 3000 );
   camaras[1] = new Camara( Tupla3f(0,500,-1000), Tupla3f(0,0,0), Tupla3f(0,1,0), PERSPECTIVA, 50, 50, 25, 3000 );
   camaras[2] = new Camara( Tupla3f(0,500,1000), Tupla3f(0,0,0), Tupla3f(0,1,0), ORTOGONAL, 2000, 2000, 25, 3000 );
   camaras[3] = new Camara( Tupla3f(1000,0,1000), Tupla3f(0,0,0), Tupla3f(0,1,0), ORTOGONAL, 2000, 2000, 25, 3000 );

   foco0 = new LuzPosicional( GL_LIGHT0 );
   foco1 = new LuzPosicional( Tupla3f(0,500,0), GL_LIGHT1, Tupla4f(1,1,1,1), Tupla4f(1,1,1,1), Tupla4f(1,1,1,1) );
   foco2 = new LuzPosicional( Tupla3f(-500,250,-500), GL_LIGHT2, Tupla4f(1,0,0,1), Tupla4f(0,0,0,1), Tupla4f(0,0,0,1) );
   foco3 = new LuzPosicional( Tupla3f(-300,0,500), GL_LIGHT3, Tupla4f(0,0,0,1), Tupla4f(0,1,0,1), Tupla4f(0,0,0,1) );
   foco4 = new LuzPosicional( Tupla3f(500,-500,700), GL_LIGHT4, Tupla4f(0,0,0,1), Tupla4f(0,0,0,1), Tupla4f(0,0,1,1) );
   foco5 = new LuzPosicional( Tupla3f(900,0,900), GL_LIGHT5, Tupla4f(1,0,0,1), Tupla4f(0,1,0,1), Tupla4f(0,0,1,1) );
   foco6 = new LuzPosicional( Tupla3f(0,-600,0), GL_LIGHT6, Tupla4f(1,0,0,1), Tupla4f(1,1,0,1), Tupla4f(1,1,1,1) );
   foco7 = new LuzDireccional( Tupla2f(0,0), GL_LIGHT7, Tupla4f(1,1,1,1), Tupla4f(1,1,1,1), Tupla4f(1,1,1,1) );

   mColor = new Material( Tupla4f(0.05,0.75,0.75,1), Tupla4f(0.75,0.75,0.75,1), Tupla4f(0,0,0,1), 128 );
   mDifuso = new Material( Tupla4f(1,1,1,1), Tupla4f(0,0,0,1), Tupla4f(0,0,0,1), 100 );               // para el peon blanco
   mAmbiente = new Material( Tupla4f(1,1,1,1), Tupla4f(0,0,0,1), Tupla4f(1,1,1,1), 128 );
   mEspecular = new Material( Tupla4f(0,0,0,1), Tupla4f(1,1,1,1), Tupla4f(0,0,0,1), 128 );          // para el peon negro

   mTexturaBlanco = new Material( Tupla4f(0,0,0,1), Tupla4f(1,1,1,1), Tupla4f(1,1,1,1), 128 );
   mTexturaNegro = new Material( Tupla4f(0,0,0,1), Tupla4f(1,1,1,1), Tupla4f(0,0,0,1), 128 );
   mMapamundi = new Material( Tupla4f(0,0,0,1), Tupla4f(0.48,0.48,1,1), Tupla4f(1,1,1,1), 128 );
   mCesped = new Material( Tupla4f(0,0.35,0,1), Tupla4f(0,0,0,1), Tupla4f(0,0.33,0,1), 128 );
   mCielo = new Material( Tupla4f(0.4,0.4,0.7,1), Tupla4f(0,0,0,1), Tupla4f(0,0,0,1), 128 );
   mGris = new Material( Tupla4f(0.5,0.5,0.5,1), Tupla4f(0,0,0,1), Tupla4f(0.5,0.5,0.5,1), 35 );
   mMetalico = new Material( Tupla4f(0.6,0.6,0.6,1), Tupla4f(0.45,0.45,0.45,1), Tupla4f(/*0.25,0.25,0.25,1*/0,0,0,0), 50);
   mMetalOxidado = new Material( Tupla4f(0.55,0.5,0.5,1), Tupla4f(0.7,0.45,0.45,1), Tupla4f(0.3,0.15,0.15,1), 35 );

   tMapaMundi = new Textura( "jpgs/mapa-mundi.jpg" );
   tCuadro = new Textura( "jpgs/washington.jpg" );
   tPublicidad = new Textura( "jpgs/airline.jpg" );
   tPavimento = new Textura( "jpgs/pavimento2.jpg" );
   tCielo = new Textura( "jpgs/cielo1_2.jpg" );
   tCesped = new Textura( "jpgs/cesped.jpg" );

   /////////////////////   cinta maletas
   /*c2PRUEBA = new C2( 0.1075 );
   armazonPRUEBA = new Armazon(2.5);
   cintaPRUEBA = new CintaCorredera(2);
   faroPRUEBA = new Faro();*/
   cintaMaletas = new CintaMaletas( 2.5 );
   /////////////////////
   /*cintaMaletas->variarAnguloElevacion(0);
   cintaMaletas->variarAnguloGiro(0);
   cintaMaletas->variarIncrementoLargo(0);*/

   //flecha = new Flecha( 20, 40, 20 );
   //ejesFlecha = new EjesFlecha();

   cubo = new Cubo( 50 );
   piramide = new PiramidePentagonal( 50, 25 );

   esfera = new Esfera( 100, 60, 50 );
   cilindro = new Cilindro( 5, 40, 20, 10 );

   beethoven = new ObjPLY( "plys/beethoven" );

   //peon = new ObjRevolucion( "plys/peon", 20 );
   
   //lata_pcue = new ObjRevolucion( "plys/lata-pcue", 20 );

   //peon_blanco = new ObjRevolucion( "plys/peon", 20 );
   //peon_negro = new ObjRevolucion( "plys/peon", 20 );

   torre = new ObjRevolucion( "plys/torre", 40 );

   sueloPavimento = new Plano( 3000, true );
   sueloCesped = new Plano( 3000, true );

   esferaCielo = new Esfera( 100, 60, 0.5, true );

   cartelPublicidad = new CartelPublicidad( 200, 200 );
   cartelPublicidad->setID( objSelecionable(CARTEL) );

   avion = new ObjPLY( "plys/airplane" );
   avion->setID( objSelecionable(AVION) );

   vaca = new ObjPLY( "plys/cow" );

   cono = new Cono( 5, 9, 20, 10 );

   //
   iniMaterialesTexturas();
}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	//glClearColor( 0.0, 0.0, 0.0, 0.0 ); // se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-

	Width  = UI_window_width/10;
	Height = UI_window_height/10;

   change_projection( /*float(UI_window_width)/float(UI_window_height)*/ );
	glViewport( 0, 0, UI_window_width, UI_window_height );


   // habilitar ocultar caras traseras
   glEnable( GL_CULL_FACE );
   // habilitra no variar normales al transformar
   glEnable( GL_NORMALIZE );

   //
   glEnable( GL_TEXTURE_2D );

   // establecer todos los modos en false por defecto
   iniVisualizaciones();

   // establecer modo de visualización en sólido por defecto (true)
   visualizacionActiva[2] = true;

   ilu = true;
   lucesActivas[0] = true;
   lucesActivas[1] = true;

   activaCintaMaletas[0] = true;
   activaCintaMaletas[1] = true;
   activaCintaMaletas[2] = true;

   pos_objetos.resize( numObjSeleccionables );
}

void Escena::iniMaterialesTexturas()
{
   /////////////////////   cinta maletas
   /*c2PRUEBA->setMaterial( mColor );
   armazonPRUEBA->setMaterial( mColor );
   cintaPRUEBA->setMaterial( mColor );
   faroPRUEBA->setMaterial( mColor );*/
   cintaMaletas->setMaterial( mMetalOxidado );
   /////////////////////

   //flecha->setMaterial( mColor );

   //esfera->setMaterial( mColor );
   beethoven->setMaterial( mColor );
   //peon->setMaterial( mAmbiente );
   cono->setMaterial( mColor );
   cubo->setMaterial( mColor );           // mAmbiente
   piramide->setMaterial(mColor);         // mAmbiente
   cilindro->setMaterial( mColor );
   //lata_pcue->setMaterial( mAmbiente );

   cartelPublicidad->setMaterial( mAmbiente );
   esfera->setMaterial( mAmbiente );
   sueloPavimento->setMaterial( mGris );
   sueloCesped->setMaterial( mCesped );
   esferaCielo->setMaterial( mAmbiente );
   avion->setMaterial( mMetalico );
   vaca->setMaterial( mColor );
   torre->setMaterial( mMetalico );

   //esfera->setTextura( tMapaMundi );
   //cono->setTextura( tMapaMundi );
   sueloPavimento->setTextura( tPavimento );
   esferaCielo->setTextura( tCielo );
   sueloCesped->setTextura( tCesped );

   esfera->setColor(  Tupla3f( 1, 0, 0 ), Tupla3f( 0, 1, 0 ), Tupla3f( 1, 1, 1 )  );


   coloresCopia[0] = avion->getColor();
   coloresCopia[1] = cartelPublicidad->getColor();
}


//
void Escena::animarModeloJerarquico()
{
   if( cintaMaletas != nullptr and selAutomatico ) {
      ////////// Elevacion segunda rampa
      if( activaCintaMaletas[1] ) {
         if( cintaMaletas->getAnguloElevacion() == cintaMaletas->getMAXanguloElevacion() ) elevacionAnimacion = MINelevacionAnimacion;
         else if( cintaMaletas->getAnguloElevacion() == 0 ) elevacionAnimacion = MAXelevacionAnimacion;

         cintaMaletas->variarAnguloElevacion( velocidadAnimacion*elevacionAnimacion );
      }
      //////////

      ////////// Extensión tercera rampa
      if( activaCintaMaletas[2] ) {
         if( cintaMaletas->getIncrementoLargo() == cintaMaletas->getMAXincrementoLargo() ) extensionAnimacion = MINextensionAnimacion;
         else if( cintaMaletas->getIncrementoLargo() == 0 ) extensionAnimacion = MAXextensionAnimacion;

         cintaMaletas->variarIncrementoLargo( 2*velocidadAnimacion*extensionAnimacion );
      }
      //////////

      ////////// Giro rampa completa
      if( activaCintaMaletas[0] ) {
         if( cintaMaletas->getAnguloGiro() == cintaMaletas->getMAXanguloGiro() ) giroAnimacion = MINgiroAnimacion;
         else if( cintaMaletas->getAnguloGiro() == cintaMaletas->getMINanguloGiro() ) giroAnimacion = MAXgiroAnimacion;

         cintaMaletas->variarAnguloGiro( velocidadAnimacion*giroAnimacion );
      }
      //////////
   }

}

void Escena::animacionesColoresLucesMateriales()
{
   if( cubo != nullptr ) {
      
      switch ( momentoColorAnimacion ) {
         case 0:
            colorAnimacion[1] += incrementoColorAnimacion;
            if( colorAnimacion[1] >= 1 ) {momentoColorAnimacion++;   colorAnimacion[1]=1;}
            break;

         case 1:
            colorAnimacion[0] -= incrementoColorAnimacion;
            if( colorAnimacion[0] <= 0 ) {momentoColorAnimacion++;   colorAnimacion[0]=0;}
            break;

         case 2:
            colorAnimacion[2] += incrementoColorAnimacion;
            if( colorAnimacion[2] >= 1 ) {momentoColorAnimacion++;   colorAnimacion[2]=1;}
            break;

         case 3:
            colorAnimacion[1] -= incrementoColorAnimacion;
            if( colorAnimacion[1] <= 0 ) {momentoColorAnimacion++;   colorAnimacion[1]=0;}
            break;
         
         case 4:
            colorAnimacion[0] += incrementoColorAnimacion;
            if( colorAnimacion[0] >= 1 ) {momentoColorAnimacion++;   colorAnimacion[0]=1;}
            break;

         case 5:
            colorAnimacion[2] -= incrementoColorAnimacion;
            if( colorAnimacion[2] <= 0 ) {momentoColorAnimacion = 0;   colorAnimacion[2]=0;}
            break;
         
         default:
            colorAnimacion = Tupla3f(1,0,0);
            momentoColorAnimacion = 0;
            break;
      }

      foco7->setColor( Tupla4f(1,1,1,1), Tupla4f(1,1,1,1), Tupla4f(colorAnimacion[0],colorAnimacion[1],colorAnimacion[2],1) );

      vaca->setColor( Tupla3f( 1, 0, 0 ), Tupla3f( 0, 1, 0 ), colorAnimacion );
   }
}

void Escena::animacionesVarias()
{
   espera++;

   if( animacionLuzPuntual ) {
      if( espera == 10 ) {
         Tupla4f posicion = Tupla4f( 0, 0, 0, 0 );
         float pos = 0;

         for( int i=0; i<3; i++ ) {
            pos = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/1000));
            
            if( ( rand() % 100 ) % 2 == 0 ) posicion[i] = -pos;
            else posicion[i] = pos;
         }

         foco6->setPosicion( posicion );

         espera = 0;
      }
   }
   else espera = 9;

   if( avanzando ) {
      trayecto += 5;
      if( trayecto >= 300 ) avanzando = false;
   }
   else {
      trayecto -= 5;
      if( trayecto <= 0 ) avanzando = true;
   }
}



// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************

void Escena::dibujar()
{
   // limpiar pantalla
   clear_window();

   //
   encenderLuces();

   
   //transformar( cubo, { make_pair(E,Tupla4f(10,10,10,0)) } );
   transformar( torre,              { make_pair(E,Tupla4f(8,8,8,0)), make_pair(T,Tupla4f(100,0,-90,0)), make_pair(RO,Tupla4f(0,1,0,70)) } );
   transformar( vaca,               { make_pair(E,Tupla4f(30,30,30,0)), make_pair(T,Tupla4f(-33.3333,0.05,-26.6666,0)) } );
   transformar( cintaMaletas,       { make_pair(E,Tupla4f(35,35,35,0)), make_pair(RO,Tupla4f(0,1,0,180)), make_pair(T,Tupla4f(-8,0,-5,0)) } );
   transformar( avion,              { make_pair(E,Tupla4f(0.75,0.75,0.75,0)), make_pair(T,Tupla4f(-900,15,700,0)), make_pair(RO,Tupla4f(1,0,0,-90)) } );
   transformar( cartelPublicidad,   { make_pair(T,Tupla4f(-1000,0.05,-800,0)), make_pair(RO,Tupla4f(0,1,0,45)) } );
   transformar( sueloCesped,        { make_pair(T,Tupla4f(-1500,0.05,-900,0)), make_pair(RO,Tupla4f(0,1,0,-10)), make_pair(E,Tupla4f(0.5,1,1.5,0)), make_pair(RO,Tupla4f(1,0,0,-90)) } );
   transformar( sueloPavimento,     { make_pair(T,Tupla4f(0,-0.05,0,0)), make_pair(RO,Tupla4f(1,0,0,-90)) } );
   transformar( esferaCielo,        { make_pair(E,Tupla4f(3000,3000,3000,0)), make_pair(RO,Tupla4f(0,0,1,180)), make_pair(T,Tupla4f(0,-0.5,0,0)) } );
}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada( unsigned char tecla, int x, int y )
{
   bool salir = false;

   switch( toupper(tecla) )
   {
      case '0' :
         if( modoMenu == SELMANUAL and elegirMovimientoCintaMaletas ) 
            if( !activaCintaMaletas[0] ) activaCintaMaletas[0] = true;
            else activaCintaMaletas[0] = false;
         else if( ilu and modoMenu == SELVISUALIZACION )
            if( !lucesActivas[0] ) lucesActivas[0] = true;
            else lucesActivas[0] = false;
         else if( modoMenu == SELMANUAL )
            gradoLibertadMJ = 0;
         else if( modoMenu == SELCAMARA ) {
            camaraActiva = 0;
            change_projection();
         }
         break;
      case '1' :
         if( modoMenu == SELMANUAL and elegirMovimientoCintaMaletas ) 
            if( !activaCintaMaletas[1] ) activaCintaMaletas[1] = true;
            else activaCintaMaletas[1] = false;
         else if( ilu and modoMenu == SELVISUALIZACION )
            if( !lucesActivas[1] ) lucesActivas[1] = true;
            else lucesActivas[1] = false;
         else if( modoMenu == SELMANUAL )
            gradoLibertadMJ = 1;
         else if( modoMenu == SELCAMARA ) {
            camaraActiva = 1;
            change_projection();
         }
         break;
      case '2' :
         if(  modoMenu == SELMANUAL and elegirMovimientoCintaMaletas ) 
            if( !activaCintaMaletas[2] ) activaCintaMaletas[2] = true;
            else activaCintaMaletas[2] = false;
         else if( ilu and modoMenu == SELVISUALIZACION )
            if( !lucesActivas[2] ) lucesActivas[2] = true;
            else lucesActivas[2] = false;
         else if( modoMenu == SELMANUAL )
            gradoLibertadMJ = 2;
         else if( modoMenu == SELCAMARA ) {
            camaraActiva = 2;
            change_projection();
         } 
         break;
      case '3' :
         if( ilu and modoMenu == SELVISUALIZACION )
            if( !lucesActivas[3] ) lucesActivas[3] = true;
            else lucesActivas[3] = false;
         else if( modoMenu == SELCAMARA ) {
            camaraActiva = 3;
            change_projection();
         }
         break;
      case '4' :
         if( ilu and modoMenu == SELVISUALIZACION )
            if( !lucesActivas[4] ) lucesActivas[4] = true;
            else lucesActivas[4] = false;
         break;
      case '5' :
         if( ilu and modoMenu == SELVISUALIZACION )
            if( !lucesActivas[5] ) lucesActivas[5] = true;
            else lucesActivas[5] = false;
         break;
      case '6' :
         if( ilu and modoMenu == SELVISUALIZACION )
            if( !lucesActivas[6] ) lucesActivas[6] = true;
            else lucesActivas[6] = false;
         break;
      case '7' :
         if( ilu and modoMenu == SELVISUALIZACION )
            if( !lucesActivas[7] ) lucesActivas[7] = true;
            else lucesActivas[7] = false;
         break;


      ////////////


      // visualiza/oculta cubo
      case 'C' :
         modoMenu = SELCAMARA;
         break;

      // visualiza/oculta piramide
      case 'P' :
         if( ilu and modoMenu == SELVISUALIZACION )
            if( !animacionLuzPuntual ) animacionLuzPuntual = true;
            else animacionLuzPuntual = false; 
         break;


      ////////////


      //
      case 'D' :
         if ( modoMenu == SELVISUALIZACION )
            if ( !visualizacionActiva[0] ) visualizacionActiva[0] = true;
            else visualizacionActiva[0] = false;
         break;

      //
      case 'L' :
         if ( modoMenu == SELVISUALIZACION )
            if ( !visualizacionActiva[1] ) visualizacionActiva[1] = true;
            else visualizacionActiva[1] = false;
         break;

      //
      case 'S' :
         if ( modoMenu == SELVISUALIZACION )
            if ( !visualizacionActiva[2] ) visualizacionActiva[2] = true;
            else visualizacionActiva[2] = false;

         else if( ilu )
            if ( !visualizacionActiva[3] ) {
               visualizacionActiva[3] = true;
               if( visualizacionActiva[4] ) visualizacionActiva[4] = false;
            }
            else visualizacionActiva[3] = false;
         break;


      ////////////


      case 'F' :
         if( ilu and SELVISUALIZACION )
            if( !visualizacionActiva[4] ) {
               visualizacionActiva[4] = true;
               if( visualizacionActiva[3] ) visualizacionActiva[3] = false;
            }
            else {
               visualizacionActiva[4] = false;
               visualizacionActiva[3] = true;
            }
         break;

      case 'A' :
         // variacion del ángulo alpha
         if( ilu and modoMenu == SELVISUALIZACION )
            if( !lucesActivas[8] ) {
               lucesActivas[8] = true;
               if( lucesActivas[9] ) lucesActivas[9] = false;
            }
            else lucesActivas[8] = false;
         else {
            modoMenu = SELAUTOMATICO;
            if( !selAutomatico ) selAutomatico = true;
            else selAutomatico = false;
         }
         break;

      case 'B' :
         // variacion del ángulo beta
         if( ilu and modoMenu == SELVISUALIZACION )
            if( !lucesActivas[9] ) {
               lucesActivas[9] = true;
               if( lucesActivas[8] ) lucesActivas[8] = false;
            }
            else lucesActivas[9] = false;
         break;

      case '>' :
         if( ilu and modoMenu == SELVISUALIZACION ) {
            if( lucesActivas[8] and lucesActivas[7] ) foco7->variarAnguloAlpha( 10 * M_PI / 180 );
            else if( lucesActivas[9] and lucesActivas[7] ) foco7->variarAnguloBeta( 10 * M_PI / 180 );
         }
         break;
      
      case '<' :
         if( ilu and modoMenu == SELVISUALIZACION )
            if( lucesActivas[8] and lucesActivas[7] ) foco7->variarAnguloAlpha( -6 * M_PI / 180 );
            else if( lucesActivas[9] and lucesActivas[7] ) foco7->variarAnguloBeta( -6 * M_PI / 180 );
         break;

      case 'R' : // reiniciar pos luz direccional
         if( ilu and modoMenu == SELVISUALIZACION ){
            if( lucesActivas[7] ) foco7->resetAngulos();
            if( lucesActivas[8] ) lucesActivas[8] = false;
            if( lucesActivas[9] ) lucesActivas[9] = false;
         }
         break;


      ////////////


      // sale del modo en el que se encuentre
      case 'Q' :
         if ( modoMenu!=NADA ) modoMenu=NADA;            
         else salir=true;
         break;
      
      case 'I' :
         // ESTAMOS EN MODO SELECCION DE ILUMINACION
         if( modoMenu == SELVISUALIZACION )
            if( !ilu ) ilu = true;
            else ilu = false;
         break;

      case 'O' :
         // ESTAMOS EN MODO SELECCION DE OBJETO
         modoMenu=SELOBJETO;
         break;

      case 'V' :
         // ESTAMOS EN MODO SELECCION DE MODO DE VISUALIZACION
         modoMenu=SELVISUALIZACION;
         break;

      case 'N' :
         if( !fondoNegro ) fondoNegro = true;
         else fondoNegro = false;
         break;


      ////////////
      
      
      case 'M' :
         modoMenu = SELMANUAL;
         break;

      case 'E' : //
         if( modoMenu == SELMANUAL )
            if( elegirMovimientoCintaMaletas ) elegirMovimientoCintaMaletas = false;
            else elegirMovimientoCintaMaletas = true;
         break;

      case '+' : // aumentar angulo rampa
         if( selAutomatico ) variarVelocidadAnimacion( 0.5 );
         else if( modoMenu == SELMANUAL )
            switch ( gradoLibertadMJ ) {
            case 0: cintaMaletas->variarAnguloGiro(2); break;
            case 1: cintaMaletas->variarAnguloElevacion(2); break;
            case 2: cintaMaletas->variarIncrementoLargo(0.05); break;
            }
         break;

      case '-' : // aumentar angulo rampa
         if( selAutomatico ) variarVelocidadAnimacion( -0.5 );
         else if( modoMenu == SELMANUAL )
            switch ( gradoLibertadMJ ) {
            case 0: cintaMaletas->variarAnguloGiro(-2); break;
            case 1: cintaMaletas->variarAnguloElevacion(-2); break;
            case 2: cintaMaletas->variarIncrementoLargo(-0.05); break;
            }
         break;
   }

   if( visualizacionActiva[3] ) glShadeModel( GL_SMOOTH );
   else if( visualizacionActiva[4] ) glShadeModel( GL_FLAT );

   mostrarInformacion();

   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         //Observer_angle_y-- ;
         camaras[camaraActiva]->moverAccion( IZQUIERDA, 15 );
         break;
	   case GLUT_KEY_RIGHT:
         //Observer_angle_y++ ;
         camaras[camaraActiva]->moverAccion( DERECHA, 15 );
         break;
	   case GLUT_KEY_UP:
         //Observer_angle_x-- ;
         camaras[camaraActiva]->moverAccion( AVANZAR, 15 );
         break;
	   case GLUT_KEY_DOWN:
         //Observer_angle_x++ ;
         camaras[camaraActiva]->moverAccion( RETROCEDER, 15 );
         break;
	   case GLUT_KEY_PAGE_UP:
         //Observer_distance *=1.2 ;
         break;
	   case GLUT_KEY_PAGE_DOWN:
         //Observer_distance /= 1.2 ;
         break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( /*const float ratio_xy*/ )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   //const float wx = float(Height)*ratio_xy ;
   //glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );

   camaras[camaraActiva]->setProyeccion();
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();

   glOrtho( 0, Width, Height, 0, 1, -1 );

   float ratioX = newWidth / Width;
   float ratioY = newHeight / Height;
   float ratio;

   if( ratioX < ratioY )
      ratio = ratioX;
   else
      ratio = ratioY;

   float viewWidth = Width * ratio;
   float viewHeight = Height * ratio;

   float viewX = ( newWidth - viewWidth ) / 2;
   float viewY = ( newHeight - viewHeight ) / 2;

   float wx = (float)Height * viewHeight / viewWidth;

   camaras[camaraActiva]->setDimensiones( wx, Height );
   camaras[camaraActiva]->setWidth_High( newWidth, newHeight );

   change_projection();

   glViewport( viewX, viewY, viewWidth, viewHeight );

   glMatrixMode( GL_MODELVIEW );

   glLoadIdentity();

   /*Width  = newWidth/10;
   Height = newHeight/10;
   change_projection( /*float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );*/
}

//********************************* *****************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   /*glTranslatef( 0.0, 0.0, -Observer_distance );
   glRotatef( Observer_angle_y, 0.0 ,1.0, 0.0 );
   glRotatef( Observer_angle_x, 1.0, 0.0, 0.0 );*/
   
   camaras[camaraActiva]->setObserver();
}



//
void Escena::variarVelocidadAnimacion( float incremento )
{
   float nuevaVelocidad = velocidadAnimacion + incremento;

   if( nuevaVelocidad >= MINvelocidadAnimacion and nuevaVelocidad <= MAXvelocidadAnimacion ) velocidadAnimacion = nuevaVelocidad;
   else if( nuevaVelocidad > MAXvelocidadAnimacion ) velocidadAnimacion = MAXvelocidadAnimacion;
   else velocidadAnimacion = MINvelocidadAnimacion;
}


//
void Escena::clear_window()
{
   bool reactivarLuz = false, reactivarTextura = false;

   if( fondoNegro ) glClearColor( 0, 0, 0, 0 );
   else glClearColor( 1, 1, 1, 1 );

   // limpiar la pantalla
   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

   // cambiar punto de vista observador
   change_observer();

   // asignar ancho lineas ejes
   glLineWidth( 1.0f );

   
   // dibujar ejes
   if( glIsEnabled( GL_LIGHTING ) ) {
      glDisable( GL_LIGHTING );
      reactivarLuz = true;
   }
   if( glIsEnabled( GL_TEXTURE_2D ) ) {
      glDisable( GL_TEXTURE_2D );
      reactivarTextura = true;
   }
   ejes.draw();
   if( reactivarLuz ) glEnable( GL_LIGHTING );
   if( reactivarTextura ) glEnable( GL_TEXTURE_2D );
}


//
void Escena::iniVisualizaciones()
{
   activaCintaMaletas.resize(3);

   visualizacionActiva.resize(5);

   for( int i=0; i<visualizacionActiva.size(); i++ )
      if( visualizacionActiva[i] != false )
         visualizacionActiva[i] = false;


   lucesActivas.resize(10);

   for( int i=0; i<lucesActivas.size(); i++ )
      if( lucesActivas[i] != false )
         lucesActivas[i] = false;
}


template <class TipoObjeto>
void Escena::dibujarObjeto( TipoObjeto * objeto )
{
   for( int i=0; i<visualizacionActiva.size(); i++ )
      if( visualizacionActiva[i] )
      {
         setDrawMode( objeto, i );

         if( objeto != nullptr ) objeto->draw();
      }
}


template <class TipoObjeto>
void Escena::setDrawMode( TipoObjeto * objeto, int mVisu )
{
   switch ( mVisu )
   {
   case 0:
      objeto->setPolygonMode( GL_POINT );
      glPolygonMode( GL_FRONT, GL_POINT );
      // asignar ancho puntos
      glPointSize( 2 );
      break;

   case 1:
      objeto->setPolygonMode( GL_LINE );
      glPolygonMode( GL_FRONT, GL_LINE );
      // asignar ancho lineas
      if( debug == P1 ) glLineWidth( 3 );
      else glLineWidth( 1 );
      break;

   default:
      objeto->setPolygonMode(GL_FILL);
      glPolygonMode( GL_FRONT, GL_FILL );
      break;
   }
}


template <class TipoObjeto>
void Escena::transformar( TipoObjeto * objeto, const std::vector<pair<transformaciones,Tupla4f>> & transf ) 
{
   bool reactivarTextura = false;

   glPushMatrix();

      for( int i=0; i<transf.size(); i++ ){
         Tupla4f valores(transf[i].second);

         switch ( transformaciones( transf[i].first ) ) {
            case T:
               glTranslatef( valores[0], valores[1], valores[2] );
               break;
            
            case E:
               glScalef( valores[0], valores[1], valores[2] );
               break;

            case RO:
               glRotatef( valores[3], valores[0], valores[1], valores[2] );
               break;

            /*case CIZALLA:
               ??¿¿
               break;*/

            default:
               std::cout << std::endl << std::endl << "No se ha aplicado la transformacion " << i << std::endl << std::endl;
               break;
         }
      }


      if( !objeto->tieneTextura() and glIsEnabled( GL_TEXTURE_2D ) ) {
         glDisable( GL_TEXTURE_2D );
         reactivarTextura = true;
      }

      dibujarObjeto( objeto );

      if( reactivarTextura ) glEnable( GL_TEXTURE_2D );

      /*GLint id_ = objeto->getID();

      for( int i=0; i<16; i++ ) model_matrix[i] = 0;

      if( id_ == cartelPublicidad->getID() ) {
         glGetFloatv( GL_MODELVIEW_MATRIX, model_matrix );
         pos_objetos[0] = Tupla3f( (float)model_matrix[12], (float)model_matrix[13], (float)model_matrix[14] );
      }
      else if( id_ == avion->getID() ) {
         glGetFloatv( GL_MODELVIEW_MATRIX, model_matrix );
         pos_objetos[1] = Tupla3f( (float)model_matrix[12], (float)model_matrix[13], (float)model_matrix[14] );
      }*/

      /*case rampa:
         break;

      case torre:*/

   glPopMatrix();
}


void Escena::encenderLuces()
{
   if( ilu ) glEnable( GL_LIGHTING );
   else if( glIsEnabled( GL_LIGHTING ) ) glDisable( GL_LIGHTING );

   for( int i=0; i<lucesActivas.size()-2; i++ ) {
      Luz l = obtenerLuz(i);
      bool activa = glIsEnabled(l.getId()); 

      if( lucesActivas[i] and !activa ) l.activar();
      else if( !lucesActivas[i] and activa ) l.desactivar();
   }
}

Luz Escena::obtenerLuz( int i )
{
   Luz l;

   switch (i)
   {
   case 1:
      l = *foco1;
      break;
   
   case 2:
      l = *foco2;
      break;

   case 3:
      l = *foco3;
      break;
    
   case 4:
      l = *foco4;
      break;

   case 5:
      l = *foco5;
      break;
   
   case 6:
      l = *foco6;
      break;

   case 7:
      l = *foco7;
      break;
   
   default:
      l = *foco0;
      break;
   }

   return l;
}



void Escena::mostrarInformacion()
{
   cout << endl;

   if( modoMenu == SELAUTOMATICO ) {
      if( velocidadAnimacion == 0 ) cout << endl << "El objeto está parado (velocidad == 0)." << endl;
      else cout << endl << "El objeto está en movimiento (velocidad = " << velocidadAnimacion << ")." << endl;
   }

   if( elegirMovimientoCintaMaletas ) {
      cout << endl << "Está activo el modo elegir movimiento rampa.";

      cout << endl << "Movimientos de la rampa activos (giro,elevación,extensión): ";
      for(int i=0;i<activaCintaMaletas.size();i++) cout << activaCintaMaletas[i] << " ";
      cout << endl;
   }

   if( ilu ) {
      cout << endl << "Está activo el modo iluminación.";

      if( !elegirMovimientoCintaMaletas ) {
         cout << endl << "Focos de luz activados (0-7): ";
         for(int i=0;i<lucesActivas.size();i++) cout << lucesActivas[i] << " ";
         cout << endl;
      }
   }

   if( lucesActivas[7] ) cout << endl << "Está activa la luz direccional (\"foco\" 7).";
   if( lucesActivas[8] and lucesActivas[7] ) cout << endl << "Está activa la variación del angulo alpha. Ángulo: " << foco7->getAnguloAlpha();
   else if( lucesActivas[9] and lucesActivas[7] ) cout << endl << "Está activa la variación del angulo beta. Ángulo: " << foco7->getAnguloBeta();

   //cout << endl << "Visu: ";
   //for(int i=0;i<visualizacionActiva.size();i++) cout << visualizacionActiva[i] << " ";
   //cout << endl;

   cout << endl;
}


void Escena::clickRaton( int boton, int estado, int x, int y )
{
   switch( boton ) {

      case GLUT_RIGHT_BUTTON:
         if( estado == GLUT_DOWN ) {
            botonDerchPulsado = true;
            x1 = x;
            y1 = y;
         }
         else botonDerchPulsado = false;
         break;
      
      case GLUT_LEFT_BUTTON:
         if( estado == GLUT_DOWN ) {
            //dibujarSeleccion( x, y );

            //if( hayObjSeleccionado ) camaras[camaraActiva]->setObjSeleccionado( pos_objetos[objSeleccionado] );
         }
         break;

      case 3:
         if( estado == GLUT_UP ) camaras[camaraActiva]->zoom(2);
         change_projection();
         break;
      
      case 4:
         if( estado == GLUT_UP ) camaras[camaraActiva]->zoom(-2);
         change_projection();
         break;

   }
}

void Escena::ratonMovido( int x, int y )
{
   if( hayObjSeleccionado and botonDerchPulsado ) {
      camaras[camaraActiva]->rotarXExaminar( (x - x1) * 0.0025 );
      camaras[camaraActiva]->rotarYExaminar( (y - y1) * 0.0025 );
   }
   else if( botonDerchPulsado ) {
      camaras[camaraActiva]->rotarXFirstPerson( (x - x1) * 0.0025 );
      camaras[camaraActiva]->rotarYFirstPerson( (y - y1) * 0.0025 );
   }
   //else botonDerchPulsado = false;
   x1 = x; y1 = y;
}

void Escena::dibujarSeleccion( float x, float y ) {
   glDisable( GL_DITHER );
   glDisable( GL_TEXTURE_2D );

   bool luces_activas = false;

   if( glIsEnabled( GL_LIGHTING ) ) {
      luces_activas = true;
      glDisable( GL_LIGHTING );
   }

   for( int i=0; i<numObjSeleccionables; i++ ) {
      glPushMatrix();
         switch (i) {
            case 0:
               avion->setColor( Tupla3f(0.9,0,0), Tupla3f(0.9,0,0), Tupla3f(0.9,0,0) );
               transformar( avion, { make_pair(E,Tupla4f(0.75,0.75,0.75,0)), make_pair(T,Tupla4f(-900,15,700,0)), make_pair(RO,Tupla4f(1,0,0,-90)) } );
               break;

            case 1:
               cartelPublicidad->setColor( Tupla3f(0.8,0,0), Tupla3f(0.8,0,0), Tupla3f(0.8,0,0) );
               transformar( cartelPublicidad, { make_pair(T,Tupla4f(-900,0,-900,0)), make_pair(RO,Tupla4f(0,1,0,45)) } );
               break;
            
            default:
               break;
         }
      glPopMatrix();
   }


   GLint viewport[4];
   GLfloat pixel[3];

   glGetIntegerv( GL_VIEWPORT, viewport );

   glReadPixels( x, viewport[3]-y, 1, 1, GL_RGB, GL_FLOAT, (void *)pixel );

   cout << endl << "Pixel: " << pixel[0] << endl;

   if( pixel[0] == 0.9 ) {
      objSeleccionado = 0;       // avion
      hayObjSeleccionado = true;
   }
   else if( pixel[0] == 0.8 ) {
      objSeleccionado = 1;       // cartelPublicidad
      hayObjSeleccionado = true;
   }
   else hayObjSeleccionado = false;


   if( luces_activas ) glEnable( GL_LIGHTING );

   glEnable( GL_TEXTURE_2D );
   glEnable( GL_DITHER );

   avion->setColor( coloresCopia[0][0], coloresCopia[0][1], coloresCopia[0][2] );
   cartelPublicidad->setColor( coloresCopia[1][0], coloresCopia[1][1], coloresCopia[1][2] );
}