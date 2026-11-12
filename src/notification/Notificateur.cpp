
#include "../../include/notification/Notificateur.h"

namespace Notification {

    Notificateur::Notificateur() : 
        etat_(Etat::CORRECT), 
        notificationsActives_(true) 
    {
        observateurs_.clear();
    }

    Notificateur::~Notificateur() = default;

    void Notificateur::activerNotifications(bool activer) { this->notificationsActives_ = activer; }

    void Notificateur::ajouterObservateur(Observateur* o) { this->observateurs_.push_back(o); }

    void Notificateur::retirerObservateur(Observateur* o) { 
        auto it = std::find(this->observateurs_.begin(), this->observateurs_.end(), o);
        observateurs_.erase(it);
    }

    Etat Notificateur::obtenirEtat() { return etat_; }

    void Notificateur::mettreEtat(Etat e) { etat_ = e; }

    void Notificateur::notifier(double qte) {
        if (notificationsActives_) {
            for (auto o : this->observateurs_) {
                o->notifier(qte);
            }
        }
    }

    void Notificateur::notifier(const std::string& the, double qte) {
        if (notificationsActives_) {
            for (auto o : this->observateurs_) {
                o->notifier(the, qte);
            }
        }
    }

}  // namespace Notification