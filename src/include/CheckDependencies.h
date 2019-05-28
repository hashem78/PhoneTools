#pragma once

#include <string>
#include <vector>

//so that adding files later won't be a problem
extern std::vector<std::string> filenames;
/*
  function: checkd
  description:
  checks for blobs for proper program function
  return values:
  1 if everything is present
  0 if something is missing
*/
int checkd();