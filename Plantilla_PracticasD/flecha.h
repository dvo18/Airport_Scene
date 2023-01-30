
#ifndef FLECHA_H_INCLUDED
#define FLECHA_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"


class Flecha : public ObjRevolucion
{
   public:
   Flecha( const float hPunta = 1, const float hAstil = 1, const int nRev = 30 );
} ;


#endif