#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

#include "../../include/notification/Notificateur.h"
#include "TheInsuffisant.h"
#include "EauInsuffisante.h"
#

namespace Machine
{

    class Reserve : public Notification::Notificateur
    {
    public:
        Reserve();
        void distribuerEau(double qte, double ratio);
        void distribuerThe(const std::string &the, double qte, double ratio);
        void activerNotifications(bool activer);
        void remplirThe(const std::string &the, double qte);
        void remplirEau(double qte);
        void ajouterThe(const The &the);
        void theSuffisant(const std::string &nomThe, double quantite, double ratio) const;
        const The &obtenirThe(const std::string &nomThe) const;
        void eauSuffisante(double quantite, double ratio) const;
        void afficherReserves() const;

    private:
        double qteEau_;
        std::unordered_map<std::string, The> thes_;
    };

} // namespace Machine