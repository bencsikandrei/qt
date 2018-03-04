#pragma once

// standard libs
#include <string>
#include <memory>
#include <cstdint>
#include <iostream>
#include <sstream>

namespace common {

// types
using Health = uint64_t;
using Damage = Health; // damage is the opposite of health
using Name = std::string;

// constants
constexpr Health DEFAULT_VEHICLE_HEALTH = 100;

} // common
