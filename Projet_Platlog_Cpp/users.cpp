#include "users.h"

Users::Users() {
    profils = new Profil();
}

Users::~Users(){
    delete(profils);
}
