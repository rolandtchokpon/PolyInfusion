
#pragma once

namespace Machine { class Systeme; }

namespace CMD
{

    // Une opération demandée à la machine. Elle ne connaît ni la console ni l'historique.
    class Commande
    {
    public:
        virtual ~Commande() = 0;
        virtual void executer(Machine::Systeme *sys) = 0;

    protected:
        Commande();
    };

} // namespace CMD
