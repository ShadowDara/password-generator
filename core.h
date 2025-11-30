#pragma once

#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <random>

// Help Function Declaration
int print_help();

std::vector<std::string> generate_password(int strength, int length, int count);

#endif // CORE_H
