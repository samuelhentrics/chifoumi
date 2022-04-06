/***************************************************************
 * Name:      chifoumiMain.h
 * Author:    P.Dagorret ()
 * Created:   2021-05-10
 * Description : classe m�tier (= mod�le) Chifoumi-v1
 **************************************************************/
#include "chifoumi.h"

#include <cstdlib>
#include <ctime>


///* ---- PARTIE MOD�LE ---------------------------

Chifoumi::Chifoumi()
{
    //ctor
    // partie mod�le
    scoreJoueur=0;
    scoreMachine=0;
    coupJoueur=rien;
    coupMachine=rien;

}

Chifoumi::~Chifoumi()
{
    //dtor
}

/// Getters

Chifoumi::UnCoup Chifoumi::getCoupJoueur() {
    return coupJoueur;
}

Chifoumi::UnCoup Chifoumi::getCoupMachine() {
    return coupMachine;
}

unsigned int Chifoumi::getScoreJoueur() {
    return scoreJoueur;
}

unsigned int Chifoumi::getScoreMachine() {
    return scoreMachine;
}

char Chifoumi::determinerGagnant()
{
    char gagnantARetourner;

    // avant de commencer : match nul 
    gagnantARetourner = 'N';

    // il sera modifi� dans l'un des cas suivants

    if (getCoupJoueur()>=0 && getCoupJoueur()<=2
            && getCoupMachine()>=0 && getCoupMachine()<=2){
        if ((getCoupJoueur()>getCoupMachine()) || (getCoupJoueur()==0 && getCoupMachine()==3)){
            gagnantARetourner = 'J';
        }
        if ((getCoupMachine()>getCoupJoueur()) || (getCoupMachine()==0 && getCoupJoueur()==3)){
            gagnantARetourner = 'M';
        }
    }

    return gagnantARetourner;
}

///* M�thodes utilitaires du Mod�le

int randMinMax(int min, int max){
    /* pr�-condition : min<max ;
       Le nbre al�atoire est compris entre [min, max[ */
    return rand()%(max-min) + min;
}

Chifoumi::UnCoup Chifoumi::genererUnCoup()
{
    UnCoup valeurGeneree;   // valeur � retourner

    valeurGeneree = rien;
    int valeurAleatoire;   // valeur al�atoire retourner par la machine
    valeurAleatoire = randMinMax(1,3);
    switch (valeurAleatoire) {
    case 1 : valeurGeneree=pierre;
    case 2 : valeurGeneree=papier;
    case 3 : valeurGeneree=ciseau;
    }
    return valeurGeneree;
}

/// Setters

void Chifoumi::setCoupJoueur(UnCoup p_coup) {
    coupJoueur = p_coup;
}

void Chifoumi::setCoupMachine(UnCoup p_coup) {
    coupMachine = p_coup;
}

void Chifoumi::setScoreJoueur(unsigned int p_score) {
    scoreJoueur = p_score;
}

void Chifoumi::setScoreMachine(unsigned int p_score) {
    scoreMachine = p_score;
}

void Chifoumi::majScores(char p_gagnant) {
    if (p_gagnant=='M'){
        setScoreMachine(getScoreMachine()+1);
    }
    else if (p_gagnant=='J'){
        setScoreJoueur(getScoreJoueur()+1);
    }
}

void Chifoumi::initScores() {
    scoreJoueur=0;
    scoreMachine=0;
}

void Chifoumi::initCoups() {
    coupJoueur= rien;
    coupMachine = rien;
}
