#include "assets.h"
#include <string>

std::string getAssetPath(const std::string &relativePath) {
  	return std::string(ASSET_PATH) + relativePath;
}

