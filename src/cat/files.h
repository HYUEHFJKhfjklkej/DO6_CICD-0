// Copyright (c) 2022 Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See License file in the project root for
// license information.
//  Created by greengrb on 05.11.2022.
//
#ifndef SRC_CAT_FILES_H_
#define SRC_CAT_FILES_H_

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILE_NAME 256
void symbol(const char* simvol_masiva, int* counter, int* flag_combo_etv);
int cat(int argc, char* argv[]);

#endif  // SRC_CAT_FILES_H_
