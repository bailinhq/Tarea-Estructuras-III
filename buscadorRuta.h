/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buscadorRuta.h
 * Author: Bailin
 *
 * Created on 12 de noviembre de 2017, 12:11 PM
 */
#include "coordenadas/Coordenadas/coordenadas.h"
#ifndef BUSCADORRUTA_H
#define BUSCADORRUTA_H

class buscadorRuta {
public:
    buscadorRuta();
    
    buscadorRuta(const buscadorRuta& orig);
    
    virtual ~buscadorRuta();
    
    int buscarExhaustiva(int origenC,int origenA, int destinoC, int destinoA);
    void exhaustivaDerecha(int origenC,int origenA, int destinoC, int destinoA);
    void exhaustivaIzquierda(int origenC,int origenA, int destinoC, int destinoA);
    
private:
    
    Coordenadas *coordenada;
    std::vector< std::vector< std::vector< std::vector<char> > > > vector_coordenada;
};

#endif /* BUSCADORRUTA_H */

