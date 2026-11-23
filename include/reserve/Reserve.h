#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../../include/notification/Notificateur.h"
#include "TheInsuffisant.h"
#include "EauInsuffisante.h"

namespace Machine
{

    class Reserve : public Notification::Notificateur
    {
    public:
        Reserve();

        // Déclare une réserve de thé (quantité initiale par défaut : 20 g).
        void ajouterThe(const std::string &nom);

        void distribuerEau(double qte, double ratio);
        void distribuerThe(const std::string &the, double qte, double ratio);
        void remplirThe(const std::string &the, double qte);
        void remplirEau(double qte);

        // Lèvent une exception, sans rien consommer, si la quantité (pertes incluses) manque.
        void theSuffisant(const std::string &nomThe, double quantite, double ratio) const;
        void eauSuffisante(double quantite, double ratio) const;

        void afficherReserves() const;

    private:
        double qteEau_;
        std::unordered_map<std::string, double> thes_;
        std::vector<std::string> ordreThes_;
    };

} // namespace Machine
