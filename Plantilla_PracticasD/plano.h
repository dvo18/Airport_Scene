
#ifndef PLANO_H_INCLUDED
#define PLANO_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"


class Plano : public Malla3D
{
   public:
   Plano( float tamLado = 1, bool repetirTextura = false ) ;
} ;

#endif
