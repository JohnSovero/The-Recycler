#pragma once
#include <vector>
#include "MateriaO.h"
#include "Metales.h"
#include "Papeles.h"
#include "Plastico.h"
#include "Vidrios.h"
#include "Base.h"
#include <time.h>
using namespace std;

class Contaminadores :
    public Base
{
private:
    vector<Metales*>arr_metal;
    vector<MateriaO*>arr_materiaO;
    vector<Papeles*>arr_papel;
    vector<Plastico*>arr_plastico;
    vector<Vidrios*>arr_vidrio;
public:
    Contaminadores(int _x,int _y);
    ~Contaminadores();
    void Mover(Graphics^ g);
    void Tira_Basura(bool nivel2);
    void Dibujar_Basura(Graphics^g,Bitmap^bmp_metal, Bitmap^ bmp_materiaO,
        Bitmap^ bmp_papel, Bitmap^ bmp_plastico, Bitmap^ bmp_vidrio);
    vector<Metales*>retornar_arr_metal();
    vector<MateriaO*>retornar_arr_materia();
    vector<Papeles*>retornar_arr_papel();
    vector<Plastico*>retornar_arr_plastico();
    vector<Vidrios*>retornar_arr_vidrio();
    int retornar_can_metal();
    int retornar_can_materia();
    int retornar_can_papel();
    int retornar_can_plastico();
    int retornar_can_vidrio();
    Metales* retornar_metal(int i);
    MateriaO* retornar_materia(int i);
    Papeles* retornar_papel(int i);
    Plastico* retornar_plastico(int i);
    Vidrios* retornar_vidrio(int i);
};

