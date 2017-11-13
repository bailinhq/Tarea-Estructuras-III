/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buscadorRuta.cpp
 * Author: Bailin
 * 
 * Created on 12 de noviembre de 2017, 12:11 PM
 */
#include "coordenadas/Coordenadas/coordenadas.h"
#include "buscadorRuta.h"

buscadorRuta::buscadorRuta() {
    coordenada = new Coordenadas();
    vector_coordenada = coordenada->getVector();
}

buscadorRuta::buscadorRuta(const buscadorRuta& orig) {
}

buscadorRuta::~buscadorRuta() {
}

int buscadorRuta::buscarExhaustiva(int origenC,int origenA, int destinoC, int destinoA) {
    if(origenC == destinoC && origenA == destinoA){
        return 0;
    }else{
    int mejorValor = -1;
    if(origenA > destinoA){ //vamos para arriba
        if(origenC > destinoC){//hacia la izquierda
            int valor1 = vector_coordenada[origenA][origenC][origenA][origenC-1];
            if(valor1 != -1){
                valor1 += buscarExhaustiva(origenC-1, origenA, destinoC, destinoA);
            }
            int valor2 = vector_coordenada[origenA][origenC][origenA-1][origenC-1];
            if(valor2 != -1){
                valor2 += buscarExhaustiva(origenC-1, origenA-1, destinoC, destinoA);
            }
            int valor3 = vector_coordenada[origenA][origenC][origenA-1][origenC];
            if(valor3 != -1){
                valor3 += buscarExhaustiva(origenC, origenA-1, destinoC, destinoA);
            }
            if(valor1 != -1){
                mejorValor = valor1;
            }
            if(valor2 != -1){
                if(mejorValor > valor2){
                    mejorValor = valor2;
                }
            }
            if(valor3 != -1){
                if(mejorValor > valor3){
                    mejorValor = valor3;
                }
            }
        } else{//hacia la derecha
            int valor1 = vector_coordenada[origenA][origenC][origenA][origenC+1];
            if(valor1 != -1){
                valor1 += buscarExhaustiva(origenC+1, origenA, destinoC, destinoA);
            }
            int valor2 = vector_coordenada[origenA][origenC][origenA-1][origenC+1];
            if(valor2 != -1){
                valor2 += buscarExhaustiva(origenC+1, origenA-1, destinoC, destinoA);
            }
            int valor3 = vector_coordenada[origenA][origenC][origenA-1][origenC];
            if(valor3 != -1){
                valor3 += buscarExhaustiva(origenC, origenA-1, destinoC, destinoA);
            }
            if(valor1 != -1){
                mejorValor = valor1;
            }
            if(valor2 != -1){
                if(mejorValor > valor2){
                    mejorValor = valor2;
                }
            }
            if(valor3 != -1){
                if(mejorValor > valor3){
                    mejorValor = valor3;
                }
            }
        }
    } else{ //vamos para abajo
        if(origenC > destinoC){//hacia la izq
            int valor1 = vector_coordenada[origenA][origenC][origenA][origenC-1];
            if(valor1 != -1){
                valor1 += buscarExhaustiva(origenC-1, origenA, destinoC, destinoA);
            }
            int valor2 = vector_coordenada[origenA][origenC][origenA+1][origenC-1];
            if(valor2 != -1){
                valor2 += buscarExhaustiva(origenC-1, origenA+1, destinoC, destinoA);
            }
            int valor3 = vector_coordenada[origenA][origenC][origenA+1][origenC];
            if(valor3 != -1){
                valor3 += buscarExhaustiva(origenC, origenA+1, destinoC, destinoA);
            }
            if(valor1 != -1){
                mejorValor = valor1;
            }
            if(valor2 != -1){
                if(mejorValor > valor2){
                    mejorValor = valor2;
                }
            }
            if(valor3 != -1){
                if(mejorValor > valor3){
                    mejorValor = valor3;
                }
            }
        } else{// hacia la derecha
            int valor1 = vector_coordenada[origenA][origenC][origenA][origenC+1];
            if(valor1 != -1){
                valor1 += buscarExhaustiva(origenC+1, origenA, destinoC, destinoA);
            }
            int valor2 = vector_coordenada[origenA][origenC][origenA+1][origenC+1];
            if(valor2 != -1){
                valor2 += buscarExhaustiva(origenC+1, origenA+1, destinoC, destinoA);
            }
            int valor3 = vector_coordenada[origenA][origenC][origenA+1][origenC];
            if(valor3 != -1){
                valor3 += buscarExhaustiva(origenC, origenA+1, destinoC, destinoA);
            }
            if(valor1 != -1){
                mejorValor = valor1;
            }
            if(valor2 != -1){
                if(mejorValor > valor2){
                    mejorValor = valor2;
                }
            }
            if(valor3 != -1){
                if(mejorValor > valor3){
                    mejorValor = valor3;
                }
            }
        }
    }
    return mejorValor;
    }
}

void buscadorRuta::exhaustivaIzquierda(int origenC,int origenA, int destinoC, int destinoA){
    
    
}

void buscadorRuta::exhaustivaDerecha(int origenC,int origenA, int destinoC, int destinoA){
    
}