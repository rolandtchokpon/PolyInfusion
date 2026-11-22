
#include "../../include/notification/Notificateur.h"

namespace Notification {

    Notificateur::Notificateur()
    {
        observateurs_.clear();
    }

    Notificateur::~Notificateur() = default;


    void Notificateur::ajouterObservateur(Observateur* o) { this->observateurs_.push_back(o); }

    void Notificateur::retirerObservateur(Observateur* o) { 
        auto it = std::find(this->observateurs_.begin(), this->observateurs_.end(), o);
        observateurs_.erase(it);
    }

    void Notificateur::notifier(double qte) {
        for (auto o : this->observateurs_) {
            o->notifier(qte);
        }
    }

    void Notificateur::notifier(const std::string& the, double qte) {
        for (auto o : this->observateurs_) {
            o->notifier(the, qte);
        }
    }

}  // namespace Notification