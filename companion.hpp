#ifndef COMPANION_H_INCLUDED
#define COMPANION_H_INCLUDED

#include <string>

class Companion
{
    public:

    std::string name;

    int blu;
    int prc;
    int sla;
    int fire;
    int ice;
    int wat;
    int thu;
    int win;
    int ear;
    int lig;
    int drk;
    int bluRes;
    int prcRes;
    int slaRes;
    int firRes;
    int iceRes;
    int watRes;
    int thuRes;
    int winRes;
    int earRes;
    int ligRes;
    int drkRes;
    int poison;
    int stun;
    int curse;
    int blind;
    int slow;
    int haste;
    int sleep;
    int frozen;
    int burn;
    int petrified;
    int stop;
    int fear;
    int order;
    double hitRate;

    unsigned int level;
    unsigned int exp;


    Companion(std::string name, int blu, int prc, int sla, int fire, int ice, int wat, int thu, int win, int ear, int lig, int drk,
    int bluRes, int prcRes, int slaRes, int firRes, int iceRes, int watRes, int thuRes, int winRes, int earRes, int ligRes, int drkRes,
    int poison, int stun, int curse, int blind, int slow, int haste,
    int sleep, int frozen, int burn, int petrified, int stop, int fear, int order,
    double hitRate, unsigned level = 1)
    {
            this->name = name;
			this->blu = blu;
			this->prc = prc;
			this->sla = sla;
			this->fire = fire;
			this->ice = ice;
			this->wat = wat;
			this->thu = thu;
			this->win = win;
			this->ear = ear;
			this->lig = lig;
			this->drk = drk;
			this->bluRes = bluRes;
			this->prcRes = prcRes;
			this->slaRes = slaRes;
			this->firRes = firRes;
			this->iceRes = iceRes;
			this->watRes = watRes;
			this->thuRes = thuRes;
			this->winRes = winRes;
			this->earRes = earRes;
			this->ligRes = ligRes;
			this->drkRes = drkRes;
			this->poison = poison;
			this->stun = stun;
			this->blind = blind;
			this->curse = curse;
			this->slow = slow;
			this->haste = haste;
			this->sleep = sleep;
			this->frozen = frozen;
			this->burn = burn;
			this->petrified = petrified;
			this->stop = stop;
			this->fear = fear;
			this->hitRate = hitRate;
			this->level = level;
			this->exp = 0;
			this->order = order;
    }

        Companion()
        {

        }

};

#endif // COMPANION_H_INCLUDED
