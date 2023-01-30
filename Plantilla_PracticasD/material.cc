
#include "material.h"


Material::Material() {}

Material::Material( const Material & material )
{
    especular = material.especular;
    ambiental = material.ambiental;
    difusa = material.difusa;
    brillo = material.brillo;
}

Material::Material( Tupla4f mdifuso, Tupla4f mespecular, Tupla4f mambiente, float mbrillo )
{
    especular = mespecular;
    ambiental = mambiente;
    difusa = mdifuso;
    brillo = mbrillo;
}

void Material::aplicar()
{
    glMaterialfv( GL_FRONT, GL_SPECULAR, especular );
    glMaterialfv( GL_FRONT, GL_AMBIENT, ambiental );
    glMaterialfv( GL_FRONT, GL_DIFFUSE, difusa );
    glMaterialf( GL_FRONT, GL_SHININESS, brillo );
}