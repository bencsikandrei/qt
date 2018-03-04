#pragma once

// standard libs
#include <string>
#include <memory>
#include <cstdint>
#include <iostream>
#include <sstream>

// project specific
#include <position.h>

namespace common {

using Health = uint64_t;
using Damage = Health; // damage is the opposite of health

constexpr Health DEFAULT_VEHICLE_HEALTH = 100;


} // common
