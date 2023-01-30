#include "auxiliar.h"
#include "malla.h"

using namespace std;

// *****************************************************************************
//
// IG_D Clase Malla3D
//
// *****************************************************************************

Malla3D::Malla3D()
{
   id = 0;

   material = new Material();

   id_vbo_ver = 0;
   id_vbo_tri = 0;
   id_vbo_col = 0;

   id_vbo_colP = 0;
   id_vbo_colL = 0;
   id_vbo_colS = 0;

   id_vbo_nor = 0;
   id_vbo_tex = 0;

   polygonMode = GL_FILL;

   repetirTextura = false;
}

Malla3D::Malla3D(const Malla3D & malla)
{
   id = malla.id;

   material = malla.material;

   id_vbo_ver = malla.id_vbo_ver;
   id_vbo_tri = malla.id_vbo_tri;
   id_vbo_col = malla.id_vbo_col;

   id_vbo_colP = malla.id_vbo_colP;
   id_vbo_colL = malla.id_vbo_colL;
   id_vbo_colS = malla.id_vbo_colS;

   id_vbo_nor = malla.id_vbo_nor;
   id_vbo_tex = malla.id_vbo_tex;

   v = malla.v;
   f = malla.f;

   cP = malla.cP;
   cL = malla.cL;
   cS = malla.cS;

   nv = malla.nv;
   ct = malla.ct;

   polygonMode = malla.polygonMode;

   repetirTextura = malla.repetirTextura;
}


// -----------------------------------------------------------------------------
// Función de visualización de la malla,

void Malla3D::draw()
{ 
   bool tieneTextura = textura != nullptr;

   material->aplicar();

   if( id_vbo_ver == 0 ) id_vbo_ver = CrearVBO( GL_ARRAY_BUFFER, sizeof(Tupla3f)*v.size()*3, v.data() );

   if( id_vbo_tri == 0 ) id_vbo_tri = CrearVBO( GL_ELEMENT_ARRAY_BUFFER, sizeof(Tupla3i)*f.size()*3, f.data() );

   if( id_vbo_colP == 0 ) id_vbo_colP = CrearVBO( GL_ARRAY_BUFFER, sizeof(Tupla3f)*cP.size()*3,  cP.data() );
   if( id_vbo_colL == 0 ) id_vbo_colL = CrearVBO( GL_ARRAY_BUFFER, sizeof(Tupla3f)*cL.size()*3,  cL.data() );
   if( id_vbo_colS == 0 ) id_vbo_colS = CrearVBO( GL_ARRAY_BUFFER, sizeof(Tupla3f)*cS.size()*3,  cS.data() );

   if( id_vbo_nor == 0 ) id_vbo_nor = CrearVBO( GL_ARRAY_BUFFER, sizeof(Tupla3f)*nv.size()*3, nv.data() );

   if( tieneTextura and id_vbo_tex == 0 ) id_vbo_tex = CrearVBO( GL_ARRAY_BUFFER, sizeof(Tupla2f)*ct.size()*2, ct.data() );
   

   switch ( polygonMode ) {
      case GL_POINT :
         id_vbo_col = id_vbo_colP;
         break;

      case GL_LINE :
         id_vbo_col = id_vbo_colL;
         break;

      case GL_FILL :
         id_vbo_col = id_vbo_colS;
         break;
   }

   ////////////

   // activar VBO vértices
   glBindBuffer( GL_ARRAY_BUFFER, id_vbo_ver );
   // usar el buffer activo para almacenar los vértices
   glVertexPointer( 3, GL_FLOAT, 0, 0 );
   // desactivar VBO vértices
   glBindBuffer( GL_ARRAY_BUFFER, 0 );

   ////////////

   if( tieneTextura ) {
      glBindBuffer( GL_ARRAY_BUFFER, id_vbo_tex );
      glTexCoordPointer( 2, GL_FLOAT, 0, 0 );
      glBindBuffer( GL_ARRAY_BUFFER, 0 );

      if( repetirTextura ) textura->activar( true );
      else textura->activar();

      glEnableClientState( GL_TEXTURE_COORD_ARRAY );
   }

   /////////////
   
   glBindBuffer( GL_ARRAY_BUFFER, id_vbo_nor );
   glNormalPointer( GL_FLOAT, 0, 0 );
   glBindBuffer( GL_ARRAY_BUFFER, 0 );

   ////////////

   // activar VBO colores
   glBindBuffer( GL_ARRAY_BUFFER, id_vbo_col );
   // usar el buffer activo para almacenar los colores
   glColorPointer( 3, GL_FLOAT, 0, 0 );
   // desactivar VBO colores
   glBindBuffer( GL_ARRAY_BUFFER, 0 );

   ////////////

   // habilitar uso de la tabla de vértices
   glEnableClientState( GL_VERTEX_ARRAY );

   glEnableClientState( GL_NORMAL_ARRAY );

   // habilitar uso de la tabla de colores
   glEnableClientState( GL_COLOR_ARRAY );


   // activar VBO triángulos
   glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri );
   // dibujar con el buffer de índices activo
   glDrawElements( GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0 );
   // desactivar VBO triángulos
   glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );


   if ( tieneTextura ) glDisableClientState( GL_TEXTURE_COORD_ARRAY );

   glDisableClientState( GL_NORMAL_ARRAY );

   // deshabilitar uso de la tabla de colores
   glDisableClientState( GL_COLOR_ARRAY );

   // deshabilitar uso de la tabla de la tabla de vértices
   glDisableClientState( GL_VERTEX_ARRAY );
}



GLuint Malla3D::CrearVBO( GLuint tipo_vbo, GLuint tam, GLvoid * puntero_ram )
{
   // resultado: identificador de VBO 
   GLuint id_vbo;

   // crear nuevo VBO, obtener identificador
   glGenBuffers( 1, & id_vbo );
   // activar el VBO usando su identificador
   glBindBuffer( tipo_vbo, id_vbo );

   //transferencia de datos desde RAM hacia GPU
   glBufferData( tipo_vbo, tam, puntero_ram, GL_STATIC_DRAW );

   // desactivación del VBO (activa 0)
   glBindBuffer( tipo_vbo, 0 );
   
   // devuelve el identificador del VBO
   return id_vbo;
}


void Malla3D::rotacionesPlanoXZ( int maximo, int numSegmentos, float r, float h, float anguloComienzo )
{
   float segmento = 2*M_PI / numSegmentos;

   for(int i=0; i<maximo; i++)
      v.push_back( Tupla3f( r*(float)cos(anguloComienzo + i*segmento), h, -r*(float)sin(anguloComienzo + i*segmento) ) );
}



void Malla3D::setColor( Tupla3f colorP, Tupla3f colorL, Tupla3f colorS )
{
   if( !v.empty() ) {
      rellenarColor( cP, colorP );
      rellenarColor( cL, colorL );
      rellenarColor( cS, colorS );
   }

   id_vbo_colL = 0;
   id_vbo_colP = 0;
   id_vbo_colS = 0;
}

void Malla3D::rellenarColor( std::vector<Tupla3f> & tablaColor, Tupla3f color )
{
   tablaColor.resize(v.size());

   for( int i=0; i<tablaColor.size(); i++ )
      tablaColor[i] = color;
}

TuplaG3<Tupla3f> Malla3D::getColor()
{
   return TuplaG3<Tupla3f>( cP[0], cL[0], cS[0] );
}

double Malla3D::radAGrad( double rad )
{
   return rad * 180 / M_PI;
}

double Malla3D::gradARad( double grados )
{
   return grados * M_PI / 180;
}


/////////////////////////////////////////


void Malla3D::calcularNormales()
{
   if( !v.empty() and !f.empty() ) {
      nv.resize( v.size() );

      for( int i=0; i<f.size(); i++ ) {
         //asignarNormal( f[i], ( ( (Tupla3f)(v[f[i][1]]-v[f[i][0]]) ).cross( (Tupla3f)(v[f[i][2]]-v[f[i][0]]) ) ).normalized() );

         Tupla3f a = v[f[i][1]] - v[f[i][0]];
         Tupla3f b = v[f[i][2]] - v[f[i][0]];

         Tupla3f normalCara = a.cross(b);

         asignarNormal( f[i], normalCara.normalized() );
      }

      //for( int i=0; i<nv.size(); i++ ) nv[i] = nv[i].normalized();

      for( int i=0; i<nv.size(); i++ ) {
         float mod = sqrt( pow(nv[i][0],2) + pow(nv[i][1],2) + pow(nv[i][2],2) );

         nv[i] = Tupla3f( nv[i][0]/mod, nv[i][1]/mod, nv[i][2]/mod );
      }
   }
}

void Malla3D::asignarNormal( Tupla3i cara, Tupla3f normal )
{
   nv[cara[0]] = nv[cara[0]] + normal;
   nv[cara[1]] = nv[cara[1]] + normal;
   nv[cara[2]] = nv[cara[2]] + normal;
}


/////////////////////////////////////////


void Malla3D::setTextura( Textura * t )
{
   textura = t;
}

bool Malla3D::tieneTextura()
{
   return textura != nullptr;
}

void Malla3D::setRepetirTextura( bool repetir )
{
   repetirTextura = repetir;
}



void Malla3D::setPolygonMode( GLenum mode )
{
   polygonMode = mode;
}

void Malla3D::setMaterial( Material * m )
{
   material = m;
}

void Malla3D::setID( GLint i )
{
   id = i;
}

GLint Malla3D::getID()
{
   return id;
}