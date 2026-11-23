
#pragma once

#include <map>
#include <string>
#include <vector>

#include "Observateur.h"

namespace Notification
{

    // Sujet du patron Observer : il détecte les passages sous le seuil (et le retour au seuil)
    // et avertit tous les observateurs abonnés. Il ne connaît aucun destinataire concret.
    class Notificateur
    {
    public:
        virtual ~Notificateur() = 0;

        void ajouterObservateur(Observateur *o);
        void retirerObservateur(Observateur *o);

    protected:
        Notificateur();

        void verifierEau(double qte);
        void verifierThe(const std::string &the, double qte);

    private:
        std::vector<Observateur *> observateurs_;
        bool eauFaible_;
        std::map<std::string, bool> theFaible_;
    };

} // namespace Notification
