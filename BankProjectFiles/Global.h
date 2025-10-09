#pragma once
#include <iostream>
#include "clsBankUser.h"

clsUser CurrentUser = clsUser::Find("", "");
bool FailLogin = true;

