#include "coordenadas.h"

Coordenadas::Coordenadas()
{
    controlador();
}

Coordenadas::~Coordenadas()
{

}

void Coordenadas::controlador()
{
    dimensionar_vector();
    llenar_vector();

    // Para efectos de esta tarea, solo se va a necesitar las hojas de "Altos y reductores".
    // Leo los del archivos respectivos.  OJO, ruta NO general, hay que especificar la ruta junto con los nombres.
    leer_archivo("C:\\Users\\defaultuser\\Desktop\\N.csv",  '0');
    leer_archivo("C:\\Users\\defaultuser\\Desktop\\S.csv",  '1');
    leer_archivo("C:\\Users\\defaultuser\\Desktop\\E.csv",  '2');
    leer_archivo("C:\\Users\\defaultuser\\Desktop\\O.csv",  '3');
    leer_archivo("C:\\Users\\defaultuser\\Desktop\\NE.csv", '4');
    leer_archivo("C:\\Users\\defaultuser\\Desktop\\SE.csv", '5');
    leer_archivo("C:\\Users\\defaultuser\\Desktop\\NO.csv", '6');
    leer_archivo("C:\\Users\\defaultuser\\Desktop\\SO.csv", '7');
}

std::vector< std::vector< std::vector< std::vector<char> > > > Coordenadas::getVector() {
    return vector_coordenadas;
}


/*
 * Función que procesa un string para poder asignarle valores al vector coordenadas.
 * Por parámetro recibe el string de la línea del archivo.
 * Además del número de fila, donde se encuentra (se asume que al inicio debería de pasar un 0).
 */
void Coordenadas::procesar_linea( std::string linea, size_t numero_fila, char direccion )
{
    // Lo que hay que restar para poder asignar el vector desde 0.
    size_t contador_calles = 0;
    size_t contador = retornar_tercer_cuadro(linea); // Variable para recorrer línea.

    char numero_string[] = "       "; // Se asume que por cuadro hay pocos caracteres.

    size_t contador_numero = 0;
    int numero_recibido = 0;

    while( contador < linea.size() )
    {
#if DEBUG
        std::cout << linea[contador];
#endif
        if( linea[contador] != ',' )
        {
            do
            {
                numero_string[contador_numero] = linea[contador];
                ++contador;
                ++contador_numero;

            }while( linea[contador] != ',' && contador < linea.size() );

            numero_string[contador_numero] = '\0'; // Agregar fin de línea para atoi.

            // Convierto el número recibido.
            numero_recibido = atoi(numero_string);

            // Asigno valor al vector_coordenadas
            // Note que tengo que restar la coordenada calle, por que al iniciar, contador no es 0.
            asginar_valor_vector_coordenadas(numero_recibido, direccion, numero_fila, contador_calles );

            contador_numero = 0; // Restauro valor.
        }
        ++contador_calles; // Cada vez que se pasa una coma, se está recorriendo una calle.
        ++contador;
    }
}

/*
 * Direcciones:
 * 0: Norte
 * 1: Sur
 * 2: Este
 * 3: Oeste
 * 4: Noreste
 * 5: Sureste
 * 6: Noroeste
 * 7: Suroeste
 */
void Coordenadas::asginar_valor_vector_coordenadas(int numero_recibido, char direccion, size_t avenida, size_t calle)
{
    int avenida_destino = avenida;
    int calle_destino = calle;

    // El switch modifica avenida_destino y calle_destino, conforme a la dirección, el desplazamiento varía.
    switch (direccion)
    {
        case '0': // N
        {
            --avenida_destino;
            break;
        }
        case '1': // S
        {
            ++avenida_destino;
            break;
        }
        case '2': // E
        {
            ++calle_destino;
            break;
        }
        case '3': // O
        {
            --calle_destino;
            break;
        }
        case '4': // NE
        {
            --avenida_destino;
            ++calle_destino;
            break;
        }
        case '5': // SE
        {
            ++avenida_destino;
            ++calle_destino;
            break;
        }
        case '6': // NO
        {
            --avenida_destino;
            --calle_destino;
            break;
        }
        default: // SO
        {
            ++avenida_destino;
            --calle_destino;
        }
    }

    // Asigna el valor captado en el vector.
    vector_coordenadas[avenida][calle][avenida_destino][calle_destino] =  numero_recibido;
}

/*
 * Leer un archivo, el cual el nombre se pasa por parámetro.
 * Luego de leer la línea, asigna los valores respectivos al vector coordenadas.
 * Note que con el nombre se tiene que pasar con la extensión, en este caso, .csv
 * Puede que se tenga que poner la ruta del archivo.
 */
void Coordenadas::leer_archivo( std::string nombre_archivo, char direccion )
{
    std::ifstream archivo(nombre_archivo.data());
    std::string linea;

    size_t posicion_fila = 0;

    if( archivo.is_open() == true ) // Si se abrió correctamente el archivo.
    {
        // Empezar a leer desde la tercera línea.
        for( short contador = 1; contador < 3; ++contador )
            std::getline(archivo, linea);

        while( archivo.eof() == false ) // Mientras no haya llegado al final del archivo.
        {
            std::getline(archivo, linea); // Lee una línea del archivo.
            procesar_linea(linea, posicion_fila, direccion);
            ++posicion_fila;

#if DEBUG
            std::cout << linea << std::endl;
#endif
        }
    }
    else
    {
        std::cerr << "Error al abrir " << nombre_archivo << std::endl;
    }

    archivo.close(); // Cerrar el archivo, obligatorio en todo caso.
}

// Llena el vector de -1's
void Coordenadas::llenar_vector()
{
    for( size_t contador_avenidas_partida = 0; contador_avenidas_partida < AVENIDAS; ++contador_avenidas_partida )
        for( size_t contador_calles_partida = 0; contador_calles_partida < CALLES; ++contador_calles_partida )
            for( size_t contador_avenidas_meta = 0; contador_avenidas_meta < AVENIDAS; ++contador_avenidas_meta )
                for( size_t contador_calles_meta = 0; contador_calles_meta < CALLES; ++contador_calles_meta )
                    vector_coordenadas[contador_avenidas_partida][contador_calles_partida][contador_avenidas_meta][contador_calles_meta] = -1;
}

void Coordenadas::dimensionar_vector()
{
    vector_coordenadas.resize(AVENIDAS);

    for( size_t contador_avenidas = 0; contador_avenidas < AVENIDAS; ++contador_avenidas )
        vector_coordenadas[contador_avenidas].resize(CALLES);

    for( size_t contador_avenidas = 0; contador_avenidas < AVENIDAS; ++contador_avenidas )
        for( size_t contador_calles = 0; contador_calles < CALLES; ++contador_calles )
            vector_coordenadas[contador_avenidas][contador_calles].resize(AVENIDAS);

    for( size_t contador_avenidas = 0; contador_avenidas < AVENIDAS; ++contador_avenidas )
        for( size_t contador_calles = 0; contador_calles < CALLES; ++contador_calles )
            for( size_t contador_avenidas_meta = 0; contador_avenidas_meta < AVENIDAS; ++contador_avenidas_meta )
                vector_coordenadas[contador_avenidas][contador_calles][contador_avenidas_meta].resize(CALLES);
}

// Retorna el contador al inicio del tercer cuadro.
size_t Coordenadas::retornar_tercer_cuadro(std::string linea)
{
    size_t contador = 0;
    int contador_comas = 0;

    // Buscar la segunda coma.  Después de la seguna coma es el inicio del tercer cuadro.
    while( contador < linea.size() && contador_comas < 2  )
    {
        if( linea[contador] == ',' ) // Si no es coma,
        {
            ++contador_comas;
        }
        ++contador;
    }
    return contador;
}
