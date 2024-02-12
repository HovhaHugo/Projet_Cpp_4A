#include "users.h"

Users::Users() {
    admin = false;
    profils = new Profil();
}

Users::~Users(){
    delete(profils);
}
