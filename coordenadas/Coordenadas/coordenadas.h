#ifndef COORDENADAS_H
#define COORDENADAS_H


#define CALLES 120
#define AVENIDAS 120

#define DEBUG 0 // Si DEBUG es 1, se está depurando, si 0, no (se omite o no código).

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>

class Coordenadas
{
    public:
        Coordenadas();
        ~Coordenadas();
        std::vector< std::vector< std::vector< std::vector<char> > > > getVector();

    protected:
        // Para no gastar la memoria del segmento de datos.
        std::vector< std::vector< std::vector< std::vector<char> > > > vector_coordenadas;

        void controlador();
        void dimensionar_vector();
        void llenar_vector();

        void leer_archivo(std::string nombre_archivo , char direccion);
        void procesar_linea(std::string linea, size_t numero_fila , char direccion);

        void asginar_valor_vector_coordenadas(int numero_recibido, char direccion, size_t avenida, size_t calle);

        size_t retornar_tercer_cuadro(std::string linea );
};

#endif // COORDENADAS_H
