// src/myLib.cpp
#include "myLib.h"

#include <tinyxml2.h>

bool validate_xml(const char *xml) {
  tinyxml2::XMLDocument doc;
  doc.Parse(xml);

  return doc.ErrorID() == 0;
}
