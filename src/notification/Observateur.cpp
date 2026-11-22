
#include "../../include/notification/Observateur.h"

namespace Notification
{

    Observateur::~Observateur() = default;

    Observateur::Observateur() : notifActive_(true) {}

    void Observateur::activerNotifications(bool activer) { notifActive_ = activer; }

} // namespace Notification