#include "Idle.hpp"
#include "Game.hpp"
#include "Character.hpp"
#include "utils.hpp"

Idle::Idle()
: AAction(100, 4, "./assets/1 Characters/1/D_Idle.png", {}, NEVER) {}

Idle::~Idle() {}

void Idle::execute(Game& game, Character& actor) { /* Idle action does nothing */ }

bool Idle::isFinished() const { return false; }
